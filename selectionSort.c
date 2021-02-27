#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarAleatoriamente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = rand();
}

void inicializarOrdemCrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = i;
}

void inicializarOrdemDecrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = n-i;
}

void selection_sort(int vetor[], int n){
    int min, temp;

    for(int i=0; i<n; i++){
        min=i;
        for(int j=i+1; j<n; j++){
            if(vetor[j]<vetor[min]){
                min=j;
            }
        }
        if(vetor[i] != vetor[min]){
            temp=vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=temp;
        }
    }
}

int main(){

    srand(time(NULL)); // gerando valores aleatorios
    double inicio, fim, t_percorrido;
    int N = 100000;
    int v[N];

    //ALEATÓRIO
    inicializarAleatoriamente(v, N); //inicializando o vetor aleatoriamente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	selection_sort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Selection Sort preenchido aleatoriamente: %f\n", t_percorrido);

    //ORDENAÇÃO CRESCENTE
    inicializarOrdemCrescente(v,N); //inicializando o vetor em ordem crescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	selection_sort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Selection Sort preenchido em ordem crescente: %f\n", t_percorrido);

    //ORDENÇÃO DECRESCENTE
    inicializarOrdemDecrescente(v,N); //iniciando o vetor em ordem decrescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	selection_sort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Selection Sort preenchido em ordem decrescente: %f\n", t_percorrido);

    return 0;
}

