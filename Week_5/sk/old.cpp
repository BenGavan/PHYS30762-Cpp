// g++ -std=c++11 -o assignment_3 assignment_3.cpp
// ./assignment_3
// Assignments/assignment_3.cpp
// Stuart Kirk, updated 09/03/2022
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<limits>
#include<algorithm>
#include<tuple>

class galaxy
{
private:
    std::string hubble_type{"Sb"};
    double redshift{0.0};
    double total_mass_in_solar_masses{1.2e12};
    double stellar_mass_fraction{0.04};
    std::vector<*galaxy> satellites{};

public:
    // Constructors
    galaxy() = default;
    galaxy(std::string galaxy_type, double galaxy_redshift, double galaxy_total_mass, double galaxy_stellar_mass_fraction, std::vector<galaxy> galaxy_satellites) :
            hubble_type{galaxy_type}, redshift{galaxy_redshift}, total_mass_in_solar_masses{galaxy_total_mass}, stellar_mass_fraction{galaxy_stellar_mass_fraction}, satellites{galaxy_satellites}
    {}

    // Destructor
    ~galaxy(){std::cout<<"Destroying galaxy"<<std::endl;}

    double stellar_mass_in_solar_masses()
    {
        return total_mass_in_solar_masses * stellar_mass_fraction;
    }

    void add_satellite(*galaxy input_satellite)
    {
        satellites.push_back(&input_satellite);
    }

    void change_hubble_type(std::string input_hubble_type)
    {
        hubble_type = input_hubble_type;
    }

    void print_galaxy_data();
    void print_full_galaxy_data_including_satellites();
};

void galaxy::print_galaxy_data() {
    std::cout.precision(3);
    std::cout<<"GALAXY DATA:"<<std::endl<<"Hubble type = "<<hubble_type<<std::endl
             <<"Redshift = "<<redshift<<std::endl<<"Total mass = "<<total_mass_in_solar_masses<<" solar masses"
             <<std::endl<<"Stellar mass fraction = "<<stellar_mass_fraction<<std::endl<<std::endl;
}

void galaxy::print_full_galaxy_data_including_satellites()
{
    std::vector<galaxy>::iterator vector_iterator;
    print_galaxy_data();
    if(!satellites.empty()) {
        std::cout<<"Satellites:"<<std::endl;
        for(vector_iterator=satellites.begin(); vector_iterator<satellites.end(); ++vector_iterator) {
            vector_iterator->print_galaxy_data();
        }
    }
}

int main()
{
    std::vector<*galaxy> galaxies;

    galaxy milky_way;
    galaxies.push_back(&milky_way);
    galaxy andromeda{"Sb", -0.001001, 1.5e12, 0.1, {}};
    galaxies.push_back(&andromeda);
    galaxy satellite1;
    andromeda.add_satellite(&satellite1);
    satellite1.change_hubble_type("E5");

    andromeda.print_full_galaxy_data_including_satellites();


    std::vector<galaxy>::iterator galaxy_iterator;
    for(galaxy_iterator=galaxies.begin(); galaxy_iterator<galaxies.end(); ++galaxy_iterator) {
        galaxy_iterator->print_full_galaxy_data_including_satellites();
    }

    std::cout<<"The stellar mass of the Milky Way is "<<milky_way.stellar_mass_in_solar_masses()<<" solar masses."<<std::endl;

    return 0;
}
