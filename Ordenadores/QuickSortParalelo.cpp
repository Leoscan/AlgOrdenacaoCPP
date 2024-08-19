#include <iostream>
#include <vector>
#include <ctime> 
#include <omp.h>
#include "Ordenador.hpp"

using namespace std;

class QuickSortParalelo : public Ordenador
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
            
            #pragma omp parallel sections
            {
                #pragma omp section
                {
                    quickSort(arr, low, pi - 1);
                }
                #pragma omp section
                {
                    quickSort(arr, pi + 1, high);
                }
            }
        }
    }

public:
    vector<int> ordenador(vector<int> valores) override
    {
        const int numThreads[] = {1, 2, 4, 8, 12};
        int n = valores.size();

        for (int i = 0; i < 5; i++) {
            vector<int> valoresCopia = valores; // Faz uma cópia do array original

            int numThread = numThreads[i];
            omp_set_num_threads(numThread);

            clock_t start = clock();
            quickSort(valoresCopia, 0, n - 1);
            clock_t end = clock();

            double tempo = 1000.0 * (end - start) / CLOCKS_PER_SEC;            
            printf("Teste com %d Threads: Tempo de execução: %f ms\n", numThread, tempo);
        }
        return valores;
    }
};
