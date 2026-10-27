#include <iostream>
#include <vector>

struct Velha {
    std::vector <char> tab = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    void exibir_tabuleiro() {
        std::cout << "\n" << tab[0] << " | " << tab[1] << " | " << tab[2] << "\n";
        std::cout << "---------\n";
        std::cout << tab[3] << " | " << tab[4] << " | " << tab[5] << "\n";
        std::cout << "---------\n";
        std::cout << tab[6] << " | " << tab[7] << " | " << tab[8] << "\n";
    }

    bool verifica_vitoria() {
        if (
            (tab[0] == tab[1] && tab[1] == tab[2]) ||
            (tab[3] == tab[4] && tab[4] == tab[5]) ||
            (tab[6] == tab[7] && tab[7] == tab[8]) ||
            (tab[0] == tab[3] && tab[3] == tab[6]) ||
            (tab[1] == tab[4] && tab[4] == tab[7]) ||
            (tab[2] == tab[5] && tab[5] == tab[8]) ||
            (tab[0] == tab[4] && tab[4] == tab[8]) ||
            (tab[2] == tab[4] && tab[4] == tab[6])
        ) {return true;}

        return false;
    }

    void altera_casa(int casa, int jogador) {
        if (jogador == 1) {
            tab[casa - 1] = 'X';
        } else {
            tab[casa - 1] = 'O';
        }
    }

    void definir_opcao(char& opcao, int tipo) {
        bool definido = false;
        std::string tentativa; getline(std::cin, tentativa);

        if (tipo == 1) {
            while (!definido) {
                if (tentativa.size() != 1 || !(tentativa[0] > '0' && tentativa[0] <= '9')) {
                    std::cout << "Opção inválida. Tente novamente:";
                    getline(std::cin, tentativa);
                } else {
                    if (tab[tentativa[0] - '0' - 1] == 'X' || tab[tentativa[0] - '0' - 1] == 'O') {
                        std::cout << "Posição já ocupada. Tente novamente.";
                        getline(std::cin, tentativa);
                    } else {
                        opcao = tentativa[0];
                        definido = true;
                    }
                }
            }
        } else if (tipo == 2) {
            while (!definido) {
                char a = tentativa[0];
                if (tentativa.size() != 1 || (a != 's' && a != 'S' && a != 'N' && a != 'n')) {
                    std::cout << "Opção inválida. Tente novamente [S/s/N/n]:";
                    getline(std::cin, tentativa);
                } else {
                    opcao = tentativa[0];
                    definido = true;
                }
            }
        }
    }
};

int main() {
    bool querer = true;

    while (querer) {
        Velha velha;
        int jogador = 2, casas_preenchidas = 0;

        std::cout << "========================================\n\n";
        std::cout << "SEJAM BEM VINDOS AO JOGO DA VELHA!!\n\n";
        std::cout << "Tabuleiro inicial:\n";
        velha.exibir_tabuleiro();
        std::cout << "\n========================================\n";

        while (casas_preenchidas < 9) {
            jogador = 3 - jogador;
            char posicao; std::vector<char> sim = {'X', 'O'};

            std::cout << "\nJogador " << jogador << " (" << sim[jogador - 1] << "), escolha sua posicao:";
            velha.definir_opcao(posicao, 1);
            velha.altera_casa(posicao - '0', jogador);
            casas_preenchidas ++;
            velha.exibir_tabuleiro();
            std::cout << "\n========================================\n";

            if (velha.verifica_vitoria()) {
                break;
            }
        }

        if (casas_preenchidas == 9 && !velha.verifica_vitoria()) {
            std::cout << "\nEmpate: ninguém venceu.\n\n";
        } else {
            std::cout << "\nParabéns! O jogador " << jogador << " venceu!\n\n";
        }

        std::cout << "Vocês querem jogar mais? [S/s/N/n]: ";
        char auxiliar; velha.definir_opcao(auxiliar, 2);

        if (auxiliar == 'n' || auxiliar == 'N') {
            std::cout << "\nEncerrando o programa... voltem sempre!";
            querer = false;
        }
    }
}