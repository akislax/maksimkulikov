#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>

void addBook(std::map<std::string, std::string>& books, std::map<std::string, std::string>& status);
void borrowBook(std::map<std::string, std::string>& books, std::map<std::string, std::string>& status, std::map<std::string, std::vector<std::string>>& readerBooks);
void returnBook(std::map<std::string, std::string>& status, std::map<std::string, std::vector<std::string>>& readerBooks);
void bookStatus(std::map<std::string, std::string>& books, std::map<std::string, std::string>& status);
void readerBooks(std::map<std::string, std::vector<std::string>>& readerBooks);