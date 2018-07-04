/* ******** */
/* INCLUDES */
/* ******** */
#include <tgi.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cbm.h>
// GENERIC
#include "env\3d.c"
#include "env\video.c"


/* ******** */
/* DATA     */
/* ******** */
byte B1 = 0;
byte B2 = 0;
byte F1 = 0;
byte F2 = 0;
byte K  = 0;
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
unsigned char rxA = 0;
unsigned char ryA = 0;
// MODEL
int cube_vertices[] = { 
-100,-100,100,-100,100,100,-100,-100,-100,-100,100,-100,100,-100,100,100,100,100,100,-100,-100,100,100,-100
}; 
unsigned char cube_faces[] = {
2,4,3,1,4,8,7,3,8,6,5,7,6,2,1,5,1,3,7,5,6,8,4,2
};  
unsigned char cube_2d[8*2]; 
unsigned int vertices_counter = 0;

/* ********* */
/* FUNCTIONS */
/* ********* */

// DRAW BORDER
void draw_border() {
  tgi_gotoxy(0,0);
  tgi_lineto(255,0);
  tgi_lineto(255,199);
  tgi_lineto(0,199);
  tgi_lineto(0,0);
} /* draw_border */
// DRAW MODEL
void draw_model() {
  unsigned int mv  = 0;               // model vertices
  unsigned int vc = 0;                // mv counter
  unsigned int mf  = 1;               // model faces
  unsigned int fc = 0;                // mf counter
  int x2, y2, z2 = 0;                 // 3D base + point
  register unsigned char x3, y3 = 0;  // 2D equivalent
  //
  /* CALCULATE 2D POINTS */
  for (mv; mv<=sizeof(cube_vertices)/sizeof(cube_vertices[0])-3; mv=mv+3) {
    x2 = start_x+cube_vertices[mv+0];
    y2 = start_y+cube_vertices[mv+1];
    z2 = start_z+cube_vertices[mv+2];
    // CHOOSE BETWEEN...
      // PERSPECTIVE
      //transform3Into2_NEW(&rxA,&ryA, x2,y2,z2, camera_x,camera_y,camera_z, th_x,th_y,th_z); 
      // AND ORTOGRAPHIC 
      ortographic_projection(&rxA,&ryA, x2,y2,z2, 4,4, 4,4);
    // ...PROJECTION
    vertices_counter = vertices_counter + 1;
    //printf("%d,%d,%d => %d x %d\n", x2,y2,z2, rxA,ryA);
    cube_2d[vc+0] = rxA;
    cube_2d[vc+1] = ryA;
    vc+=2;
  } /* for */
  //return;
  tgi_clear();
  //video_clear();
  tgi_gotoxy(cube_2d[0], cube_2d[1]);
  //video_gotoxy(cube_2d[0], cube_2d[1]);
  // DRAW LINES BETWEEN VERTICES BASED ON FACES DEFINITION
  for (mf; mf<=sizeof(cube_faces)/sizeof(cube_faces[0])-1; mf++) {
    fc = (cube_faces[mf]*2)-2;
    x3 = cube_2d[fc+0];
    y3 = cube_2d[fc+1];
    tgi_lineto(x3,y3);
    //video_lineto(x3,y3);
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
    unsigned int direction = 1;
    unsigned char should_run = 1;
    unsigned char key = 0;
    unsigned char page = 0;
    /* TGI */
    tgi();
    //video_init();
    /* RESET TIMER */
    *(byte*) 0x00a1 = 0;
    *(byte*) 0x00a2 = 0;      
    // LOOP
    while (should_run) {                 
      /**************/
      /* PROJECTION */
      /**************/
      draw_model();
      draw_border();
      /* MOVE */
      K = *(byte*) 0x00CB;  
      if (K == 10) { direction = -1; start_x+=4*direction;  }
      else if (K == 18) { direction = 1; start_x+=4*direction;  }
      /* PERFORMANCE */
      if (vertices_counter > 1000) {
        F1 = *(byte*) 0x00a1;
        F2 = *(byte*) 0x00a2;       
        printf("=> vc = %d => %d, %d\n", vertices_counter, F1,F2);              
        *(byte*) 0x00a1 = 0;
        *(byte*) 0x00a2 = 0;        
        tgi_done();
        //video_exit();
        should_run = 0;
      } // if    
    } /* while */
    /* END */
    cprintf("%s\n", "FINISHED");    
    //printf("%d %d", rxA, ryA);
    /* EXIT */
    return 0;
} /* main */
