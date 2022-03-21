//
// Created by alexc on 20/02/2022.
//

#include "pokemon_database.h"
#include "pokemon.h"

std::vector<pokemon> pokemon_database::_pokemon_data;

/**
 * @brief Retorna el tamaño del vector creado
 * @return Tamaño del vector
 */
int pokemon_database::getTam() const {

    return _pokemon_data.size();
}
/**
 * @brief Retorna una referencia a la posicion de memoria donde se localiza el vector donde se encuentran
 * todosp los pokemon
 * @return posicion de memoria
 */
std::vector<pokemon> pokemon_database::getVector() const {
    return this->_pokemon_data;
}

/**
 * @brief Muestra por pantalla todas las estadisticas del pokemon dicho
 * @param [in] pos La posicion en donde se ecuentra el pokemon dentro del vector
 */
void pokemon_database::getStats(const int pos) const {

    // Comprobamos que es una poscion válida
    if(pos < 0 || pos > this->_pokemon_data.size()){
        throw string ("Posicion no valida");
    }
    // Mostramos _nombre y tipos
    cout << "Name: " << this->_pokemon_data[pos].getNombre() << endl;
    cout << "Type 1: " << this->_pokemon_data[pos].getType1() << endl;

    // Si no es doble tipo, no mostramos el segundo tipo
    if(this->_pokemon_data[pos].getType2() != "null"){
        cout << "Type 2: " << this->_pokemon_data[pos].getType2() << endl;
    }
    // Mostramos las estadisticas
    cout << "Live Points: " << this->_pokemon_data[pos].getPv() << endl;
    cout << "Attack: " << this->_pokemon_data[pos].getAttack() << endl;
    cout << "Defence: " << this->_pokemon_data[pos].getDefense() << endl;
    cout << "Special Attack: " << this->_pokemon_data[pos].getSpecialAttack() << endl;
    cout << "Special Defence: " << this->_pokemon_data[pos].getSpecialDefese() << endl;
    cout << "Speed: " << this->_pokemon_data[pos].getSpeed() << endl;

    // Mostramos los movimientos
    // Si un movimiento es nulo, no lo mostramos
    if(this->_pokemon_data[pos].getMove1() != "null"){
        cout << "Move 1: " << this->_pokemon_data[pos].getMove1() << endl;
    }
    if(this->_pokemon_data[pos].getMove2() != "null"){
        cout << "Move 2: " << this->_pokemon_data[pos].getMove2() << endl;
    }
    if(this->_pokemon_data[pos].getMove3() != "null"){
        cout << "Move 3: " << this->_pokemon_data[pos].getMove3() << endl;
    }
    if(this->_pokemon_data[pos].getMove4() != "null"){
        cout << "Move 4: " << this->_pokemon_data[pos].getMove4() << endl;
    }
}
/**
 * @brief Funcion auxiliar de addPokemon
 * @param cosa_a_buscar String que se quiere ver si esta en el vector
 * @param cosa_que_se_busca Parametro que se busca en el vector
 */
bool pokemon_database::bucle(const string &cosa_a_buscar, const std::vector<string>& cosa_que_se_busca){
    int i = 0;
    bool encontrado = false;
    while( i < cosa_que_se_busca.size() && !encontrado ){

        if( cosa_a_buscar == cosa_que_se_busca[i] ){
            encontrado = true;
        }
        i++;
    }
    return encontrado;
}/**
 * @brief Funcion auxiliar de addPokemon
 * @param cosa_que_queremos_buscar String que se quiere ver si esta en el vector
 * @param cosa_buscadora Parametro que se busca en el vector
 */
bool pokemon_database::bucle(const string &cosa_que_queremos_buscar, const std::vector<move_struct>& cosa_buscadora){
    int i = 0;
    bool encontrado = false;
    while(i < cosa_buscadora.size() && !encontrado ){

        if(cosa_que_queremos_buscar == cosa_buscadora[i].getNombre() ){
            encontrado = true;
        }
        i++;
    }
    return encontrado;
}
/**
 * @brief Dado un pokemon por parametro, este funcion lo añade al vector para poder usarse en cualquier momento
 * @param pkmn Pokemon a añadir
 */
std::string pokemon_database::addPokemon(const pokemon& pkmn) {
    // Comprobamos que es un pokemon valido
    // Miramos los tipos
    std::vector<string> types = {"steel", "water", "bug", "dragon",
                        "electric", "ghost", "fire", "fairy",
                        "ice", "fight", "normal", "plant", "psychic",
                        "rock", "dark", "dirt", "poison", "flying", "null"};

    // Buscamos los tipos
    // Tipo 1
    if( !bucle( pkmn.getType1(), types ) || pkmn.getType1() == "null" ){
        throw invalid_argument("El tipo 1 del pokemon " + pkmn.getNombre() + " no es valido");
    }
    // Tipo 2
    if( !bucle( pkmn.getType2(), types ) ){
        throw invalid_argument("El tipo 2 del pokemon " + pkmn.getNombre() + " no es valido");
    }

    // Miramos los movimientos
    move_database move;
    vector<move_struct> moveData = move.getMoveData();
    moveData.emplace_back("null", "null", 0, 0, "null" );

    // Miramos el movimiento 1
    if( !bucle(pkmn.getMove1(), moveData )){
        throw invalid_argument("El movimiento 1 del pokemon " + pkmn.getNombre() + " no es valido");
    }
    // Miramos el movimiento 2
    if( !bucle(pkmn.getMove2(), moveData )){
        throw invalid_argument("El movimiento 2 del pokemon " + pkmn.getNombre() + " no es valido");
    }
    // Miramos el movimiento 3
    if( !bucle(pkmn.getMove3(), moveData )){
        throw invalid_argument("El movimiento 3 del pokemon " + pkmn.getNombre() + " no es valido");
    }
    // Miramos el movimiento 4
    if( !bucle(pkmn.getMove4(), moveData )){
        throw invalid_argument("El movimiento 4 del pokemon " + pkmn.getNombre() + " no es valido");
    }
    // Miramos las stats
    if( pkmn.getPv() < 0 || pkmn.getSpecialDefese() < 0 || pkmn.getDefense() < 0 || pkmn.getAttack() < 0
    || pkmn.getSpecialAttack() < 0 || pkmn.getSpeed() < 0 ) {
        throw invalid_argument("Las estadisticas del pokemon" + pkmn.getNombre() + " no son validas");
    }

    _pokemon_data.push_back(pkmn);

    return "Pokemon created and added with success";
}

pokemon_database& pokemon_database::operator=(const pokemon_database &orig) = default;

