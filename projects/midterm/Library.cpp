#include <iostream>
#include <fstream>
#include <algorithm>
#include "Library.h"

Library::Library() {
    std::ifstream books, users;

    long long int isbn;
    std::string title;
    std::string author;
    std::string category;
    int copies;

    int is_teacher;
    std::string username;
    std::string password;

    Book book;

    int consec_id = 0;

    books.open("book.txt");
    if (books.fail()) {
        std::cerr << "Could not open books file!" << std::endl;
        exit(1);
    }
    
    users.open("student.txt");
    if (users.fail()) {
        std::cerr << "Could not open credentials file!";
        exit(1);
    }

    while (!books.eof()) {
        books >> isbn >> title >> author >> category >> copies;
        for (int i = 0; i < copies; i++) {
            book = {isbn, title, author, category, consec_id};
            this->catalog.push_back(book);
            consec_id++;
        }
    }
    number_of_books = catalog.size();
}

int Library::num_books() {
    return number_of_books;
}

void Library::print_book(Book book) {
    std::cout << "ISBN:     " << book.isbn << std::endl;
    std::cout << "Title:    " << book.title << std::endl;
    std::cout << "Author:   " << book.author << std::endl;
    std::cout << "Category: " << book.category << std::endl;
    std::cout << "Intrn ID: " << book.id << std::endl << std::endl;
}

void Library::print_books_vector(std::vector<Book> bookvec) {
    for (Book book : bookvec)  {
        print_book(book);
    }
}

void Library::print_all_books() {
    for (Book book : catalog) {
        print_book(book);
    }
}

Book Library::borrow_book(int id) {
    
}

void return_book(int id) {

}

void add_book(Book book) {

}

void update_day(int days) {

}

Book Library::search_catalog_by_id(int id, int start, int end) {
    Book invalid = {.isbn=-1};
    if (start <= end) {
        int mid = (start + end) / 2;
        if (catalog[mid].id == id) {
            return catalog[mid];
        }
        if (catalog[mid].id > id) {
            return search_catalog_by_id(id, start, mid - 1);
        }
        if (catalog[mid].id < id) {
            return search_catalog_by_id(id, mid + 1, end);
        }
    }
    return invalid;
}