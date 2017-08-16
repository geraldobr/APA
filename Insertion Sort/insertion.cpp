#include <iostream>
#include <time.h>

using namespace std;

int insertionSort(int arr[]);
void show(int arr[]);

const int TAM_ARRAY = 10;

int main(void){
    
    srand(0);

    int arr[TAM_ARRAY], l = TAM_ARRAY;
    for(int i=0;i<TAM_ARRAY;i++){
        arr[i] = rand()%100;
    }

    cerr << "Caso Aleatório" << endl;
    show(arr);
    cerr << " - Número de Passos:   " << insertionSort(arr) << endl; // Caso Aleatório
    show(arr);

    int arrr[] = {1, 4, 6, 8, 2, 7, 5, 15, 13, 11};

    cerr << "Caso Não Aleatório" << endl;
    show(arrr);
    cerr << " - Número de Passos:  " << insertionSort(arrr) << endl; // Caso Aleatório
    show(arrr);

    for(int j=0;j<TAM_ARRAY;j++){
        arr[j] = j;
    }

    cerr << "Melhor Caso" << endl;
    show(arr);
    cerr << " - Número de Passos: " << insertionSort(arr) << endl; // Melhor Caso
    show(arr);

    for(int k=0;k<TAM_ARRAY;k++){
        arr[k] = l;
        l--;
    }

    cerr << "Pior Caso" << endl;
    show(arr);
    cerr << " - Número de Passos: " << insertionSort(arr) << endl; // Pior Caso
    show(arr);

    return 0;
}

int insertionSort(int arr[]){
    int posAtual=0,j, numPassos=0;
    for(int i=1; i<TAM_ARRAY; i++){
        posAtual = arr[i];              // - Posição atual atualizada
        j = i-1;                        // - selecionamos o J na posição anterior
        while(j>=0 && arr[j]>posAtual){ // - Iniciamos as comparações
            arr[j+1] = arr[j];          //   de cada iteração do while
            j--;                        //   caso seja menor, atualiza a posição
            numPassos++;                //   e decrementa o J
        }                               
        arr[j+1] = posAtual;            // - Atualizamos a posição Atual
    }
    return numPassos;
}

void show(int arr[]){
    
    for(int i=0; i<TAM_ARRAY; i++){
        cerr << arr[i] << " ";
    }
    cerr << endl;
}