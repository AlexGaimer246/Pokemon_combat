//
// Created by alexc on 20/02/2022.
// This class has all the Pokemon created in this game
//

#ifndef POKEMON_POKEMON_DATABASE_H
#define POKEMON_POKEMON_DATABASE_H
#include "pokemon.h"
#include <vector>
#include "move_database.h"
#include "sstream"
#include "iostream"



class pokemon_database {
public:
    pokemon_database() {

    }
    ~pokemon_database() = default;

    int getTam() const;

    std::vector<pokemon> getVector() const; ///< Retorna el vector de pokemon

    static std::string addPokemon(const pokemon& pkmn); ///< Permite añadir un pokemon al vector

    void getStats(int pos) const;

    static std::vector<pokemon> _pokemon_data; ///< Vector donde se guardan todos los pokemon del juego

    pokemon_database& operator= (const pokemon_database &orig);

private:

    static bool bucle(const string &cosa_que_queremos_buscar, const std::vector<move_struct>& cosa_buscadora);

    static bool bucle(const string &cosa_a_buscar, const std::vector<string>& cosa_que_se_busca);

    // pokemon* _pokemon_data = nullptr; ///< El puntero al vector dinamico de pokemon

    int tam = -1;
};


#endif //POKEMON_POKEMON_DATABASE_H
