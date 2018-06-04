/* INCLUDES */
#include <tgi.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* GENERIC */
#include "env\3d.c"

/* DATA */
int camera_x = 200;
int camera_y = 335;
int camera_z = -250;
int camera_angle_x = 0;
int camera_angle_y = 0;
int camera_angle_z = 0;
int point_x = 100;
int point_y = 50;
int point_z = 1000;
int assert_x = 104; // 103.99
int assert_y = 160; // 159.60

/* MAIN */
int main (void) {    
    int line_x = 0;
    int line_y = 0;
    int i = 0;
    
    /* WAIT */
    cprintf("%s\n", "PRESS KEY TO PROCEED");    
    cgetc();
    
    /* TGI */
    //tgi_install(tgi_static_stddrv);
    //tgi_init();    
    //tgi_clear();
    //tgi_setcolor(TGI_COLOR_WHITE);
    
    //while (1) {      
      ++line_x;
      ++line_y;
      //tgi_line(0, 0, line_x, line_y);
      
      /* Project 3D point onto 2D screen */
      clrscr();
      transform3Into2_NEW(point_x,point_y,point_z, camera_x,camera_y,camera_z, camera_angle_x,camera_angle_y,camera_angle_z);
      
      if (i % 10 == 0 ) {
        //tgi_clear();         
      }
              
      if (line_y > 200) {
        line_x = 0;
        line_y = 0;
      }
      
      ++i;
   //} /* while */

    /* EXIT */
    return 0;
} /* main */
