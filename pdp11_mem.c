 #include <stdio.h>
#include <tclDecls.h>

#include "pdp11.h"
typedef unsigned char byte; //8 bit
typedef unsigned short int word; //16 bit
typedef word Adress;  //16 bit

#define MEMSIZE (64*1024)

byte mem[MEMSIZE]; //массив типа byte размера MEMSZIE
void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void w_write(Adress adr, word w);
word w_read(Adress adr);

int main() {
    return 0;
}