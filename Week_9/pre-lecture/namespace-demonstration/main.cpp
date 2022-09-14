#include <iostream>

namespace namespace1 {
    const double ab{1.5};

    class my_class
    {
    private:
        int x;
    public:
        my_class() : x{} {}
        my_class(int xx): x{xx} {}
        ~my_class() {}
        void show() { std::cout << "x = " << x << std::endl; }
    };
}

namespace namespace2 {
    const double ab{2.5};

    class my_class
    {
    private:
        int x, y;
    public:
        my_class(): x{}, y{} {}
        my_class(int xx, int yy): x{xx}, y{yy} {}
        ~my_class() {}
        void show() { std::cout << "x = " << x << ", y = " << y << std::endl; }
    };

}

int main()
{
    std::cout << "Week 9 - Pre-lecture: Namespace Demonstration" << std::endl;

    namespace1::my_class c1{1};
    c1.show();

    namespace2::my_class c2{1, 2};
    c2.show();

    std::cout << "namespace1::ab = " << namespace1::ab << std::endl;
    std::cout << "namespace2::ab = " << namespace2::ab << std::endl;

    return 0;
}