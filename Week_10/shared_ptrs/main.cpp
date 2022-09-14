#include <iostream>
#include <memory>
#include <vector>

class base
{
private:
    int id;
public:
    base() {}
    base(const int &id) : id{id} {}
    ~base() { std::cout << "deleting base with id: " << id << std::endl; }

    void print() {
        std::cout << "id: " << id << std::endl;
    }
};

class report
{
private:
    std::vector<std::shared_ptr<base>> objects;
public:
    report() {}
    report(const std::vector<std::shared_ptr<base>> &objects) : objects{objects} {}
    ~report() { objects.clear(); }

    void print() {
        std::cout << "Report:\n-------\n";
        for (auto iter{objects.begin()}; iter!=objects.end(); ++iter) {
            (*iter)->print();
        }
        std::cout << "-------" << std::endl;
    }

    void pop() {
        objects.pop_back();
    }
};

void print_vector(const std::vector<std::shared_ptr<base>> &vect) {
    std::cout << "vector:\n-------\n";
    for (auto iter{vect.begin()}; iter!=vect.end(); ++iter) {
        (*iter)->print();
    }
    std::cout << "-------" << std::endl;
}

int main()
{
    std::cout << "Week 10 - Shared Pointers" << std::endl;

    std::vector<std::shared_ptr<base>> obs;
    obs.push_back(std::shared_ptr<base>(new base{1}));
    obs.push_back(std::shared_ptr<base>(new base{2}));

    report rep{obs};

    rep.print();
    print_vector(obs);

    std::cout << "\n------------\n";
    std::cout << "pop original\n";
    obs.pop_back();
    std::cout << "------------" << std::endl;

    rep.print();
    print_vector(obs);

    std::cout << "\n----------\n";
    std::cout << "pop report\n";
    rep.pop();
    std::cout << "----------" << std::endl;

    rep.print();
    print_vector(obs);

    std::cout << "\n----------\n";
    std::cout << "pop report again\n";
    rep.pop();
    std::cout << "----------" << std::endl;

    rep.print();
    print_vector(obs);

    obs.clear();

    return 0;
}