#include<iostream>
#include<memory>

class base_class{
public:
    base_class() {}
    ~base_class() {}
    virtual void print() = 0;
};

class my_class : public base_class
{
public:
    my_class() { std::cout << "my_class constructor (with i = " << i << " already)\n"; }
    my_class(double i) : i{i} { std::cout << "my_class constructor setting i = " << i << "\n"; }
    my_class(const my_class&) { std::cout << "my_class copy constructor\n"; }
    my_class(my_class&&) { std::cout << "my_class move constructor\n"; }
    ~my_class() { std::cout << "~my_class destructor (i=" << i  << ")\n" << std::endl; }

    double i;

    void print() {
        std::cout << "hi\n";
    }
};

class deleter
{
public:
    deleter() {}
    deleter(const deleter&) { std::cout << "deleter copy ctor\n"; }
    deleter(deleter&) { std::cout << "non-const deleter copy ctor\n"; }
    deleter(deleter&&) { std::cout << "deleter move ctor\n"; }
    void operator() (my_class* p) const {
        std::cout << "deleter is deleting a my_class with i = " << p->i << "\n";
        delete p;
    }
};

int main()
{
    std::cout << "Week 9 - Pre-lecture: Smart ptr" << std::endl;

    std::cout << "Example constructor 1\n---------------------\n";

//    std::unique_ptr<>()
    std::unique_ptr<my_class> up1;
    std::unique_ptr<my_class> up1b{nullptr};

    std::cout << "Example constructor 2\n---------------------\n";
    {
        std::unique_ptr<my_class> up2{new my_class{2}};  // up2 now owns a my_class

        std::unique_ptr<base_class> upalt2{std::make_unique<my_class>(my_class{3})};

        upalt2->print();
    } // my_class deleted (i=2)
    return 0;

    std::cout << "Example constructor 3\n---------------------\n";
    deleter d;
    {
        std::unique_ptr <my_class, deleter> up3{new my_class, d};  // deleter copied
        std::cout << "-\n";
        std::cout << up3.get()->i << std::endl;
    }


    // deleter type is a reference
    {
        std::unique_ptr<my_class, deleter&> up3b{new my_class{3}, d};  // up3b holds a reference to d
        std::cout << "-\n";
        std::cout << up3b.get()->i << std::endl;
    }

    std::cout << "Example constructor 4\n---------------------\n";
    {  // deleter is not a reference
        std::unique_ptr<my_class, deleter> up4{new my_class, deleter{}};  // deleter moved
    }

    std::cout << "Example constructor 5\n---------------------\n";
    {
        std::unique_ptr<my_class> up5a{new my_class{5}};
        std::unique_ptr<my_class> up5b{std::move(up5a)};  // ownership transfer

        std::cout << up5b.get()->i << std::endl;
    }

    std::cout << "Example constructor 6\n---------------------\n";
    {
        std::unique_ptr<my_class, deleter> up6a{new my_class{6.1}, d};  // deleter is copied
        std::unique_ptr<my_class, deleter> up6b(std::move(up6a));  // deleter is moved

        std::unique_ptr<my_class, deleter&> up6c{new my_class{6.3}, d};  // deleter is a reference
        std::unique_ptr<my_class, deleter> up6d{move(up6c)};  // deleter is copied
    }

    std::cout << "Example constructor 7\n---------------------\n";
    {
        std::unique_ptr<my_class> up7a{new my_class{7.1}};
        std::unique_ptr<my_class> up7b{std::move(up7a)};  // ownership transfer
        std::cout << up7b.get()->i << std::endl;
    }

    return 0;
}