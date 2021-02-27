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

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(n^2) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
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

	heapsort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Heap Sort preenchido aleatoriamente: %f\n", t_percorrido);

    //ORDENAÇÃO CRESCENTE
    inicializarOrdemCrescente(v,N); //inicializando o vetor em ordem crescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	heapsort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Heap Sort preenchido em ordem crescente: %f\n", t_percorrido);

    //ORDENÇÃO DECRESCENTE
    inicializarOrdemDecrescente(v,N); //iniciando o vetor em ordem decrescente

    inicio = (double) clock()/CLOCKS_PER_SEC; //medindo o tempo inicial

	heapsort(v, N);

    fim = (double) clock() / CLOCKS_PER_SEC; //medindo o tempo final
    t_percorrido = fim - inicio; //medindo o tempo total
    printf("Tempo em segundos do Heap Sort preenchido em ordem decrescente: %f\n", t_percorrido);


    return 0;
}
