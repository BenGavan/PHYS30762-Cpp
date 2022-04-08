#include<iostream>
#include<cmath>
#include<vector>

class particle {
private:
    std::string type;
    double mass;
    double momentum;
    double energy;
public:
    // Default constructor
    particle() : type{"Ghost"}, mass{}, momentum{}, energy{} {}
    // Parameterized constructor
    particle(std::string particle_type, double particle_mass, double particle_momentum) :
    type{particle_type}, mass{particle_mass}, momentum{particle_momentum}, energy{sqrt(mass*mass + momentum*momentum)} {}

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
    std::cout << "05_class5" << std::endl;

    std::vector<particle> particle_data;
    particle_data.push_back(particle{"electron", 5.11e5, 1.e6});
    particle_data.push_back(particle{"proton", 0.938e9, 3.e9});

    for (auto particle_it = particle_data.begin(); particle_it<particle_data.end(); ++particle_it) {
        particle_it->print_data();
        std::cout << "Has gamma = " << particle_it->gamma() << std::endl;
    }

    return 0;
}
