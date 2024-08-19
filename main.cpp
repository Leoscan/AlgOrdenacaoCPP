#include <iostream>
#include <vector>
#include <ctime>
#include "Ordenadores/MergeSort.cpp"
#include "Ordenadores/MergeSortParalelo.cpp"
#include "Ordenadores/QuickSortParalelo.cpp"
#include "Ordenadores/QuickSort.cpp"


using namespace std;

int main()
{
    Ordenador* ordenador = new MergeSort();
    //Ordenador* ordenador = new MergeSortParalelo();
    // Ordenador* ordenador = new QuickSortParalelo();
    // Ordenador* ordenador = new QuickSort();

    const int SIZE = 100000;
    vector<int> inteiros(SIZE);

    srand(time(NULL));    
    for (int i = 0; i < SIZE; i++) {
        inteiros[i] = rand() % SIZE;
    }

    ordenador->ordenador(inteiros);

    delete ordenador;

    return 0;
}
