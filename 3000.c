#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int buscaBinaria (int N, int* vet, int key) 
{
	int e, m, d;  
    e = 0; d = N-1; 

	while (e <= d) {
	    m = (e + d)/2; 
	    if (vet[m] == key) 
	        return m; 
	    if (vet[m] < key) 
            e = m + 1; 
        else 
            d = m - 1; 
    } 
	return -1; 
}

int sequencial(int N, int* vet, int key) 
{ 
	int i; 

	for (i = 0; i < N; i++) 
	{ 
	    if (key == vet[i]) 
            return i; 
	} 

	return -1; 
}


int main(){
    int vetor[3000],res,res2;
    clock_t t1,t2,t3,t4;
    
    for(int i = 0; i<3000;i++){
        vetor[i] = i+1;
    }

    t1 = clock();
    res = sequencial(3000,vetor,0);
    t3 = clock();
    
    t2 = clock();
    res2 = buscaBinaria(3000,vetor,0);
    t4 = clock();

    printf("Tempo Sequencial: %lf ms",((double)t3-t1)/ CLOCKS_PER_SEC *1000);
    printf("\nTempo Binaria: %lf ms",((double)t4-t2)/CLOCKS_PER_SEC*1000);
    return 0;
}