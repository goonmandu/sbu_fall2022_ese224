#pragma once
#include <vector>
#include <string>

typedef struct Book {
    long long int isbn;
    std::string title;
    std::string author;
    std::string category;
    int id;
    std::string reader;
    int borrow_date;        // = "start date of borrowing periods"
    int return_date;        // = "expiration date"
} Book;

typedef struct User {
    int is_teacher;
    std::string username;
    std::string password;
} User;

class Library {
    private:
        std::vector<Book> catalog;
        std::vector<User> credentials;
        int number_of_books;

    public:
        Library();
        void print_book(Book book);
        void Library::print_books_vector(std::vector<Book> bookvec);
        void print_all_books();
        User search_user(std::string username);
        void print_user(User user);
        std::vector<Book> search_book_title(std::string title);
        std::vector<Book> search_book_isbn(long long isbn);
        std::vector<Book> search_book_author(std::string author);
};