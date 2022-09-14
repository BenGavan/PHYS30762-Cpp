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

int main()
{
    std::cout << "Week 8 - Pre-lecture: Polymorphic Array" << std::endl;

    particle** particle_ptr_array = new particle*[2];
    particle_ptr_array[0] = new particle{2};
    particle_ptr_array[1] = new ion{1, 2};  // He+

    particle_ptr_array[0]->info();
    particle_ptr_array[1]->info();

    delete particle_ptr_array[0];
    delete particle_ptr_array[1];
    delete[] particle_ptr_array;

    return 0;
}