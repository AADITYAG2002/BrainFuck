#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char temp;
    printf("Enter: ");
    scanf("%c", &temp);
    int temp_int = (int)temp;
    printf("output: %c %i", temp, temp_int);

    return EXIT_SUCCESS;
}