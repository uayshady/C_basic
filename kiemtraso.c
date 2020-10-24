#include <stdio.h>
#include <stdlib.h>
 
int clean_stdin() {
    while (getchar() != 'n') {
    }
    return 1;
}
 
int main(void) {
    int input;
    char c;
    do {
        printf("Enter an integer: ");
    } while (((scanf("%d%c", &input, &c) != 2 || c != 'n') && clean_stdin()));
 
    printf("done, number is %d", input);
    return 0;
}