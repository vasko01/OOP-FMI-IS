#pragma once

#include <iostream>
#include <cstring>

#include "stormtrooper.hpp"
#include "jedi.hpp"

template<class Pilot>
class BattleShip
{
private:
    double speed;
    int gunsCount;
    bool hyperJump;
    double shipSize;
    Pilot pilot;

public:
    BattleShip();
    BattleShip(const BattleShip& other);
    BattleShip& operator=(const BattleShip& other);
    BattleShip(const double _speed, const int _gunsCount, const bool _hyperJump, const double _shipSize, const Pilot _pilot);
    BattleShip& operator=(const BattleShip& other);
    ~BattleShip();

    void set_speed(const double _speed);
    void set_gunsCount(const int _gunsCount);
    void set_hyperJump(const bool _hyperJump);
    void set_shipSize(const double _shipSize);
    void set_pilot(const Pilot _pilot);

    double get_speed() const;
    int get_gunsCount() const;
    bool get_hyperJump() const;
    double get_shipSize() const;
    Pilot get_pilot() const;

    friend std::ostream& operator<<(std::ostream os, const BattleShip& battleShip);
    friend std::istream& operator>>(std::istream is, BattleShip& battleShip);
};