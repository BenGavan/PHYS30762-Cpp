#include <iostream>
#include <cmath>
#include <iomanip>

/*
 * Assignment 1
 * Ben Gavan - 18/02/2022
 * Program to calculate transition energy using simple Bohr formula.
 */

double ev_to_joules(double ev)
{
    return ev * 1.60218 * pow(10, -19);
}

double calculate_transition_energy(int atomic_number, int initial_quantum_number,
                                   int final_quantum_number, bool is_energy_units_ev)
// Calculate transition energy in either eV (default) or J (units='J')
{
    double delta_energy = 13.6 * std::pow(atomic_number, 2)
            * (std::pow(final_quantum_number, -2) - std::pow(initial_quantum_number, -2));  // eV
    if (!is_energy_units_ev) {
        delta_energy = ev_to_joules(delta_energy);
    }
    return delta_energy;
}

std::string remove_leading_whitespace(std::string s)
{
    if (s.empty()) return s;

    int start_index = s.find_first_not_of(" \n\r\f\t\v");
    return s.substr(start_index);
}

std::string remove_trailing_whitespace(std::string s)
{
    if (s.empty()) return s;

    int end_index = s.find_last_not_of(" \n\r\f\t\v");
    return s.substr(0, end_index+1);
}

std::string trim_whitespace(std::string s)
// Remove both leading and trailing whitespace.
{
    return remove_leading_whitespace(remove_trailing_whitespace(s));
}

bool is_number(std::string s)
// Check if all characters in string is numeric (0123456789.) (includes period).
{
    std::string::iterator iterator = s.begin();
    while ( (iterator != s.end()) && (std::isdigit(*iterator) || *iterator == '.')) {
        ++iterator;
    }
    return !s.empty() && (iterator == s.end());
}

bool is_integer_in_inclusive_bounds(int i, int lower_bound, int upper_bound)
{
    return (i >= lower_bound) && (i <= upper_bound);
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

int get_integer_input(std::string prompt_str)
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

int get_integer_input_with_bounds(std::string prompt_str, int lower_bound, int upper_bound)
// Request integer input with inclusive bounds using a given string prompt
// until a valid integer is given.
{
    int input = get_integer_input(prompt_str);
    while (!is_integer_in_inclusive_bounds(input, lower_bound, upper_bound)) {
        std::cout << "Entered integer out of bounds, need to be in range: ("
        << lower_bound << " <= i <= " << upper_bound << ")." << std::endl;
        input = get_integer_input(prompt_str);
    }
    return input;
}

bool get_bool_input(std::string prompt_str, std::string true_str, std::string false_str)
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

void run()
{
    bool is_correct{false};
    int atomic_number;
    int initial_quantum_number;
    int final_quantum_number;
    bool is_energy_units_ev;
    std::string energy_unit_str;

    while (!is_correct) {
        atomic_number = get_integer_input_with_bounds("Enter atomic number:",
                                                      1, INT32_MAX);
        initial_quantum_number = get_integer_input_with_bounds("Enter initial quantum number: ",
                                                   1, INT32_MAX);
        final_quantum_number = get_integer_input_with_bounds("Enter final quantum number: ",
                                                 1, INT32_MAX);
        is_energy_units_ev = get_bool_input("Enter energy eV or J: (e/J) ", "e", "J");

        if (is_energy_units_ev) {
            energy_unit_str = "eV";
        } else {
            energy_unit_str = "J";
        }

        std::cout << "-------------------" << std::endl;
        std::cout << "You entered:\n";
        std::cout << "-------------------" << std::endl;
        std::cout << "Atomic number, Z = " << atomic_number << std::endl;
        std::cout << "Initial quantum number: " << initial_quantum_number << std::endl;
        std::cout << "Final quantum number: " << final_quantum_number << std::endl;
        std::cout << "Energy units: " << energy_unit_str << std::endl;
        std::cout << "-------------------" << std::endl;

        is_correct = get_bool_input("Is this correct? (y/n)", "y", "n");
    }

    // calculate transition energy
    double transition_energy = calculate_transition_energy(atomic_number,
                                                           initial_quantum_number,
                                                           final_quantum_number,
                                                           is_energy_units_ev);

    std::cout << "-------------------" << std::endl;
    std::cout << "Transition energy = " << std::setprecision(3)
    << transition_energy << " " << energy_unit_str << std::endl;

    if (transition_energy > 0) {
        std::cout << "-> Photon emitted with energy: " << std::setprecision(3)
        << transition_energy << " " << energy_unit_str << std::endl;
    } else if (transition_energy < 0) {
        std::cout << "-> Photon absorbed with energy: " << std::setprecision(3)
        << std::abs(transition_energy) << " " << energy_unit_str << std::endl;
    } else {
        std::cout << "No transition has occurred!" << std::endl;
    }
    std::cout << "-------------------" << std::endl;
}

int main()
{
    bool is_finished{false};

    while (!is_finished) {
        run();
        is_finished = get_bool_input("Repeat (0) or exit (1)?: ", "1", "0");
        std::cout << "********************" << std::endl;
    }

    return 0;
}