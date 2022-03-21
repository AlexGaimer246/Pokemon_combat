/**
 * @author Alejandro
 * @github AlexGaimer246
 * @date 20/02/2022
 * @version 0.1
 */


#include <iostream>
#include <vector>
#include <cstdlib>

#include "pokemon_database.h"
#include "move_database.h"
#include "trainers_database.h"
#include "trainers_struct.h"
#include "pokemon.h"
#include "move_struct.h"
#include "pokemon_battle.h"
#include "external_functions.h"

using namespace std;


int main() {

    try {

        /**
         * @brief Creamos la base de datos por defecto
         * @note Si quieres crear tu propio pokemon o movimiento, lo recomendable es hacerlo desde este metodo en el fichero "external_functions.cpp"
         * aunque tambien lo puedes hacer desde aqui de la siguiente forma:
         *  * @note Primero incluye los movmientos y luego los pokemon porque si no no vas a poder usar un movimiento ya que aun no esta en la base
         * de datos hasta que no los hagas con extra_funtions::nuevoMovimiento
         * @note Para crear un movimiento, crea un objeto del tipo move_struct (como en la definicion de la clase o como esta más abajo)
         * y lo añades a la base de datos, ya sea con el comando extra_funtions::nuevoMovimiento y el objeto, o añadiendolo al propio vector ya creado
         * @note Para crear un pokemon, crea un objeto del tipo pokemon como está mas abajo y añadelo a la base de datos con el mismo
         * procedimiento que con los movimientos, usando la funcion extra_funtions::nuevoPokemon, ambos métodos se han hecho así a drede
         * @note más informacion en: extra_funcions::main
         */
        extra_funcions::main(); ///< Esta linea de codigo crea la base de datos por defecto

        // Creamos al jugador propio jugador
        trainers_struct player("Alejandro", "pikachu", "charmander", "null", "null", "null", "null");
        // Creamos al entrenador enemigo
        // trainers_struct enemy("Ash", "pikachu", "charmander", /"squartle", "null", "null", "null");

        // Tambien podemos crear un entrenador aleatorio usando: extra_funcions::GenerateRandomTrainer
        trainers_struct enemy = extra_funcions::GenerateRandomTrainer("Ash", 6);

        // Y a un pokemon salvaje
        // ¡Atencion! ver la documentacion en deoxigen sobre la funcion extra_funcions::searchPokemon ya que es muy importante
        pokemon wildPokemon = extra_funcions::searchPokemon("bulbasaur");
        // Seleccionamos la dificultad del combate
        // Para ver las dificultades disponibles, mira la documentation de los atributos de la clase pokemon_battle.h
        string difficulty = "easy";

        // Creamos la batalla, la clase pokemon_battle se encarga del resto
        // Puede ser tanto contra un pokemon salvaje (objeto de tipo pokemon) o contra un entrenador (objeto de tipo trainer_struct)
        // Mira la documentacio de la clase pokemon_battle para más informacio
        pokemon_battle batalla(player, wildPokemon, difficulty);

    } catch (exception &error){
        cerr << "Ha sucedido un error " << error.what() << endl;
    }

    return 0;
}
