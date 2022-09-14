#include<iostream>
#include<cmath>
#include<vector>

/*
 *  Assignment 6 - Shapes
 */

class shape
{
public:
    shape() {}
    virtual ~shape() { std::cout << "deleting shape" << std::endl; }
    virtual void print() const = 0;
    virtual double area() const = 0;
};

class shape_2d : public shape
{
public:
    shape_2d() {}
    virtual ~shape_2d() { std::cout << "deleting shape_2d -> "; }
    virtual double perimeter() const = 0;
};

class shape_3d : public shape
{
public:
    shape_3d() {}
    virtual ~shape_3d() { std::cout << "deleting shape_3d -> "; }
    virtual double volume() const = 0;
};

class rectangle : public shape_2d
{
private:
    double side_length_a, side_length_b;
public:
    rectangle() : side_length_a{0}, side_length_b{0} {}
    rectangle(const double a, const double b) :
        side_length_a{a}, side_length_b{b} {}
    ~rectangle() { std::cout << "deleting rectangle -> "; }

    double perimeter() const
        { return side_length_a * 2 + side_length_b * 2; }
    double area() const { return side_length_a * side_length_b; }

    void print() const { std::cout << "Rectangle:\narea = " << area()
        << "\nperimeter = " << perimeter() << "\n---------" << std::endl; }
};

class square : public rectangle
{
public:
    square() : rectangle{0, 0} {}
    square(const double side_length) : rectangle{side_length, side_length} {}
    ~square() { std::cout << "deleting square -> "; }

    void print() const override { std::cout << "Square:\narea = " << area()
        << "\nperimeter = " << perimeter() << "\n---------" << std::endl; }
};

class ellipse : public shape_2d
{
private:
    double semi_minor, semi_major;
public:
    ellipse() : semi_minor{0}, semi_major{0} {}
    ellipse(const double semi_minor, const double semi_major) :
        semi_minor{semi_minor}, semi_major{semi_major} {}
    ~ellipse() { std::cout << "deleting ellipse -> "; }

    double perimeter() const { return M_PI *
        ( 3.0 * (semi_minor + semi_major) -
        std::sqrt( (3.0 * semi_minor + semi_major)
            * (semi_minor + 3.0 * semi_major) )); }
    double area() const { return M_PI * semi_minor * semi_major; }

    void print() const { std::cout << "Ellipse:\narea = " << area()
        << "\nperimeter = " << perimeter() << "\n---------" << std::endl; }
};

class circle : public ellipse
{
public:
    circle() : ellipse{0, 0} {}
    circle(const double radius) : ellipse{radius, radius} {}
    ~circle() { std::cout << "deleting circle -> "; }

    void print() const { std::cout << "Circle:\narea = " << area()
        << "\nperimeter = " << perimeter() << "\n---------" << std::endl; }
};

class cuboid : public shape_3d
{
private:
    double side_length_a, side_length_b, side_length_c;
public:
    cuboid() {}
    cuboid(const double side_length_a, const double side_length_b,
           const double side_length_c) : side_length_a{side_length_a},
           side_length_b{side_length_b}, side_length_c{side_length_c} {}
    ~cuboid() { std::cout << "deleting cuboid -> "; }

    double ab_area() const { return side_length_a * side_length_b; }
    double ac_area() const { return side_length_a * side_length_c; }
    double bc_area() const { return side_length_b * side_length_c; }

    double volume() const
        { return side_length_a * side_length_b * side_length_c; }
    double area() const
        { return ab_area() * 2 + ac_area() * 2 + bc_area() * 2; }

    void print() const { std::cout << "Cuboid:\narea = " << area()
        << "\nvolume = " << volume() << "\n-------\n"; }
};

class cube : public cuboid
{
public:
    cube() : cuboid(0, 0, 0) {}
    cube(const double side_length) :
        cuboid(side_length, side_length, side_length) {}
    ~cube() { std::cout << "deleting cube -> "; }

    void print() const { std::cout << "Cube:\narea = " << area()
        << "\nvolume = " << volume() << "\n-------\n"; }
};

class ellipsoid : public shape_3d
{
private:
    double a{0}, b{0}, c{0};
public:
    ellipsoid() {}
    ellipsoid(const double a, const double b, const double c) :
        a{a}, b{b}, c{c} {}
    ~ellipsoid() { std::cout << "deleting ellipsoid -> "; }

    double volume() const { return (4.0/3.0) * M_PI * a * b * c; }
    double area() const {  // approximate surface area
        const double p{1.6075};
        const double x{std::pow(a, p) * std::pow(b, p)
                    + std::pow(a, p) * std::pow(c, p)
                    + std::pow(b, p) * std::pow(c, p)};
        return 4 * M_PI * std::pow(x/3, 1/p);
    }

    void print() const { std::cout << "Ellipsoid:\narea = " << area()
        << "\nvolume = " << volume() << "\n-------\n"; }
};

class sphere : public ellipsoid
{
public:
    sphere() {}
    sphere(const double radius) : ellipsoid(radius, radius, radius) {}
    ~sphere() { std::cout << "deleting sphere -> "; }

    void print() const { std::cout << "Sphere:\narea = " << area()
        << "\nvolume = " << volume() << "\n-------\n"; }
};

class prism : public shape_3d
{
private:
    shape_2d* base_2d_shape;
    double depth{0};
public:
    prism() {}
    prism(shape_2d* base_shape_ptr, const double depth) :
        base_2d_shape{base_shape_ptr}, depth{depth} {}
    ~prism()
    {
        std::cout << "deleting prism -> ";
        delete base_2d_shape;
        base_2d_shape = nullptr;
    }

    double volume() const { return base_2d_shape->area() * depth; }
    double area() const { return base_2d_shape->area() * 2
        + base_2d_shape->perimeter() * depth; }

    void print() const { std::cout << "Prism:\narea = " << area()
        << "\nvolume = " << volume() << "\n-------\n"; }
};

int main()
{
    std::cout << "C++ - Assignment 6 - shapes" << std::endl;

    // demonstration shapes
    std::vector<shape*> shapes{10};
    shapes[0] = new rectangle{1, 2};
    shapes[1] = new square{2};
    shapes[2] = new ellipse{1, 2};
    shapes[3] = new circle{3};
    shapes[4] = new cuboid{2,3,4};
    shapes[5] = new cube{3};
    shapes[6] = new ellipsoid{2, 3, 4};
    shapes[7] = new sphere{2};
    shapes[8] = new prism{new circle{3}, 10};
    shapes[9] = new prism{new rectangle{2, 3}, 4};

    // print information of each shape
    std::cout << "------------------\n";
    std::cout << "Shape information\n";
    std::cout << "------------------\n";
    for (auto iter=shapes.begin(); iter!=shapes.end(); ++iter) {
        (*iter)->print();
    }

    // clean up
    std::cout << "------------------\n";
    std::cout << "Cleaning up shapes\n";
    std::cout << "------------------\n";
    for (auto iter=shapes.begin(); iter!=shapes.end(); ++iter) {
        delete *iter;
        *iter = nullptr;
        std::cout << "----\n";
    }

    shapes.clear();

    return 0;
}