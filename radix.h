#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}
        void countingSort(int array[], int size, int exponente) {

        int salida[size];
        int i, cuenta[10] = {0};
        for (i = 0; i < size; ++i)
            cuenta[(array[i] / exponente) % 10]++;
        for (i = 1; i < 10; i++)
            cuenta[i] += cuenta[i - 1];
        for (i = size - 1; i >= 0; --i) {
            salida[cuenta[(array[i] / exponente) % 10] - 1] = array[i];
            cuenta[(array[i] / exponente) % 10]--;
        }
        for (i = 0; i < size; ++i)
            array[i] = salida[i];

        }
        void execute() {
                int maximo = *max_element(elements,elements+size);
                for (int exponente = 1; maximo/exponente > 0; exponente *= 10){
                    countingSort(elements, size, exponente);
                }

        }

        inline string name() { return "RadixSort"; }
};

#endif