#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t){
    {t < t} -> convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(vector<T>& v){
    const unsigned int n = v.size();

    for(unsigned int i = 0; i < n-1; i++){
        for(unsigned int j = i+1; j < n; j++){
            if(v[j]<v[i]){
                // swap
                T tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}


// ordina gli alberi ogni volta che viene chiamata 
template<Sortable T>
void OrdinaAlbero(vector<T>& v, const unsigned int n, const int i){
    int piuGrande = i;
    int sinistra = 2*i + 1;
    int destra = 2*i + 2;

    if(destra < n && v[destra]>v[piuGrande]){
        piuGrande = destra;
    }

    if(sinistra < n && v[sinistra]>v[piuGrande]){
        piuGrande = sinistra;
    }

    // se la foglia sotto era effettivamente più grande
    if(piuGrande != i){
        // faccio lo swap
        T tmp = v[i];
        v[i] = v[piuGrande];
        v[piuGrande] = tmp;

        // chiamo OrdinaAlbero ricorsivamente
        OrdinaAlbero(v, n, piuGrande);
    }
}


template<Sortable T>
void HeapSort(vector<T>& v){
    
    const unsigned int n = v.size();
    vector<T> v1(v); // faccio una copia

    // costruisco il maxheap, prendo le i partendo dalle foglie arrivando a metà
    for(int i = n/2 - 1; i >= 0; i--){
        OrdinaAlbero(v,n,i);
    }


    // estraggo gli elementi dall'heap
    for(int i = n-1; i>0; i--){
        // faccio lo swap del più grande con l'ultimo elemento
        
        T tmp = v[i];
        v[i] = v[0];
        v[0] = tmp;

        // ripristino il maxheap, dopo aver modificato l'albero
        OrdinaAlbero(v,i,0);

    }   
}


}


