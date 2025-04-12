//Aluno Gabriel Almeida Buzzi 

#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "jogador.hpp"
#include "baralho.hpp"
#include "ll2encadeada.hpp"
#include "ll1.hpp"
#include <iostream>
#include <fstream> 

using namespace std;

struct Jogada {
    string nomeJogador;
    Carta cartaJogada;
};

class Partida {
private:
    ListaEncadeada<Jogador> jogadores;
    ListaEncadeada<Jogada> logRodadas;
    Baralho baralho;

    ListaEstatica<int> pontuacao;
    int numJogadores;
    int cartasPorJogador;
    int numRodadas;

public:
    Partida(int numJogadores, int cartasPorJogador, int numRodadas)
        : numJogadores(numJogadores), cartasPorJogador(cartasPorJogador), numRodadas(numRodadas) {
        
        for (int i = 0; i < numJogadores; i++) {
            string nome = "Jogador " + to_string(i + 1);
            jogadores.inserirFim(Jogador(nome));
            pontuacao.inserirFim(0);
        }
    }

    void iniciar() {
        baralho.embaralhar();
        distribuirCartas();
        executarRodadas();
        mostrarLog();
        mostrarRanking();
        salvarLogEmArquivo();
    }

    void distribuirCartas() {
        for (int i = 0; i < cartasPorJogador; i++) {
            for (int j = 0; j < numJogadores; j++) {
                Jogador* jogador = jogadores.obterItem(j);
                if (jogador && baralho.temCartas()) {
                    jogador->receberCarta(baralho.comprar());
                }
            }
        }

        cout << "\nCartas distribuídas:\n";
        for (int j = 0; j < numJogadores; j++) {
            jogadores.obterItem(j)->mostrarMao();
        }

        cout << "---------------------------------\n";
    }

    void executarRodadas() {
        for (int r = 0; r < numRodadas; r++) {
            cout << "\n Rodada " << (r + 1) << ":\n";

            for (int j = 0; j < numJogadores; j++) {
                Jogador* jogador = jogadores.obterItem(j);

                if (jogador && jogador->getQtdCartas() > 0) {
                    Carta jogada = jogador->jogarCarta();

                    cout << jogador->getNome() << " jogou " << jogada << "\n";

                    Jogada registro;
                    registro.nomeJogador = jogador->getNome();
                    registro.cartaJogada = jogada;

                    logRodadas.inserirFim(registro);

                    int* pontos = pontuacao.obterItem(j);
                    if (pontos) {
                        *pontos += jogada.getValor();
                    }
                }
            }

            cout << "---------------------------------\n";
        }
    }

    void mostrarLog() const {
        cout << "\n LOG DA PARTIDA:\n";
        for (int i = 0; i < logRodadas.getTamanho(); i++) {
            const Jogada* jogada = logRodadas.obterItem(i);
            if (jogada) {
                cout << jogada->nomeJogador << " jogou " << jogada->cartaJogada << "\n";
            }
        }
    }

    void mostrarRanking() const {
        cout << "\n RESULTADO:\n";

        int maiorPontuacao = -1;
        string vencedor;

        for (int i = 0; i < numJogadores; i++) {
            const Jogador* jogador = jogadores.obterItem(i);
            const int* pontos = pontuacao.obterItem(i);

            if (jogador && pontos) {
                cout << jogador->getNome() << " → " << *pontos << " pontos\n";

                if (*pontos > maiorPontuacao) {
                    maiorPontuacao = *pontos;
                    vencedor = jogador->getNome();
                }
            }
        }

        cout << "\n Vencedor: " << vencedor << " com " << maiorPontuacao << " pontos!\n";
    }
//salvar em txt
    void salvarLogEmArquivo(const string& nomeArquivo = "historico.txt") const {
        ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            cerr << " Erro ao criar o arquivo de log.\n";
            return;
        }

        arquivo << " LOG DA PARTIDA:\n";
        for (int i = 0; i < logRodadas.getTamanho(); i++) {
            const Jogada* jogada = logRodadas.obterItem(i);
            if (jogada) {
                arquivo << jogada->nomeJogador << " jogou " << jogada->cartaJogada << "\n";
            }
        }

        arquivo << "\n RESULTADO FINAL:\n";

        int maiorPontuacao = -1;
        string vencedor;

        for (int i = 0; i < numJogadores; i++) {
            const Jogador* jogador = jogadores.obterItem(i);
            const int* pontos = pontuacao.obterItem(i);

            if (jogador && pontos) {
                arquivo << jogador->getNome() << " -> " << *pontos << " pontos\n";

                if (*pontos > maiorPontuacao) {
                    maiorPontuacao = *pontos;
                    vencedor = jogador->getNome();
                }
            }
        }

        arquivo << "\n Vencedor: " << vencedor << " com " << maiorPontuacao << " pontos!\n";
        arquivo.close();

        cout << "\n Log salvo com sucesso em \"" << nomeArquivo << "\"!\n";
    }
};

#endif
