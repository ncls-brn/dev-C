#include <stdio.h> 
void swap(int *a, int *b);


int main(int argc, char const *argv[]){

    int a=1;
    int b=2;
    printf("a= %d\nb= %d\n",a,b );
    printf("adresse memoire de a = %p\n", &a);
    printf("adresse memoire de b = %p\n", &b);
    swap(&a, &b);

    printf("\n");
    printf("a= %d\nb= %d\n",a,b );


    return 0;
}


void swap(int *a, int *b) {
    printf("swapping\n");
 int temp = *a;
*a =*b; 
*b =temp; 

}
