/* INCLUDES */
#include <tgi.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


/* GENERIC */
#include "elements\vector.c"
#include "env\3d.c"


/* DATA */
Vector2 * vector2;


/* MAIN */
int main (void) {    
    int line_x = 0;
    int line_y = 0;
    int i = 0;
    
    /* ******* */
    /* GENERIC */
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
      
      /* Project 3D point onto 2D screen */
      transform3Into2_NEW(0,0,0, 1,1,1, 2,2,2);
      
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
