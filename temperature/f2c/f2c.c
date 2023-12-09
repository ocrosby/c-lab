#include <stdio.h>
#include <stdlib.h>

#include "./conversion.h"

int main(int argc, char *argv[]) {
    int celsius;
    int fahrenheit;

    // Check if temperature argument is provided
    if (argc != 2) {
        printf("Usage: %s <temperature>\n", argv[0]);
        return 1;
    }

    // Convert the argument to an integer
    fahrenheit = atoi(argv[1]);

    celsius = fahrenheit_to_celsius(fahrenheit);

    printf("The provided temperature %d degrees fahrenheit is %d degrees celsius\n", fahrenheit, celsius);

    return 0;
}
