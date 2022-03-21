//
// Created by alexc on 20/02/2022.
//

#include "move_database.h"
#include "move_struct.h"

std::vector<move_struct> move_database::_move_data;

/**
* @brief Object constructor
*/
move_database::move_database() {
}

/**
 * @brief Proporciona el tamaño actual del vector que guarda todos los movmientos
 * @return Tamaño de _move_data
 */
int move_database::getMoveDataTam() const {
    return _move_data.size();
}

/**
 * @brief Retorna la referencia al vector _move_data
 * @return _move_data
 */
std::vector<move_struct> move_database::getMoveData() const {
    return this->_move_data;
}


/**
 * @brief Funcion auxiliar de addPokemon
 * @param cosa_a_buscar String que se quiere ver si esta en el vector
 * @param cosa_que_se_busca Parametro que se busca en el vector
 */
bool move_database::bucle(const std::string &cosa_a_buscar, const std::vector<std::string>& cosa_que_se_busca){
    int i = 0;
    bool encontrado = false;
    while( i < cosa_que_se_busca.size() && !encontrado ){

        if( cosa_a_buscar == cosa_que_se_busca[i] ){
            encontrado = true;
        }
        i++;
    }
    return encontrado;
}
/**
 * @brief Permite al programador añadir un movimiento desde cuaquier parte del codigo
 * @param move Movimiento a añadir
 * @return String indicando que el movimiento ha sido añadido de forma adecuada
 */
std::string move_database::addMove(const move_struct &move) {

    if(move.getNombre().empty()) {
        throw std::invalid_argument("El movimiento tiene que tener nombre");
    }

    // Miramos si el tipo del movimiento es valido

    std::vector<std::string> types = {"steel", "water", "bug", "dragon",
                                 "electric", "ghost", "fire", "fairy",
                                 "ice", "fight", "normal", "plant", "psychic",
                                 "rock", "dark", "dirt", "poison", "flying"};

    if(!bucle(move.getMoveType(), types)){
        throw std::invalid_argument("El movimiento " + move.getNombre() + " tiene que tener un tipo valido");
    }
    if(move.getTypeOfDamage() != "normal" && move.getTypeOfDamage() != "special"){
        throw std::invalid_argument("El movimiento " + move.getNombre() + " no tiene un tipo de movimiento valido");
    }
    if(move.getPp() < 0){
        throw std::invalid_argument("El movimiento " + move.getNombre() + " tiene un pp base negativo");
    }
    if(move.getDamage() < 0){
        throw std::invalid_argument("El movimiento " + move.getNombre() + " tiene un danio negativo");
    }

    _move_data.push_back(move);

    return "Movimiento agregado de forma exitosa";
}
