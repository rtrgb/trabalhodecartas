//Aluno Gabriel Almeida Buzzi 

#ifndef LL1_HPP
#define LL1_HPP

#include <iostream>

using namespace std;

const int MAX_TAM = 100;

template <typename T>
class ListaEstatica {
private:
    T itens[MAX_TAM];
    int tamanho;

public:
    ListaEstatica() {
        tamanho = 0;
    }

    bool inserirInicio(const T& item) {
        if (tamanho >= MAX_TAM) return false;
        for (int i = tamanho; i > 0; i--) {
            itens[i] = itens[i - 1];
        }
        itens[0] = item;
        tamanho++;
        return true;
    }

    bool inserirFim(const T& item) {
        if (tamanho >= MAX_TAM) return false;
        itens[tamanho] = item;
        tamanho++;
        return true;
    }

    bool inserirPosicao(const T& item, int pos) {
        if (pos < 0 || pos > tamanho || tamanho >= MAX_TAM) return false;
        for (int i = tamanho; i > pos; i--) {
            itens[i] = itens[i - 1];
        }
        itens[pos] = item;
        tamanho++;
        return true;
    }

    bool removerInicio() {
        if (tamanho == 0) return false;
        for (int i = 0; i < tamanho - 1; i++) {
            itens[i] = itens[i + 1];
        }
        tamanho--;
        return true;
    }

    bool removerFim() {
        if (tamanho == 0) return false;
        tamanho--;
        return true;
    }

    bool removerPosicao(int pos) {
        if (pos < 0 || pos >= tamanho) return false;
        for (int i = pos; i < tamanho - 1; i++) {
            itens[i] = itens[i + 1];
        }
        tamanho--;
        return true;
    }

    T* obterItem(int pos) const {
        if (pos < 0 || pos >= tamanho) return nullptr;
        return (T*)&itens[pos];
    }

    bool contem(const T& item) const {
        for (int i = 0; i < tamanho; i++) {
            if (itens[i] == item) return true;
        }
        return false;
    }

    int indice(const T& item) const {
        for (int i = 0; i < tamanho; i++) {
            if (itens[i] == item) return i;
        }
        return -1;
    }

    void imprimir() const {
        cout << "[ ";
        for (int i = 0; i < tamanho; i++) {
            cout << itens[i];
            if (i < tamanho - 1) cout << ", ";
        }
        cout << " ]\n";
    }

    int getTamanho() const {
        return tamanho;
    }
};

#endif
