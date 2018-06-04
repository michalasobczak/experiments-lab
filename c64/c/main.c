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
int th_x = 0;
int th_y = 0;
int th_z = 0;
int point_x = 100;
int point_y = 50;
int point_z = 1000;
int assert_x = 104; // 103.99
int assert_y = 160; // 159.60

/* MAIN */
int main (void) {    
    int i = 0;
    int rxA = 0;
    int ryA = 0;
    int rxB = 0;
    int ryB = 0;
    
    /* WAIT */
    cprintf("%s\n", "PRESS KEY TO PROCEED");    
    cgetc();
    
    /* TGI */
    tgi_install(tgi_static_stddrv);
    tgi_init();    
    tgi_clear();
    tgi_setcolor(TGI_COLOR_WHITE);
    
    while (1) {           
      //tgi_line(0, 0, line_x, line_y);
      
      /* Project 3D point onto 2D screen */      
      transform3Into2_NEW(&rxA,&ryA, point_x,point_y,point_z, camera_x,camera_y,camera_z, th_x,th_y,th_z);
      transform3Into2_NEW(&rxB,&ryB, point_x,point_y,point_z+100, camera_x,camera_y,camera_z, th_x,th_y,th_z);
      tgi_line(rxA, ryA, rxB, ryB);
      transform3Into2_NEW(&rxA,&ryA, point_x+100,point_y,point_z+100, camera_x,camera_y,camera_z, th_x,th_y,th_z);
      tgi_line(rxB, ryB, rxA, ryA);
      transform3Into2_NEW(&rxB,&ryB, point_x+100,point_y,point_z, camera_x,camera_y,camera_z, th_x,th_y,th_z);
      tgi_line(rxA, ryA, rxB, ryB);
      transform3Into2_NEW(&rxA,&ryA, point_x,point_y,point_z, camera_x,camera_y,camera_z, th_x,th_y,th_z);
      tgi_line(rxB, ryB, rxA, ryA);
      
      if (i % 10 == 0 ) {
        tgi_clear();         
        //printf("%d\n", i);
      }
      
      ++i;
   } /* while */

    /* EXIT */
    return 0;
} /* main */
