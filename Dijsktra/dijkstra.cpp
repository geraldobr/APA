#include <iostream>
#include <fstream>
#include "heap.hpp"

using namespace std;

void showVec(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << endl;
}

int main(){
    int dimension;
    ifstream in("instancias/dij10.txt");
    if(!in){
        cout << "impossivel abrir arquivo." << endl;
    }

    in >> dimension;
    cout << "dimension: "<< dimension << endl;

    int adj[dimension][dimension];
    for(int i=0; i<dimension ; i++){
        for(int j=i+1; j<dimension; j++){
            in >> adj[i][j];
            adj[j][i] = adj[i][j];
        }
    }
    
    for(int i=0; i<dimension ; i++){
        adj[i][i] = 0;
    }

    in.close();
    
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // ---------------------------------
    const int INITIAL_NODE = 0;
    int NODE = INITIAL_NODE, extractNode;
    int found;
    vector<int> caminho;

    bool visited[dimension];

    for(int i=0;i<dimension; i++){
        visited[i] = false;
    }

    caminho.push_back(INITIAL_NODE);
    visited[INITIAL_NODE] = true;

    heapMin heapDij;
    heapDij.tamanhoHeap = dimension-1;

    // ---------------------------------
    while(heapDij.tamanhoHeap != 0){
        for(int i=0;i<dimension; i++){
            if(adj[NODE][i] !=0 && visited[i] == false)
                heapDij.heap.push_back(adj[NODE][i]);
        }
        cout << "HEAP:" << endl;
        buildHeapify(&heapDij);

        found = -1;
        for(int i=0; i<dimension; i++){
            if(heapDij.heap[0] == adj[NODE][i])
                found = i;
        }
        extractNode = heapExtractMin(&heapDij);

        caminho.push_back(found);
        visited[found] = true;
        show(heapDij);

        
        heapDij.heap.clear();
        NODE = found;
        cout << "Caminho: " << endl;
        showVec(caminho);
    }

    return 0;
}