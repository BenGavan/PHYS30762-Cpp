/*
 * 17/03/2022
 * PHYS30762 - Assignment 4 - Class for complex numbers
*/

#include<iostream>
#include<cmath>
#include<sstream>

class complex
{
    friend std::ostream &operator<<(std::ostream &os, const complex &z);
    friend std::istream &operator>>(std::istream &is, complex &z);
private:
    double real, imaginary;
public:
    complex() : real{0}, imaginary{0} {}
    complex(const double real_in, const double imaginary_in) :
        real{real_in}, imaginary{imaginary_in} {}

    ~complex() {}

    double get_real() const { return real; }
    double get_imaginary() const { return imaginary; }

    double modulus() const;
    double argument() const;
    complex conjugate() const;

    complex operator+(const complex &z) const;
    complex operator-(const complex &z) const;
    complex operator*(const complex &z) const;
    complex operator/(const complex &z) const;
};

double complex::modulus() const
{
    return std::sqrt(real * real + imaginary * imaginary);
}

complex complex::conjugate() const
{
    return complex{real, -imaginary};
}

double complex::argument() const
{
    return std::atan2(imaginary, real);
}

complex complex::operator+(const complex &z) const
{
    const complex sum{real + z.real, imaginary + z.imaginary};
    return sum;
}

complex complex::operator-(const complex &z) const
{
    return {real - z.real, imaginary - z.imaginary};
}

complex complex::operator*(const complex &z) const
{
    return {real * z.real - imaginary * z.imaginary,
            imaginary * z.real + real * z.imaginary};
}

complex complex::operator/(const complex &z) const
{
    const double mod2 = z.real*z.real + z.imaginary*z.imaginary;
    return {(real * z.real + imaginary * z.imaginary) / mod2,
            (imaginary * z.real - real * z.imaginary) / mod2};
}

std::ostream &operator<<(std::ostream &os, const complex &z)
{
    // prints in format: "a+ib" or "a-ib"
    os << z.real;
    if (z.imaginary >= 0) {
        os << "+i";
    } else {
        os << "-i";
    }
    os << std::abs(z.imaginary);
    return os;
}

std::istream &operator>>(std::istream &is, complex &z)
{
    // input format: "a+ib" or "a-ib"
    char sign;

    is >> z.real >> sign;
    is.ignore(1);  // ignore 'i'
    is.putback(sign); // put the sign back in front of the imaginary component.
    is >> z.imaginary;

    return is;
}

int main()
{
    std::cout.precision(3);

    const complex a{3, 4};
    const complex b{1, -2};

    std::cout << "--- Using ---" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;

    // Get real and imaginary components
    std::cout << "--- real and imaginary components ---" << std::endl;
    std::cout << "Re(a) = " << a.get_real() << ", Im(a) = "
              << a.get_imaginary() << std::endl;

    const double b_real{b.get_real()};
    const double b_imag{b.get_imaginary()};
    std::cout << "Re(b) = " << b_real << ", Im(b) = " << b_imag << std::endl;
    std::cout << std::endl;

    // Get modulus and argument
    std::cout << "--- modulus and argument ---" << std::endl;
    std::cout << "mod(a) = " << a.modulus() << ", arg(a) = " << a.argument()
              << std::endl;

    const double b_mod{b.modulus()};
    const double b_arg{b.argument()};
    std::cout << "mod(b) = " << b_mod << ", arg(b) = " << b_arg << std::endl;
    std::cout << std::endl;

    // Get conjugates
    std::cout << "--- Conjugates ---" << std::endl;
    std::cout << "a* = " << a.conjugate() << std::endl;

    const complex b_conjugate{b.conjugate()};
    std::cout << "b* = " << b_conjugate << std::endl;
    std::cout << std::endl;

    // Sum a+b, difference, product, & quotient
    std::cout << "--- Sum, difference, product, & quotient ---" << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
    std::cout << std::endl;

    // Instream demonstration from string
    std::cout << "--- Instream from std::stringstrean ---" << std::endl;
    std::stringstream stringstream;
    stringstream << "3.141-i59.265";
    complex string_input_z;
    stringstream >> string_input_z;

    std::cout << "Input z from string: " << string_input_z << std::endl;
    std::cout << std::endl;

    // Instream demonstration from console
    std::cout << "--- Instream from std::cin (format: \"a+ib\" or \"a-ib\") ---" << std::endl;
    complex console_input_z;
    std::cin >> console_input_z;

    std::cout << "Input z from console: z = " << console_input_z << std::endl;
    std::cout << "z* = " << console_input_z.conjugate() << std::endl;
    std::cout << "Re(z) = " << console_input_z.get_real() << ", Im(z) = "
        << console_input_z.get_imaginary() << std::endl;
    std::cout << "mod(z) = " << console_input_z.modulus() << ", arg(z) = " << console_input_z.argument()
        << std::endl;

    return 0;
}
