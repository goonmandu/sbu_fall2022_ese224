#include <vector>
#include <iostream>

typedef struct Book {
    long long int isbn;
    std::string title;
    std::string author;
    std::string category;
    int id;
    double due_in;
} Book;

typedef struct UserData {
    std::string username;
    bool is_teacher;
    std::vector<Book> borrowed_books;
} UserData;

class Reader {
    protected:
        std::vector<UserData> database = {
            {"Teacher1", true, {
                {69420, "Sometitle", "Someauthor", "Somecategory", 0, -1},
                {7469, "Someothertitle", "Someotherauthor", "Someothercategory", 1, 4}
            }},
            {"Student1", false, {
                {1234321, "Studenttitle", "Studentauthor", "Studentcategory", 2, 7}
            }}
        };

    public:
        void return_book(int id) {
            std::cout << "Returned book " << id << std::endl;
        }
        void borrow_book(int id) {
            std::cout << "Borrowed book " << id << std::endl;
        }
        void renew_book(int id) {
            std::cout << "Renewed book " << id << std::endl;
        }
        void number_of_users() {
            std::cout << "Number of users: " << database.size() << std::endl;
        }
};

class Teacher: public Reader {
    public:
        Teacher() {
            std::cout << "Teacher constructor called" << std::endl;
        }
        void delete_book(int id) {
            std::cout << "Deleted book " << id << std::endl;
        }
        void request_book(int id) {
            std::cout << "Added book " << id << std::endl;
        }
};

class Student: public Reader {
    public:
        Student() {
            std::cout << "Student constructor called" << std::endl;
        }
};

void role(Student s) {
    std::cout << "The user is a student!" << std::endl;
}

void role(Teacher t) {
    std::cout << "The user is a teacher!" << std::endl;
}

int main() {
    Teacher teacher = Teacher();
    Student student = Student();
    teacher.request_book(69);
    student.renew_book(420);
    teacher.number_of_users();
    role(teacher);
    role(student);
}