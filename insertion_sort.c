#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
void insertion_sort(int A[100],int n){            
        for(int j=1;j<n;j++){
                int key=A[j];
                int i=j-1;
                while(i>=0&&A[i]>key){
                        A[i+1]=A[i];
                        i=i-1;
                }
                A[i+1]=key;
        }
}
void print(int a[],int n){
	insertion_sort(a,n);
	for(int i=0;i<n;i++){
	printf("%d\t",a[i]);
	}
   printf("\n"); 
}
long long get_time(){
    struct timeval val;
    gettimeofday(&val,NULL);
    return((long long) val.tv_sec*1000000)+val.tv_usec;
}
void sorting_time(const char *input_file, const char *out_file) {
    FILE *file = fopen(input_file, "r");
    if (!file) {
        fprintf(stderr, "Error al abrir el archivo de entrada\n");
        return;
    }

    FILE *time_file = fopen(out_file, "w");
    if (!time_file) {
        fprintf(stderr, "Error al abrir el archivo de salida\n");
        fclose(file);
        return;
    }

    int n;
    long long start_time, end_time;
    char line[1024];

    // Leer cada línea del archivo
    while (fgets(line, sizeof(line), file) != NULL) {
        int count = 0;
        int a[100];

        // Tokenizar la línea para obtener los números
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            a[count++] = atoi(token);
            token = strtok(NULL, " \t\n");
        }

        // Ordenar el arreglo
        start_time = get_time();
        insertion_sort(a, count);
        end_time = get_time();

        // Escribir el tamaño del arreglo y el tiempo de ordenamiento en el archivo de salida
        fprintf(time_file, "%d %lld\n", count, end_time - start_time);

        // Mostrar el arreglo ordenado en la consola
        printf("Arreglo ordenado: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    fclose(file);
    fclose(time_file);
}
int main(){
  int a[100]={1,22,13,14,5};
  insertion_sort(a,5);
  print(a,5);
  sorting_time("data.in","time_data.txt");
      return 0;
} 

