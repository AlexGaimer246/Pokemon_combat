//
// Created by alexc on 20/02/2022.
//

#include "trainers_struct.h"

trainers_struct &trainers_struct::operator=(const trainers_struct &orig) {

    _nombre = orig._nombre;
    _pokemon1 = orig._pokemon1;
    _pokemon2= orig._pokemon2;
    _pokemon3= orig._pokemon3;
    _pokemon4= orig._pokemon4;
    _pokemon5= orig._pokemon5;
    _pokemon6= orig._pokemon6;

    return (*this);
}
