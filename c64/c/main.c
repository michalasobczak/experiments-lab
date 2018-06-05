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
int start_y = 50;
int start_z = 1400;
int rxA = 0;
int ryA = 0;
// MODEL
int cube_vertices[] = { 
-38,92,0,-70,70,0,-100,0,0,-70,-70,0,-27,92,-27,-50,70,-49,-65,38,-65,-70,0,-70,-65,-38,-65,-50,-70,-49,-27,-92,-27,0,92,-38,0,70,-70,0,38,-92,0,0,-99,0,-38,-92,0,-70,-70,0,-92,-38,0,100,0,27,92,-27,49,70,-49,65,38,-65,70,0,-70,65,-38,-65,49,-70,-49,27,-92,-27,38,92,0,70,70,0,92,38,0,99,0,0,92,-38,0,70,-70,0,38,-92,0,27,92,27,49,70,49,65,38,65,70,0,70,65,-38,65,49,-70,49,27,-92,27,0,92,38,0,70,70,0,38,92,0,0,99,0,-38,92,0,-70,70,0,-92,38,-27,92,27,-50,70,49,-65,38,65,-70,0,70,-65,-38,65,-50,-70,49,-27,-92,27,-92,38,0,-92,-38,0,-38,-92,0,0,-100,0
};
int cube_faces[] = {
4,56,9,10,2,1,5,6,57,4,10,11,55,2,6,7,58,57,11,3,55,7,8,56,3,8,9,1,19,5,10,9,16,17,6,5,12,13,11,10,17,18,7,6,13,14,58,11,18,8,7,14,15,9,8,15,16,5,19,12,16,15,23,24,12,19,20,17,16,24,25,13,12,20,21,18,17,25,26,14,13,21,22,58,18,26,15,14,22,23,58,26,33,23,22,29,30,24,23,30,31,20,19,27,25,24,31,32,21,20,27,28,26,25,32,33,22,21,28,29,33,32,39,40,29,28,35,36,58,33,40,30,29,36,37,31,30,37,38,27,19,34,32,31,38,39,28,27,34,35,39,38,45,46,35,34,41,42,40,39,46,47,36,35,42,43,58,40,47,37,36,43,44,38,37,44,45,34,19,41,45,44,51,52,41,19,48,46,45,52,53,42,41,48,49,47,46,53,54,43,42,49,50,58,47,54,44,43,50,51,58,54,57,51,50,55,3,52,51,3,56,48,19,1,53,52,56,4,49,48,1,2,54,53,4,57,50,49,2,55
};  
int cube_2d[58*2];          


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
  tgi_gotoxy(cube_2d[0], cube_2d[1]);
  // DRAW LINES BETWEEN VERTICES BASED ON FACES DEFINITION
  for (f; f<=sizeof(cube_faces)/sizeof(cube_faces[0])-1; f++) {
    face_index = (cube_faces[f]*2)-2;
    x3 = cube_2d[face_index+0];
    y3 = cube_2d[face_index+1];
    tgi_lineto(x3,y3);
  } /* for */
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
    /* WAIT */
    cprintf("%s\n", "PRESS KEY TO PROCEED");    
    cgetc();
    clrscr();
    /* TGI */
    tgi();
    // LOOP
    //while (1) {                 
      /* PROJECTION */
      draw_model();
      // CLEAR SCREEN
      if (i % 2 == 0 ) {
        //tgi_clear();
        //start_x+=5;
      } /* if */     
      ++i;
    //} /* while */
    /* EXIT */
    return 0;
} /* main */
