#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define size    100

typedef struct{
    char name[60];
    int start_month;
    int duration;
}projectT;


void ReadWorkpackages(int s, projectT table[]);
projectT FindFirstWP(int s, projectT table[]);
int FindMakespan(int s, projectT table[]);

int main(){
    projectT WP[size];
    projectT first;
    int twp, total;

    printf("Total work packages: ");
    twp = GetInteger();
    ReadWorkpackages(twp, WP);
    first = FindFirstWP(twp, WP);
    printf("First WP: %s start: %d duration: %d\n", first.name, first.start_month, first.duration);
    total = FindMakespan(twp, WP);
    printf("Total duration = %d", total);
    return 0;
}


void ReadWorkpackages(int s, projectT table[]){
    int i;

    for(i=0; i<s; i++){
        printf("WP Name: ");
        gets(table[i].name);
        printf("WP Start Month:");
        table[i].start_month = GetInteger();
        printf("WP Duration:");
        table[i].duration = GetInteger();
    }
}

projectT FindFirstWP(int s, projectT table[]){
    int i;
    int index, min;

    min = table[0].start_month;
    index = 0;

    for(i=1; i<s; i++){
        if(table[i].start_month < min){
            min = table[i].start_month;
            index = i;
        }
    }
    return table[index];
}

int FindMakespan(int s, projectT table[]){
    int i, max, cur_max;

    max = table[0].start_month + table[0].duration;
    for(i=1; i<s; i++){
        cur_max = table[i].start_month + table[i].duration;
        if(cur_max > max){
            max = cur_max;
        }
    }
    return max;
}
