#include "planet.hpp"

Planet::Planet()
{
    this->name = nullptr;
    this->planetSystem = nullptr;
    this->republic = nullptr;
    this->typeOfPlanet = None;
}

Planet::Planet(const Planet& other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->planetSystem = new char[strlen(other.planetSystem) + 1];
    strcpy(this->planetSystem, other.planetSystem);
    this->republic = new char[strlen(other.republic) + 1];
    strcpy(this->republic, other.republic);
    this->typeOfPlanet = other.typeOfPlanet;
}

Planet& Planet::operator=(const Planet& other)
{
    if(this != &other)
    {
        delete[] name;
        delete[] planetSystem;
        delete[] republic;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->planetSystem = new char[strlen(other.planetSystem) + 1];
        strcpy(this->planetSystem, other.planetSystem);
        this->republic = new char[strlen(other.republic) + 1];
        strcpy(this->republic, other.republic);
        this->typeOfPlanet = other.typeOfPlanet;
    }

    return *this;
}

Planet::Planet(char* _name, char* _planetSystem, char* _republic, PlanetType _typeOfPlanet)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);
    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);
    this->typeOfPlanet = _typeOfPlanet;
}

Planet::~Planet()
{
    delete[] name;
    delete[] planetSystem;
    delete[] republic;
}

void Planet::set_name(const char* _name)
{
    delete[] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Planet::set_planetSystem(const char* _planetSystem)
{
    delete[] this->planetSystem;
    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);
}

void Planet::set_republic(const char* _republic)
{
    delete[] this->republic;
    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);
}

void Planet::set_typeOfPlanet(const PlanetType _typeOfPlanet)
{
    this->typeOfPlanet = _typeOfPlanet;
}


char* Planet::get_name() const
{
    return this->name;
}
char* Planet::get_planetSystem() const
{
    return this->planetSystem;
}
char* Planet::get_republic() const
{
    return this->republic;
}
PlanetType Planet::get_typeOfPlanet () const
{
    return this->typeOfPlanet;
}

const char* Planet::enumToString(const PlanetType &r) const
{
    switch (r)
    {
        case PlanetType::Chthonian : return "Chthonian";
        case PlanetType::Carbon : return "Carbon";
        case PlanetType::Coreless : return "Coreless";
        case PlanetType::Desert : return "Desert";
        case PlanetType::Gas : return "Gas";
        case PlanetType::Helium : return "Helium";
        case PlanetType::Ice : return "Ice";
        case PlanetType::Iron : return "Iron";
        case PlanetType::Lava : return "Lava";
        case PlanetType::Ocean : return "Ocean";
        case PlanetType::Proto : return "Proto";
        case PlanetType::Puffy : return "Puffy";
        case PlanetType::Silicate : return "Silicate";
        case PlanetType::Terrestrial : return "Terrestrial";
        default : return "Unknown";
    }
}



ostream& operator<<(ostream &os, const Planet &planet)
{
    os << planet.name << std::endl;
    os << planet.planetSystem << std::endl;
    os << planet.republic << std::endl;
    os << planet.enumToString(planet.typeOfPlanet) << std::endl;
    return os;
}

istream& operator>>(istream &is, Planet &planet)
{
    char buff[50];
    is >> buff;
    planet.set_name(buff);
    is >> buff;
    planet.set_planetSystem(buff);
    is >> buff;
    planet.set_republic(buff);
    is >> buff;
    planet.set_typeOfPlanet(stringToEnum(buff));
    return is;
}

PlanetType stringToEnum(char* str)
{
    if (!strcmp(str,"Chthonian")) return PlanetType::Chthonian;
    if (!strcmp(str,"Carbon")) return PlanetType::Carbon;
    if (!strcmp(str,"Coreless")) return PlanetType::Coreless;
    if (!strcmp(str,"Desert")) return PlanetType::Desert;
    if (!strcmp(str,"Gas")) return PlanetType::Gas;
    if (!strcmp(str,"Helium")) return PlanetType::Helium;
    if (!strcmp(str,"Ice")) return PlanetType::Ice;
    if (!strcmp(str,"Iron")) return PlanetType::Iron;
    if (!strcmp(str,"Lava")) return PlanetType::Lava;
    if (!strcmp(str,"Ocean")) return PlanetType::Ocean;
    if (!strcmp(str,"Proto")) return PlanetType::Proto;
    if (!strcmp(str,"Puffy")) return PlanetType::Puffy;
    if (!strcmp(str,"Silicate")) return PlanetType::Silicate;
    if (!strcmp(str,"Terrestrial")) return PlanetType::Terrestrial;
    return PlanetType::None;
}




