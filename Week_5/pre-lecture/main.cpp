#include<iostream>

class vector3 {
    friend vector3 operator+(double scalar, const vector3 &v3);
    friend std::ostream& operator<<(std::ostream &os, const vector3 &v);
private:
    double x, y, z;
public:
    vector3(): x{}, y{}, z{} {}
    vector3(double xin, double yin, double zin): x{xin}, y{yin}, z{zin} {}
    ~vector3() {
        std::cout << "Destroying vector" << std::endl;
    }

    void set_x(double xin) {
        x = xin;
    }

    void set_y(double yin) {
        y = yin;
    }

    void set_z(double zin) {
        z = zin;
    }

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    double get_z() const {
        return z;
    }

    double dot_product(const vector3 &v) const {
        return x*v.x + y*v.y + z*v.z;
    }

    vector3 operator+(const vector3 &v) const {
        vector3 temp{x+v.x, y+v.y, z+v.z};
        return temp;
    }

    vector3 operator+(const double scalar) const {
        vector3 temp{x+scalar, y+scalar, z+scalar};
        return temp;
    }

    void operator+=(const double scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
    }

    void operator+=(const vector3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }
};

vector3 operator+(double scalar, const vector3 &v) {
    
}

int main() {
    std::cout << "Week 5 - pre-lecture" << std::endl;

    return 0;
}