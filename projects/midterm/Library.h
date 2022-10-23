#pragma once
#include <vector>
#include <string>

typedef struct Book {
    long long int isbn;
    std::string title;
    std::string author;
    std::string category;
    int id;
    int due_in;  // -1 if in available, nonnegative (>0) if on loan
} Book;

class Library {
    private:
        std::vector<Book> catalog;
        int number_of_books;
        int consec_id;

    public:
        Library();
        int num_books();
        void print_book(Book book);
        void print_books_vector(std::vector<Book> bookvec);
        void print_all_books();
        Book borrow_book(int id, int borrow_days);
        void return_book(int id);
        void delete_book(int id);
        void add_book(long long int isbn, std::string title, std::string author, std::string category);
        void update_day(int days);
        Book search_catalog_by_id(int id, int start, int end);
        /*
        std::vector<Book> search_book_title(std::string title);
        std::vector<Book> search_book_isbn(long long isbn);
        std::vector<Book> search_book_author(std::string author);
         */
};