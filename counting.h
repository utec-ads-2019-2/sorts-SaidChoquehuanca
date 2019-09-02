#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>


class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int maximo = *max_element(elements,elements+size);
            int minimo = *min_element(elements,elements+size);
            int rango = maximo-minimo+1;
            int arrayordenado[size];
            int ite[rango];
            for(int i=0;i<rango;i++){
                ite[i] = 0;}
            for(int j=0;j<size;j++){
                ite[elements[j]-minimo]++;
            }for(int k=1;k<=rango;k++){
                ite[k] += ite[k-1];
            }for(int f=size-1;f>=0;f--){
                arrayordenado[ite[elements[f]-minimo]-1]= elements[f];
                ite[elements[f]-minimo]--;
            }for(int y=0;y<size;y++){
                elements[y]=arrayordenado[y];
            }
        }

        inline string name() { return "CountingSort"; }
};

#endif