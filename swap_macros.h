#ifndef MY_LAB_6_SWAP_MACROS_H
#define MY_LAB_6_SWAP_MACROS_H

#define swap(type, a, b) { \
    type tmp = a;          \
    a = b;                 \
    b = tmp;               \
}

#endif //MY_LAB_6_SWAP_MACROS_H
