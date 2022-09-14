#include<iostream>
#include<map>
#include<string>

typedef std::map<int, std::string> international_dial_codes;

void search_database(international_dial_codes &dial_codes, int code_search)
{
    international_dial_codes::iterator dial_codes_iterator;
    dial_codes_iterator = dial_codes.find(code_search);

    if (dial_codes_iterator != dial_codes.end()) {
        std::cout << "Found country for dial code " << code_search << " = " << dial_codes_iterator->second << std::endl;
    } else {
        std::cout << "Sorry, code " << code_search << " is not in database" << std::endl;
    }
}

int main()
{
    std::cout << "Week 10 - Pre-lecture: Map" << std::endl;

    international_dial_codes dial_codes;

    dial_codes[49] = "Germany";
    dial_codes[44] = "UK";

    dial_codes.insert(std::pair<int, std::string>(672, "Christmas Island"));

    std::cout << "Size of database = " << dial_codes.size() << std::endl;

    for (auto dial_codes_iter = dial_codes.begin(); dial_codes_iter != dial_codes.end(); ++dial_codes_iter) {
        std::cout << "Dial code: " << dial_codes_iter->first << ", country: " << dial_codes_iter->second <<std::endl;
    }

    int code_search{672};
    search_database(dial_codes, code_search);

    code_search = 673;
    search_database(dial_codes, code_search);

    return 0;
}