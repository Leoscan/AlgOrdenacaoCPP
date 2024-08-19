#include <iostream>
#include <vector>
#include <ctime> 
// #include <fstream> Log File
#include "Ordenador.hpp"

using namespace std;

class MergeSort : public Ordenador
{
private:
    void merge(vector<int>& arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int left, int right)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

public:
    vector<int> ordenador(vector<int> valores) override
    {
        /* Log File
        ofstream logFile("logMergeSort.txt");
        logFile << "Primeiros 100 números antes de ordenar:\n";
        for (int i = 0; i < 100 && i < valores.size(); i++) {
            logFile << valores[i] << " ";
        }
        logFile << "\n\n";
        logFile << "Primeiros 100 números depois de ordenar:\n";
        for (int i = 0; i < 100 && i < valores.size(); i++) {
            logFile << valores[i] << " ";
        }
        logFile << "\n\n";
        */

        clock_t start = clock();
        mergeSort(valores, 0, valores.size() - 1);
        clock_t end = clock();


        // Tempo em (ms)
        double tempo = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        printf("Tempo Total para ordenar (ms): %.2f ms\n", tempo);

        return valores;
    }
};
