#include <stdlib.h>
#include <stdio.h>
#define NUM_ARRAYS 30
int main(int argc,char* argv[]){
  if(argc<2){
	fprintf(stderr,"INGRESE EL TAMAÑO DEL ARREGLO");
	return 1;
  }
  int n=atoi(argv[1]);
  printf("%d\n",n);
  for(int i=0;i<NUM_ARRAYS;i++){
  	for(int j=0;j<n;j++){
	int num=rand();
	printf("%d\t",num);
	}
	printf("\n");
  }
  return 0;
}
