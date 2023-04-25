#include <stdlib.h>
#include <stdio.h>
#include "swap_macros.h"

void input_string(char *string) {
    char input;  // Переменная для считывания посимвольно
    for (int i = 0; (input = getchar()) != '\n'; ++i) {
        string = (char *) realloc(string, sizeof(char) * (i + 1));
        string[i] = input;
        string[i + 1] = '\0';
    }
}

void find_with_binary_search(int value, int array[5], int lower, int upper) {
    int array_index = (lower + upper)/2;
    if (value == array[array_index]) {
        printf("Element's position in array is: %d \n", array_index);
        return;
    }
    else {
        if (lower == upper - 1) {
            puts("No such element");
            return;
        }
        if (value > array[array_index]) {
            lower = array_index;
        }
        if (value < array[array_index]) {
            upper = array_index;
        }
        find_with_binary_search(value, array, lower, upper);
    }
}

void input_array(int amount_of_elements, int *array) {
    int input;  // Переменная для считывания
    for (int i = 0; i < amount_of_elements; ++i) {
        puts("Enter an element");
        scanf("%d", &input);
        array[i] = input;
    }
}

void show_array(int amount_of_elements, int *array) {
    for(int i = 0; i < amount_of_elements; ++i)
        printf("%d ", array[i]);
}

int *quick_sort(int *array, int begin, int end) {
    int left;
    int right;
    int pivot;

    do {
        left = begin;
        right = end;

        pivot = array[right / 2];

        while (left <= right) {
            while (array[left] < pivot){
                left++;
            }
            while (array[right] > pivot){
                right--;
            }
            if (left <= right) {
                swap(int, array[left], array[right])
                right--;
                left++;
            }
        }
        if (begin < right) {
            end = right;
            continue;
        }
        if (end > left) {
            begin = left;
            continue;
        }
        /*if (begin >= right || end <= left)
            return array;*/
    } while (begin < right || end > left); //&&

    return array;
}