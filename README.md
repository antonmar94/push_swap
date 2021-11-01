# push_swap
Number ordenation function with recursive quicksort.

Add print_list in main to display list.

Use make to compile.
Use ./push_swap [number list] to execute. Doesnt work with duplicates numbers or no integers. 

Use:
ARG=$(seq [range of numbers] | sort -R | tail -n [elements in the list] | tr '\n' ' ')  ;  ./push_swap $ARG
for generate a random number list and execute the program.

The program sort the elements with less than 700 moves in a 100 elements list and less
than 5500 in a 500 elements list, doing so it displays the operations in console.
