//
// Created by alexc on 20/02/2022.
//

#include "trainers_database.h"
#include "trainers_struct.h"

trainers_database::trainers_database() {
    trainers_struct Ash("Ash", "pikachu", "charmander", "squartle", "bulbasaur", "null", "null");
    trainers_struct Gary("Gary", "squartle", "null", "null", "null", "null", "null");

    this->_trainers_data = {Ash, Gary};
}

const std::vector<trainers_struct> &trainers_database::getTrainersData() const {
    return _trainers_data;
}
