#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}
        void merge(int *array,int inicial,int media,int final){
            int n1,n2,i,j,k;
            n1=media-inicial+1;
            n2=final-media;
            int L[n1],R[n2];
            for(i=0;i<n1;i++)
            {
                L[i]=array[inicial+i];
            }
            for(j=0;j<n2;j++)
            {
                R[j]=array[media+j+1];
            }
            i=0,j=0;
            for(k=inicial;i<n1&&j<n2;k++)
            {
                if(L[i]<R[j])
                {
                    array[k]=L[i++];
                }
                else
                {
                    array[k]=R[j++];
                }
            }
            while(i<n1)
            {
                array[k++]=L[i++];
            }
            while(j<n2)
            {
                array[k++]=R[j++];
            }

        }
        int mergesort(int *array,int inicial ,int final){
            int media=(inicial+final)/2;
            if(inicial<final)
            {
                mergesort(array,inicial,media);
                mergesort(array,media+1,final);
                merge(array,inicial,media,final);
            }
            int q;
        }
        void execute() {
            mergesort(elements,0,size-1);
            // TODO
        }

        inline string name() { return "MergeSort"; }
};

#endif