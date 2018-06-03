/* INCLUDES */
#include <tgi.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


/* GENERIC */
#include "elements\vector.c"
#include "env\3d.c"


/* DATA */


/* MAIN */
int main (void) {    
    int line_x = 0;
    int line_y = 0;
    int i = 0;
    int j = 0;
    int * c;
    int * d;
    
    /* ******* */
    /* GENERIC */
    /* ******* */
    int a[9] = {10,10,10,10,10,10,10,10,10};
    int b[9] = {100,1,2,3,4,5,6,7,8};
    c = matS(a, b);  
    printf("main => c addr => %p\n", c); 
    for (j; j<=8; j++) {
      printf("main => for c[j] => %i\n", *(c+j));     
    }
    free(c);
    /* MOD */
    a[0] = 13;
    d = matS(a,b);
    printf("main => d[0] => %i\n", *(d+0)); 
    free(d);
    /* ******* */
    
    /* WAIT */
    cprintf("%s\n", "PRESS KEY TO PROCEED");    
    cgetc();
    
    /* TGI */
    tgi_install(tgi_static_stddrv);
    tgi_init();    
    tgi_clear();
    tgi_setcolor(TGI_COLOR_WHITE);
    
    while (1) {      
      ++line_x;
      ++line_y;
      tgi_line(0, 0, line_x, line_y);
      
      if (i % 10 == 0 ) {
        tgi_clear();          
      }
              
      if (line_y > 200) {
        line_x = 0;
        line_y = 0;
      }
      
      ++i;
    } /* while */

    /* EXIT */
    return 0;
} /* main */
