#include <iostream>
#include <cstdio>
using namespace std;

void exibirjogo (int lin, int col, int jogo[6][7]){
  for (lin = 0; lin < 6; lin++){
      if (lin == 0){
      cout << "\n";}
      if (lin != 0 ){
      cout << "\n------------\n";}
    for (col = 0; col<7; col++){
      if (col != 0 ){
      cout << "|";}
      if (jogo[lin][col] == 0){
        cout << " ";
      }

      else if (jogo[lin][col] == 1){
        cout << "X";
      }

      else if (jogo[lin][col] == 2){
        cout << "O";
      }
      
    }
  }
  cout << "\n\n";
}

void jogadajog1 (int jog1col, char jog1nome [64], int jogo[6][7], bool *error1){
  
    cout << jog1nome << " : Escolha a coluna que você quer marcar: ";
    cin >> jog1col;
    if (jog1col > 6 || jog1col < 0){
      cout << "Posição invalida!!!\n";
      *error1 = true;
      
    }
    else {jogo[jog1lin-1][jog1col-1] = 1;}
}

int main() {
  int lin = 0,col = 0;
  int jogo [6][7];
  int op_ini;
  bool error1 = false;
	bool error2 = false;
  int jog1col = 0;
  int jog2col = 0;

  char jog1nome [64];
	char jog2nome [64];

  for (lin = 0; lin < 6; lin++){
    for (col = 0; col < 7; col++){
      jogo[lin][col] = 0;
    }
  }

  while (op_ini != 2){
    cout << "BEM VINDO AO LIG4\n" << "--------------------------\n" << "POR FAVOR DIGITE\n\n" << "1 - Jogar\n2 - Sair\n\n";

    cin >> op_ini;

    if (op_ini == 1){
    cout << "\nDigite seu nome Jogador 1: ";
    cin >> jog1nome;
    cout << "Digite seu nome Jogador 2: ";
    cin >> jog2nome;
    cout << "\n";
    cout << jog1nome << " Marcará X\n";
    cout << jog2nome << " Marcará O\n\n";

    while (1){
    exibirjogo(lin,col,jogo);
    jogadajog1(jog1col, jog1nome, jogo, &error1);
    }
  }
}
}