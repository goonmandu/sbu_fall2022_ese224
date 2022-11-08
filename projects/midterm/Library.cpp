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

    consec_id = 0;

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

    catalog.push_back({-1, "", "", "", -1, -1});  // Invalid book in catalog to return pointers as

    while (!books.eof()) {
        books >> isbn >> title >> author >> category >> copies;
        for (int i = 0; i < copies; i++) {
            book = {isbn, title, author, category, consec_id, -1};
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
};

Book Library::borrow_book(int id, int borrow_days) {
    Book *bookptr = search_id(id);
    bookptr->due_in = borrow_days;
    return *(bookptr);
}

void Library::return_book(int id) {
    /* Sequential
    for (Book book : catalog) {
        if (book.id == id) {
            book.due_in = -1;
            return;
        }
    }
     */
    
    /* Use existing function to directly modify attribute */
    Book *bookptr = search_id(id);
    bookptr->due_in = -1;
}

void Library::delete_book(int id) {
    int index = search_id(id) - &catalog[0];
    catalog.erase(catalog.begin() + index);
}

void Library::add_book(long long int isbn, std::string title, std::string author, std::string category) {
    Book book = {isbn, title, author, category, consec_id++, -1};
    catalog.push_back(book);
    this->number_of_books = catalog.size();
}

void Library::update_day(int days) {
    for (Book book : catalog) {
        if (book.due_in > 0) {
            book.due_in -= days;
            if (book.due_in < 0) {
                book.due_in = 0;
            }
        }
    }
}

Book* Library::search_id(int id) {
    return binary_search_catalog(id, 0, this->number_of_books - 1);
}

Book* Library::binary_search_catalog(int id, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (catalog[mid].id == id) {
            return &catalog[mid];
        }
        if (catalog[mid].id > id) {
            return binary_search_catalog(id, start, mid - 1);
        }
        if (catalog[mid].id < id) {
            return binary_search_catalog(id, mid + 1, end);
        }
    }
    return &catalog[0];
}

std::ostream& operator<<(std::ostream &out, const Book &book) {
    out << "ISBN:     " << book.isbn << std::endl;
    out << "Title:    " << book.title << std::endl;
    out << "Author:   " << book.author << std::endl;
    out << "Category: " << book.category << std::endl;
    out << "Intrn ID: " << book.id << std::endl << std::endl;
    return out;
}

std::istream& operator>>(std::istream &in, Book &book) {
    std::cout << "ISBN:     ";
    in >> book.isbn;
    std::cout << "Title:    ";
    in >> book.title;
    std::cout << "Author:   ";
    in >> book.author;
    std::cout << "Category: ";
    in >> book.category;
    std::cout << "Intrn ID: ";
    in >> book.id;
    return in;
}