//
// Created by alexc on 20/03/2022.
//

#ifndef POKEMON_EXTERNAL_FUNCTIONS_H
#define POKEMON_EXTERNAL_FUNCTIONS_H

#include "pokemon.h"
#include "pokemon_database.h"
#include "trainers_struct.h"
#include "iostream"


namespace extra_funcions {

    void nuevoPokemon(const pokemon &pkmn );
    void nuevoPokemon(const std::vector<pokemon>& pkmns);

    void nuevoMovimiento( const move_struct &move );
    void nuevoMovimiento(const vector<move_struct>& moves);

    pokemon searchPokemon(const string &name);

    trainers_struct GenerateRandomTrainer(const string &nombre_entrenador, int numPokemon);

    void main();
}




#endif //POKEMON_EXTERNAL_FUNCTIONS_H
