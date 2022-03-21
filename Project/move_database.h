//
// Created by alexc on 20/02/2022.
//

#ifndef POKEMON_MOVE_DATABASE_H
#define POKEMON_MOVE_DATABASE_H
#include <vector>
#include <array>
#include <iostream>
#include "move_struct.h"


class move_database {
public:

    move_database();

    int getMoveDataTam() const;

    std::string addMove(const move_struct& move); ///< Permite añadir un pokemon al vector

    std::vector<move_struct> getMoveData() const;

    move_database& operator=(const move_database &orig) = default;

private:

    static bool bucle(const std::string &cosa_a_buscar, const std::vector<std::string>& cosa_que_se_busca);

    static std::vector<move_struct> _move_data;
};


#endif //POKEMON_MOVE_DATABASE_H
