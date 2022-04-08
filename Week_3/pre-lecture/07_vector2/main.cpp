#include<iostream>
#include<vector>

int main()
{
    std::cout << "07_vector2" << std::endl;

    const size_t n_a{5};
    std::vector<double> a{n_a};
    std::vector<double> b;
    std::vector<int> c{3, 1};
    std::vector<std::string> names{3};
    std::vector<std::vector<double>> dd{3};

    dd[0] = a;

    if (!(a.empty())) {
        std::cout << "a is not empty" << std::endl;
    }

    if (b.empty()) std::cout << "b is empty" << std::endl;

    std::cout << "a has size: " << a.size() << std::endl;
    std::cout << "b has size: " << b.size() << std::endl;
    std::cout << "c has size: " << c.size() << std::endl;
    std::cout << "names has size: " << names.size() << std::endl;
    std::cout << "dd has size: " << dd.size() << std::endl;

    names[0] = "Vector";
    names[1] = "of";
    names[2] = "strings";

    for (size_t i{0}; i<names.size(); i++) {
        std::cout << "names[" << i << "] = " << names[i] << std::endl;
    }

    b.push_back(1.5);
    b.push_back(3.0);
    b.push_back(4.5);

    std::cout << "b now has size: " << b.size() << std::endl;

    for (size_t i{0}; i<b.size(); ++i) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    b.pop_back();

    std::cout << "b now has size: " << b.size() << std::endl;

    for (size_t i{0}; i<b.size(); ++i) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    return 0;
}
