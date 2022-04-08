/*
 * PHYS30762 - Assignment 2
 * Ben Gavan - 18/02/2022
 *
 * Program to compute mean, standard deviation and standard
 * error of the a set of courses. Data is read from file.
 */

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<iomanip>

struct Course {
    std::string name;
    int code;
    double mark;

    std::string make_course_title() const;
};

std::string Course::make_course_title() const
{
    std::ostringstream string_stream;
    string_stream << "PHYS " << code << ' ' << name;
    std::string course_title(string_stream.str());
    string_stream.str("");
    return course_title;
}

int get_first_digit(const int i)
{
    std::string s{std::to_string(i)};
    return std::stoi(s.substr(0,1));
}

std::string remove_leading_whitespace(const std::string s)
{
    if (s.empty()) return s;

    int start_index = s.find_first_not_of(" \n\r\f\t\v");
    return s.substr(start_index);
}

std::string remove_trailing_whitespace(const std::string s)
{
    if (s.empty()) return s;

    int end_index = s.find_last_not_of(" \n\r\f\t\v");
    return s.substr(0, end_index+1);
}

std::string trim_whitespace(const std::string s)
// Remove both leading and trailing whitespace.
{
    return remove_leading_whitespace(remove_trailing_whitespace(s));
}

bool is_number(std::string s)
// Check if all characters in string is numeric (0123456789.-).
{
    std::string::iterator iterator = s.begin();
    while ( (iterator != s.end())
            && (std::isdigit(*iterator) || *iterator == '.' || *iterator == '-')) {
        ++iterator;
    }
    return !s.empty() && (iterator == s.end());
}

void get_integer_input(int* input, bool* is_input_valid_integer)
{
    std::string in_str;
    std::getline(std::cin, in_str);

    in_str = trim_whitespace(in_str);

    // Check if string is numeric only (1,2,3,4,5,7,8,9,0,.)
    if (!is_number(in_str)) {
        *is_input_valid_integer = false;
        return;
    }

    int input_as_int;
    double input_as_double;

    // Try to convert input string to integer and a double.
    // If the integer and double version have the same double value, the
    // original string was intended to be an integer.
    try {
        input_as_int = std::stoi(in_str);
        input_as_double = std::stod(in_str);

        if (input_as_double == double(input_as_int)) {
            *input = input_as_int;
            *is_input_valid_integer = true;
            return;
        }
    } catch (...) {
        *is_input_valid_integer = false;
        return;
    }
}

int get_integer_input(const std::string prompt_str)
{
    int input;
    bool is_input_integer{false};
    while (!is_input_integer) {
        std::cout << prompt_str << std::endl;
        get_integer_input(&input, &is_input_integer);
        if (!is_input_integer) std::cout << "Please enter a valid integer" << std::endl;
    }
    return input;
}

int get_integer_input_with_bounds(const std::string prompt_str, const int lower_bound,
                                  const int upper_bound)
// Request integer input with inclusive bounds using a given string prompt
// until a valid integer is given.
{
    int input = get_integer_input(prompt_str);
    while (!(lower_bound <= input && input <= upper_bound)) {
        std::cout << "Entered integer out of bounds, need to be in range: ("
                  << lower_bound << " <= i <= " << upper_bound << ")." << std::endl;
        input = get_integer_input(prompt_str);
    }
    return input;
}

bool get_bool_input(const std::string prompt_str, const std::string true_str,
                    const std::string false_str)
// Request string input of two options corresponding to a boolean value until
// valid option entered.
{
    std::string in_str;

    // Request for input until input is valid
    while (true) {
        std::cout << prompt_str << std::endl;
        std::getline(std::cin, in_str);
        if (in_str == true_str) return true;
        if (in_str == false_str) return false;
        std::cout << "Please enter a valid option: (" << true_str << "/"
                  << false_str << ")" << std::endl;
    }
}

double calculate_mean_mark(const std::vector<Course>& courses)
{
    if (courses.size() == 0) return 0;

    double total_mark{0};
    double num_courses{double(courses.size())};
    for (auto iterator=courses.begin(); iterator!=courses.end(); ++iterator) {
        total_mark += iterator->mark;
    }
    return total_mark / num_courses;
}

double calculate_standard_deviation(const std::vector<Course>& courses)
{
    if (courses.size() <= 1) return 0;

    double num_courses{double(courses.size())};
    double mean_mark{calculate_mean_mark(courses)};
    double std_deviation_squared{0};

    for (auto iterator=courses.begin(); iterator!=courses.end(); ++iterator) {
        std_deviation_squared += std::pow(iterator->mark - mean_mark, 2);
    }

    std_deviation_squared *= 1.0 / (num_courses - 1.0);
    return std::sqrt(std_deviation_squared);
}

double calculate_standard_error(const double std_deviation, const int num_coursers)
{
    if (num_coursers == 0) return 0;
    return std_deviation / std::sqrt(num_coursers);
}

std::vector<std::string> make_course_title_vector(const std::vector<Course>& courses)
{
    std::vector<std::string> course_titles{courses.size()};
    for (int i{0}; i<courses.size(); i++) {
        course_titles[i] = courses[i].make_course_title();
    }
    return course_titles;
}

size_t count_lines_in_file(const std::string filename)
{
    std::fstream file_stream(filename);

    int num_lines{0};
    char c;

    file_stream.get(c);

    while (!file_stream.eof()) {
        if (c=='\n') num_lines++;
        file_stream.get(c);
    }

    file_stream.close();
    return num_lines;
}

std::string get_filename(const std::string prompt_str)
{
    std::string filename;
    bool does_filename_exit{false};
    while (!does_filename_exit) {
        std::cout << prompt_str;
        std::getline(std::cin, filename);
        std::fstream course_file_stream(filename);
        does_filename_exit = !(!course_file_stream);

        if (!does_filename_exit) {
            std::cout << "Filename (\"" << filename << "\") not valid!" << std::endl;
        }
    }

    return filename;
}

void extract_data_from_line(std::string line, double& mark, int& course_code, std::string& course_name)
{
    int start_index = line.find_first_of(" ");
    std::string mark_str = line.substr(0, start_index);
    line = line.substr(start_index);

    start_index = line.find_first_not_of(" \t");
    line  = line.substr(start_index);

    int end_index = line.find_first_of(" \t");
    std::string course_code_str = line.substr(0, end_index);
    line = line.substr(end_index);

    end_index = line.find_first_not_of(" \t");
    line = line.substr(end_index);

    course_name = line;

    try {
        mark = std::stof(mark_str);
        course_code = std::stoi(course_code_str);
    } catch (...) {
        std::cout << "invalid line" << std::endl;
    }
}

std::vector<Course> get_courses_from_file(const std::string filename)
{
    std::fstream course_file_stream(filename);

    const size_t num_lines{count_lines_in_file(filename)};
    std::cout << "Number of lines/courses in file: " << num_lines << std::endl;

    if (num_lines == 0) return {};

    std::vector<Course> courses{num_lines};

    // read in data
    std::string line_str;
    int line_counter{0};

    while (getline(course_file_stream, line_str)) {
        double mark;
        int course_code;
        std::string course_name;

        extract_data_from_line(line_str, mark, course_code, course_name);

        Course c{course_name, course_code, mark};
        courses[line_counter] = c;
        line_counter++;
    }

    course_file_stream.close();

    return courses;
}

void filter_courses(std::vector<Course>& courses, const int year)
{
    if (year >= 1 && year <= 4) {
        courses.erase(std::remove_if(courses.begin(), courses.end(),
                                     [&](Course course) {
            return get_first_digit(course.code) != year;
        } ), courses.end());
    }
}

void order_courses(std::vector<Course>& courses, const bool is_ordered_by_title,
                   const bool is_ordered_ascending)
{
    if (is_ordered_by_title) {
        if (is_ordered_ascending) {
            std::sort(courses.begin(), courses.end(),
                      [&](Course a, Course b) -> bool { return a.name > b.name; });
        } else {
            std::sort(courses.begin(), courses.end(),
                      [&](Course a, Course b) -> bool { return a.name < b.name; });
        }
    } else {
        if (is_ordered_ascending) {
            std::sort(courses.begin(), courses.end(),
                      [&](Course a, Course b) { return a.code < b.code; });
        } else {
            std::sort(courses.begin(), courses.end(),
                      [&](Course a, Course b) { return a.code > b.code; });
        }
    }
}

void analyse_courses(const std::vector<Course>& courses)
{
    double mean_mark = calculate_mean_mark(courses);
    double standard_deviation = calculate_standard_deviation(courses);
    double standard_error{calculate_standard_error(standard_deviation, courses.size())};

    std::cout << "-------------" << std::endl;
    std::cout << "Mean mark: " << std::fixed << std::setprecision(2) << mean_mark << std::endl;
    std::cout << "Standard Deviation: " << std::fixed << std::setprecision(2) << standard_deviation << std::endl;
    std::cout << "Standard Error: " << std::fixed << std::setprecision(2) << standard_error << std::endl;
    std::cout << "-------------" << std::endl;
}

void print_courses(const std::vector<Course>& courses)
{
    std::cout << "-------------" << std::endl;
    for (auto iterator=courses.begin(); iterator!=courses.end(); ++iterator) {
        std::cout << iterator->make_course_title() << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

int main()
{
    std::cout << "-------------" << std::endl;
    std::cout << "Instructions:" << std::endl;
    std::cout << "Please provide a file with one course per line in the format"
                 " \"{MARK} {COURSE_CODE} {COURSE_TITLE}\" with a new line at "
                 "the end of file." << std::endl;
    std::cout << "-------------" << std::endl;

    const std::string filename = get_filename("Enter filename (relative to "
                                              "current working directory): ");

    std::vector<Course> courses{get_courses_from_file(filename)};

    if (courses.size() == 0) {
        std::cout << "No courses in file!" << std::endl;
        std::cout << " -> Exiting program." << std::endl;
        return 0;
    }

    const int year_input{get_integer_input_with_bounds("Enter year (1-4) or all"
                                                       " years (0): ", 0, 4)};
    const bool is_ordered_by_title{get_bool_input("How would you like courses to be "
                                                  "ordered: title or code (t/c)?",
                                                  "t", "c")};
    const bool is_ordered_ascending{get_bool_input("Ascending or Descending (a/d)?",
                                                   "a", "d")};

    filter_courses(courses, year_input);
    order_courses(courses, is_ordered_by_title, is_ordered_ascending);

    print_courses(courses);
    analyse_courses(courses);

    return 0;
}
