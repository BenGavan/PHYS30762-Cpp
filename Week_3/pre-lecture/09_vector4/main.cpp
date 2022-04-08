#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::cout << "09_vector4" << std::endl;

    std::vector<double> double_vector;
    double_vector.push_back(4.5);
    double_vector.push_back(1.5);
    double_vector.push_back(3.0);

    std::vector<double>::iterator vector_begin{double_vector.begin()};
    std::vector<double>::iterator vector_end{double_vector.end()};
    std::vector<double>::iterator vector_iterator;

    std::sort(vector_begin, vector_end);

    std::cout << "ascending" << std::endl;

    for (vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        std::cout << *vector_iterator << std::endl;
    }

    std::cout << "reverse" << std::endl;

    std::reverse(vector_begin, vector_end);

    for (vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        std::cout << *vector_iterator << std::endl;
    }

    std::cout << "alt" << std::endl;

    for (auto iterator=double_vector.begin(); iterator!=double_vector.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }

    return 0;
}
