#include<iostream>

class A {
protected:
    double Ax;
public:
    A(const double Axin) : Ax{Axin} {}
    void show() {
        std::cout << "Ax=" << Ax << std::endl;
    }
};

class B {
protected:
    double Bx;
public:
    B(const double Bxin) : Bx{Bxin} {}
    void show() {
        std::cout << "Bx = " << Bx << std::endl;
    }
};

class C : public A, public B {
protected:
    double Cx;
public:
    C(const double Axin, const double Bxin, const double Cxin) :
        A{Axin}, B(Bxin), Cx{Cxin} {}
    void show() {
        std::cout << "Ax = " << Ax << ", Bx = " << Bx << ", Cx = " << Cx << std::endl;
    }
};

class D : public C {
protected:
    double Dx;
public:
    D(const double Axin, const double Bxin, const double Cxin, const double Dxin) : C(Axin, Bxin, Cxin), Dx{Dxin} {}
    void show() {
        std::cout << "Ax = " << Ax << ", Bx = " << Bx << ", Cx = " << Cx << ", Dx = " << Dx << std::endl;
    }
};

int main() {
    C my_object{0.1, 0.2, 0.3};
    my_object.show();
    return 0;
}