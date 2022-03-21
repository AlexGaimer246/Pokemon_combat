//
// Created by alexc on 20/02/2022.
//

#ifndef POKEMON_TRAINERS_STRUCT_H
#define POKEMON_TRAINERS_STRUCT_H
#include <iostream>

class trainers_struct {
public:

    trainers_struct() = default;

    trainers_struct(const std::string nombre, const std::string pokemon1, const std::string pokemon2, const std::string pokemon3,
                    const std::string pokemon4, const std::string pokemon5, const std::string pokemon6):
            _nombre(nombre), _pokemon1(pokemon1), _pokemon2(pokemon2), _pokemon3(pokemon3), _pokemon4(pokemon4),
            _pokemon5(pokemon5), _pokemon6(pokemon6) {};

    ~trainers_struct() = default;

    const std::string &getNombre() const {
        return _nombre;
    }

    const std::string &getPokemon1() const {
        return _pokemon1;
    }

    const std::string &getPokemon2() const {
        return _pokemon2;
    }

    const std::string &getPokemon3() const {
        return _pokemon3;
    }

    const std::string &getPokemon4() const {
        return _pokemon4;
    }

    const std::string &getPokemon5() const {
        return _pokemon5;
    }

    const std::string &getPokemon6() const {
        return _pokemon6;
    }


    void setNombre(const std::string &nombre) {
        _nombre = nombre;
    }

    void setPokemon1(const std::string &pokemon1) {
        _pokemon1 = pokemon1;
    }

    void setPokemon2(const std::string &pokemon2) {
        _pokemon2 = pokemon2;
    }

    void setPokemon3(const std::string &pokemon3) {
        _pokemon3 = pokemon3;
    }

    void setPokemon4(const std::string &pokemon4) {
        _pokemon4 = pokemon4;
    }

    void setPokemon5(const std::string &pokemon5) {
        _pokemon5 = pokemon5;
    }

    void setPokemon6(const std::string &pokemon6) {
        _pokemon6 = pokemon6;
    }

    trainers_struct& operator= (const trainers_struct &orig);

private:

    std::string _nombre = "";
    std::string _pokemon1 = "null";
    std::string _pokemon2 = "null";
    std::string _pokemon3 = "null";
    std::string _pokemon4 = "null";
    std::string _pokemon5 = "null";
    std::string _pokemon6 = "null";
};


#endif //POKEMON_TRAINERS_STRUCT_H
