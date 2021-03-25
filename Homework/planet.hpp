#include <iostream>
#include <cstring>

using namespace std;

enum PlanetType
{
    Chthonian,
    Carbon,
    Coreless,
    Desert,
    Gas,
    Helium,
    Ice,
    Iron,
    Lava,
    Ocean,
    Proto,
    Puffy,
    Silicate,
    Terrestrial,
    None
};


class Planet
{
private:
    char* name;
    char* planetSystem;
    char* republic;
    PlanetType typeOfPlanet;

public:
    Planet();
    Planet(const Planet& other);
    Planet& operator=(const Planet& other);
    Planet(char* _name, char* _planetSystem, char* _republic, PlanetType _typeOfPlanet);
    ~Planet();

    void set_name(const char* _name);
    void set_planetSystem(const char* _planetSystem);
    void set_republic(const char* _republic);
    void set_typeOfPlanet(const PlanetType _typeOfPlanet);


    char* get_name() const;
    char* get_planetSystem() const;
    char* get_republic() const;
    PlanetType get_typeOfPlanet () const;

    const char* enumToString(const PlanetType &r) const;



    friend ostream& operator<<(ostream &os, const Planet &planet);
    friend istream& operator>>(istream &is, Planet &planet);


};

PlanetType stringToEnum(char* str);

template<class P>
void print(P toPrint)
{
    cout << toPrint << endl;
}

template<class I>
void read(I &toRead)
{
    cin >> toRead;
}

