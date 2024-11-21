#include <stdio.h>


float average (int length, int array[]);

int main(void){
    int n=25;
    int scores[n];

    for (int i=0; i<n; i++){
        scores[i] = i;
    
    }

    printf("Average: %.2f\n", average(n, scores));

return 0;
}


float average(int length, int array[]) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    return (float)sum / length;
}