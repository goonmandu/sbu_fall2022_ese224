#include <vector>
#include <string>


/* Smallest unit of data in the database */
typedef struct BookAndDue {

    /* Book title */
    Book book;

    /* How many days the book is due in */
    int due;

} BookAndDue;


/* Struct that has a username and their borrowed books */
typedef struct UserData {

    /* Username */
    std::string username;

    /* List of the books and their due dates */
    std::vector<BookAndDue> borrowed_books;

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
        int Student::index_of_username(std::string username);
};