#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

static const char Text [] = "Hello, world!";

int main (void) {
    clrscr ();
    printf("%s", Text);
    cgetc ();
    clrscr ();
    return EXIT_SUCCESS;
}
