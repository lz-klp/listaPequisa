#include <stdio.h>
#include <stdlib.h>

int buscaBinaria (int N, char* vet, char key) 
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

int binariaRecursiva(int e,int N, char* vet, char key){
    int m,d;
    d = N-1;
    m = (e+d) / 2;

    if(vet[m] == key){
        return m;
    }
    else if(vet[m] < key){
        return binariaRecursiva(m,d,vet,key);
    }
    else{
        return binariaRecursiva(0,m,vet,key);
    }

}

int main(){
    int vetor[8];
    int pos1,pos2;
    for(int i = 0; i<8;i++){
        vetor[i] = i*2;
    }
    pos1 = buscaBinaria(8,vetor,4);
    pos2 = binariaRecursiva(0,8,vetor,8);

    printf("%d %d",pos1,pos2);
    return 0;
}