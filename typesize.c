#include <stdio.h>
#include <stdlib.h>



typedef struct Person {
    int id;
    char c;
    struct Person* mother;
}Person;




int main(){

    int size = 5;
    int* numbers = malloc(size * sizeof(int));
    if (numbers == NULL) {
        return 1;
    }

    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1; 
    }
    printf("Tableau avant : \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    size++;
    int* temp = realloc(numbers, size * sizeof(int));
    if (temp == NULL) {
        free(numbers); 
        return 1;      
    }
    numbers = temp; 
    numbers[5] = 6;

    printf("Tableau après : \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    free(numbers);

    return 0;
}