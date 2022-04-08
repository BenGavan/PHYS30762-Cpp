#include<iostream>
#include<vector>
#include<string>

void print_vector_double(std::vector<int> v)
{
    for (int i{0}; i<v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "06_vector1" << std::endl;

    const size_t n_a{5};
    std::vector<double> a{n_a};
    std::vector<double> b;
    std::vector<int> c(3, 1); // vector of len=3 with elements = 1
    std::vector<std::string> names{3};
    std::vector<std::vector<double>> dd{3};

//    print_vector_double(a);
//    print_vector_double(b);
    print_vector_double(c);

    dd[0] = a;

    return 0;
}
