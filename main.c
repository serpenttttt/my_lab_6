#include <stdio.h>
#include "my_functions.h"
#include <stdlib.h>
#include "swap_macros.h"

int main() {

    puts("Task 1\n"
         "Input the type of values you want to enter, please\n"
         "1 - char\n"
         "2 - float\n"
         "3 - int");

    int type;

    char *data_char_1;
    data_char_1 = (char *) malloc(sizeof(char));
    char *data_char_2;
    data_char_2 = (char *) malloc(sizeof(char));

    scanf("%d", &type);

    fflush(stdin);

    switch (type) {
        case 1:

            puts("Enter 2 strings");
            fflush(stdin);

            input_string(data_char_1);
            input_string(data_char_2);

            swap(char *, data_char_1, data_char_2)

            printf("a is %s now\n", data_char_1);
            printf("b is %s now\n", data_char_2);

            break;

        case 2:

            puts("Enter two float values");

            float data_float[2];
            scanf("%f", &data_float[0]);
            fflush(stdin);
            scanf("%f", &data_float[1]);
            fflush(stdin);

            swap(float, data_float[0], data_float[1])

            printf("a is %g now\n", data_float[0]);
            printf("b is %g now\n", data_float[1]);

            break;

        case 3:

            puts("Enter two int values");

            int data_int[2];
            scanf("%d", &data_int[0]);
            fflush(stdin);
            scanf("%d", &data_int[1]);
            fflush(stdin);

            swap(int, data_int[0], data_int[1])

            printf("a is %d now\n", data_int[0]);
            printf("b is %d now\n", data_int[1]);

            break;

        default:
            puts("Unknown type");
            fflush(stdin);
    }


    puts("\nTask 2\n"
         "Enter the amount of elements, please");

    int *binary_search_array;
    int amount_of_elements;

    if (scanf("%d", &amount_of_elements)) {

        fflush(stdin);

        binary_search_array = (int *) malloc(sizeof(int) * amount_of_elements);
        input_array(amount_of_elements, binary_search_array);

        int value;

        fflush(stdin);
        puts("\nInput the element you want to find with binary search");
        scanf("%d", &value);
        fflush(stdin);

        int lower = 0;

        find_with_binary_search(value, binary_search_array, lower, amount_of_elements);

    } else puts("Incorrect amount of elements");

    puts("\nTask 3\n"
         "Enter the amount of elements, please");

    int *quick_sort_array;

    fflush(stdin);

    if (scanf("%d", &amount_of_elements)) {

        fflush(stdin);

        quick_sort_array = (int *) malloc(sizeof(int) * amount_of_elements);

        input_array(amount_of_elements, quick_sort_array);

        int right = amount_of_elements;

        puts("You have entered:");
        show_array(amount_of_elements, quick_sort_array);

        quick_sort_array = quick_sort(quick_sort_array, right);

        puts("\nSorted with quick sort:");
        show_array(amount_of_elements, quick_sort_array);
        free(quick_sort_array);

    } else puts("Incorrect amount of elements");

    puts("\n\nTask 4\n"
         "Enter the amount of elements, please");

    int *sort_array;

    fflush(stdin);

    if (scanf("%d", &amount_of_elements)) {

        fflush(stdin);

        sort_array = (int *) malloc(sizeof(int) * amount_of_elements);

        input_array(amount_of_elements, sort_array);

        int *array_counting_sort = counting_sort(sort_array, amount_of_elements);

        puts("Sorted with counting sort: ");
        show_array(amount_of_elements, array_counting_sort);

    } else puts("Incorrect amount of elements");

    return 0;
}
