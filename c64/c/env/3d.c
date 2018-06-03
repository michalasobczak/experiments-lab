int* matM(int a[], int b[]) {
  int p1,p2,p3,p4,p5,p6,p7,p8,p9 = 0;
  static int r[9];
  
  p1 = a[0]*b[0] + a[1]*b[3] + a[2]*b[6];
  p2 = a[0]*b[1] + a[1]*b[4] + a[2]*b[7];
  p3 = a[0]*b[2] + a[1]*b[5] + a[2]*b[8];
  
  p4 = a[3]*b[0] + a[4]*b[3] + a[5]*b[6];
  p5 = a[3]*b[1] + a[4]*b[4] + a[5]*b[7];
  p6 = a[3]*b[2] + a[4]*b[5] + a[5]*b[8];

  p7 = a[6]*b[0] + a[7]*b[3] + a[8]*b[6];
  p8 = a[6]*b[1] + a[7]*b[4] + a[8]*b[7];
  p9 = a[6]*b[2] + a[7]*b[5] + a[8]*b[8];

  r[0] = p1;
  r[1] = p2;
  r[2] = p3;
  r[3] = p4;
  r[4] = p5;
  r[5] = p6;
  r[6] = p7;
  r[7] = p8;
  r[8] = p9;
  
  return r;
} /* matM */


int* matMV(int a[], int b[]) {
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
  int *r = malloc(9);
  printf("matS => sizeof(a) = %d\n", sizeof(a));
  printf("matS => sizeof(b) = %d\n", sizeof(b));
  /* */
  if(!r)
    return NULL;
  /* */
  printf("matS => 0 => %d\n", a[0]);
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


/*
getB = function(dx,dy,dz) {
    var newEntry = Vector2(0,0);
    var ezDivDz = -700 / dz;
    newEntry.x = -1*(dx*ezDivDz) + canvasWidthHalf;
    newEntry.y = dy*ezDivDz;
    return newEntry;
  }
}
*/