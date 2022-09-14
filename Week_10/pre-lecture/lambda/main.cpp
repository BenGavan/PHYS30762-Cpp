#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::cout << "Week 10 - Pre-lecture: Lambda" << std::endl;

    std::vector<int> v;

    for (int i{0}; i<10; i++) {
        v.push_back(i+1);
    }

    // Count the number of even numbers in vector
    int even_counter = 0;
    std::for_each(v.begin(), v.end(), [&even_counter] (int n) {
        std::cout << n;
        if (n % 2 == 0) {
            std::cout << " is even" << std::endl;
            ++even_counter;
        } else {
            std::cout << " is odd" << std::endl;
        }
    });

    std::cout << "There are " << even_counter << " even numbers in the vector." << std::endl;

    return 0;
}