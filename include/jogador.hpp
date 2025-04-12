//Aluno Gabriel Almeida Buzzi 

#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "carta.hpp"
#include "ll1.hpp"
#include <string>
#include <iostream>

using namespace std;

class Jogador {
private:
    string nome;
    ListaEstatica<Carta> mao;

public:
    Jogador() : nome("Jogador") {}

    Jogador(const string& nome) {
        this->nome = nome;
    }

    string getNome() const {
        return nome;
    }

    void receberCarta(const Carta& carta) {
        mao.inserirFim(carta);
    }

    Carta jogarCarta() {
        Carta* carta = mao.obterItem(0);
        if (carta) {
            Carta copia = *carta;
            mao.removerInicio();
            return copia;
        }
        return Carta(); // retorno neutro
    }

    int getQtdCartas() const {
        return mao.getTamanho();
    }

    void mostrarMao() const {
        cout << nome << " tem as cartas: ";
        mao.imprimir();
    }
};

#endif
