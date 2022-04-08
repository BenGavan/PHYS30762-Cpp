#include<iostream>
#include<cmath>

class particle {
public:
    std::string type;
    double mass;
    double momentum;
    double energy;
};

void print_data(const struct particle &p) {
    std::cout.precision(3);
    std::cout << "Particle: [type, m, p, E] = [" << p.type << ", " << p.mass << ", " << p.momentum << ", " << p.energy
              << "]" << std::endl;
}

double gamma(const struct particle &p) {
    return p.energy / p.mass;
}

int main() {
    std::cout << "02_class2" << std::endl;

    particle electron;
    electron.type = "electron";
    electron.mass = 5.11e5;
    electron.momentum = 1.e6;
    electron.energy = sqrt(electron.mass * electron.mass + electron.momentum * electron.momentum);

    particle proton;
    proton.type = "proton";
    proton.mass = 0.938e9;
    proton.momentum = 3.e9;
    proton.energy = sqrt(proton.mass * proton.mass + proton.momentum * proton.momentum);

    print_data(electron);
    print_data(proton);

    std::cout.precision(3);
    std::cout << "Particle 1 has Lorentz factor gamma = " << gamma(electron) << std::endl;
    std::cout << "Particle 2 has Lorentz factor gamma = " << gamma(proton) << std::endl;

    return 0;
}