#include <stdio.h>

#define N    100

int get_data(int numbers[]);
void update(int size, int table[], int *min, int *max);

int main(){
    int numbers[N];
    int min, max, multitude;

    printf("Enter the elements of the array, one per line.\nUse -1 to signal the end of the list.\n");
    multitude = get_data(numbers);
    update(multitude, numbers, &min, &max);
    printf("The range of values is %d-%d", min, max);
    return 0;
}

int get_data(int numbers[]){
    int i, number;

    i = 0;
    do{
        printf("? ");
        scanf("%d", &number);
        if(number == -1 || i >= N)
            break;
        numbers[i] = number;
        i++;
    }while(1);
    return i;
}

void update(int size, int table[], int *min, int *max){
    int i;

    *min = table[0];
    *max = table[0];
    for(i = 1; i < size; i++){
        if(table[i] > *max){
            *max = table[i];
        }
        if(table[i] < *min){
            *min = table[i];
        }
    }
}
