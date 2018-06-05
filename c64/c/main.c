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
//
int cube_obj[] = {
                    10, -10, -10,
                    10, -10,  10,
                   -10, -10,  10,
                   -10, -10, -10,
                    10,  10,  -9,
                     9,  10,  10,
                   -10,  10,  10,
                   -10,  10, -10
                 };

            
/* DRAW */
void draw_line_to(int x,int y,int z) {
  int rxA = 0;
  int ryA = 0;
  transform3Into2_NEW(&rxA,&ryA, point_x+x,point_y+y,point_z+z, camera_x,camera_y,camera_z, th_x,th_y,th_z);
  tgi_lineto(rxA, ryA);
} /* draw_line */
//
void draw_model() {
  int k = 3;
  int startxA = 0;
  int startyA = 0;
  transform3Into2_NEW(&startxA,&startyA, point_x+cube_obj[0],point_y+cube_obj[1],point_z+cube_obj[2], camera_x,camera_y,camera_z, th_x,th_y,th_z);
  tgi_gotoxy(startxA, startyA);
  for (k; k<=sizeof(cube_obj)/sizeof(cube_obj[0])-3; k=k+3) {
    //printf("%d\n", k);
    draw_line_to(cube_obj[0+k],cube_obj[1+k],cube_obj[2+k]);
  } /* for */
} /* draw_model */


/* MAIN */
int main (void) {    
    int i = 0;

    /* WAIT */
    cprintf("%s\n", "PRESS KEY TO PROCEED");    
    cgetc();
    clrscr();
    
    /* TGI */
    tgi_install(tgi_static_stddrv);
    tgi_init();    
    tgi_clear();
    tgi_setcolor(TGI_COLOR_WHITE);
    
    while (1) {                 
      /* Project 3D point onto 2D screen */      
      draw_model();
     
      if (i % 10 == 0 ) {
        tgi_clear();         
        //printf("%d\n", i);
      }
      
      ++i;
   } /* while */

    /* EXIT */
    return 0;
} /* main */
