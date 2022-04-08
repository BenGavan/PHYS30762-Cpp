#include<iostream>
#include<cmath>

class particle {
private:
    std::string type{"Ghost"};
    double mass{0.0};
    double momentum{0.0};
    double energy{0.0};

public:
    particle() = default;  // Default constructor
    particle(std::string particle_type, double particle_mass,
             double particle_momentum) : type(particle_type), mass{particle_mass},
                                         momentum{particle_momentum},
                                         energy{sqrt(mass * mass + momentum * momentum)} {}

    // Destructor
    ~particle() {
        std::cout << "Destroying particle: " << type << std::endl;
    }

    double gamma() {
        return energy / mass;
    }

    void print_data();
};

void particle::print_data() {
    std::cout.precision(3);
    std::cout << "Particle: [type,m,p,E] = [" << type << ", " << mass
              << ", " << momentum << ", " << energy << "]" << std::endl;
}

int main() {
    std::cout << "05_class4" << std::endl;

    particle electron{"electron", 5.11e5, 1.e6};
    particle proton{"proton", 0.938e9, 3.e9};

    electron.print_data();
    proton.print_data();

    std::cout.precision(3);
    std::cout << "Particle 1 has Lorentz factor gamma = " << electron.gamma() << std::endl;
    std::cout << "Particle 2 has Lorentz factor gamma = " << proton.gamma() << std::endl;

    return 0;
}