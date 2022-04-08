#include<iostream>
#include<string>
#include<vector>
#include<cmath>

enum Hubble_type
{
    E0 = 0, E1 = 1, E2 = 2, E3 = 4, E4 = 5, E5 = 5, E6 = 6, E7 = 7, S0 = 8,
    Sa = 9, Sb = 10, Sc = 11, SBa = 12, SBb = 13, SBc = 14, Irr = 15
};

class galaxy
{
private:
    Hubble_type hubble_type;
    double redshift;
    double total_mass;
    double stellar_mass_fraction;
    std::vector<galaxy> satellite_galaxies;

public:

    galaxy() = default;

    galaxy(Hubble_type hubble_type_in, double redshift_in, double total_mass_in,
           double stellar_mass_fraction_in) :
            hubble_type{hubble_type_in}, redshift{redshift_in},
            total_mass{total_mass_in}, stellar_mass_fraction{stellar_mass_fraction_in},
            satellite_galaxies{} {};

    ~galaxy() {}

    double stellar_mass() const { return stellar_mass_fraction * total_mass; }

    void change_type(Hubble_type new_type) { hubble_type = new_type; }

    void add_satellite_galaxy(galaxy g) { satellite_galaxies.push_back(g); }

    std::string get_hubble_type_as_string() const
    {
        const std::vector<std::string> hubble_strings{"E0", "E1", "E2", "E3", "E4",
                                                 "E5", "E6", "E7", "S0", "Sa",
                                                 "Sb", "Sc", "SBa", "SBb",
                                                 "SBc", "Irr"};
        return hubble_strings[hubble_type];
    }

    void print_data() const;
};

void galaxy::print_data() const
{
    // Print galaxy data
    std::cout << "Hubble Type: " << get_hubble_type_as_string() << std::endl;
    std::cout << "Redshift, z = " << redshift << std::endl;
    std::cout << "Total Mass, M_tot = " << total_mass << std::endl;
    std::cout << "Stellar Mass Fraction = " << stellar_mass_fraction << std::endl;
    std::cout << "Stellar Mass = " << stellar_mass() << std::endl;
    std::cout << "Number of satellite galaxies = " << satellite_galaxies.size() << std::endl;

    // Print satellite galaxies data
    for (auto iterator{satellite_galaxies.begin()};
    iterator != satellite_galaxies.end(); ++iterator) {
        std::cout << "\n- Satellite Galaxy:" << std::endl;
        iterator->print_data();
    }
}

void print_galaxies(const std::vector<galaxy> &galaxies)
{
    int galaxy_counter{0};
    for (auto iterator{galaxies.begin()}; iterator != galaxies.end(); ++iterator) {
        std::cout << "----------------------------" << std::endl;
        std::cout << "Galaxy " << galaxy_counter << std::endl;
        std::cout << "----------------------------" << std::endl;
        iterator->print_data();
        std::cout << "\n----- End of galaxy " << galaxy_counter << " ------\n" << std::endl;
        galaxy_counter++;
    }
}

int main()
{
    std::vector<galaxy> galaxies;

    galaxy galaxy1{Hubble_type::E0, 5, std::pow(10, 8), 0.03};
    galaxy galaxy2{Hubble_type::E1, 7, std::pow(10, 9), 0.04};
    galaxy galaxy3{Hubble_type::E2, 8, std::pow(10, 10), 0.05};

    const galaxy satellite1{Hubble_type::SBa, 8, std::pow(10, 10), 0.01};
    const galaxy satellite2{Hubble_type::SBb, 8.1, std::pow(10, 10.1), 0.011};
    const galaxy satellite3{Hubble_type::SBc, 8.2, std::pow(10, 10.2), 0.012};

    const galaxy satellite4{Hubble_type::SBa, 8.3, std::pow(10, 10.3), 0.013};

    galaxy1.change_type(Hubble_type::E7);

    galaxy3.change_type(Hubble_type::E6);

    galaxy1.add_satellite_galaxy(satellite1);
    galaxy1.add_satellite_galaxy(satellite2);
    galaxy1.add_satellite_galaxy(satellite3);

    galaxy2.add_satellite_galaxy(satellite4);

    galaxies.push_back(galaxy1);
    galaxies.push_back(galaxy2);
    galaxies.push_back(galaxy3);

    print_galaxies(galaxies);

    return 0;
}