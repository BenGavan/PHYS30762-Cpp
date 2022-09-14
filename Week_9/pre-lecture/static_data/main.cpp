#include<iostream>

class my_class
{
private:
    int x{0};
    static int n_objects;
public:
    my_class() : x{0} { n_objects++; }
    my_class(int x) : x{x} { n_objects++; }
    ~my_class() { n_objects--; }
    void show() {
        std::cout << "x = " << x << ", n_objects = " << n_objects << std::endl;
    }
};

int my_class::n_objects{0};


void test()
{
    my_class a3{3};
    a3.show();
}

int main()
{
    std::cout << "Week 9 - Pre-lecture: Static data" << std::endl;

    my_class a1{1};
    a1.show();

    my_class a2{2};
    a2.show();

    test();

    a1.show();

    return 0;
}