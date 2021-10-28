#include <stdio.h>
#include <stdlib.h>

// returns a new rows_num
int addRow(int **arr, int rows_num, int default_row_length) {
    // using realloc to increase the size of the array of pointers by 1.
    arr = (int **)realloc(arr, (rows_num + 1) * sizeof(int));
    // allocating a block of 5 integers for the newly added pointer.
    arr[rows_num] = (int *)calloc(1, sizeof(int));

    return rows_num + 1;
}

void print2dArray(int **arr, int rows_num, int default_row_length) {
    for (int i = 0; i < rows_num; i++) {
        for (int j = 0; j < default_row_length; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int **create2dArray(int rows_num, int default_row_length) {
    // initialize an array of pointers
    int **arr = (int **)calloc(rows_num, sizeof(int *));

    // for each pointer, allocate a memory block for 'default_row_length'
    // integer values.
    // NOTE: calloc fills the memory block with 0's. malloc doesn't.
    for (int i = 0; i < rows_num; i++)
        arr[i] = (int *)calloc(default_row_length, sizeof(int));

    return arr;
}

int main(int argc, char const *argv[]) {
    // We can also create a 2d dynamic arrays by creating a double pointer.
    int **x;
    int rows_num = 3;
    int default_row_length = 5;

    // The advantage of it is that we can easily pass it between functions
    x = create2dArray(rows_num, default_row_length);

    // set some random values
    x[1][4] = 100;
    x[2][1] = 200;

    print2dArray(x, rows_num, default_row_length);

    printf("\n");

    // dynamically add a row to the array
    rows_num = addRow(x, rows_num, default_row_length);

    x[3][0] = 123456;

    print2dArray(x, rows_num, default_row_length);

    return 0;
}
