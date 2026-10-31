typedef unsigned char byte;
typedef unsigned word;
byte TMP1 = 0;
byte TMP2 = 0;
unsigned int base_screen = 0xE000;  
unsigned int base_color = 0xD000; 
unsigned char color = 2;


void print_binary(unsigned int n) {
  while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");
    n >>= 1;
  }
  printf("\n");
}
int set_nth_bit(int num, int n){
    return (num | 1 << n);
}
int clear_nth_bit(int num, int n){
    return (num & ~( 1 << n));
}
int toggle_nth_bit(int num, int n){
    return num ^ (1 << n);
}
int check_nth_bit(int num, int n){
    return num & (1 << n);
}
// VIDEO CLEAR BUFFER
void video_clear() {
  unsigned int i = base_screen;
   // CLEAR
  for (i; i<=base_screen+7999; i++) { 
    //*(byte*) i = 0x01;
  } // for
  i = base_color;
  for (i; i<=base_color+1023; i++) {
    //*(byte*) i = 0;
  } // for
} // video_clear
// VIDEO INIT
void video_init() {
  printf("video_init\n");
  // DATA DIRECTION
  TMP1 = *(byte*) 0xDD02;
  TMP1 = TMP1 | 3;
  *(byte*) 0xDD02 = TMP1;
  // VIC-II BANK
  TMP1 = *(byte*) 0xDD00;
  TMP1 = TMP1 & 252;
  //TMP1 = TMP1 | 1;
  *(byte*) 0xDD00 = TMP1;
  // BITMAP LOCATION, RELATIVE TO VIC-II BANK
  // POKE53272,PEEK(53272)OR8
  //TMP2 = *(byte*) 0xD018;
  //TMP2 = TMP2 | 8;
  *(byte*)0xD018 = 0x48;
  // BITMAP MODE
  // 10 POKE53265,PEEK(53265)OR32
  TMP1 = *(byte*) 0xD011;
  TMP1 = TMP1 | 32;  
  *(byte*) 0xD011 = TMP1;
  // HIGH BYTE
  //*(word*)0x0288 = 128; 
  // INITIALLY CLEAR THE BUFFER
  video_clear();
} // video_init
// VIDEO EXIT
void video_exit() {
  // POKE53265,PEEK(53265)AND223
  TMP1 = *(byte*) 0xD011;
  TMP1 = TMP1 & 223;  
  *(byte*) 0xD011 = TMP1;
  printf("\n\nDONE!\n");
} // video_exit
// VIDEO GOTOXY
void video_gotoxy(unsigned char x, unsigned char y) {
  x = 0;
  y = 0;
} // video_gotoxy
void video_lineto(unsigned char x, unsigned char y) {
  x = 0;
  y = 0;
} // video_lineto
