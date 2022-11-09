#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Library.h"
#define STUDENT_BORROW_DURATION 30
#define STUDENT_BORROW_LIMIT 5
#define SECONDS_PER_DAY 5

typedef struct StudentData {
    std::string username;
    std::vector<Book> borrowed_books_student;
    std::vector<Book> current_student_books;
} StudentData;

class Student
{
    private:
        std::string session_username, session_password;
        int numCopies, maxBorrow;
        std::vector<std::string> usernames;
        std::vector<std::string> passwords;
        std::fstream myFile;
        int inter;
        std::vector<StudentData> database;
        int index_in_database;
    public:
        Student();
        StudentData get_userdata(std::istream& in);
        void print_userdata(StudentData data);
        int index_of_username(std::string username);
        void returnBook(int id);
        std::string GetUsername();
        std::string GetPassword();
        int getNumCopy();
        int getBorrow();
        void clear_history();
        Book return_book_student(Library lib, int id);
        Book renew_book_student(int id);
        bool borrow_book_student(Library lib, int id);
        void renew();
        void update_day(double day);
        void request_book(Library lib, long long int isbn, std::string title, std::string author, std::string category);
        //void debugprinteruser();
        //void debugprintpass();
        int menu(Library &lib);
        bool auth(std::string usr, std::string pas);
        //int BorrowBooks(int id);
        void fill_creds();
        bool check_auth(std::string id, std::string pw);
        void print_all_users_in_db();
        bool session_has_overdue_books();
        bool session_exceeded_books_limit();
};