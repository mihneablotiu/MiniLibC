Blotiu Mihnea-Andrei - 333CA - Tema 1 - Mini-libc

For this homework I used the following references in order to understand exactly what some functions
do and how to exactly implement them:
    1. For all the functions and especially for the string.h ones I used the Linux Manual pages in
    order to understand exactly what some functions do in different situations:
    https://man7.org/linux/man-pages/index.html

    2. For the system calls I used the following table to see what ID each system call has and what
    is the order of the parameters that have to be given to the system call:
    https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md

    3. For the memory part and especially for malloc, calloc and free I used pages from 140 to 149
    from the book entitled: The linux programming interface in order to see exactly how these
    functions work together: https://sciencesoftcode.files.wordpress.com/2018/12/the-linux-programming-interface-michael-kerrisk-1.pdf

    4. To find out what exactly is the timespec C structure that nanosleep uses I found it out
    from the following site: https://www.educative.io/answers/what-is-timespec-in-c

