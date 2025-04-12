//Aluno Gabriel Almeida Buzzi 

#ifndef LL2ENCADEADA_HPP
#define LL2ENCADEADA_HPP

#include <iostream>

using namespace std;

template <typename T>
struct No {
    T dado;
    No* prox;

    No(const T& valor) : dado(valor), prox(nullptr) {}
};

template <typename T>
class ListaEncadeada {
private:
    No<T>* inicio;
    int tamanho;

public:
    ListaEncadeada() : inicio(nullptr), tamanho(0) {}

    ~ListaEncadeada() {
        while (inicio != nullptr) {
            No<T>* temp = inicio;
            inicio = inicio->prox;
            delete temp;
        }
    }

    bool inserirInicio(const T& item) {
        No<T>* novo = new No<T>(item);
        novo->prox = inicio;
        inicio = novo;
        tamanho++;
        return true;
    }

    bool inserirFim(const T& item) {
        No<T>* novo = new No<T>(item);

        if (inicio == nullptr) {
            inicio = novo;
        } else {
            No<T>* atual = inicio;
            while (atual->prox != nullptr) {
                atual = atual->prox;
            }
            atual->prox = novo;
        }

        tamanho++;
        return true;
    }

    bool inserirPosicao(const T& item, int pos) {
        if (pos < 0 || pos > tamanho) return false;
        if (pos == 0) return inserirInicio(item);

        No<T>* atual = inicio;
        for (int i = 0; i < pos - 1; i++) {
            atual = atual->prox;
        }

        No<T>* novo = new No<T>(item);
        novo->prox = atual->prox;
        atual->prox = novo;
        tamanho++;
        return true;
    }

    bool removerInicio() {
        if (inicio == nullptr) return false;
        No<T>* temp = inicio;
        inicio = inicio->prox;
        delete temp;
        tamanho--;
        return true;
    }

    bool removerFim() {
        if (inicio == nullptr) return false;
        if (inicio->prox == nullptr) {
            delete inicio;
            inicio = nullptr;
        } else {
            No<T>* atual = inicio;
            while (atual->prox->prox != nullptr) {
                atual = atual->prox;
            }
            delete atual->prox;
            atual->prox = nullptr;
        }
        tamanho--;
        return true;
    }

    bool removerPosicao(int pos) {
        if (pos < 0 || pos >= tamanho) return false;
        if (pos == 0) return removerInicio();

        No<T>* atual = inicio;
        for (int i = 0; i < pos - 1; i++) {
            atual = atual->prox;
        }

        No<T>* temp = atual->prox;
        atual->prox = temp->prox;
        delete temp;
        tamanho--;
        return true;
    }

    T* obterItem(int pos) const {
        if (pos < 0 || pos >= tamanho) return nullptr;
        No<T>* atual = inicio;
        for (int i = 0; i < pos; i++) {
            atual = atual->prox;
        }
        return &atual->dado;
    }

    bool contem(const T& item) const {
        No<T>* atual = inicio;
        while (atual != nullptr) {
            if (atual->dado == item) return true;
            atual = atual->prox;
        }
        return false;
    }

    int indice(const T& item) const {
        No<T>* atual = inicio;
        int pos = 0;
        while (atual != nullptr) {
            if (atual->dado == item) return pos;
            atual = atual->prox;
            pos++;
        }
        return -1;
    }

    void imprimir() const {
        No<T>* atual = inicio;
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
