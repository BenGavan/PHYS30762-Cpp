#include<iostream>
#include<cmath>

class particle {
public:
    std::string type;
    double mass;
    double momentum;
    double energy;

    void set_type(const std::string &ptype) {
        type = ptype;
    }

    void print_type() {
        std::cout << "Particle is of type " << type << std::endl;
    }
};

void print_data(const struct particle &p) {
    std::cout.precision(3); // 2 significant figures
    std::cout << "Particle: [type,m,p,E] = [" << p.type << "," << p.mass
              << "," << p.momentum << "," << p.energy << "]" << std::endl;
}

double gamma(const struct particle &p) {
    return p.energy / p.mass;
}

int main() {
    std::cout << "04_class3" << std::endl;

    particle electron;
    electron.set_type("electron");
    electron.mass = 5.11e5;
    electron.momentum = 1.e6;
    electron.energy = sqrt(electron.mass * electron.mass + electron.momentum * electron.momentum);

    particle proton;
    proton.set_type("proton");
    proton.mass = 0.938e9;
    proton.momentum = 3.e9;
    proton.energy = sqrt(proton.mass * proton.mass + proton.momentum * proton.momentum);

    print_data(electron);
    print_data(proton);

    std::cout.precision(3);
    electron.print_type();
    std::cout << "Particle 1 has Lorentz factor gamma = " << gamma(electron) << std::endl;
    proton.print_type();
    std::cout << "Particle 2 has Lorentz factor gamma = " << gamma(proton) << std::endl;

    return 0;
}
