//
// Created by alexc on 20/02/2022.
//

#ifndef POKEMON_POKEMON_H
#define POKEMON_POKEMON_H
#include <iostream>
using namespace std;

class pokemon {
public:

    pokemon() = default;

    pokemon(string nombre, string type1, string type2, int pv, int attack, int defense, int special_attack,
    int special_defese, int speed, string move1, string move2, string move3, string move4);

    ~pokemon() = default;

    // Getters for every parameter

    const string &getNombre() const;

    const string &getType1() const;

    const string &getType2() const;

    double getPv() const;

    int getAttack() const;

    int getDefense() const;

    int getSpecialAttack() const;

    int getSpecialDefese() const;

    int getSpeed() const;

    const string &getMove1() const;

    const string &getMove2() const;

    const string &getMove3() const;

    const string &getMove4() const;

    void setPv(double pv);

    double _pv = -1;

    pokemon& operator= (const pokemon &orig);

private:
    string _nombre = "null";
    string _type1 = "null";
    string _type2 = "null";

    // double _pv = -1;
    int _attack = -1;
    int _defense = -1;
    int _special_attack = -1;
    int _special_defese = -1;
    int _speed = -1;
    // MoveSet
    string _move1 = "null";
    string _move2 = "null";
    string _move3 = "null";
    string _move4 = "null";
};


#endif //POKEMON_POKEMON_H
