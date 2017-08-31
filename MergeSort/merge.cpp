#include <iostream>
#include <time.h>

using namespace std;

void merge(int *vet, int com, int meio, int fim);
void mergeSort(int *vet, int com, int fim);
void show(int a[]);

int tam = 10;
int cont=0;

int main(void){
	srand(time(NULL));
    int x=10, vet[tam];
    cout << " - - - Vetor totalmente Desordenado - - -" << endl;
    for(int i=0; i<tam; i++){
        vet[i] = x;
        x--;
        cout << vet[i] << " ";
    }
    cout << endl;

    mergeSort(vet,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(vet);

    cout << " - - - Vetor já Ordenado - - -" << endl;
    cont=0;
    for(int i=0; i<tam; i++){
        vet[i] = i;
        cout << vet[i] << " ";
    }
    cout << endl;

    mergeSort(vet,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(vet);

    cout << " - - - Vetor Aleatório - - -" << endl;
    cont=0;
    for(int i=0; i<tam; i++){
        vet[i] = rand()%100;
        cout << vet[i] << " ";
    }
    cout << endl;

    mergeSort(vet,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(vet);

    cout << " - - - Vetor não aleatório - - -" << endl;
    cont=0;
    int vet2[] = {87, 64, 57, 92, 9, 12, 36, 75, 85, 10};
    cout << endl;
    show(vet2);
    mergeSort(vet2,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(vet2);

    return 0;
}

void mergeSort(int *vet, int com, int fim){
    cont++;
    if(com < fim){
        int meio = (fim+com)/2;

        mergeSort(vet,com,meio);
        mergeSort(vet,meio+1,fim);
        merge(vet,com,meio,fim);
    }
}

void merge(int *vet, int com, int meio, int fim){
    int lim1 = com, lim2 = meio+1, limAux = 0;
    int vetAux[fim-com+1];

    while(lim1 <= meio && lim2 <= fim){
        if(vet[lim1] <= vet[lim2]){
            vetAux[limAux] = vet[lim1];
            lim1++;
        }else{
            vetAux[limAux] = vet[lim2];
            lim2++;
        }
        limAux++;
    }

    while(lim1 <= meio){
        vetAux[limAux] = vet[lim1];
        limAux++; lim1++;
    }

    while(lim2 <= fim){
        vetAux[limAux] = vet[lim2];
        limAux++; lim2++;
    }

    for(limAux = com; limAux<=fim; limAux++){
        vet[limAux] = vetAux[limAux-com];
    }

}

void show(int a[]){
    for(int i=0; i<tam; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}