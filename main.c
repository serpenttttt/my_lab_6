#include <stdio.h>
#include "my_functions.h"
#include <stdlib.h>
#include "swap_macros.h"

int main() {
    char type;

    char *data_char_1;
    data_char_1 = (char *) malloc(sizeof(char));
    char *data_char_2;
    data_char_2 = (char *) malloc(sizeof(char));

    puts("Task 1\n Input the type of values you want to enter, please\n"
         "1 - char\n"
         "2 - float\n"
         "3 - int");

    scanf("%c", &type);

    switch (type) {
        case '1':
            puts("Enter 2 strings");
            getchar();
            input_string(data_char_1);
            input_string(data_char_2);
            swap(char *, data_char_1, data_char_2)
            printf("a is %s now\n", data_char_1);
            printf("b is %s now\n", data_char_2);
            break;
        case '2':
            puts("Enter two float values");
            float data_float[2];
            scanf("%f", &data_float[0]);
            scanf("%f", &data_float[1]);
            swap(float, data_float[0], data_float[1])
            printf("a is %g now\n", data_float[0]);
            printf("b is %g now\n", data_float[1]);
            break;
        case '3':
            puts("Enter two int values");
            int data_int[2];
            scanf("%d", &data_int[0]);
            scanf("%d", &data_int[1]);
            swap(int, data_int[0], data_int[1])
            printf("a is %d now\n", data_int[0]);
            printf("b is %d now\n", data_int[1]);
            break;
        default:
            puts("Unknown type");
    }

    puts("\nTask 2");

    int array[5] = {1,2,3,4,5};
    puts("Input the element you want to find with binary search (1-5)");
    int value;
    scanf("%d", &value);

    int lower = 0;
    int upper = sizeof(array)/sizeof(array[0]);

    find_with_binary_search(value, array, lower, upper);

    puts("\nTask 3");

    int *quick_sort_array = NULL;
    int amount_of_elements;
    puts("Enter the amount of elements, please");
    getchar();
    scanf("%d", &amount_of_elements);
    quick_sort_array = (int *) malloc(sizeof(int) * amount_of_elements);

    input_array(amount_of_elements, quick_sort_array);

    int left = 0;
    int right = amount_of_elements;

    puts("You have entered:");
    show_array(amount_of_elements, quick_sort_array);

    quick_sort_array = quick_sort(quick_sort_array, left, right);

    puts("\nSorted:");
    show_array(amount_of_elements, quick_sort_array);

    puts("\n\nTask 4");

    return 0;
}
