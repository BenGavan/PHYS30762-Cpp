#include<iostream>
#include<list>

void print_list(std::list<int> &list_in)
{
    std::cout << "List contents: ";
    for (auto li=list_in.begin(); li != list_in.end(); ++li) {
        std::cout << *li << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Week 10 - Pre-lecture: List" << std::endl;

    std::list<int> my_list;

    my_list.push_front(1);
    my_list.push_front(2);

    my_list.push_back(3);
    my_list.push_back(4);

    print_list(my_list);

    // insertion via iterator
    std::list<int>::iterator li{my_list.begin()};
    for (int i{0}; i<2; i++) {
        li++;
    }
    my_list.insert(li, 5);

    print_list(my_list);

    // sort list
    my_list.sort();
    print_list(my_list);

    // new second list
    std::list<int> my_list2;
    for (int i{0}; i<3; i++) {
        my_list2.push_back(9-i);
    }

    print_list(my_list2);

    // merge lists
    my_list.merge(my_list2);

    // sort
    my_list.sort();
    print_list(my_list);
    print_list(my_list2);

    // remove first entry
    my_list.pop_front();

    // remove last entry
    my_list.pop_back();

    print_list(my_list);

    return 0;
}