//Aluno Gabriel Almeida Buzzi 

#ifndef CARTA_HPP
#define CARTA_HPP

#include <string>
#include <iostream>

using namespace std;

enum Naipe {
    OUROS,
    ESPADAS,
    COPAS,
    PAUS
};

class Carta {
private:
    int valor;
    Naipe naipe;

public:
    Carta() : valor(0), naipe(OUROS) {}

    Carta(int valor, Naipe naipe) {
        this->valor = valor;
        this->naipe = naipe;
    }

    int getValor() const { return valor; }
    Naipe getNaipe() const { return naipe; }

    string getDescricao() const {
        string nomesValores[] = {
            "", "Ás", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"
        };

        string naipes[] = {
            "Ouros", "Espadas", "Copas", "Paus"
        };

        return nomesValores[valor] + " de " + naipes[naipe];
    }

    bool operator==(const Carta& outra) const {
        return valor == outra.valor && naipe == outra.naipe;
    }

    bool operator!=(const Carta& outra) const {
        return !(*this == outra);
    }

    bool operator<(const Carta& outra) const {
        return valor < outra.valor;
    }

    bool operator>(const Carta& outra) const {
        return valor > outra.valor;
    }

    friend ostream& operator<<(ostream& os, const Carta& carta) {
        os << carta.getDescricao();
        return os;
    }
};

#endif
