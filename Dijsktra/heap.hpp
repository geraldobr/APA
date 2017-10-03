#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct {
    vector<int> heap;
    int tamanhoHeap;
}heapMin;

int pai(int i) { return ceil(i/2)-1; }
int esq(int i) { return 2*i+1; }
int dir(int i) { return 2*i+2; }

void show(heapMin x){ for(int i=0; i<x.tamanhoHeap; i++) cout << x.heap[i] << " "; cout << endl; }

void minHeapify(heapMin *x, int i){
    int l = esq(i), r = dir(i);
    int menor=999, aux;
    if(l < x->tamanhoHeap && x->heap[l] < x->heap[i])
        menor = l;
    else
        menor = i;
    if (r < x->tamanhoHeap && x->heap[r] < x->heap[menor]) {
        menor = r;
    }
    if(menor!=i){
        aux = x->heap[i];
        x->heap[i] = x->heap[menor];
        x->heap[menor] = aux;
        minHeapify(x,menor);
    }
}

void buildHeapify(heapMin *x){
    for(int i=(x->tamanhoHeap/2)-1; i>=0; i--){
        minHeapify(x,i);
    }
}

int heapExtractMin(heapMin *x){
    if(x->tamanhoHeap < 1)
        cout << "tamanho da heap invalido!" << endl;
    int min = x->heap[0];
    x->heap[0] = x->heap[x->tamanhoHeap-1];
    x->tamanhoHeap--;
    minHeapify(x,0);
    return min;
}

void decreaseKey(heapMin *x, int i, int key){
    int aux;
    if(key>x->heap[i]){
        cout << "valor menor!!!" << endl;
    } else {
        x->heap[i] = key;
        while(i>0 && x->heap[pai(i)] > x->heap[i]){
            aux = x->heap[pai(i)];
            x->heap[pai(i)] = x->heap[i];
            x->heap[i] = aux;
            i = pai(i);
        }
    }

}

// int main (void){
//     heapMin x;
//     x.heap.push_back(9);
//     x.heap.push_back(6);
//     x.heap.push_back(4);
//     x.heap.push_back(5);
//     x.heap.push_back(8);
//     x.heap.push_back(1);
//     x.tamanhoHeap = x.heap.size();
//     show(x);
//     cout << "tamanhoHeap: " << x.tamanhoHeap << endl;
//     buildHeapify(&x);
//     show(x);
//     cout << "Menor Valor: " << heapExtractMin(&x) << endl;
//     show(x);
//     decreaseKey(&x,3, 0);
//     show(x);
//     return 0;
// }
