#include <stdio.h>gcc
#include <assert.h>


typedef unsigned char byte; //8 bit
typedef unsigned short int word; //16 bit
typedef word Adress;  //16 bit

#define MEMSIZE (64*1024)

byte mem[MEMSIZE]; //массив типа byte размера MEMSZIE
void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void w_write(Adress adr, word w);
word w_read(Adress adr);

void test_mem(){
    //Пишем байт, читаем байт
    byte b0 = 0x0a;
    b_write(2, b0);
    byte bres =  b_read(2);
    printf("02hhx == %02hhx",b0, bres);


    //Пишем 2 байта, читаем слово
    Adress a=4;
    byte b1 = 0x0b;
    b0 = 0x0a;
    word w = 0x0b0a;
    b_write(a, b0);
    b_write(a+1, b1);
    word wres = w_read(a);
    printf("%04hx=%02hhx%02hhx\n", wres, b1, b0);
    assert(w = wres);
}

int main() {
    test_mem();
    return 0;
}

void b_write(Adress adr,byte b){
    mem[adr] = b;
}

byte b_read(Adress adr){
    return mem[adr];
}

void w_write(Adress adr, word w){
    mem[adr] = w;
}

word w_read(Adress a){
    word w =  ((word)mem[a+1]) << 8;//Сдвинули старший байт
    w = w | mem[a];
    printf("w = %x\n",w);
    return w;
}
