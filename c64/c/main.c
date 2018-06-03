/* INCLUDES */
#include <tgi.h>


/* GENERIC */
#include "env\3d.c"


/* DATA */
;

/* MAIN */
int main (void) {    
    int line_x = 0;
    int line_y = 0;
    int i = 0;
    
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

    return 0;
} /* main */
