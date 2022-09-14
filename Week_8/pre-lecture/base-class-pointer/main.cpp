#include<iostream>

class particle
{
protected:
    double charge;
public:
    particle(double q) : charge{q} {}
    virtual void info() { std::cout << "particle: charge = " << charge <<  "e" << std::endl; }
};

class ion : public particle
{
private:
    int atomic_number;
public:
    ion(double q, int z) : particle(q), atomic_number{z} {}
    void info() {
        std::cout << "ion:\ncharge = " << charge << "e\natomic number = " << atomic_number << "\n------" << std::endl;
    }
};

int main() {
    std::cout << "Week 8 - Pre-lecture: Base Class Pointer" << std::endl;

    particle particle_1{1};  // proton
    ion ion_1{2, 2};  // helium

    particle_1.info();
    ion_1.info();

    particle* particle_ptr;
    particle_ptr = &particle_1;
    particle_ptr->info();

    particle_ptr = &ion_1;
    particle_ptr->info();

    return 0;
}