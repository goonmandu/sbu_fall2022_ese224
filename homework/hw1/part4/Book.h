#pragma once
#include <iostream>

class Book {
    private:
        int number;
        std::string title;
        std::string author;
        std::string genre;
        int pages;

    public:
        Book();
        Book(int number, std::string title, std::string author, std::string genre, int pages);
        void set_number(int number);
        void set_title(std::string title);
        void set_author(std::string author);
        void set_genre(std::string genre);
        void set_pages(int pages);
        void print_stats();
        void operator= (const Book &b);
};