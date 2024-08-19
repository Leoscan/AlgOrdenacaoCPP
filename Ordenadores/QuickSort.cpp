#include <iostream>
#include <vector>
#include <ctime> 
#include <omp.h>
#include "Ordenador.hpp"

using namespace std;

class QuickSort : public Ordenador
{
private:
    int partition(vector<int>& arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(vector<int>& arr, int low, int high)
    {
        if (low < high) {
            int pi = partition(arr, low, high);            
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

public:
    vector<int> ordenador(vector<int> valores) override
    {
        int n = valores.size();

        clock_t start = clock();
        quickSort(valores, 0, n - 1);
        clock_t end = clock();

        double tempo = 1000.0 * (end - start) / CLOCKS_PER_SEC;            
        printf("Tempo de execução: %f ms\n", tempo);
    
        return valores;
    }
};
