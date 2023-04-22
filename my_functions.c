#include <stdlib.h>
#include <stdio.h>

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