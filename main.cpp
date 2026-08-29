#include <iostream>
#include <vector>
using namespace std;

struct Velha {
    vector <char> velha = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void exiba() {
        cout << velha[0] << " | " << velha[1] << " | " << velha[2] << "\n";
        cout << "---------\n";
        cout << velha[3] << " | " << velha[4] << " | " << velha[5] << "\n";
        cout << "---------\n";
        cout << velha[6] << " | " << velha[7] << " | " << velha[8] << "\n"; 
    }
    bool validar(char p) {
        int k = p - '0';
        if (k < 1 || k > 9) {
            return false;
        }
        if (velha[k - 1] != 'X' && velha[k - 1] != 'O') {
            return true;
        }
        return false;
    }
    void alterar(char p, int jogador) {
        if (validar(p)) {
            int k = p - '0';
            if (jogador == 1) {
                velha[k - 1] = 'X';
            } else if (jogador == 2) {
                velha[k - 1] = 'O';
            }   
        }
    }
    bool win() {
        // verifica linha por linha
        for (int i = 0; i < 9; i += 3) {
            if (velha[i] == velha[i + 1] && velha[i + 1] == velha[i + 2]) {
                return true;
            }
        }
        // verifica coluna por coluna
        for (int i = 0; i < 3; i ++) {
            if (velha[i] == velha[i + 3] && velha[i + 3] == velha[i + 6]) {
                return true;
            }
        }
        // verifica diagonais
        if (velha[0] == velha[4] && velha[4] == velha[8]) {
            return true;
        }

        if (velha[2] == velha[4] && velha[4] == velha[6]) {
            return true;
        }

        return false;
    }


};

void linha() {
    cout << "\n===================================\n";
}

int main() {
    while (1) {
        Velha grid;
        int jogador = 2;
        char f = 'S';

        linha();
        cout << "\nSEJAM BEM VINDOS AO JOGO DA VELHA!!\n\n";
        cout << "Tabuleiro inicial:\n\n";
        grid.exiba();
        linha();
        int p = 0;

        while (!grid.win() && p < 9) {
            jogador = 3 - jogador;
            vector <char> x = {'X', 'O'};
            cout << "\nJogador " << jogador << " (" << x[jogador - 1] << "), escolha uma posição:";
            
            char a; cin >> a;
            while (!grid.validar(a)) {
                cout << "Posição inválida ou já ocupada. Tente novamente: ";
                cin >> a;
            }
            grid.alterar(a, jogador);
            cout << "\n"; grid.exiba();
            linha();

            p ++;
            if (grid.win()) {
                cout << "\nParabéns! Jogador " << jogador << " venceu!\n";
                cout << "Vocês querem jogar novamente? [S/N]";
                cin >> f;

                while (f != 'S' && f != 'N' && f != 's' && f != 'n') {
                    cout << "Erro, tente uma opção válida [S/N]: ";
                    cin >> f;
                }

            }
            if (!grid.win() && p == 9) {
                cout << "\nEmpate! Ninguém ganhou!\n";
                cout << "Vocês querem jogar novamente? [S/N]";
                cin >> f;

                while (f != 'S' && f != 'N' && f != 's' && f != 'n') {
                    cout << "Erro, tente uma opção válida [S/N]: ";
                    cin >> f;
                }
            }
        }

        if (f == 'n' || f == 'N') {
            cout << "Voltem sempre!";
            break;
        }
    }
}
