#include<iostream>
#include<string>
#include<sstream>

int main()
{
    int file_index{123};

    std::ostringstream output_stream;
    output_stream << "FileData." << file_index;
    std::string output_filename = output_stream.str();
    std::cout << output_filename << std::endl;
    output_stream.str("");
//    output_stream.clear();

    return 0;
}
