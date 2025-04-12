//Aluno Gabriel Almeida Buzzi 

#ifndef LLDUPLA_HPP
#define LLDUPLA_HPP

#include <iostream>

using namespace std;

template <typename T>
struct NoDuplo {
    T dado;
    NoDuplo* prox;
    NoDuplo* ant;

    NoDuplo(const T& valor) : dado(valor), prox(nullptr), ant(nullptr) {}
};

template <typename T>
class listaduplaz {
private:
    NoDuplo<T>* inicio;
    NoDuplo<T>* fim;
    int tamanho;

public:
    listaduplaz() : inicio(nullptr), fim(nullptr), tamanho(0) {}

    ~listaduplaz() {
        while (inicio != nullptr) {
            NoDuplo<T>* temp = inicio;
            inicio = inicio->prox;
            delete temp;
        }
    }

    bool inserirInicio(const T& item) {
        NoDuplo<T>* novo = new NoDuplo<T>(item);
        novo->prox = inicio;
        if (inicio != nullptr) {
            inicio->ant = novo;
        } else {
            fim = novo;
        }
        inicio = novo;
        tamanho++;
        return true;
    }

    bool inserirFim(const T& item) {
        NoDuplo<T>* novo = new NoDuplo<T>(item);
        novo->ant = fim;
        if (fim != nullptr) {
            fim->prox = novo;
        } else {
            inicio = novo;
        }
        fim = novo;
        tamanho++;
        return true;
    }

    bool inserirPosicao(const T& item, int pos) {
        if (pos < 0 || pos > tamanho) return false;
        if (pos == 0) return inserirInicio(item);
        if (pos == tamanho) return inserirFim(item);

        NoDuplo<T>* atual = inicio;
        for (int i = 0; i < pos; i++) {
            atual = atual->prox;
        }

        NoDuplo<T>* novo = new NoDuplo<T>(item);
        novo->prox = atual;
        novo->ant = atual->ant;
        atual->ant->prox = novo;
        atual->ant = novo;
        tamanho++;
        return true;
    }

    bool removerInicio() {
        if (inicio == nullptr) return false;
        NoDuplo<T>* temp = inicio;
        inicio = inicio->prox;
        if (inicio != nullptr) {
            inicio->ant = nullptr;
        } else {
            fim = nullptr;
        }
        delete temp;
        tamanho--;
        return true;
    }

    bool removerFim() {
        if (fim == nullptr) return false;
        NoDuplo<T>* temp = fim;
        fim = fim->ant;
        if (fim != nullptr) {
            fim->prox = nullptr;
        } else {
            inicio = nullptr;
        }
        delete temp;
        tamanho--;
        return true;
    }

    bool removerPosicao(int pos) {
        if (pos < 0 || pos >= tamanho) return false;
        if (pos == 0) return removerInicio();
        if (pos == tamanho - 1) return removerFim();

        NoDuplo<T>* atual = inicio;
        for (int i = 0; i < pos; i++) {
            atual = atual->prox;
        }

        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
        delete atual;
        tamanho--;
        return true;
    }

    T* obterItem(int pos) const {
        if (pos < 0 || pos >= tamanho) return nullptr;
        NoDuplo<T>* atual = inicio;
        for (int i = 0; i < pos; i++) {
            atual = atual->prox;
        }
        return &atual->dado;
    }

    bool contem(const T& item) const {
        NoDuplo<T>* atual = inicio;
        while (atual != nullptr) {
            if (atual->dado == item) return true;
            atual = atual->prox;
        }
        return false;
    }

    int indice(const T& item) const {
        NoDuplo<T>* atual = inicio;
        int pos = 0;
        while (atual != nullptr) {
            if (atual->dado == item) return pos;
            atual = atual->prox;
            pos++;
        }
        return -1;
    }

    void imprimir() const {
        NoDuplo<T>* atual = inicio;
        cout << "[ ";
        while (atual != nullptr) {
            cout << atual->dado;
            if (atual->prox != nullptr) cout << ", ";
            atual = atual->prox;
        }
        cout << " ]\n";
    }

    int getTamanho() const {
        return tamanho;
    }
};

#endif
