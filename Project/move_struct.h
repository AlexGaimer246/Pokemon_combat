//
// Created by alexc on 20/02/2022.
//

#ifndef POKEMON_MOVE_STRUCT_H
#define POKEMON_MOVE_STRUCT_H
#include <iostream>

class move_struct {

public:
    move_struct() = default;
    move_struct(std::string nombre, std::string move_type, int damage, int pp, std::string type_of_damage);
    ~move_struct() = default;

    const std::string &getNombre() const;

    const std::string &getMoveType() const;

    int getDamage() const;

    int getPp() const;

    const std::string &getTypeOfDamage() const;

    move_struct& operator=(const move_struct &orig);

private:
    std::string nombre = "null"; ///< Nombre del movimiento
    std::string move_type = "null"; ///< Tipo elemental del movimiento
    int damage = -1; ///< El daño que hace el movimiento
    int pp = -1; ///< Los puntos de poder del movimiento
    std::string type_of_damage = "null"; ///< El tipo de daño que es, "normal" para ser daño fisico y "special" para ser un ataque especial
};


#endif //POKEMON_MOVE_STRUCT_H
