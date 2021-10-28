#include <stdio.h>
#include <stdlib.h>  // required for memory allocation

int main(int argc, char const *argv[]) {
    int classic_array[5] = {1, 2, 3, 4, 5};

    // Let's print values and their addresses. As you can see, array elements
    // are stored in a contiguous block of memory.
    for (int i = 0; i < 5; i++)
        printf("value: %d, addres: %p\n", classic_array[i], &classic_array[i]);

    // --------------------------------------------

    printf("\n\n");

    // Allocates memory for 5 integers and returns a pointer to the first
    // element of the block
    int *arr = (int *)calloc(5, sizeof(int));

    // Let's fill our dynamic array with some values
    for (int i = 0; i < 5; i++)
        arr[i] = i * 2;

    // Let's print values and their addresses again.
    for (int i = 0; i < 5; i++)
        printf("value: %d, addres: %p\n", arr[i], arr + i);

    // Always remember to free the memory that you are no longer using
    free(arr);

    return 0;
}
