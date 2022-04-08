#include<iostream>

class rectangle {
    int x, y;
public:
    rectangle(): x{}, y{} {};

    rectangle(int a, int b): x{a}, y{b} {};

    ~rectangle() {
        std::cout << "Deleting rectangle" << std::endl;
    }

    void set_dimensions(int, int);

    int area() {
        return x*y;
    }
};

void rectangle::set_dimensions(int a, int b) {
    x = a;
    y = b;
}

int main() {
    std::cout << "02_rectangle" << std::endl;

    rectangle rectangle1;
    std::cout << "Rectangle has area: " << rectangle1.area() << std::endl;
    rectangle1.set_dimensions(3, 5);
    std::cout << "Rectangle has area: " << rectangle1.area() << std::endl;

    return 0;
}