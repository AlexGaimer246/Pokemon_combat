//
// Created by alexc on 24/02/2022.
//

#ifndef POKEMON_POKEMON_BATTLE_H
#define POKEMON_POKEMON_BATTLE_H

#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>

#include "pokemon_database.h"
#include "move_database.h"
#include "trainers_database.h"
#include "trainers_struct.h"
#include "pokemon.h"
#include "move_struct.h"

using namespace std;

class pokemon_battle{

public:

    pokemon_battle(trainers_struct &player, trainers_struct &rival, string &difficulty); ///< Constructor que se llama
    ///< cuando trata de realizarse un batalla entre dos entrenadores

    pokemon_battle(trainers_struct &player, pokemon &wild_pokemon, string &difficulty); ///< Constructor que se llama cuando
    ///< se realiza una batalla entre el jugador y un pokemon salvaje

private:

    void estadoBatalla();

    bool comprobarBatalla(bool &victoria) const;

    int calculaIndice(string vect[], const string &tipo_a_buscar);

    double calculateDamage(move_struct &move, pokemon &pkmn_user, pokemon &pkmn_enemy);

    void pausa();

    pokemon searchPokemon(const string &name);

    move_struct searchMove(const string &mov);

    bool printMove(move_struct &mov);

    int mostrarPokemon(const pokemon &pkmn, const bool tieneCout);

    bool printMove(move_struct &mov, int &indice, const bool tieneCout);

    int cambioPokemon();

    double atacar();

    void curarPokemon();

    void combat_controller();

    double enemyAI(); ///< La inteligencia artificial del enemigo, sea entrenador o pokemon salvaje

    trainers_struct _player; ///< Atributo donde se guarda la estructura de entrenador del propio jugador
    trainers_struct _enemy; ///< Atributo donde se guarda la estructura de entrenador del entrenador enemigo

    vector<pokemon> _playerTeam; ///< Vector donde se guarda el equipo pokemon del jugador
    //pokemon *_playerTeam = nullptr; ///< Vector donde se guarda el equipo pokemon del jugador
    int _pokemonActual = 0; ///< Indice que guarda la posicion del pokemon que el jugador esta usando

    vector<pokemon> _enemyTeam; ///< Vector donde se guarda el equipo pokemon del rival
    // pokemon *_enemyTeam = nullptr; ///< Vector donde se guarda el equipo pokemon del rival
    int _pokemonEnemyActual = 0; ///< Indice que guarda la posicion del pokemon que el otro entrenador esta usando en ese momento

    pokemon _wildPokemon; ///< En caso de ser una batalla contra un pokemon salvaje, dicho pokemon se guarda en este atributo

    int _numPociones = 5; ///< Numero de pociones con las que cuenta el entrenador

    string _mode; ///< Este atributo sirve para marcar el modo en el que se esta realizando la batalla \
                  ///< [trainer] Si es una batalla entre entrenadores, [wild] si es una batalla contra un pokemon salvaje

    string _difficulty; ///< Este atributo se usa para seleccionar la dificultad de la IA enemiga. Modos: \n
                        ///< @note Por ahora solo esta implementada la dificultad easy
                        ///< [easy]: Los movimientos elegidos son aleatorios y si es un entrenador, no cambia sus pokemon \n
                        ///< [medium]: Los movimientos elegidos son el que más daño hacen y el entrenador cura su pokemon un 50% de las veces si su vida es inferior a un 40% \n
                        ///< [hard]: Igual con los movimientos, pero si es un entrenador, este cambia sus pokemon por el que tenga ventaja de tipos un 40% de las veces que el jugador cambia su pokemon \n
                        ///< [hell]: El entrenador cambia y cura siempre, nunca podrás tener ventaja de tipo si es posible


};

#endif //POKEMON_POKEMON_BATTLE_H
