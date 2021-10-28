// Different approaches to the square function in C. Created to demonstrate the
// usage of pointers in C. Look at the main() and try to understand what each
// method actually does!

#include <stdio.h>
#include <stdlib.h>

int square_classic(int n) {
    int result = n * n;
    return result;
}

int square_pointer(int *n) {
    // this function takes a pointer to n, so if you want to get the value you
    // need to use a * operator.
    int result = *n * *n;
    return result;
}

void square_pointer_inplace(int *n) {
    // this function takes a pointer to n again, but replaces the value in the
    // variable declared in the caller function
    *n = *n * *n;
}

int *square_pointer_return(int *n) {
    // this function takes a pointer to n, stores a result to result, and
    // returns a pointer 'result_p' to the result
    int result = *n * *n;
    int *result_p = &result;
    return result_p;
}

int main(int argc, char const *argv[]) {
    // 1. usuall square function - takes a variable and returns a static
    // value

    int n1 = 5;
    // variable n1 passed as an argument
    int func_result1 = square_classic(n1);
    printf("%d\n", func_result1);

    // ------------------------------------------------------------------------

    // 2. square function taking an address of a variable and returning a
    // value

    int n2 = 5;
    // square pointer taking address of the variable n2
    int func_result2 = square_pointer(&n2);
    printf("%d\n", func_result2);

    // ------------------------------------------------------------------------

    // 3. square function taking a pointer to a variable and returning a
    // value

    int n3 = 5;
    // pointer p3 pointing to variable n3
    int *p3 = &n3;
    // square pointer taking the pointer to variable n3
    int func_result3 = square_pointer(p3);
    printf("%d\n", func_result3);

    // ------------------------------------------------------------------------

    // 4. square function taking a pointer to a variable and changing it
    // inside itself!

    int n4 = 5;
    // pointer p3 pointing to variable n4
    int *p4 = &n4;
    // square_pointer_inplace taking the pointer to variable n4 and replacing
    // this variable with the result
    square_pointer_inplace(p4);
    printf("%d\n", n4);

    // ------------------------------------------------------------------------

    // 5. square function taking a pointer to a variable and returning a
    // pointer to a calculated result

    int n5 = 5;
    // pointer p3 pointing to variable n5
    int *p5 = &n5;
    // square_pointer_return taking the pointer to variable n5 and returning a
    // pointer to a result
    int *func_result5 = square_pointer_return(p5);
    printf("%d\n", *func_result5);

    return 0;
}
