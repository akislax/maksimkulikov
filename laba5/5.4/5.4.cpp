#include "5.4.h"

void addBook(std::map<std::string, std::string>& books, std::map<std::string, std::string>& status) {
    std::string bookId, bookName;
    std::cin >> bookId >> bookName;
    if (books.count(bookId)) {
        std::cout << "Ошибка: Книга с идентификатором " << bookId << " уже существует" << std::endl;
    } else {
        books[bookId] = bookName;
        status[bookId] = "lib";
        std::cout << "Книга " << bookId << " " << bookName << " добавлена" << std::endl;
    }
}

void borrowBook(std::map<std::string, std::string>& books, std::map<std::string, std::string>& status, std::map<std::string, std::vector<std::string>>& readerBooks) {
    std::string bookId, readerId;
    std::cin >> bookId >> readerId;
    if (books.find(bookId) == books.end()) {
        std::cout << "Ошибка: Книги с идентификатором " << bookId << " не существует" << std::endl;
    } else if (status[bookId] != "lib") {
        std::cout << "Ошибка: Книга уже выдана" << std::endl;
    } else if (readerBooks[readerId].size() >= 2) {
        std::cout << "Ошибка: Книгу нельзя выдать читателю " << readerId << ", поскольку у него превышен лимит" << std::endl;
    } else {
        status[bookId] = readerId;
        readerBooks[readerId].push_back(bookId);
        std::cout << "Книга " << bookId << " выдана читателю " << readerId << std::endl;
    }
}

void returnBook(std::map<std::string, std::string>& status, std::map<std::string, std::vector<std::string>>& readerBooks) {
    std::string bookId;
    std::cin >> bookId;
    if (status.find(bookId) == status.end() || status[bookId] == "lib") {
        std::cout << "Ошибка: Книги с идентификатором " << bookId << " нет у читателей" << std::endl;
    } else {
        std::string readerId = status[bookId];
        status[bookId] = "lib";
        auto& currentBooks = readerBooks[readerId];
        for (auto it = currentBooks.begin(); it != currentBooks.end(); ++it) {
            if (*it == bookId) { currentBooks.erase(it); break; }
        }
        std::cout << "Книга " << bookId << " возвращена в библиотеку" << std::endl;
    }
}

void bookStatus(std::map<std::string, std::string>& books, std::map<std::string, std::string>& status) {
    std::string bookId;
    std::cin >> bookId;
    if (books.find(bookId) == books.end()) {
        std::cout << "Ошибка: Книги не существует" << std::endl;
    } else if (status[bookId] == "lib") {
        std::cout << "Книга " << bookId << " находится в библиотеке" << std::endl;
    } else {
        std::cout << "Книга " << bookId << " находится у читателя " << status[bookId] << std::endl;
    }
}

void readerBooks(std::map<std::string, std::vector<std::string>>& readerBooks) {
    std::string readerId;
    std::cin >> readerId;
    std::cout << "Читатель " << readerId << " имеет книги:";
    if (readerBooks[readerId].empty()) {
        std::cout << " -" << std::endl;
    } else {
        for (const auto& bookId : readerBooks[readerId]) std::cout << " " << bookId;
        std::cout << std::endl;
    }
}