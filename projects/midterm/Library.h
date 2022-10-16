#pragma once
#include <vector>
#include <string>

typedef struct Book {
    long long int isbn;
    std::string title;
    std::string author;
    std::string category;
    int id;
} Book;

class Library {
    private:
        std::vector<Book> catalog;
        int number_of_books;

    public:
        Library();
        void print_book(Book book);
        void Library::print_books_vector(std::vector<Book> bookvec);
        void print_all_books();
        /* 
        std::vector<Book> search_book_title(std::string title);
        std::vector<Book> search_book_isbn(long long isbn);
        std::vector<Book> search_book_author(std::string author);
         */
};