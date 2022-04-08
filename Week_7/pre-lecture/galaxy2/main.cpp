#include<iostream>
#include<string>

class celestial_object
{
protected:
    std::string name;
    double mass, distance, luminosity;
public:
    celestial_object() : name{"no-name"}, mass{}, distance{}, luminosity{} {}
    celestial_object(const std::string nm, const double l, const double m, const double d) :
        name{nm}, distance{d}, mass{m}, luminosity{l} {}
    ~celestial_object() {}
    std::string get_name() { return name; };
    friend std::ostream& operator<<(std::ostream&, const celestial_object&);
};

class galaxy: public celestial_object
{
private:
    std::string hubble_type;
public:
    galaxy(): celestial_object{}, hubble_type{"Sc"} {}
    galaxy(const std::string nm, const double l, const double m, const double d,
           const std::string ht) : celestial_object(nm, l, m, d) {}
    ~galaxy() {}
    friend std::ostream& operator<<(std::ostream&, const galaxy&);
};

//std::ostream& operator<<(std::ostream& o, const galaxy& gx)
//{
//    o << " galaxy " << gx.get_name() << "";
//}

std::ostream& operator<<(std::ostream& o, const galaxy& gx)
{
    o <<" galaxy "<< gx.get_name() <<": "<<std::endl <<" Hubble type "<<gx.hubble_type<<std::endl;
    return o;
}

int main() {
    std::cout << "Week 7 - prelecture -  galaxy 2" << std::endl;



    return 0;
}