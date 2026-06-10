#include "5.4.h"

int main() {
    int queryCount;
    std::cin >> queryCount;
    std::map<std::string, std::string> bookNames;
    std::map<std::string, std::string> bookStatusMap;
    std::map<std::string, std::vector<std::string>> readerBooksMap;
    
    std::string command;
    while (queryCount--) {
        std::cin >> command;
        if (command == "ADD_BOOK") addBook(bookNames, bookStatusMap);
        else if (command == "BORROW") borrowBook(bookNames, bookStatusMap, readerBooksMap);
        else if (command == "RETURN") returnBook(bookStatusMap, readerBooksMap);
        else if (command == "BOOK_STATUS") bookStatus(bookNames, bookStatusMap);
        else if (command == "READER_BOOKS") readerBooks(readerBooksMap);
    }
    return 0;
}