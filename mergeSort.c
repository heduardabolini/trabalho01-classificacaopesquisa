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

void merge(int vec[], int vecSize){
    int mid;
    int i, j,k;
    int* tmp;
    tmp = (int*)malloc(vecSize * sizeof(int));
    if(tmp == NULL){
        exit(1);
    }
    mid = vecSize/2;
    i=0;
    j=mid;
    k=0;
    while(i<mid && j<vecSize){
        if(vec[i]<vec[j]){
            tmp[k] = vec[i];
            ++i;
        }else{
            tmp[k] = vec[j];
            ++j;
        }
        ++k;
    }
    if(i==mid){
        while(j< vecSize){
            tmp[k] = vec[j];
            ++j;
            ++k;
        }
    }else{
        while(i<mid){
            tmp[k] = vec[i];
            ++i;
            ++k;
        }
    }
    for(i=0; i<vecSize; ++i){
        vec[i] = tmp[i];
    }
    free(tmp);
}

void mergeSort(int vec[], int vecSize){
    int mid;

    if(vecSize>1){
        mid= vecSize/2;
        mergeSort(vec, mid);
        mergeSort(vec+mid, vecSize-mid);
        merge(vec, vecSize);
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

	mergeSort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Merge Sort preenchido aleatoriamente: %f\n", t_percorrido);

    //ORDENAÇÃO CRESCENTE
    inicializarOrdemCrescente(v,N); //inicializando o vetor em ordem crescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	mergeSort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Merge Sort preenchido em ordem crescente: %f\n", t_percorrido);

    //ORDENÇÃO DECRESCENTE
    inicializarOrdemDecrescente(v,N); //iniciando o vetor em ordem decrescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	mergeSort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Merge Sort preenchido em ordem decrescente: %f\n", t_percorrido);


    return 0;
}


