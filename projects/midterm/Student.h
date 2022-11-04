#include "Library.h"
#include <vector>
#include <string>

/* Struct that has a username and their borrowed books */
typedef struct UserData {

    /* Username */
    std::string username;

    /* List of the books and their due dates */
    std::vector<Book> borrowed_books;

} UserData;


class Student {
    private:
        /* A list of UserData variables */
        std::vector<UserData> database;
    
    public:
        Student();
        UserData get_userdata(std::istream& in);
        void print_userdata(UserData data);
        void update_day(int days);
        int index_of_username(std::string username);
};