#include<iostream>

template <class T> class pair_of_numbers
{
private:
    T x, y;
public:
    pair_of_numbers() : x{}, y{} {}
    pair_of_numbers(T x, T y) : x{x}, y{y} {}
    T add() { return x + y; }
    T sub() { return x - y; }
};

int main()
{
    std::cout << "Week 9 - Pre-lecture: Two num 2" << std::endl;

    int x{1};
    int y{2};

    double a{-1.5};
    double b{-2.5};

    // Use class template for object representing pair of integers
    pair_of_numbers<int> int_pair{x, y};
    std::cout << "x + y = " << int_pair.add() << std::endl;
    std::cout << "x - y = " << int_pair.sub() << std::endl;

    // Use class template for object representing pair of doubles
    pair_of_numbers<double> double_pair{a, b};
    std::cout << "x + y = " << double_pair.add() << std::endl;
    std::cout << "x - y = " << double_pair.sub() << std::endl;


    return 0;
}