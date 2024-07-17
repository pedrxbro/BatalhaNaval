#include <iostream>
using namespace std;
#include <stdlib.h>  
#include <time.h>       
#include <windows.h>

#define TAM 5
#define NAV 2
#define SHOT 2

void printarMatriz(int matriz[TAM][TAM]){
    cout << "    ";
    for(int x = 0; x < TAM; x++)
        cout << x+1 << " ";
    cout << endl;
    for(int i = 0 ; i < TAM; i++){
        cout << i + 1 << " - ";
        for(int j = 0; j < TAM; j++){
            if(matriz[i][j] == -1)
                cout << "~ ";
            if(matriz[i][j] == 0)
                cout << "X ";
            if(matriz[i][j] == 1)
                cout << "0 ";
        }   cout << endl;
    }
cout << "Legenda: '~' = Agua, 'X' = Acertou o navio, '0' = Atirou e errou.";
}

int retornaRandom(){
    int random = rand()%TAM; // vai usar uma função para randomizar a posição dos navios.
    return random;
}

void retornaDica(int shot[SHOT], int nav1[NAV], int nav2[NAV], int nav3[NAV]){
    int contLinha = 0;
    int contColuna = 0;
    string dica;

    if(shot[0] == nav1[0])
        contLinha++;
    if(shot[1] == nav1[1])
        contColuna++;
    if(shot[0] == nav2[0])
        contLinha++;
    if(shot[1] == nav2[1])
        contColuna++;
    if(shot[0] == nav3[0])
        contLinha++;
    if(shot[1]== nav3[1])
        contColuna++;
      
    
    cout << "Nessa linha temos " << contLinha << " navios. E na coluna temos " << contColuna << " navios.";
}

int main()
{
    
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int naviosAcertados = 0;
    int matriz[TAM][TAM];
    int navio1[NAV];
    int navio2[NAV];
    int navio3[NAV];
    int shot[SHOT];
    int contador = 0;
    bool iguais = false;
    bool jogadorVenceu = false;

    //Randomizar a posição i e j dos navios.
    navio1[0] = retornaRandom();
    navio1[1] = retornaRandom();

    navio2[0] = retornaRandom();
    navio2[1] = retornaRandom();

    navio3[0] = retornaRandom();
    navio3[1] = retornaRandom();


    while(iguais == false) //se a posiçao i e j do navio forem iguais, gera outro valor.
    {
        iguais = true;
        if(navio1[0] == navio2[0])
        {
            if(navio1[1] == navio2[1])  
            {
                iguais = false;
                navio2[0] = retornaRandom();
                navio2[1] = retornaRandom();
            }
        }

        if(navio1[0] == navio3[0])
        {
            if(navio1[1] == navio3[1])
            {
                iguais = false;
                navio3[0] = retornaRandom();
                navio3[1] = retornaRandom();
            }
        }

        if(navio2[0] == navio3[0])
        {
            if(navio2[1] == navio3[1])
            {
                iguais = false;
                navio3[0] = retornaRandom();
                navio3[1] = retornaRandom();
            }
        }
    }
    //Inicializar a matriz com valores correspondentes à agua.
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            matriz[i][j] = -1;
        }
    }
    //printar os navios para testar (apagar)
    //cout << navio1[0] << " " << navio1[1] << endl; 
    //cout << navio2[0] << " " << navio2[1] << endl;
    //cout << navio3[0] << " " << navio3[1] << endl;

    while((contador <= 20) && jogadorVenceu == false){ // Número máximo de jogadas = 20 ou jogador acertar os 3 navios.

        printarMatriz(matriz);
        cout << endl;

        //Verificamos a entrada do jogador
         do {
        cout << "Entre com a linha do seu tiro (min. 1, max. 5): ";
        cin >> shot[0];
        shot[0]--; //Decrementar a entrada do jogador*

        cout << "Entre com a coluna do seu tiro (min. 1, max. 5): ";
        cin >> shot[1];
        shot[1]--; //Decrementar a entrada do jogador*

        //*Usuário vai inserir um valor ''humano'' e vamos trazer para um valor de ''máquina''. 

        if ((shot[0] > 4 || shot[0] < 0) || (shot[1] > 4 || shot[1] < 0)) { //evitar valores incorretos. 
            cout << "Valor incorreto" << endl;
        }

    } while ((shot[0] > 4 || shot[0] < 0) || (shot[1] > 4 || shot[1] < 0));
    
        //Verificamos a jogada 
        //Para navio 1
     if(matriz[shot[0]][shot[1]] != -1){ //se o usuário atirar e for diferente de água (navio abatido/tiro repetido), a jogada foi inválida. 
        system("cls");
        cout << "Jogada inválida" << endl;
        system("pause");
     }
     else
     {   if((shot[0] == navio1[0]) && (shot[1] == navio1[1])) //se a posição i e j do tiro corresponder ao i e j do navio, jogador acertou. 
        {
            matriz[navio1[0]][navio1[1]] = 0; //muda para 0, ou seja, acertou o navio e a matriz atualizou para X. 
            naviosAcertados++;
            system("cls");
            cout << "jogador Acertou!!";
            system("pause");
        }
        else if((shot[0] == navio2[0]) && (shot[1] == navio2[1])) //se a posição i e j do tiro corresponder ao i e j do navio, jogador acertou.
        {
            matriz[navio2[0]][navio2[1]] = 0; //muda para 0, ou seja, acertou o navio e a matriz atualizou para X. 
            naviosAcertados++;
            system("cls");
            cout << "jogador Acertou!!";
            system("pause");
        }
        else if((shot[0] == navio3[0]) && (shot[1] == navio3[1])) //se a posição i e j do tiro corresponder ao i e j do navio, jogador acertou.
        {
            matriz[navio3[0]][navio3[1]] = 0; //muda para 0, ou seja, acertou o navio e a matriz atualizou para X. 
            naviosAcertados++;
            system("cls");
            cout << "jogador Acertou!!";
            system("pause");
        }
        else{ // se nada corresponder, errou. 
            system("cls");
            cout << "jogador Errou!!";
            matriz[shot[0]][shot[1]] = 1; //atualizou para 1, ou seja, errou o tiro e virou 0 no tabuleiro. 
            system("pause");
            retornaDica(shot, navio1, navio2, navio3);
            system("pause");
        }
    }

        system("cls");

        if(naviosAcertados == 3) //sempre que o jogador acerta, incrementa em um a variável naviosAcertados, se chegar a 3, o jogador vence.
        {
            system("cls");
            cout << "Parabens, Jogador Venceu!!!";
            jogadorVenceu = true;
        }
        contador++; // quando acabar o loop, adiciona uma jogada para o contador.

        if(contador >= 20) //
        {
            system("cls");
            cout << "Acabou. Jogador excedeu número de jogadas";
            system("pause");
            
            return 0;
        }
    }

}
