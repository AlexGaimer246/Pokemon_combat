//
// Created by alexc on 20/03/2022.
//

#include <vector>
#include "external_functions.h"
#include "pokemon.h"

/**
 * @brief Permite al editor del codigo crear un nuevo pokemon a su gusto
 */
void extra_funcions::nuevoPokemon(const pokemon &pkmn) {
    try{
        pokemon_database().addPokemon(pkmn);
    } catch (std::exception &error){
        cerr << "Error al crear el pokemon " << error.what() << endl;
    }
}
/**
 * @brief Permite al editor del codigo crear un nuevo pokemon a su gusto
 * @param pkmns Vector de pokemon que se quieren añadir
 */
void extra_funcions::nuevoPokemon(const std::vector<pokemon>& pkmns) {

    for(const auto & pkmn : pkmns){
        try{
            nuevoPokemon(pkmn);
        }  catch (std::exception &error){
            cerr << "Error al crear el pokemon " << error.what() << endl;
        }
    }
}
/**
 * @brief Permite al editor del codigo crear un nuevo movimiento a su gusto
 */
void nuevoMovimiento( const move_struct &move ){
    try{
        move_database().addMove( move );
    } catch (std::exception &error){
        cerr << "Error al aniadir el movimiento " << error.what() << endl;
    }
}
/**
 * @brief Permite al editor del codigo crear un nuevo movimiento a su gusto
 * @param moves Vector de movimientos que se quieren añadir
 */
void extra_funcions::nuevoMovimiento(const vector<move_struct>& moves) {

    for(const auto & move : moves){
        try{
            move_database().addMove( move );
        }  catch (std::exception &error){
            cerr << "Error al crear el pokemon " << error.what() << endl;
        }
    }
}



/**
 * @brief Dado el nombre de un pokemon, esta funcion buscara en la base de datos el pokemon de dicho nombre y retornara
 * el objeto de tipo pokemon que se corresponda de esa manera
 * @param name Nombre del pokemon a buscar
 * @return Objeto pokemon cuyo nombre coincida con el buscado
 */
pokemon extra_funcions::searchPokemon(const string &name){
    // Generamos un pokemon por defecto
    pokemon pkmn;
    // Generamos la database de pokemon
    pokemon_database pkmn_data;
    // Y el vector
    vector<pokemon> pkmn_data_vect = pkmn_data.getVector();
    // Tambien el tamaño de dicho vector
    int tam = pkmn_data.getTam();

    // Buscamos al pokemon
    bool encontrado = false;
    int i = 0;
    while(i < tam && !encontrado){
        if(pkmn_data_vect[i].getNombre() == name){
            encontrado = true;
            pkmn = pkmn_data_vect[i];
        }
        i++;
    }


    return pkmn;
}

// Tipos de los pokemon validos
// {"steel", "water", "bug", "dragon",
// "electric", "ghost", "fire", "fairy",
// "ice", "fight", "normal", "plant", "psychic",
// "rock", "dark", "dirt", "poison", "flying"};
// "null" ///< Se usa si el pokemon no tiene tipo

/**
 * @brief Base de datos por defecto de los pokemon
 * @post Crea la base de datos personalizada de pokemon y movimientos en un futuro
 * @note Primero incluye los movmientos y luego los pokemon porque si no no vas a poder usar un movimiento ya que aun no esta en la base
 * de datos hasta que no los hagas con nuevoMovimiento
 * @note Para crear un movimiento, crea un objeto del tipo move_struct (como en la definicion de la clase o como esta más abajo)
 * y lo añades a la base de datos, ya sea con el comando nuevoMovimiento y el objeto, o añadiendolo al propio vector ya creado
 * @note Para crear un pokemon, crea un objeto del tipo pokemon como está mas abajo y añadelo a la base de datos con el mismo
 * procedimiento que con los movimientos, ambos métodos se han hecho así a drede
 */
void extra_funcions::main() {

    // Base de datos por defecto de los momivientos de los pokemon

    move_struct Flamethrower ("flamethrower", "fire", 50, 10 ,"normal");
    move_struct Thunderbolt ("thunderbolt", "electric", 100, 7, "special");
    move_struct Quick_attack ("quick _attack", "normal", 60, 10, "normal");
    move_struct Ember ("ember", "fire", 40, 20, "special");
    move_struct Water_Gun ("water gun", "water", 40, 20, "special");
    move_struct Vine_Whip ("vine whip", "plant", 40, 20, "normal");

    // Añadimos los movimientos a las bases de datos

    std::vector<move_struct> moves = {Flamethrower, Thunderbolt, Quick_attack, Ember, Water_Gun, Vine_Whip};
    nuevoMovimiento( moves );

    // Base de datos por defecto de los pokemon
    // Creamos los pokemon
    pokemon Pikachu("pikachu", "electric", "null",
                    60, 40, 40, 120, 50, 80,
                    "thunderbolt", "quick _attack", "null", "null");

    pokemon Bulbasaur("bulbasaur", "plant", "null",
                      60, 60, 60, 60, 60, 60,
                      "vine whip", "null", "null", "null");

    pokemon Charmander("charmander", "fire", "null",
                       80, 60, 60, 60, 40, 30,
                       "flamethrower", "quick _attack", "ember", "null");

    pokemon Squartle("squartle", "water", "null",
                     80, 60, 60, 60, 40, 30,
                     "water gun", "null", "ember", "null");

    // Los añadimos a la base de datos
    std::vector<pokemon> pkmns = {Pikachu, Bulbasaur, Charmander, Squartle};
    nuevoPokemon( pkmns );

}

/**
 * @brief Genera un entrenador aleatorio con el número de pokemon deseados
 * @param nombre_entrenador Nombre del entrenador
 * @param numPokemon Numero de pokemon del entrenador
 * @return trainer_struct con un numero x de pokemon
 */
trainers_struct extra_funcions::GenerateRandomTrainer(const string &nombre_entrenador, int numPokemon) {

    if(numPokemon <= 0){
        throw invalid_argument("No se puede crear un entrenador sin pokemon");
    }

    // Creamos el entrenador por defecto
    trainers_struct entrenador;
    entrenador.setNombre( nombre_entrenador );
    pokemon_database pkmn_data; // Obtenemos la base de datos de los pokemon

    // Seleccionamos los pokemon
    int i = 0;
    int posPokemon;

    // Pokemon 1
    posPokemon = rand() % pkmn_data.getVector().size();
    entrenador.setPokemon1( pkmn_data.getVector()[posPokemon].getNombre() );
    // Pokemon 2
    if( numPokemon > 1 ){
        posPokemon = rand() % pkmn_data.getVector().size();
        entrenador.setPokemon2( pkmn_data.getVector()[posPokemon].getNombre() );
    }
    //Pokemon 3
    if( numPokemon > 2 ){
        posPokemon = rand() % pkmn_data.getVector().size();
        entrenador.setPokemon3( pkmn_data.getVector()[posPokemon].getNombre() );
    }
    // Pokemon 4
    if( numPokemon > 3 ){
        posPokemon = rand() % pkmn_data.getVector().size();
        entrenador.setPokemon4( pkmn_data.getVector()[posPokemon].getNombre() );
    }
    // Pokemon 5
    if( numPokemon > 4 ){
        posPokemon = rand() % pkmn_data.getVector().size();
        entrenador.setPokemon5( pkmn_data.getVector()[posPokemon].getNombre() );
    }
    // Pokemon 6
    if( numPokemon > 5 ){
        posPokemon = rand() % pkmn_data.getVector().size();
        entrenador.setPokemon6( pkmn_data.getVector()[posPokemon].getNombre() );
    }

    return entrenador;
}
