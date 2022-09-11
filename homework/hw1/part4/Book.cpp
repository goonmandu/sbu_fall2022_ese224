#include <iostream>
#include "Book.h"

Book::Book() {
    number = 0;
    title = "Example Title";
    author = "Example Name";
    genre = "Example Genre";
    pages = 0;
}

Book::Book(int number, std::string title, std::string author, std::string genre, int pages) {
    this->number = number;
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->pages = pages;
}

void Book::set_number(int number) {
    this->number = number;
}

void Book::set_title(std::string title) {
    this->title = title;
}

void Book::set_author(std::string author) {
    this->author = author;
}

void Book::set_genre(std::string genre) {
    this->genre = genre;
}

void Book::set_pages(int pages) {
    this->pages = pages;
}

void Book::operator= (const Book &b) {
    number = b.number;
    title = b.title;
    author = b.author;
    genre = b.genre;
    pages = b.pages;
}

void Book::print_stats() {
    std::cout << "Book Number: " << number << std::endl;
    std::cout << "Book Title: " << title << std::endl;
    std::cout << "Book Author: " << author << std::endl;
    std::cout << "Book Genre: " << genre << std::endl;
    std::cout << "Book Pages: " << pages << std::endl;
}