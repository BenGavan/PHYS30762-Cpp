#include<iostream>
#include<vector>
#include<algorithm>

struct Course {
    std::string name;
    int code;
    double mark;
};

int main()
{
    std::cout << "10_sort-vector" << std::endl;

    std::vector<double> v{1.5, 4.5, 3.0, 0};
    std::vector<std::string> ss{"anna", "ben", "Ben", "Anna", "sam"};
    std::vector<Course> courses{{"AQM", 40567, 50.2}, {"QFT", 40798, 72}};

    std::sort(v.begin(), v.end(), [&](double i,double j) { return (i<j); });

    for (auto iter=v.begin(); iter!=v.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    std::sort(ss.begin(), ss.end(), [&](std::string a, std::string b) { return a < b; });

    for (auto it=ss.begin(); it!=ss.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::sort(courses.begin(), courses.end(), [&](Course a, Course b) { return a.name > b.name; });

    for (auto i=courses.begin(); i!=courses.end(); ++i) {
        std::cout << i->name << std::endl;
    }

    return 0;
}
