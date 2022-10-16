#include <vector>
#include <string>

/* Smallest unit of data in the database */
typedef struct BookAndDue {
    std::string title;
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
};