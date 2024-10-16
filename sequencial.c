#include <stdio.h>
#include <stdlib.h>

int sequencial(int N, char* vet, char key) 
{ 
	int i; 

	for (i = 0; i < N; i++) 
	{ 
	    if (key == vet[i]) 
            return i; 
	} 

	return -1; 
}

int seq_ordenada(int N, char* vet, char key) 
{ 
	int i; 
	for (i = 0; i < N; i++) 
	{ 
	    if (key == vet[i]) 
            return i;

	    else if(key < vet[i])
		    return -1;
	} 	
    return -1; 
}

int main(){
    char vetor[8];
    int pos1,pos2;
    for(int i = 0; i<8;i++){
        vetor[i] = i*2;
    }

    pos1 = sequencial(8,vetor,6);
    pos2 = seq_ordenada(8,vetor,3);

    printf("%d %d",pos1,pos2);
    return 0;
}