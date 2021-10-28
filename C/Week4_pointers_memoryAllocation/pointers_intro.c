#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 3;
    int b = 4;
    int *p1 = &a;
    int *p2;
    p2 = &b;

    // *p - value of the variable that the pointer p (int *p) is pointing to
    // &a - address of the variable a (int a)

    // print pointer p1 -> print address under which the variable 'a' is stored
    printf("%p\n", p1);
    // print pointer p2 -> print address under which the variable 'b' is stored
    printf("%p\n", p2);

    // print the value of the pointer p1 -> print the value that is stored where
    // the pointer p1 is pointing to
    printf("%d\n", *p1);
    // print the value of the pointer p2 -> print the value that is stored where
    // the pointer p2 is pointing to
    printf("%d\n", *p2);

    return 0;
}
