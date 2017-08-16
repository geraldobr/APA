#include <iostream>
#include <time.h>

using namespace std;

int selection(int arr[]);
void show(int arr[]);
void troca(int *p1, int *p2);

const int tam = 10;

int main(void){
    srand(0);

    int arr[tam], l = tam;
    for(int i=0;i<tam;i++){
        arr[i] = rand()%100;
    }

    cerr << "Caso Aleatório" << endl;
    show(arr);
    cerr << "Número de Passos: " << selection(arr) << endl; // Caso Aleatório
    show(arr);

    int arr2[] = {17, 6, 8, 3, 4, 2, 7, 9, 12, 10};

    cerr << "Caso Não Aleatório" << endl;
    show(arr2);
    cerr << "Número de Passos: " << selection(arr2) << endl; // Caso Aleatório
    show(arr2);

    for(int j=0;j<tam;j++){
        arr[j] = j;
    }

    cerr << "Melhor Caso" << endl;
    show(arr);
    cerr << "Número de Passos: " << selection(arr) << endl; // Melhor Caso
    show(arr);

    for(int k=0;k<tam;k++){
        arr[k] = l;
        l--;
    }

    cerr << "Pior Caso" << endl;
    show(arr);
    cerr << "Número de Passos: " << selection(arr) << endl; // Pior Caso
    show(arr);

    return 0;
}

int selection(int arr[]){
    int numPassos = 0, menor;

    for(int i=0;i<tam;i++){
        menor=i;                    // - Valor atualizado da primeira posição
        for(int j=i+1; j<tam; j++){ // - Inicio do For a procura do menor valor do subcaminho i+1 : final do vetor
            numPassos++;
            if(arr[j] < arr[menor])
                menor = j;
        }
        troca(&arr[menor], &arr[i]); // - Ao encontrar menor valor fazemos a troca das posições
    }
    return numPassos;
}

void show(int arr[]){
    for(int i=0; i<tam; i++){
        cerr << arr[i] << " ";
    }
    cerr << endl;
}

/* 
    Função simples para troca dos valores das posições indicadas
*/
void troca(int *p1, int *p2){
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}