#include "jedi.hpp"

Jedi::Jedi()
{
    this->name = nullptr;
    this->rank = None;
    this->midiChlorian = 0;
    this->planet = {};
    this->spicies = nullptr;
    this->militaryRank = nullptr;
}

Jedi::Jedi(const Jedi& other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->rank = other.rank;
    this->midiChlorian = other.midiChlorian;
    this->planet = other.planet;
    this->spicies = new char[strlen(other.spicies) + 1];
    strcpy(this->spicies, other.spicies);
    this->militaryRank = new char[strlen(other.militaryRank) + 1];
    strcpy(this->militaryRank, other.militaryRank);
}

Jedi& Jedi::operator=(const Jedi& other)
{
    if(this != &other)
    {
        delete[] name;
        delete[] spicies;
        delete[] militaryRank;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->rank = other.rank;
        this->midiChlorian = other.midiChlorian;
        this->planet = other.planet;
        this->spicies = new char[strlen(other.spicies) + 1];
        strcpy(this->spicies, other.spicies);
        this->militaryRank = new char[strlen(other.militaryRank) + 1];
        strcpy(this->militaryRank, other.militaryRank);
    }

    return *this;
}

Jedi::Jedi(char* _name, JediRank _rank, double _midiChlorian, Planet _planet, char* _spicies, char* _militaryRank)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
    this->rank = _rank;
    this->midiChlorian = _midiChlorian;
    this->planet = _planet;
    this->spicies = new char[strlen(_spicies) + 1];
    strcpy(this->spicies, _spicies);
    this->militaryRank = new char[strlen(_militaryRank) + 1];
    strcpy(this->militaryRank, _militaryRank);
}

Jedi::~Jedi()
{
    delete[] name;
    delete[] spicies;
    delete[] militaryRank;
}


void Jedi::set_name(const char* _name)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}   

void Jedi::set_rank(const JediRank _rank)
{
    this->rank = _rank;
}

void Jedi::set_midiChlorian(const double _midiChlorian)
{
    this->midiChlorian = _midiChlorian;
}

void Jedi::set_planet(const Planet _planet)
{
    this->planet = _planet;
}

void Jedi::set_spicies(const char* _spicies)
{
    this->spicies = new char[strlen(_spicies) + 1];
    strcpy(this->spicies, _spicies);
}

void Jedi::set_militaryRank(const char* _militaryRank)
{
    this->militaryRank = new char[strlen(_militaryRank) + 1];
    strcpy(this->militaryRank, _militaryRank);
}


char* Jedi::get_name() const
{
    return name;
}

JediRank Jedi::get_rank() const
{
    return rank;
}


double Jedi::get_midiChlorian() const
{
    return midiChlorian;
}

Planet Jedi::get_planet() const
{
    return planet;
}

char* Jedi::get_spicies() const
{
    return spicies;
}

char* Jedi::get_militaryRank() const
{
    return militaryRank;
}

ostream& operator<<(ostream &os, const Jedi &jedi)
{
    os << jedi.name << std::endl;
    os << jedi.enumToString(jedi.rank) << std::endl;
    os << jedi.midiChlorian << std::endl;
    os << jedi.planet.get_name() << std::endl;
    os << jedi.spicies << std::endl;
    os << jedi.militaryRank << std:: endl;
    return os;
}

istream& operator>>(istream &is, Jedi &jedi)
{
    char buff[50];
    is >> buff;
    jedi.set_name(buff);
    is >> buff;
    jedi.set_rank(stringToEnum(buff));
    double _midiChlorian;
    is >> _midiChlorian;
    jedi.set_midiChlorian(_midiChlorian);
    is >> jedi.planet;
    is >> buff;
    jedi.set_spicies(buff);
    is >> buff;
    jedi.set_militaryRank(buff);
    
    return is;
}

const char* Jedi::enumToString(const JediRank &r) const
{
    switch(r)
    {
        case JediRank::Guardian : return "Guardian";
        case JediRank::Consular : return "Consular";
        case JediRank::Sentinel : return "Sentinel";
        default : return "None";
    }
}

JediRank stringToEnum(char* str)
{
    if(!strcmp(str,"Guardian")) return JediRank::Guardian;
    if(!strcmp(str,"Consular")) return JediRank::Consular;
    if(!strcmp(str,"Sentinel")) return JediRank::Sentinel;
    return JediRank::None;
}

