#include <iostream>
#include <cstdio>
using namespace std;

void exibirjogo (int lin, int col, int jogo[6][7]){
  for (lin = 0; lin < 6; lin++){
      if (lin == 0){
      cout << "\n";}
      if (lin != 0 ){
      cout << "\n-------------\n";}
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

void jogadajog1 (int lin,int jog1col, char jog1nome [64], int jogo[6][7], bool *error1){
  
    cout << jog1nome << " : Escolha a coluna que você quer marcar: ";
    cin >> jog1col;
    if (jog1col > 7 || jog1col < 0 || jogo[0][jog1col] == 1 || jogo[0][jog1col] == 2){
      cout << "Posição invalida!!!\n";
      *error1 = true;
      
    }
    else {
      for (lin = 0;lin<6;lin++){
        if (jogo[lin][jog1col-1] == 1 || jogo[lin][jog1col-1] == 2){
          jogo[lin-1][jog1col-1] = 1;
          break;
        }

        else if (lin == 5) {
          jogo[lin][jog1col-1] = 1;
          break;
        }
      }

    }
}

void jogadajog2 (int lin,int jog2col, char jog1nome [64], int jogo[6][7], bool *error2){
  
    cout << jog1nome << " : Escolha a coluna que você quer marcar: ";
    cin >> jog2col;
    if (jog2col > 7 || jog2col < 1 || jogo[0][jog2col] == 1 || jogo[0][jog2col] == 2){
      cout << "Posição invalida!!!\n";
      *error2 = true;
      
    }
    else {
      for (lin = 0;lin<6;lin++){
        if (jogo[lin][jog2col-1] == 1 || jogo[lin][jog2col-1] == 2){
          jogo[lin-1][jog2col-1] = 2;
          *error2 = false;
          break;
        }

        else if (lin == 5) {
          jogo[lin][jog2col-1] = 2;
          *error2 = false;
          break;
        }
      }

    }
}

void condvitoria1(bool *win1, int jogo[6][7]){
  int linha = 0, coluna = 0, n = 0,  jogadas_seguidas_diagonais = 0;
  
  for (coluna = 0; coluna < 6; coluna++){
    if (
    (
    jogo[0][coluna] == 1 && 
    jogo[1][coluna] == 1 &&
    jogo[2][coluna] == 1 &&
    jogo[3][coluna] == 1)||
    (
    jogo[1][coluna] == 1 && 
    jogo[2][coluna] == 1 &&
    jogo[3][coluna] == 1 &&
    jogo[4][coluna] == 1)||
    (
    jogo[2][coluna] == 1 && 
    jogo[3][coluna] == 1 &&
    jogo[4][coluna] == 1 &&
    jogo[5][coluna] == 1)
    )
    {
      *win1 = true;
       
       goto saida;
    }
  }

  for (linha = 0; linha < 6; linha++){
    if (
    (
    jogo[linha][0] == 1 && 
    jogo[linha][1] == 1 &&
    jogo[linha][2] == 1 &&
    jogo[linha][3] == 1)||
    (
    jogo[linha][1] == 1 && 
    jogo[linha][2] == 1 &&
    jogo[linha][3] == 1 &&
    jogo[linha][4] == 1)||
    (
    jogo[linha][2] == 1 && 
    jogo[linha][3] == 1 &&
    jogo[linha][4] == 1 &&
    jogo[linha][5] == 1)||
    (
    jogo[linha][3] == 1 && 
    jogo[linha][4] == 1 &&
    jogo[linha][5] == 1 &&
    jogo[linha][6] == 1)
    )
    {
      *win1 = true;
       
       goto saida;
    }
  }


// CONDIÇÃO DIAGONAL 1
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 2-n, coluna = 0;linha <6; linha++, coluna++){
    if (jogo[linha][coluna] == 1 && (jogo[linha-1][coluna-1] == 1 || jogo[linha+1][coluna+1] == 1) ){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win1 = true;
       
       goto saida;
  }
  }
  }
// CONDIÇÃO DIAGONAL 2
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 0, coluna = 1+n;coluna <7; linha++, coluna++){
    if (jogo[linha][coluna] == 1 && (jogo[linha-1][coluna-1] == 1 || jogo[linha+1][coluna+1] == 1)){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win1 = true;
       
       goto saida;
  }
  }
  }
// CONDIÇÃO DIAGONAL 3
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 2-n, coluna = 6; linha <6; linha++, coluna--){
    if (jogo[linha][coluna] == 1 && (jogo[linha+1][coluna-1] == 1 || jogo[linha-1][coluna+1] == 1)){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win1 = true;
       
       goto saida;
  }
  }
  }
// CONDIÇÃO DIAGONAL 4
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 0, coluna = 5-n; coluna >=0; linha++, coluna--){
    if (jogo[linha][coluna] == 1 && (jogo[linha+1][coluna-1] == 1 || jogo[linha-1][coluna+1] == 1)){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win1 = true;
       
       goto saida;
  }
  }
  }
  saida:;
}

  void condvitoria2(bool *win2, int jogo[6][7]){
    int linha = 0, coluna = 0, n = 0, jogadas_seguidas_diagonais = 0;
  
  for (coluna = 0; coluna < 6; coluna++){
    if (
    (
    jogo[0][coluna] == 2 && 
    jogo[1][coluna] == 2 &&
    jogo[2][coluna] == 2 &&
    jogo[3][coluna] == 2)||
    (
    jogo[1][coluna] == 2 && 
    jogo[2][coluna] == 2 &&
    jogo[3][coluna] == 2 &&
    jogo[4][coluna] == 2)||
    (
    jogo[2][coluna] == 2 && 
    jogo[3][coluna] == 2 &&
    jogo[4][coluna] == 2 &&
    jogo[5][coluna] == 2)
    )
    {
      *win2 = true;
       goto saida;
    }
  }

  for (linha = 0; linha < 6; linha++){
    if (
    (
    jogo[linha][0] == 2 && 
    jogo[linha][1] == 2 &&
    jogo[linha][2] == 2 &&
    jogo[linha][3] == 2)||
    (
    jogo[linha][1] == 2 && 
    jogo[linha][2] == 2 &&
    jogo[linha][3] == 2 &&
    jogo[linha][4] == 2)||
    (
    jogo[linha][2] == 2 && 
    jogo[linha][3] == 2 &&
    jogo[linha][4] == 2 &&
    jogo[linha][5] == 2)||
    (
    jogo[linha][3] == 2 && 
    jogo[linha][4] == 2 &&
    jogo[linha][5] == 2 &&
    jogo[linha][6] == 2)
    )
    {
      *win2 = true;
       
       goto saida;
    }
  }

  // CONDIÇÃO DIAGONAL 1
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 2-n, coluna = 0;linha <6; linha++, coluna++){
    if (jogo[linha][coluna] == 1 && (jogo[linha-1][coluna-1] == 1 || jogo[linha+1][coluna+1] == 1) ){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win2 = true;
       
       goto saida;
  }
  }
  }
// CONDIÇÃO DIAGONAL 2
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 0, coluna = 1+n;coluna <7; linha++, coluna++){
    if (jogo[linha][coluna] == 1 && (jogo[linha-1][coluna-1] == 1 || jogo[linha+1][coluna+1] == 1)){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win2 = true;
       
       goto saida;
  }
  }
  }
// CONDIÇÃO DIAGONAL 3
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 2-n, coluna = 6; linha <6; linha++, coluna--){
    if (jogo[linha][coluna] == 1 && (jogo[linha+1][coluna-1] == 1 || jogo[linha-1][coluna+1] == 1)){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win2 = true;
       
       goto saida;
  }
  }
  }
// CONDIÇÃO DIAGONAL 4
  for (n=0; n<3;n++){
    jogadas_seguidas_diagonais = 0;
  for (linha = 0, coluna = 5-n; coluna >=0; linha++, coluna--){
    if (jogo[linha][coluna] == 1 && (jogo[linha+1][coluna-1] == 1 || jogo[linha-1][coluna+1] == 1)){
        jogadas_seguidas_diagonais ++;
      }
    
    if (jogadas_seguidas_diagonais == 4){
       *win2 = true;
       
       goto saida;
  }
  }
  }



  saida:;
}

int main() {
  int lin = 0,col = 0;
  int jogo [6][7];
  int op_ini;
  bool error1 = false;
	bool error2 = false;
  bool win1 = false;
  bool win2 = false;
  int jog1col = 0;
  int jog2col = 0;

  char jog1nome [64];
	char jog2nome [64];

  

  

  while (op_ini != 2){
    cout << "BEM VINDO AO LIG4\n" << "--------------------------\n" << "POR FAVOR DIGITE\n\n" << "1 - Jogar\n2 - Sair\n\n";

    cin >> op_ini;
    
    if (op_ini == 1){

      error1 = false;
	    error2 = false;
      win1 = false;
      win2 = false;

    for (lin = 0; lin < 6; lin++){
    for (col = 0; col < 7; col++){
      jogo[lin][col] = 0;
    }
  }
    cout << "\nDigite seu nome Jogador 1: ";
    cin >> jog1nome;
    cout << "Digite seu nome Jogador 2: ";
    cin >> jog2nome;
    cout << "\n";
    cout << jog1nome << " Marcará X\n";
    cout << jog2nome << " Marcará O\n\n";

    while (1){
    exibirjogo(lin,col,jogo);
    
    jogadajog1(lin,jog1col, jog1nome, jogo, &error1);

    if (error1 == true){
      while (error1 != false){
      error1 = false;
      jogadajog1(lin,jog1col, jog1nome, jogo, &error1);
    }
    }

    condvitoria1(&win1, jogo);
    if (win1 == true) {
      cout << "Jogador " << jog1nome << " Venceu!\n\n";
      exibirjogo(lin,col,jogo);
      cin.ignore();
      cin.get();
      break;
    }
    exibirjogo(lin,col,jogo);
    jogadajog2(lin,jog2col, jog2nome, jogo, &error2);

    if (error2 == true){
      while (error2 != false){
      error2 = false;
      jogadajog2(lin,jog2col, jog2nome, jogo, &error2);
    }
    }

    condvitoria2(&win2, jogo);
    if (win2 == true) {
      cout << "Jogador " << jog1nome << " Venceu!\n\n";
      exibirjogo(lin,col,jogo);
      cout << "\nPressione qualquer tecla para continuar\n";
      cin.ignore();
      cin.get();
      break;
    }

    }
  }
}

 cout << "\nObrigado por usar esse programa - Autoria : Luciano Pereira\n";
}