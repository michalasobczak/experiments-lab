int * matMV(int a[], int b[]) {
  int p1,p2,p3 = 0;
  static int r[3];

  p1 = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
  p2 = a[3]*b[0] + a[4]*b[1] + a[5]*b[2];
  p3 = a[6]*b[0] + a[7]*b[1] + a[8]*b[2];
  
  r[0] = p1;
  r[1] = p2;
  r[2] = p3;
  
  return r;
} /* matMV */


int * matS(int a[], int b[]) {
  int *r = malloc(9 * sizeof(int));
  /* */
  if(!r)
    return NULL;
  /* */
  r[0] = a[0]-b[0];
  r[1] = a[1]-b[1];
  r[2] = a[2]-b[2];
  r[3] = a[3]-b[3];
  r[4] = a[4]-b[4];
  r[5] = a[5]-b[5];
  r[6] = a[6]-b[6];
  r[7] = a[7]-b[7];
  r[8] = a[8]-b[8];
  
  return r;
} /* matS */


/* *********************** */
/* getT                    */
/*   sin = 0               */
/*   cos = 1               */
/* *********************** */
int getT(int f, int val) {
  int newEntry = 0;
   if (f == 0) {
      newEntry = val; //Math.sin(val);
    }
    else if (f == 1) {
      newEntry = val; //Math.cos(val);
    }
    return newEntry;
} /* getT */


/* *********************** */
/* transform3Into2_NEW     */
/* *********************** */
int transform3Into2_NEW(int x, int y, int z, int cx, int cy, int cz, int th_x, int th_y, int th_z) {
  /* *********************** */
  /* DATA                    */
  /* *********************** */
  
  // matM                    
  int p1,p2,p3,p4,p5,p6,p7,p8,p9 = 0;
  int matM[9];
  int matM2[9];
  
  // getM                    
  // var d_1x2x3 = getM(th);
  int d1[9] = {
    1,               0,                0                  ,
    0,               100,              100                ,
    0,               100,              100                };
  int d2[9] = {
    100,             0,                100                ,
    0,               1,                0                  ,
    100,             0,                100                };
    int d3[] = {
    100,            100,               0                  ,
    100,            100,               0                  ,
    0,              0,                 1                  };
    
  /* *********************** */
  /* PROGRAM                 */
  /* *********************** */
  // getM
  // d1
  d1[4] = getT(1, th_x);
  d1[5] = -1 * getT(0, th_x);
  d1[7] = getT(0,th_x);
  d1[8] = getT(1,th_x);
  // d2
  d2[0] = getT(1,th_y);
  d2[2] = getT(0,th_y);
  d2[6] = -1*getT(0,th_y);
  d2[8] = getT(1,th_y);
  // d3
  d3[0] = getT(1,th_z);
  d3[1] = -1*getT(0,th_z);
  d3[3] = getT(0,th_z);
  d3[4] = getT(1,th_z);
  // 
  
  // matM
  //var d1d2 = matM(d1,d2);  
  p1 = d1[0]*d2[0] + d1[1]*d2[3] + d1[2]*d2[6];
  p2 = d1[0]*d2[1] + d1[1]*d2[4] + d1[2]*d2[7];
  p3 = d1[0]*d2[2] + d1[1]*d2[5] + d1[2]*d2[8];
  p4 = d1[3]*d2[0] + d1[4]*d2[3] + d1[5]*d2[6];
  p5 = d1[3]*d2[1] + d1[4]*d2[4] + d1[5]*d2[7];
  p6 = d1[3]*d2[2] + d1[4]*d2[5] + d1[5]*d2[8];
  p7 = d1[6]*d2[0] + d1[7]*d2[3] + d1[8]*d2[6];
  p8 = d1[6]*d2[1] + d1[7]*d2[4] + d1[8]*d2[7];
  p9 = d1[6]*d2[2] + d1[7]*d2[5] + d1[8]*d2[8];
  matM[0] = p1;
  matM[1] = p2;
  matM[2] = p3;
  matM[3] = p4;
  matM[4] = p5;
  matM[5] = p6;
  matM[6] = p7;
  matM[7] = p8;
  matM[8] = p9;
  
  // matM2
  //var newEntry = matM(d1d2,d3);
  
 
  
  /*
  var d4 = [
    x,
    y,
    z
  ];
  var d5 = [
    cx,
    cy,
    cz
  ];
  */

  /* *********************** */
  /* matS                    */
  /* *********************** */
  //var d4subd5 = matS(d4,d5);
  
  /* *********************** */
  /* matMV                   */
  /* *********************** */
  //var d = matMV(d_1x2x3, d4subd5);
  
  /* *********************** */
  /* getB                    */
  /* *********************** */
  //var b = getB(d[0],d[1],d[2]);
  
  /* *********************** */
  /* return                  */
  /* *********************** */
  //return b;
} /* transform3Into2_NEW */
