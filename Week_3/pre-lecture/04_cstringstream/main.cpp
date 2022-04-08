#include<iostream>
#include<stdio.h>
#include<cstring>

int main()
{
    char output_filename[100];
    int file_index{123};

    sprintf(output_filename, "FileData.%d", file_index);

    std::cout << output_filename << std::endl;

    return 0;
}
