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

void bubbleSort(int array[], int length)
{
    int i, j;
    for(i = length - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
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

	bubbleSort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Bublle Sort preenchido aleatoriamente: %f\n", t_percorrido);

    //ORDENAÇÃO CRESCENTE
    inicializarOrdemCrescente(v,N); //inicializando o vetor em ordem crescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	bubbleSort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Bublle Sort preenchido em ordem crescente: %f\n", t_percorrido);

    //ORDENÇÃO DECRESCENTE
    inicializarOrdemDecrescente(v,N); //iniciando o vetor em ordem decrescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	bubbleSort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Bublle Sort preenchido em ordem decrescente: %f\n", t_percorrido);


    return 0;
}
