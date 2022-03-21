//
// Created by alexc on 20/02/2022.
//

#include "move_struct.h"

move_struct::move_struct(std::string nombre, std::string move_type, int damage, int pp, std::string type_of_damage):
    nombre(nombre), move_type(move_type), damage(damage), pp(pp), type_of_damage(type_of_damage)
{}

const std::string &move_struct::getNombre() const {
    return nombre;
}

const std::string &move_struct::getMoveType() const {
    return move_type;
}

int move_struct::getDamage() const {
    return damage;
}

int move_struct::getPp() const {
    return pp;
}

const std::string &move_struct::getTypeOfDamage() const {
    return type_of_damage;
}

move_struct& move_struct::operator=(const move_struct &oig)  = default;
