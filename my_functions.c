#include "my_functions.h"

void input_string(char *string) {
    char input;
    for (int i = 0; (input = getchar()) != '\n'; ++i) {
        string = (char *) realloc(string, sizeof(char) * (i + 1));
        string[i] = input;
        string[i + 1] = '\0';
    }
}

void find_with_binary_search(int value, int array[5], int lower, int upper) {
    int array_index = (lower + upper) / 2;
    if (value == array[array_index]) {
        printf("Element's position in array is: %d \n", array_index);
        return;
    } else {
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
    int input;
    for (int i = 0; i < amount_of_elements; ++i) {
        puts("Enter an element");
        if (scanf("%d", &input)) {
            fflush(stdin);
            array[i] = input;
        }
        else return;
    }
}

void show_array(int amount_of_elements, int *array) {
    for (int i = 0; i < amount_of_elements; ++i)
        printf("%d ", array[i]);
}

int *quick_sort(int *array, int end) {

    int right, left;

    int left_fragment, right_fragment;

    int left_fragment_stack[1024], right_fragment_stack[1024];
    int position_in_stack = 1;
    int array_mid;

    int pivot;

    left_fragment_stack[1] = 0;
    right_fragment_stack[1] = end - 1;

    do {

        left_fragment = left_fragment_stack[position_in_stack];
        right_fragment = right_fragment_stack[position_in_stack];
        position_in_stack--;

        do {

            array_mid = (left_fragment + right_fragment) >> 1;
            left = left_fragment;
            right = right_fragment;
            pivot = array[array_mid];

            do {

                while (array[left] < pivot)
                    left++;
                while (array[right] > pivot)
                    right--;

                if (left <= right) {
                    swap(int, array[left], array[right])
                    left++;
                    right--;
                }

            } while (left <= right);

            if (left < array_mid) {

                if (left < right_fragment) {
                    position_in_stack++;
                    left_fragment_stack[position_in_stack] = left;
                    right_fragment_stack[position_in_stack] = right_fragment;
                }
                right_fragment = right;

            } else {

                if (right > left_fragment) {
                    position_in_stack++;
                    left_fragment_stack[position_in_stack] = left_fragment;
                    right_fragment_stack[position_in_stack] = right;
                }
                left_fragment = left;

            }

        } while (left_fragment < right_fragment);

    } while (position_in_stack != 0);

    return array;
}

int *counting_sort(int *array, int amount_of_elements) {

    int max = array[0], min = array[0];
    int size_of_count_array;
    int *count_array;
    int *array_counting_sort;

    for (int i = 1; i < amount_of_elements; i++) {
        if (array[i] < min)
            min = array[i];
        else if (array[i] > max)
            max = array[i];
    }

    size_of_count_array = max - min + 1;

    count_array = (int *) malloc(sizeof(int) * size_of_count_array);
    array_counting_sort = (int *) malloc(sizeof(int) * amount_of_elements);

    for (int i = 0; i < size_of_count_array; i++)
        count_array[i] = 0;
    for (int i = 0; i < amount_of_elements; i++)
        array_counting_sort[i] = 0;

    for (int i = 0; i < amount_of_elements; ++i)
        count_array[array[i] - min] += 1;

    int j = 0;
    for (int i = 0; i < size_of_count_array; i++) {
        while (count_array[i] > 0) {
            array_counting_sort[j] = min;
            j++;
            count_array[i]--;
        }
        min++;
    }

    return array_counting_sort;
}
