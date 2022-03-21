//
// Created by alexc on 20/02/2022.
//

#include "pokemon.h"

/**
 * @brief Class constructor
 * @param nombre El _nombre del pokemon
 * @param type1 El primer tipo del pokemon
 * @param type2 EL segundo tipo del pokemon
 * @param pv La caracteristica puntos de vida del pokemon
 * @param attack La caracteristica ataque físico del pokemon
 * @param defense La defensa fisica del pokemon
 * @param special_attack El ataque especial del pokemon
 * @param sepecial_defese La defensa especial del pokemon
 * @param speed La velocidad del pokemon
 * @param move1 El primer movimiento del pokemeon
 * @param move2 El segundo movimiento del pokemon
 * @param move3 El tercer movimiento del pokemon
 * @param move4 El cuarto movimiento del pokemon
 * @post Crea un pokemon con todas las caracteristicas de uno inciadas a los valores dados en los parametros
 */
pokemon::pokemon(string nombre, string type1, string type2, int pv, int attack, int defense, int special_attack,
                 int special_defese, int speed, string move1, string move2, string move3, string move4):
        _nombre(nombre), _type1(type1), _type2(type2), _pv(pv), _attack(attack), _defense(defense), _special_attack(special_attack),
        _special_defese(special_defese), _speed(speed), _move1(move1), _move2(move2), _move3(move3), _move4(move4){
}

/**
 * @brief All the getter methods for every single object parameter
*/

const string &pokemon::getNombre() const {
    return _nombre;
}

const string &pokemon::getType1() const {
    return _type1;
}

const string &pokemon::getType2() const {
    return _type2;
}

double pokemon::getPv() const {
    return _pv;
}

int pokemon::getAttack() const {
    return _attack;
}

int pokemon::getDefense() const {
    return _defense;
}

int pokemon::getSpecialAttack() const {
    return _special_attack;
}

int pokemon::getSpecialDefese() const {
    return _special_defese;
}

int pokemon::getSpeed() const {
    return _speed;
}

const string &pokemon::getMove1() const {
    return _move1;
}

const string &pokemon::getMove2() const {
    return _move2;
}

const string &pokemon::getMove3() const {
    return _move3;
}

const string &pokemon::getMove4() const {
    return _move4;
}

void pokemon::setPv(double pv) {
    pokemon::_pv = pv;
}

/**
 * @brief Operador =
 * @param orig
 * @return
 */
pokemon &pokemon::operator=(const pokemon &orig) {

    _nombre = orig._nombre;
    _type1 = orig._type1;
    _type2 = orig._type2;

    _move1 = orig._move1;
    _move2 = orig._move2;
    _move3 = orig._move3;
    _move4 = orig._move4;

    _pv = orig._pv;
    _attack = orig._attack;
    _defense = orig._defense;
    _special_attack = orig._special_attack;
    _special_defese = orig._special_defese;
    _speed = orig._speed;

    return (*this);
}
