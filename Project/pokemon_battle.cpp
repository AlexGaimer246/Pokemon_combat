//
// Created by alexc on 24/02/2022.
//
#include "pokemon_battle.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * @brief Constructor parametrizado de batalla entre el jugador y un pokemon salvaje
 * @param player
 * @param wild_pokemon
 */
pokemon_battle::pokemon_battle(trainers_struct &player, pokemon &wild_pokemon, string &difficulty)
    try:
        _player(player), _wildPokemon(wild_pokemon), _mode("wild"), _difficulty(difficulty){

        if(difficulty != "easy"){
            throw invalid_argument("La dificultad de la batalla no es correcta");
        }

        // Buscamos a los pokemon del jugador
        pokemon player_pokemon_1 = searchPokemon(player.getPokemon1());
        pokemon player_pokemon_2 = searchPokemon(player.getPokemon2());
        pokemon player_pokemon_3 = searchPokemon(player.getPokemon3());
        pokemon player_pokemon_4 = searchPokemon(player.getPokemon4());
        pokemon player_pokemon_5 = searchPokemon(player.getPokemon5());
        pokemon player_pokemon_6 = searchPokemon(player.getPokemon6());
        // Generamos el vector donde se guardan los pokemon del jugador
        _playerTeam =  {player_pokemon_1, player_pokemon_2,
                        player_pokemon_3, player_pokemon_4, player_pokemon_5, player_pokemon_6};

        combat_controller();

}   catch (exception &error){
        throw error;
    }



/**
 * @brief Constructor de batalla entre dos entrenadores
 * @param player La estructura de entrenador del jugador
 * @param rival La estructura de entrenador del rival
 * @post En caso de que a la clase se le pida una batalla entre dos entrenadores, este constructor se encargara de construir dicha batalla
 */
pokemon_battle::pokemon_battle(trainers_struct &player, trainers_struct &rival, string &difficulty)
    try:
        _player(player), _enemy(rival), _mode("trainer"), _difficulty(difficulty) {

        if(difficulty != "easy"){
            throw invalid_argument("La dificultad de la batalla no es correcta");
        }

        // Buscamos a los pokemon del jugador
        pokemon player_pokemon_1 = searchPokemon(player.getPokemon1());
        pokemon player_pokemon_2 = searchPokemon(player.getPokemon2());
        pokemon player_pokemon_3 = searchPokemon(player.getPokemon3());
        pokemon player_pokemon_4 = searchPokemon(player.getPokemon4());
        pokemon player_pokemon_5 = searchPokemon(player.getPokemon5());
        pokemon player_pokemon_6 = searchPokemon(player.getPokemon6());
        // Generamos el vector donde se guardan los pokemon del jugador
        _playerTeam =  {player_pokemon_1, player_pokemon_2,
                        player_pokemon_3, player_pokemon_4, player_pokemon_5, player_pokemon_6};

        // Buscamos los pokemon del rival
        pokemon rival_pokemon_1 = searchPokemon(_enemy.getPokemon1());
        pokemon rival_pokemon_2 = searchPokemon(_enemy.getPokemon2());
        pokemon rival_pokemon_3 = searchPokemon(_enemy.getPokemon3());
        pokemon rival_pokemon_4 = searchPokemon(_enemy.getPokemon4());
        pokemon rival_pokemon_5 = searchPokemon(_enemy.getPokemon5());
        pokemon rival_pokemon_6 = searchPokemon(_enemy.getPokemon6());

        // Generamos el vector donde se guardan los pokemon del rival
        _enemyTeam =  {rival_pokemon_1, rival_pokemon_2, rival_pokemon_3,
                       rival_pokemon_4, rival_pokemon_5, rival_pokemon_6};

        combat_controller();

}   catch (exception &error){
        throw error;
    }


/**
 * @brief Esta funcion calcula en indice del tipo de movimiento que se quiere hacer para luego
 * usarse en la tabla de tipos
 * @param tipo_a_buscar El _nombre del tipo que se trata de buscar
 * @return EL indice donde el nommbre a buscar coincide con uno de los tipos de la tabla de tipos
 */
int pokemon_battle::calculaIndice(string vect[], const string &tipo_a_buscar){

    int indice = -1;
    int i = 0;
    bool esta = false;
    while(i < 18 && !esta){

        if(vect[i] == tipo_a_buscar){
            indice = i;
            esta = true;
        }
        i++;
    }
    return indice;
}


/**
 * @brief Esta funcion calcula el daño efectuado a un pokemon por un ataque usando una fórmula algunas cosas más.
 * @param move El movimiento que se esta tratando de usar
 * @param pkmn El pokeon al que le da el movimiento
 * @return Daño efectuado a dicho pokemon
 */
double pokemon_battle::calculateDamage(move_struct &move, pokemon &pkmn_user, pokemon &pkmn_enemy){

    // Agarramos la tabla de tipos
    float tabla_tipos[18][18] = {
                                 {0.5, 0.5, 1, 1, 0.5, 1, 0.5, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1},
                                 {1, 0.5, 1, 0.5, 1, 1, 2, 1, 1, 1, 1, 0.5, 1, 2, 1, 2, 1, 1},
                                 {0.5, 1, 1, 1, 1, 0.5, 0.5, 0.5, 1, 0.5, 1, 2, 2, 1, 2, 1, 0.5, 0.5},
                                 {0.5, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 2, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 0, 1, 2},
                                 {1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0, 1, 2, 1, 0.5, 1, 1, 1},
                                 {2, 0.5, 1, 0.5, 1, 1, 0.5, 1, 2, 1, 1, 2, 1, 0.5, 1, 1, 1, 1 },
                                 {0.5, 1, 1, 2, 1, 1, 0.5, 1, 1, 2, 1, 1, 1, 1, 2, 1, 0.5, 1},
                                 {0.5, 0.5, 1, 2, 1, 1, 0.5, 1, 0.5, 1, 1, 2, 1, 1, 1, 2, 1, 2},
                                 {2, 1, 0.5, 1, 1, 0, 1, 0.5, 2, 1, 2, 1, 0.5, 2, 2, 1, 0.5, 0.5},
                                 {0.5, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1},
                                 {0.5, 2, 0.5, 0.5, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 2, 1, 2, 0.5, 0.5},
                                 {0.5, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 1, 0, 1, 2, 1},
                                 {0.5, 1, 2, 1, 1, 1, 2, 1, 2, 0.5, 1, 1, 1, 1, 1, 0.5, 1, 2},
                                 {1, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 1, 1, 2, 1, 0.5, 1, 1, 1},
                                 {2, 1, 0.5, 1, 2, 1, 2, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 2, 0},
                                 {0, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 1},
                                 {0.5, 1, 2, 1, 0.5, 1, 1, 1, 1, 2, 1, 2, 1, 0.5, 1, 1, 1, 1}
    };

    // Agarramos todos los datos
    move_database data;
    string types[18] = {"steel", "water", "bug", "dragon",
                        "electric", "ghost", "fire", "fairy",
                        "ice", "fight", "normal", "plant", "psychic",
                        "rock", "dark", "dirt", "poison", "flying"};

    int indice_tipo_mov = -1; ///< Este es el indice del tipo del movimiento que se esta efectuando
    int indice_tipo_1_pkmn = -1; ///< Este es el indice del tipo 1 del pokemon que recibe el ataque
    int indice_tipo_2_pkmn = -1; ///< Este es el indice del tipo 2 del pokemon que recibe el ataque
    double damage; ///< La cantidad de daño efectuado

    // Calculamos el indice del tipo del movimiento por el _nombre
    try{
        indice_tipo_mov = calculaIndice(types, move.getMoveType());
    } catch (std::exception &except){
        cout << "Error: " << except.what() << endl;
    }
    // Calculamos el indice del primer tipo del pokemon que recibe el ataque
    try{
        indice_tipo_1_pkmn = calculaIndice(types, pkmn_enemy.getType1());
    } catch (std::exception &except){
        cout << "Error: " << except.what() << endl;
    }
    // Calculamos el indice del segundo tipo del pokemon que recibe el ataque si no es nulo
    if(pkmn_enemy.getType2() != "null"){
        try{
            indice_tipo_2_pkmn = calculaIndice(types, pkmn_enemy.getType2());
        } catch (std::exception &except){
            cout << "Error: " << except.what() << endl;
        }
    }

    // Calculamos el daño efectuado mediante un formula matematica
    // Si el daño es nomal
    if(move.getTypeOfDamage() == "normal"){
        damage = (float(pkmn_user.getAttack()) * (float(move.getDamage()) / float(pkmn_enemy.getDefense()))) / 10.0;
    }
    // En caso de que sea especial
    if(move.getTypeOfDamage() == "special"){
        damage = (double(pkmn_user.getSpecialAttack()) * (double(move.getDamage()) / double(pkmn_enemy.getSpecialDefese()))) / 10.0;
    }

    // Le sumamos el STAB
    if(move.getMoveType() == pkmn_user.getType1() || move.getMoveType() == pkmn_user.getType2()){
        damage *= 1.5;
    }
    // Efectividad con el tipo 1
    damage *= tabla_tipos[indice_tipo_mov][indice_tipo_1_pkmn];
    // Efectividad con el tipo 2 si es no nulo
    if(indice_tipo_2_pkmn != -1){
        damage *= tabla_tipos[indice_tipo_mov][indice_tipo_2_pkmn];
    }

    // Calculamos la parte random
    damage *= (rand() %120 + 80) / 100.0;

    return damage;
}

/**
 * @brief Genera una pausa en el codigo hasta que el usuario le de al intro
 */

void pokemon_battle::pausa(){
    cout << "\n Presiona intro para continuar" << endl;
    fflush(stdin);
    getchar();
}

/**
 * @brief Dado un _nombre de un pokemon, esta funcion retorna la estructura de dicho pokemon
 * @param name Nombre del pokemon a buscar
 * @return La estrctura del pokemon encontrado
 */
pokemon pokemon_battle::searchPokemon(const string &name){
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

/**
 * @brief Dado el _nombre de un movimiento, esta funcion retorna la estrcutra completa del
 * movimieto cuyo _nombre coincide
 * @param move El _nombre del movimiento a buscar
 * @note Si el movimiento no se encuentra, se retona un move_struct con los datos por defecto
 */
move_struct pokemon_battle::searchMove(const string &mov){
    move_database move_data;
    // Pedimos el vector de move_database
    vector<move_struct> move_vect = move_data.getMoveData();

    int tam = move_data.getMoveDataTam();

    // Generamos el resultado que vamos a dar
    move_struct resultado;
    bool encontrado = false;
    // Buscamos el movimiento por el _nombre
    int i = 0;
    while(i < tam && !encontrado){
        if(move_vect[i].getNombre() == mov){
            encontrado = true;
            resultado = move_vect[i];
        }
        i++;
    }
    if(!encontrado){
        throw invalid_argument ("Movimiento no encontrado");
    }

    return resultado;
}

/**
 * @brief Dado un movimiento, esta funcion imprime los datos de dicho movimiento
 * @param mov El movimiento que se trata de sacar
 * @return True si es un movimiento no nulo, Falso si es un movimiento nulo
 */
bool pokemon_battle::printMove(move_struct &mov){
    if(mov.getNombre() != "null"){
        cout << mov.getNombre() << " \n  -Damage: " << mov.getDamage() << " \n  -PP: " << mov.getPp()
        << "\n  -Tipo: " <<  mov.getMoveType() << "\n -Tipo de danio: " << mov.getTypeOfDamage() << endl;
        // Mostramos los tipos
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Dado un movimiento, esta funcion imprime los datos de dicho movimiento y el indice del mismo
 * @param mov El movimiento que se trata de sacar
 * @param tieneCout Sirve para indicar si el usuario quiere que la funcion saque mensajes en pantalla(False = No, True = Si)
 * @return True si es un movimiento no nulo, Falso si es un movimiento nulo
 */
bool pokemon_battle::printMove(move_struct &mov, int &indice, const bool tieneCout){
    if(mov.getNombre() != "null" && tieneCout){
        cout << indice << ": " << mov.getNombre() << " \n  -Damage: " << mov.getDamage() << " \n  -PP: " << mov.getPp()
             << "\n  -Tipo: " <<  mov.getMoveType() << "\n -Tipo de danio: " << mov.getTypeOfDamage() << endl;
        // Mostramos los tipos
        indice++;
        return true;
    }
    else{
        return false;
    }
}


/**
 * @brief Muestra en salida estandar el _nombre y movimientos del pokemon pedido
 * @param pkmn El pokemon que se quiere mostrar
 * @param tieneCout Sirve para indicar si el usuario quiere que la funcion saque mensajes en pantalla(False = No, True = Si)
 * @return El numero de movimientos disponibles para el pokemon

 */
int pokemon_battle::mostrarPokemon(const pokemon &pkmn, const bool tieneCout){

    // Buscamos los movimientos del pokemon
    int moveset = 0; ///< Variable que cuenta cuantos movimientos tiene un pokemon

    move_struct move1, move2, move3, move4;

    try{
        move1 = searchMove(pkmn.getMove1());
        moveset++;
    }catch (std::exception &except){
    }
    try{
        move2 = searchMove(pkmn.getMove2());
        moveset++;
    }catch (std::exception &except){
    }
    try{
        move3 = searchMove(pkmn.getMove3());
        moveset++;
    }catch (std::exception &except){
    }
    try{
        move4 = searchMove(pkmn.getMove4());
        moveset++;
    }catch (std::exception &except){
    }

    if(pkmn.getNombre() != "null"){
        if(tieneCout){
            cout << pkmn.getNombre() << " tiene " << pkmn.getPv()
                 << " PV y conoce los movimientos: " << endl;
        }
    }
    // Mostramos los movimientos del pokemon
    // En caso de ser movimiento nulo, quitamos 1 a moveset

    int indice = 1;

    printMove(move1, indice, tieneCout);
    printMove(move2, indice, tieneCout);
    printMove(move3, indice, tieneCout);
    printMove(move4, indice, tieneCout);

    return moveset;
}

/**
 * @brief Le permite al usuario cambiar el pokemon actual
 * @param player_pokemon todos los pokemon que tiene el jugador
 * @return La posicion del pokemon seleccionado
 */
int pokemon_battle::cambioPokemon(){
    int num_pokemon = 5;
    int indice = -1;

    // Solicitamos el pokemon
    // Mostramos los pokemon
    for(int i = 0; i < 6; i++){
        if(_playerTeam[i].getNombre() != "null"){
            cout << i << " = " << _playerTeam[i].getNombre() << " y tiene "
                 << _playerTeam[i].getPv() << " PV" << endl;
        }
        else{
            num_pokemon--;
        }
    }
    // Solicitamos la posicion del pokemon pedido
    do{
        cout << "Selecciona un pokemon [0, " << num_pokemon << "]" << endl;
        cin >> indice;
    } while (indice < 0 || indice > num_pokemon);

    return indice;
}

/**
 * @brief Permite al jugador seleccionar un ataque del pokemon en uso y atacar
 * @param player_pokemon Pokemon del jugador
 * @param rival_pokemon Pokemon del rival
 * @return Daño efectuado
 * @note Esta funcion tiene un modo para batalla entre entrenadores y pokemon salvajes
 */
double pokemon_battle::atacar(){
    int actual_moves; ///< Numero de movimientos disponibles para dicho pokemon
    int selected_move; ///< Movimiento seleccionado por el pokemon a la hora de atacar

    // Mostramos lo movimientos

    try{
        actual_moves = mostrarPokemon(_playerTeam[_pokemonActual], true);
    }catch (std::exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    // Pedimos el ataque
    do{
        cout << "Selecciona un movimiento [1," << actual_moves << "]" << endl;
        cin >> selected_move;
    } while (selected_move < 1 || selected_move > actual_moves);

    // Obtenemos el ataque segun el movimiento escogido
    move_struct move_to_use;
    // Seleccionamos
    if(selected_move == 1){
        try{
            move_to_use = searchMove(_playerTeam[_pokemonActual].getMove1());
        } catch (std::exception &except){}
    }
    if(selected_move == 2){
        try{
            move_to_use = searchMove(_playerTeam[_pokemonActual].getMove2());
        } catch (std::exception &except){}
    }
    if(selected_move == 3){
        try{
            move_to_use = searchMove(_playerTeam[_pokemonActual].getMove3());
        } catch (std::exception &except){}
    }
    if(selected_move == 4){
        try{
            move_to_use = searchMove(_playerTeam[_pokemonActual].getMove4());
        } catch (std::exception &except){}
    }

    // Una vez tenemos el movimiento que queremos usar, calculamos el daño

    // Para batallas entre entrenadores
    if(_mode == "trainer") {
        return calculateDamage(move_to_use, _playerTeam[_pokemonActual], _enemyTeam[_pokemonEnemyActual]);
    } else {
        return calculateDamage(move_to_use, _playerTeam[_pokemonActual], _wildPokemon);
    }
}

/**
 * @brief Permite al jugador curar a un pokemon
 * @param pkmn
 */
void pokemon_battle::curarPokemon(){
    int num_pokemon = 5;
    int indice = -1;

    // Solicitamos el pokemon
    // Mostramos los pokemon
    for(int i = 0; i < 6; i++){
        if(_playerTeam[i].getNombre() != "null"){
            cout << i << " = " << _playerTeam[i].getNombre() << " y tiene "
                 << _playerTeam[i].getPv() << " PV" << endl;
        }
        else{
            num_pokemon--;
        }
    }
    // Solicitamos la posicion del pokemon pedido
    do{
        cout << "Selecciona el pokemon que quieres curar [0, " << num_pokemon << "]" << endl;
        cin >> indice;
    } while (indice < 0 || indice > num_pokemon);

    // Curamos al pokemon 20 _pv
    _numPociones--;
    _playerTeam[indice].setPv(_playerTeam[indice].getPv() + 20);

    // Damos feedback
    cout << _playerTeam[indice].getNombre() << " ahora tiene " << _playerTeam[indice].getPv() << " PV" << endl;
}

/**
 * @brief Muestra al usuario como esta la batalla en ese momento
 * @note Existe un modo para batallas con entrenadores y otro para batallas con pokemon salvajes
 */
void pokemon_battle::estadoBatalla() {

    cout << "Tu pokemon tiene los siguientes datos: " << endl;
    mostrarPokemon(_playerTeam[_pokemonActual], true);

    cout << endl;

    if(_mode == "trainer"){
        cout << "El entrenador rival " << _enemy.getNombre() << " tiene un pokemon con los siguientes datos: " << endl;
        mostrarPokemon(_enemyTeam[_pokemonEnemyActual], true);
    } else if(_mode == "wild"){
        cout << "El pokemon salvaje tiene estos datos: " << mostrarPokemon(_wildPokemon, true) << endl;
    }
}

/**
 * @brief Esta funcion se encarga de comprobar el estado actual de la batalla
 * @param [out] victoria En caso de perder, esta variable retornará False, si se gana, retornará True (solo en caso de que la batalla haya acabado)
 * @return True si la batalla ha terminado independientemente del resultado
 * @return False si la batalla aun no ha terminado
 * @note Esta funcion tiene dos modalidades, en caso de ser una batalla contra un entrenador, mirará por todos los pokemon del rival,
 * en caso de ser una batalla contra un pokemon salvaje, solo verá si su vida es negativa
 */
bool pokemon_battle::comprobarBatalla(bool &victoria) const {

    // Para el modo entrenadores
    bool todosDebilitados = true;

    // Miramos primero al jugador

    if(_mode == "trainer") {
        // Miramos los pokemon del otro

        todosDebilitados = true;

        for(int i = 0; i < 6; i++){
            if(_enemyTeam[i].getPv() > 0){
                todosDebilitados = false;
            }
        }
        // Si están todos debilitados, hemos terminado
        if(todosDebilitados){
            victoria = true;
            return true;
        }
    }

    // Para el modo contra pokemon salvajes
    if(_mode == "wild"){
        // Miramos al pokemon salvaje
        if(_wildPokemon.getPv() <= 0){
            victoria = true;
            return true;
        }
    }

    // Miramos al equipo del jugador

    for(int i = 0; i < 6; i++){
        if(_playerTeam[i].getPv() > 0){
            todosDebilitados = false;
        }
    }
    // Si están todos debilitados, hemos terminado
    if(todosDebilitados){
        victoria = false;
        return true;
    }

    // Si no hemos salido de la funcion, es porque aun no hemos terminado la batalla
    return false;
}

/**
 * @brief La IA del enemigo
 * @return La cantidad de daño hecha con el movimiento seleccionado
 * @post Esta funcion calcula el turno del enemigo, seleccionando un movimiento al azar o no (depende de la dificultad) \
 * y retornara dicho valor a la funcion encargada de que todo funcione
 * @note Esta funcion tiene dos modos: \
 *       - Modo entrenador:
 *       Dependiendo de la dificultad de la IA, el entrenador podra curar, cambiar o seleccionar los movimientos más eficazes
 *       - Modo pokemon salvaje
 *       Calcula el movimiento más eficaz
 */
double pokemon_battle::enemyAI() {

    pokemon pkmn; ///< Pokemon del rival seleccionado en dicho momento
    int actual_moves = 1; ///< Numero de movimientos disponibles para dicho pokemon
    int selected_move = 0; ///< Movimiento seleccionado por el pokemon a la hora de atacar
    bool turnoUsado = false;


    // Para el modo contra un entrenador
    if(_mode == "trainer"){
        pkmn = _enemyTeam[_pokemonEnemyActual];
        // Si tiene la vida a 0, cambiamos el pokemon
        if (pkmn._pv <= 0){

            // Si la dificultad es facil, cambiamos al primer pokemon que no este debilitado
            int oldIndice = _pokemonEnemyActual; ///< Solo para mostrar el mensaje de cambio de pokemon

            if(_difficulty == "easy"){

                int i = 0;
                bool encontrado = false;

                while(i < 6 && !encontrado){

                    if(_enemyTeam[i]._pv > 0){
                        _pokemonEnemyActual = i;
                        encontrado = true;
                    }
                    i++;
                }
                turnoUsado = true;
            }

            cout << "El entrenador " << _enemy.getNombre() << " ha cambiado a " << _enemyTeam[oldIndice].getNombre()
                 << " por " << _enemyTeam[_pokemonEnemyActual].getNombre() << endl;
        }

    } else if(_mode == "wild"){ // Modo pokemon salvaje
        pkmn = _wildPokemon;
    }

    actual_moves = mostrarPokemon(pkmn, false);

    // Elegimos uno de los ataques dependiendo de la dificultad
    // Para la dificultad facil
    if(_difficulty == "easy"){
        // Seleccionamos un movimiento aleatorio
        selected_move = rand() % actual_moves + 1;
    }
    if (!turnoUsado){
        // Obtenemos el ataque
        // Obtenemos el ataque segun el movimiento escogido
        move_struct move_to_use;
        // Seleccionamos
        if(selected_move == 1){
            try{
                move_to_use = searchMove(pkmn.getMove1());
            } catch (std::exception &except){}
        }
        if(selected_move == 2){
            try{
                move_to_use = searchMove(pkmn.getMove2());
            } catch (std::exception &except){}
        }
        if(selected_move == 3){
            try{
                move_to_use = searchMove(pkmn.getMove3());
            } catch (std::exception &except){}
        }
        if(selected_move == 4){
            try{
                move_to_use = searchMove(pkmn.getMove4());
            } catch (std::exception &except){}
        }

        cout << pkmn.getNombre() << " usa " << move_to_use.getNombre() << endl;

        return calculateDamage(move_to_use, pkmn, _playerTeam[_pokemonActual]);
    }
    else{
        return 0;
    }
}

/**
 * @brief Controlador de las batallas pokemon
 */
void pokemon_battle::combat_controller(){

    bool fin = false, victory;

    int opcion = -1;

    double danio; ///< Variable usada cuando se ataca (lleva la cantidad de daño efectuada)

    bool turnoUsado; ///< Sirve para indicar al programa si el turno del jugador ha sido usado o no

    while (!fin){

        turnoUsado = true; ///< Esta variable dicta si el jugador ha usado su turno o no

        // Creamos el entorno de batalla

        // Mostramos las opciones de combate

        cout << "Selecciona tu accion" << endl;
        cout << "1 = Combatir" << endl;
        cout << "2 = Cambiar de pokemon" << endl;
        cout << "3 = Curar un pokemon" << endl;
        cout << "4 = Observar estado de la batalla" << endl;

        cin >> opcion;

        // Hacemos la accion que ha pedido es usuario

        switch (opcion) {

            case 1:
                // Si el pokemon no esta debilitado, podemos atacar, si esta debilitado, no podemos
                if(_playerTeam[_pokemonActual]._pv > 0){
                    danio = atacar();
                    // Una vez calculado el daño, se lo restamos al pokemon rival
                    // Enviamos feedback de como es el estado actual de la batalla
                    if(_mode == "trainer"){
                        _enemyTeam[_pokemonEnemyActual]._pv -=  danio;
                        cout << "Le has quitado " << danio << " de vida a " << _enemyTeam[_pokemonEnemyActual].getNombre() << endl;
                        cout << "Ahora tiene " << _enemyTeam[_pokemonEnemyActual].getPv() << "PV" << endl;
                    } else if(_mode == "wild"){
                        _wildPokemon._pv -= danio;
                        cout << "Le has quitado " << danio << " de vida a " << _wildPokemon.getNombre() << endl;
                        cout << "Ahora tiene " << _wildPokemon.getPv() << "PV" << endl;
                    }

                    // Miramos el estado de la batalla
                    if(comprobarBatalla(victory)) {
                        if (victory) {
                            cout << "Has ganado el combate" << endl;
                        } else {
                            cout << "Has perdido el combate" << endl;
                        }
                        fin = true;
                    }
                } else {
                    cerr << _playerTeam[_pokemonActual].getNombre() << " esta debilitado, cambia de pokemon" << endl;
                    _pokemonActual = cambioPokemon(); ///< Position del pokemon que está en uso
                }

                break;
            case 2:
                _pokemonActual = cambioPokemon(); ///< Position del pokemon que está en uso
                break;
            case 3:
                curarPokemon();
                break;
            case 4:
                estadoBatalla();
                turnoUsado = false;
                break;

        }

        pausa();

        if(turnoUsado && !fin){

            // Ahora toca el turno del rival
            double enemyDamage;
            // Calculamos el danio segun la dificultad
            enemyDamage = enemyAI();
            // Se la restamos al pokemon del jugador
            _playerTeam[_pokemonActual]._pv -= enemyDamage;
            // Vemos el estado de la batalla
            if(_mode == "trainer"){
                cout << _enemyTeam[_pokemonEnemyActual].getNombre() << " te ha quitado " << enemyDamage << "PV" << endl;
                cout << "Tu pokemon: " << _playerTeam[_pokemonActual].getNombre() << " tiene " << _playerTeam[_pokemonActual].getPv() << "PV" << endl;
            } else if(_mode == "wild"){
                _wildPokemon._pv -= danio;
                cout << _wildPokemon.getNombre() << " te ha quitado " << enemyDamage << "PV" << endl;
                cout << "Tu pokemon: " << _playerTeam[_pokemonActual].getNombre() << " tiene " << _playerTeam[_pokemonActual].getPv() << "PV" << endl;
            }

            // Miramos el estado de la batalla
            if(comprobarBatalla(victory)) {
                if (victory) {
                    cout << "Has ganado el combate" << endl;
                } else {
                    cout << "Has perdido el combate" << endl;
                }
                fin = true;
            }
            if(!fin){
                pausa();
            }
        }
    }
}