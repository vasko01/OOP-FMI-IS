#include "planet.hpp"

Planet::Planet()
{
    name = nullptr;
    planetSystem = nullptr;
    republic = nullptr;
}

Planet::Planet(const Planet& other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->planetSystem = new char[strlen(other.planetSystem) + 1];
    strcpy(this->planetSystem, other.planetSystem);
    this->republic = new char[strlen(other.republic) + 1];
    strcpy(this->republic, other.republic);
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
    }

    return *this;
}

Planet::Planet(char* _name, char* _planetSystem, char* _republic)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);
    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);
}

Planet::~Planet()
{
    delete[] name;
    delete[] planetSystem;
    delete[] republic;
}

void Planet::set_name(const char* _name)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Planet::set_planetSystem(const char* _planetSystem)
{
    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);
}

void Planet::set_republic(const char* _republic)
{
    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);
}

char* Planet::get_name() const
{
    return name;
}
char* Planet::get_planetSystem() const
{
    return planetSystem;
}
char* Planet::get_republic() const
{
    return republic;
}

void Planet::print() const
{
    std::cout << "The name of the planet is " << get_name() << "and it is part of the " << get_planetSystem() << " . The planet is occupied by " << get_republic() << "." << std::endl; 
}




