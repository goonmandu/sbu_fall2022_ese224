#pragma once

class Student {
    private:
        std::string name;
        std::string id;
        std::string major;
        std::string email;

    public:
        Student();
        Student(std::string name, std::string id, std::string major, std::string email);
        std::string get_name();
        std::string get_id();
        std::string get_major();
        std::string get_email();
        void set_name(std::string name);
        void set_id(std::string id);
        void set_major(std::string major);
        void set_email(std::string email);
        void print_attribs();
};