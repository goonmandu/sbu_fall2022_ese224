#include <iostream>
#include <string>

class Rectangle {
    private:
        double height;
        double width;
        std::string gender;

    public:
        double area(void) {
            return width * height;
        }

        std::string get_gender(void) {
            return gender;
        }
        
    // Constructor
    Rectangle(double w, double h, std::string g) {
        width = w;
        height = h;
        gender = g;
    }
};

int main() {
    Rectangle r1 = Rectangle(6.9, 4.2, "male");

    std::cout << r1.area() << std::endl;
    std::cout << r1.get_gender() << std::endl;
    return 0;
}



/*
int main() {
    int num = 69;
    float noom = 4.20;
    char c = 't';
    std::string mystr = "Hello world!";
    std::string anotherstr = "bruhg";
    std::string combined = mystr + anotherstr;
    std::cout << mystr + anotherstr << c << noom + num << num << std::endl;
    return 0;
}
*/