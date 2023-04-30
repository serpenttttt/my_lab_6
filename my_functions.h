#ifndef MY_LAB_6_MY_FUNCTIONS_H
#define MY_LAB_6_MY_FUNCTIONS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "swap_macros.h"

void input_string(char *string);

void find_with_binary_search(int value, int array[5], int lower, int upper);

void input_array(int amount_of_elements, int *array);

void show_array(int amount_of_elements, int *array);

int *quick_sort(int *array, int end);

int *counting_sort(int *array, int amount_of_elements);

#endif //MY_LAB_6_MY_FUNCTIONS_H
