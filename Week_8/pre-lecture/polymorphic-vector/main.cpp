#include<iostream>
#include<vector>

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

    std::vector<particle*> particle_ptrs;
    particle_ptrs.push_back(new particle{2});
    particle_ptrs.push_back(new ion{1, 2});

    particle_ptrs[0]->info();
    particle_ptrs[1]->info();

    std::cout << "Particles size = " << particle_ptrs.size() << std::endl;

    for (auto iterator=particle_ptrs.begin(); iterator<particle_ptrs.end(); ++iterator) {
        delete *iterator;
    }

    particle_ptrs.clear();

    std::cout << "Particles size = " << particle_ptrs.size() << std::endl;

    return 0;
}