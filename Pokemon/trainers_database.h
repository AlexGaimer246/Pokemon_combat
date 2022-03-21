//
// Created by alexc on 20/02/2022.
//

#ifndef POKEMON_TRAINERS_DATABASE_H
#define POKEMON_TRAINERS_DATABASE_H
#include <vector>
#include "trainers_struct.h"

class trainers_database {
public:
    trainers_database();
    ~trainers_database() = default;

    const std::vector<trainers_struct> &getTrainersData() const;



private:

    std::vector<trainers_struct> _trainers_data; ///< Vector donde se van a guardar todos los entrenadores

};


#endif //POKEMON_TRAINERS_DATABASE_H
