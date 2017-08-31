#include <iostream>
#include <time.h>

using namespace std;

void swap(int *, int *);
void show(int a[]);
void quickSort(int *arr, int inicio, int fim);

int tam = 10;
static int cont = 0;

int main(void){
    srand(time(NULL));
    int x[tam], j=tam;

    // Caso Aleatório
    cout << " - - - Caso Aleatório - - - " << endl;
    for(int i=0; i<tam; i++){
        x[i] = rand() % 30;
    }

    show(x);
    quickSort(x,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(x);

    // Caso Não Aleatório
    cont=0;
    cout << " - - - Caso não Aleatório - - - " << endl;
    int x1[] = {19,5,2,9,7,6,4,8,12,20};
    show(x1);
    quickSort(x1,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(x1);

    // Melhor Caso (em que o pivô é no meio do array)
    cont=0;
    cout << " - - - Melhor caso - - - " << endl;
    for(int i=0; i<tam; i++){
        x[i] = i;
    }

    show(x);
    quickSort(x,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(x);

    // Pior caso, vetor inverso
    cont=0;
    cout << " - - - Pior caso - - - " << endl;
    for(int i=0; i<tam; i++){
        x[i] = j;
        j--;
    }

    show(x);
    quickSort(x,0,tam-1);
    cout << "Passos: " << cont << endl;
    show(x);


    return 0;
}

void swap(int *a, int *b){
    int *temp = a;
    *a = *b;
    *b = *a;
}

void show(int a[]){
    for(int i=0; i<tam; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void quickSort(int *arr, int inicio, int fim){
    int piv = arr[(int) (inicio+fim)/2], temp;
    int i=inicio, j=fim;
    while(i<=j){
        while(arr[i]<piv){
            i++;
        }
        while(arr[j]>piv){
            j--;
        }
        if(i<=j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; 
            j--;
            cont++;
        }
    };
    if(inicio < j){
        quickSort(arr,inicio,j);
    }
    if(i < fim){
        quickSort(arr,i,fim);
    }
}