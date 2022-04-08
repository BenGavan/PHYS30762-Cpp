#include<vector>
#include<iostream>
#include<cmath>
#include<string>

class galaxy
{
private:
    std::string hubble_type;  // TODO: Change to enum
    double redshift;
    double total_mass;
    double stellar_mass_fraction;
    std::vector<galaxy*> satellite_galaxies; // TODO: pointer or reference?

public:
    galaxy(): hubble_type{}, redshift{}, total_mass{}, stellar_mass_fraction{},
              satellite_galaxies{} {};

    galaxy(std::string hubble_type_in, double redshift_in, double total_mass_in,
           double stellar_mass_fraction_in):
            hubble_type{hubble_type_in}, redshift{redshift_in},
            total_mass{total_mass_in}, stellar_mass_fraction{stellar_mass_fraction_in},
            satellite_galaxies{} {};

    ~galaxy() {}

    double stellar_mass() { return stellar_mass_fraction * total_mass; }

    void change_type(std::string new_type) { hubble_type = new_type; }

    void add_satellite_galaxy(galaxy* g) { satellite_galaxies.push_back(g); }

    void print_data();
};

int main() {

    std::vector<galaxy> galaxies;

    std::vector<galaxy*> galaxy_pts;

    galaxy galaxy1{"E0", 5, std::pow(10, 8), 0.03 };

    galaxy_pts.push_back(&galaxy1);

    std::cout << galaxy_pts.size() << std::endl;


    return 0;
}