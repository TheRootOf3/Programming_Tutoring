## Suggested order

1. `pointers_intro.c`
2. `square.c`
3. `memory_allocation.c`
4. `2d_dynamic_array.c`


## Pointers and memory allocation in C

Especially when coding in C, it is important to understand how the memory for the program is allocated and managed. Generally, we can divide the whole memory in 2 major segments:
- Stack - contains local variables that size is known during the compilation stage or doesn't change throughout the program. This includes primitive data types, pointers and arrays.
  - `int a = 5;`
  - `int *p;`
  - `char word[n];`
- Heap - contains dynamic space allocated explicitly by the programmer using `malloc`, `calloc`, `realloc`. NOTE: a pointer to allocated memory itself will be stored in the Stack segment.
  - `int *p = (int*) malloc(5*sizeof(int));`

![image](https://i.stack.imgur.com/HOY4C.png)
