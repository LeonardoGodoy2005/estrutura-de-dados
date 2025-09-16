#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TrocarElemento(int * A, int *B);
int Participacao(int * V, int Inf, int Sup);
void QuickSort(int * V, int Inf, int Sup);
void ExibirVetor(int * V, int N);

void InsertionSort(int * V, int N);

#define TAMANHO 100000

int main(){

    int Conjunto[TAMANHO];

    for(int i = 0; i < TAMANHO; i++) Conjunto[i] = rand() % 1000;

    clock_t T0 = clock();
    QuickSort(Conjunto, 0, TAMANHO - 1);
    clock_t TF = clock();
        ExibirVetor(Conjunto, TAMANHO);

    printf("Tempo de CPU: %f\n", (double)(TF - T0)/CLOCKS_PER_SEC);


    int Vetor[] = {3, 6, 4, 5, 1, 7, 2};
    int Tamanho = sizeof(Vetor) / sizeof(int);
    QuickSort(Vetor, 0, Tamanho - 1);
    ExibirVetor(Vetor, Tamanho);
}

void TrocarElemento(int * A, int * B){

    int temp = *A;
    *A = *B;
    *B = temp;
}

int Participacao(int * V, int inf, int Sup){

    int Pivot = V[(inf + Sup) / 2]; 
    int i = inf;
    int j = Sup;

    while (i <= j) {
        while(V[i] < Pivot) i++;
        while(V[j] > Pivot) j--;
        if(i <= j) {
            TrocarElemento(&V[i], &V[j]);
            i++;
            j--;
        }
    }
    //for (int p = 0; p < i; p++) printf("%d\t", V[i]);
    //printf("\n[%d\n]", V[i]);
    //for (int q = i + 1; q <= Sup; q++)printf("%d\t", V[q]);
     
     
     return i;
}

void QuickSort(int * V, int Inf, int Sup){
     if (Inf < Sup) {
        int P = Participacao(V, Inf, Sup);
        QuickSort(V, Inf, P - 1);
        QuickSort(V, P, Sup);
     }

}

void ExibirVetor(int * V, int N) {
    for (int i = 0; i < N; i++) printf("%d\t", V[i]);
    printf("\n");
}

void InsertionSort(int *V, int N){

    int Chave;
    int i;
    int j;

    for(i = 1; i < N; i++) {

        Chave = V[i];
        j = i - 1;

        while(j >= 0 && V[j] > Chave){
            V[j + 1] = V[j];
            j--;
        }

        V[j + 1] = Chave;
    }
}