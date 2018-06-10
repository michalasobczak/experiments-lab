/* ******** */
/* INCLUDES */
/* ******** */
#include <tgi.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
// GENERIC
#include "env\3d.c"


/* ******** */
/* DATA     */
/* ******** */
// GENERAL
int camera_x = 200;
int camera_y = 335;
int camera_z = -250;
int th_x = 0;
int th_y = 0;
int th_z = 0;
int start_x = 250;
int start_y = 40;
int start_z = 1500;
int rxA = 0;
int ryA = 0;
// MODEL
int cube_vertices[] = { 
-100,-100,100,-100,100,100,-100,-100,-100,-100,100,-100,100,-100,100,100,100,100,100,-100,-100,100,100,-100
};
int cube_faces[] = {
2,4,3,1,4,8,7,3,8,6,5,7,6,2,1,5,1,3,7,5,6,8,4,2
};  
int cube_2d[8*2];


/* ********* */
/* FUNCTIONS */
/* ********* */
// DRAW MODEL
void draw_model() {
  int k  = 0;
  int f  = 1;
  int face_index = 0;
  int vc = 0;
  int x2, y2, z2 = 0;
  int x3, y3 = 0;

  /* CALCULATE 2D POINTS */
  for (k; k<=sizeof(cube_vertices)/sizeof(cube_vertices[0])-3; k=k+3) {
    x2 = start_x+cube_vertices[k+0];
    y2 = start_y+cube_vertices[k+1];
    z2 = start_z+cube_vertices[k+2];
    transform3Into2_NEW(&rxA,&ryA, x2,y2,z2, camera_x,camera_y,camera_z, th_x,th_y,th_z); 
    //printf("%d,%d,%d => %d x %d\n", x2,y2,z2, rxA,ryA);
    cube_2d[vc+0] = rxA;
    cube_2d[vc+1] = ryA;
    vc+=2;
  } /* for */
  tgi_clear();
  tgi_setviewpage(0);
  tgi_setdrawpage(1);
  tgi_gotoxy(cube_2d[0], cube_2d[1]);
  // DRAW LINES BETWEEN VERTICES BASED ON FACES DEFINITION
  for (f; f<=sizeof(cube_faces)/sizeof(cube_faces[0])-1; f++) {
    face_index = (cube_faces[f]*2)-2;
    x3 = cube_2d[face_index+0];
    y3 = cube_2d[face_index+1];
    tgi_lineto(x3,y3);
  } /* for */
  tgi_setviewpage(1);
} /* draw_model */
// TGI INIT
void tgi() {
  tgi_install(tgi_static_stddrv);
  tgi_init();    
  tgi_clear();
  tgi_setcolor(TGI_COLOR_WHITE);
} /* tgi */


/* ********* */
/* MAIN      */
/* ********* */
int main (void) {    
    int i = 0;
    int direction = 1;
    /* WAIT */
    cprintf("%s\n", "PRESS KEY TO PROCEED");    
    cgetc();
    clrscr();
    /* TGI */
    tgi();
    // LOOP
    while (1) {                 
      /* PROJECTION */
      draw_model();
      // MOVE
      start_x+=2*direction; 
      if (start_x>=200) {
        direction = -1;
      }
      else if (start_x <= 100) {
        direction = 1;
      }
      ++i;
    } /* while */
    /* EXIT */
    return 0;
} /* main */
