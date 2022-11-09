#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Library.h"
#define TEACHER_BORROW_DURATION 50
#define TEACHER_BORROW_LIMIT 10
#define SECONDS_PER_DAY 5

typedef struct TeacherData {
    std::string username;
    std::vector<Book> borrowed_books_teacher;
    std::vector<Book> current_teacher_books;
} TeacherData;

class Teacher
{
private:
    std::string session_username, session_password;
    int numCopies, maxBorrow;
    std::vector<std::string> usernames;
    std::vector<std::string> passwords;
    std::fstream myFile;
    int inter;
    std::vector<TeacherData> database;
    int index_in_database;
public:
    Teacher();
    TeacherData get_userdata(std::istream& in);
    void print_userdata(TeacherData data);
    int index_of_username(std::string username);
    void returnBook(int id);
    std::string GetUsername();
    std::string GetPassword();
    int getNumCopy();
    int getBorrow();
    void clear_history();
    Book return_book_teacher(Library lib, int id);
    Book renew_book_teacher(int id);
    bool borrow_book_teacher(Library lib, int id);
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