#include <stdio.h>

double mean(int length, int* arr){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += arr[i];
    }
    return sum / length;
}