#include<iostream>


class particle
{
public:
    virtual ~particle() {}  // need this
    virtual void info()=0;  // pure virtual function
};

class electron : public particle
{
private:
    int charge;
public:
    electron() : charge{-1} {}
    ~electron() { std::cout << "Electron destructure called" << std::endl; }
    void info() { std::cout << "electron: charge = " << charge << "e" << "\n--------" << std::endl; }
};

class ion : public particle
{
private:
    int charge, atomic_number;
public:
    ion(int q, int z) : charge{q}, atomic_number{z} {}
    ~ion() { std::cout << "ion destructure called" << std::endl; }
    void info() { std::cout << "ion:\ncharge = " << charge << "e\natomic number = " << atomic_number << "\n--------" << std::endl; }
};

class neutrino : public particle
{
private:
    int charge, flavour;
public:
    neutrino(int q, int f) : charge{q}, flavour{f} {}
    ~neutrino() { std::cout << "neutrino destructure called" << std::endl; }
    void info() { std::cout << "neutrino:\ncharge = " << charge << "e\nflavour = " << flavour << "\n--------" << std::endl; }
};

int main() {
    std::cout << "Week 8 - Pre-lecture: Abstract" << std::endl;

    particle* particle_ptr = new ion{1, 2};
    particle_ptr->info();
    delete particle_ptr;

    particle_ptr = new electron;
    particle_ptr->info();
    delete particle_ptr;

    particle_ptr = new neutrino{0, 2};
    particle_ptr->info();
    delete particle_ptr;

    return 0;
}