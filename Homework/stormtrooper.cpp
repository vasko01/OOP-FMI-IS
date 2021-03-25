#include "stormtrooper.hpp"
#include <cstring>

Stormtrooper::Stormtrooper()
{
    id = nullptr;
    rank = None;
    type = nullptr;
    this->planet = {};
}

Stormtrooper::Stormtrooper(const Stormtrooper& other)
{
    this->id = new char[strlen(other.id) + 1];
    strcpy(this->id, other.id);
    this->rank = other.rank;
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);
    this->planet = other.planet;
}

Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other)
{
    if(this != &other)
    {
        delete[] id;
        delete[] type;
        this->id = new char[strlen(other.id) + 1];
        strcpy(this->id, other.id);
        this->rank = other.rank;
        this->type = new char[strlen(other.type) + 1];
        strcpy(this->type, other.type);
        this->planet = other.planet;
    }

    return *this;
}

Stormtrooper::Stormtrooper(char* _id, Rank _rank, char* _type, Planet _planet)
{
    this->id = new char[strlen(_id) + 1];
    strcpy(this->id, _id);
    this->rank = _rank;
    this->type = new char[strlen(_type) + 1];
    strcpy(this->type, _type);
    planet = _planet;
}

Stormtrooper::~Stormtrooper()
{
    delete[] id;
    delete[] type;
}

void Stormtrooper::set_id(const char* _id)
{
    this->id = new char[strlen(_id) + 1];
    strcpy(this->id, _id);
}

void Stormtrooper::set_rank(const Rank _rank)
{
    this->rank = _rank;
}

void Stormtrooper::set_type(const char* _type)
{
    this->type = new char[strlen(_type) + 1];
    strcpy(this->type, _type);
}

void Stormtrooper::set_planet(const Planet _planet)
{
    this->planet = _planet;
}

char* Stormtrooper::get_id() const
{
    return id;
}

Rank Stormtrooper::get_rank() const
{
    return rank;
}

void Stormtrooper::print_rank(Rank _rank)
{
    switch(_rank)
    {
        case Cadet: std::cout << "Cadet"; break;
        case Private: std::cout << "Private"; break;
        case Corporal: std::cout << "Corporal"; break;
        case Sergeant: std::cout << "Sergeant"; break;
        case None: std::cout << "No rank"; break;
        default: std::cout << "Wrong rank set"; break;
    }
}

char* Stormtrooper::get_type() const
{
    return type;
}

Planet Stormtrooper::get_planet() const
{
    return planet;
}


ostream& operator<<(ostream &os, const Stormtrooper &stormtrooper)
{
    os << stormtrooper.id << std::endl;
    os << stormtrooper.enumToString(stormtrooper.rank) << std::endl;
    os << stormtrooper.type << std::endl;
    os << stormtrooper.planet.get_name() << std::endl;
    return os;
}

istream& operator>>(istream &is, Stormtrooper &stormtrooper)
{
    char buff[50];
    is >> buff;
    stormtrooper.set_id(buff);
    is >> buff;
    stormtrooper.set_rank(stringToEnum(buff));
    is >> buff;
    stormtrooper.set_type(buff);
    cin >> stormtrooper.planet;
    return is;
}

const char* Stormtrooper::enumToString(const Rank &r) const
{
    switch(r)
    {
        case Rank::Cadet : return "Cadet";
        case Rank::Private : return "Private";
        case Rank::Corporal : return "Corporal";
        case Rank::Sergeant : return "Sergeant";
        default : return "None";
    }
}

Rank stringToEnum (char *str)
{
    if(!strcmp(str,"Cadet")) return Rank::Cadet;
    if(!strcmp(str,"Private")) return Rank::Private;
    if(!strcmp(str,"Corporal")) return Rank::Corporal;
    if(!strcmp(str,"Sergeant")) return Rank::Sergeant;
    return Rank::None;
}