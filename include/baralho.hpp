//Aluno Gabriel Almeida Buzzi 

#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "carta.hpp"
#include "ll1.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

class Baralho {
private:
    ListaEstatica<Carta> cartas;

public:
    Baralho() {
        srand(time(nullptr));

        for (int naipe = 0; naipe < 4; naipe++) {
            for (int valor = 1; valor <= 13; valor++) {
                cartas.inserirFim(Carta(valor, static_cast<Naipe>(naipe)));
            }
        }
    }

    void embaralhar() {
        int n = cartas.getTamanho();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            Carta* cartaI = cartas.obterItem(i);
            Carta* cartaJ = cartas.obterItem(j);
            if (cartaI && cartaJ) {
                Carta temp = *cartaI;
                *cartaI = *cartaJ;
                *cartaJ = temp;
            }
        }
    }

    bool temCartas() const {
        return cartas.getTamanho() > 0;
    }

    Carta comprar() {
        Carta* carta = cartas.obterItem(0);
        if (carta) {
            Carta copia = *carta;
            cartas.removerInicio();
            return copia;
        }
        return Carta();  // retorno neutro
    }

    void imprimir() const {
        cartas.imprimir();
    }
};

#endif
