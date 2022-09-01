#include <string>

class Rectangle {
    private:
        double width;
        double height;
        std::string gender;
    
    public:
        double area(void);
        std::string get_gender(void);
        Rectangle(void);
};
