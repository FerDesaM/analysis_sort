#include <stdio.h>
#include <stdlib.h>
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

int main(){
 int a[100]={1,22,13,14,5};
 insertion_sort(a,5);
 print(a,5);
 printf("NUmeros");
        return 0;
} 

