#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

struct Course {
    std::string name;
    int code;
    double mark;
};

int get_first_digit(int i)
{
    std::string s{std::to_string(i)};
    return std::stoi(s.substr(0,1));
}

int main()
{
    std::cout << "11_filter-vector" << std::endl;

    std::vector<double> v{6,4, 3,2, 5,6, 43.76, 3};

    v.erase(std::remove_if(v.begin(), v.end(), [&](double x) -> bool {return x!=6;} ), v.end());

    for (auto iter=v.begin(); iter!=v.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    std::vector<Course> courses{{"AQM", 40567, 50.2}, {"QFT", 40798, 72}, {"EM", 30567, 60}};

    courses.erase(std::remove_if(courses.begin(), courses.end(), [&](Course c) -> bool { return get_first_digit(c.code)!=3;}), courses.end());

    for (auto i=courses.begin(); i!=courses.end(); ++i) {
        std::cout << i->code << " " << i->name << std::endl;
    }

    return 0;
}

