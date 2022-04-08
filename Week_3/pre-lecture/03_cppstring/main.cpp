#include<iostream>
#include<string>

int main()
{
    std::cout << "03_cppstring" << std::endl;

    std::string first_string{"Hello"};

    std::cout << first_string.length() << ", " << first_string << std::endl;
    std::cout << "Second char: " << first_string[1] << std::endl;

    // input
    std::string input_string;

    std::cout << "Enter a phrase: ";

    std::cin >> input_string;
    std::cin.ignore();

    std::cout << "You entered: " << input_string << std::endl;

    std::cout << "Enter a phrase: ";
    getline(std::cin, input_string);

    std::cout << "You entered: " << input_string << std::endl;

    std::string second_string{"Hello need this long like really long"};

    if (first_string == second_string) {
        std::cout << "strings match" << std::endl;
    }

    std::cout << "--- Join ---" << std::endl;

    std::string joined_string{first_string + second_string};
    std::cout << "joined_string: " << joined_string << std::endl;

    std::cout << "--- Append ---" << std::endl;
    first_string += second_string;
    std::cout << "First + Second: " << first_string << std::endl;

    std::cout << "--- Extract ---" << std::endl;
    const size_t first{18};
    const size_t last{26};
    std::string a_word = joined_string.substr(first, last - first + 1);
    std::cout << a_word << std::endl;

    return 0;
}
