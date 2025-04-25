#include <cmath>
#include <iostream>
#include <numeric>
#include <iostream>
#include <sstream>
#include <chrono>

#include "SortingAlgorithm.hpp"
using namespace std;


// stampa i vettori su terminale
template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

int main()
{
    size_t m = 10;
    cout << "lunghezza del vettore = " << m << endl;

    
    // DEFINISCO I TRE VETTORI

    vector<int> v1(m);
    iota(v1.begin(), v1.end(), -4);

    //cout << "v1: " << endl;
    //cout << ArrayToString(v1) << endl;

    srand(2);
    vector<double> v2(m);
    for(size_t i = 0; i < m; i++){
        v2[i] = rand() / ((double)RAND_MAX);
    }

    //cout << "v2: " << endl;
    //cout << ArrayToString(v2) << endl;

    vector<int> v3(m, 0);
    for(size_t i = floor(m * 0.5) + 1; i < m; i++){
        v3[i] = rand() % 1000;
    }

    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());

    //cout << "v3: " << endl;
    //cout << ArrayToString(v3) << endl;




    // INIZIO A ORDINARE CON IL BUBBLE SORT

    unsigned int numero_iterate = 100;

    
    double tempo_trascorso_bubble_v1 = 0.0;
    for(unsigned int t = 0; t<numero_iterate; t++){

        vector<int> v(v1); //costruttore di copia, crea una copia indipendente

        chrono::steady_clock::time_point tempo_inizio = chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        chrono::steady_clock::time_point tempo_fine = chrono::steady_clock::now();

        tempo_trascorso_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(tempo_fine - tempo_inizio).count();
    }
    tempo_trascorso_bubble_v1 /= numero_iterate;

    cout << "Bubble Sort - v1: " << tempo_trascorso_bubble_v1 << endl;


    double tempo_trascorso_bubble_v2 = 0.0;
    for(unsigned int t = 0; t<numero_iterate; t++){

        vector<double> v(v2); //costruttore di copia, crea una copia indipendente

        chrono::steady_clock::time_point tempo_inizio = chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        chrono::steady_clock::time_point tempo_fine = chrono::steady_clock::now();
        
        tempo_trascorso_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(tempo_fine - tempo_inizio).count();
    }
    tempo_trascorso_bubble_v2 /= numero_iterate;

    cout << "Bubble Sort - v2: " << tempo_trascorso_bubble_v2 << endl;


    double tempo_trascorso_bubble_v3 = 0.0;
    for(unsigned int t = 0; t<numero_iterate; t++){

        vector<int> v(v3); //costruttore di copia, crea una copia indipendente

        chrono::steady_clock::time_point tempo_inizio = chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        chrono::steady_clock::time_point tempo_fine = chrono::steady_clock::now();

        tempo_trascorso_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(tempo_fine - tempo_inizio).count();
    }
    tempo_trascorso_bubble_v3 /= numero_iterate;

    cout << "Bubble Sort - v3: " << tempo_trascorso_bubble_v3 << endl;



    // ORA ORDINO CON L'HEAPSORT

    double tempo_trascorso_heap_v1 = 0.0;
    for(unsigned int t = 0; t<numero_iterate; t++){

        vector<int> v(v1); //costruttore di copia, crea una copia indipendente

        chrono::steady_clock::time_point tempo_inizio = chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        chrono::steady_clock::time_point tempo_fine = chrono::steady_clock::now();

        tempo_trascorso_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(tempo_fine - tempo_inizio).count();
    }
    tempo_trascorso_heap_v1 /= numero_iterate;

    cout << "Heap Sort - v1: " << tempo_trascorso_heap_v1 << endl;


    double tempo_trascorso_heap_v2 = 0.0;
    for(unsigned int t = 0; t<numero_iterate; t++){

        vector<double> v(v2); //costruttore di copia, crea una copia indipendente

        chrono::steady_clock::time_point tempo_inizio = chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        chrono::steady_clock::time_point tempo_fine = chrono::steady_clock::now();

        tempo_trascorso_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(tempo_fine - tempo_inizio).count();
    }
    tempo_trascorso_heap_v2 /= numero_iterate;

    cout << "Heap Sort - v2: " << tempo_trascorso_heap_v2 << endl;


    double tempo_trascorso_heap_v3 = 0.0;
    for(unsigned int t = 0; t<numero_iterate; t++){

        vector<int> v(v3); //costruttore di copia, crea una copia indipendente

        chrono::steady_clock::time_point tempo_inizio = chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        chrono::steady_clock::time_point tempo_fine = chrono::steady_clock::now();

        tempo_trascorso_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(tempo_fine - tempo_inizio).count();
    }
    tempo_trascorso_heap_v3 /= numero_iterate;

    cout << "Heap Sort - v3: " << tempo_trascorso_heap_v3 << endl;
    
    return 0;
}

