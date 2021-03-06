#include <stdio.h>
#include <assert.h>


typedef unsigned char byte; //8 bit
typedef unsigned short int word; //16 bit
typedef word Adress;  //16 bit

#define MEMSIZE (64*1024)

byte mem[MEMSIZE]; //массив типа byte размера MEMSIZE
void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void w_write(Adress adr, word w);
word w_read(Adress adr);

void test_mem(){
    //Пишем байт, читаем байт
    byte b0 = 0x0a;
    b_write(2, b0);
    byte bres =  b_read(2);
    printf("%02hhx == %02hhx\n",b0, bres);


    //Пишем 2 байта, читаем слово
    Adress a=4;
    byte b1 = 0x0b;
    b0 = 0x0a;
    word w = 0x0b0a;
    b_write(a, b0);
    b_write(a+1, b1);
    word wres = w_read(a);
    printf("%04hx == %02hhx%02hhx\n", wres, b1, b0);
    assert(w = wres);

    // Пишем слово, читаем слово
    word w1 = 0x0c0a;
    w_write(6, w1);
    word w1res = w_read(6);
    printf("%04hx == %04hx\n", w1, w1res);
    assert(w1 = wres);

    // Пишем одно слово, читаем 2 байта
    Adress a1 = 8;
    word w2 = 0x0c0b;
    w_write(a1, w2);
    byte b2 = b_read(a1);
    byte b3 = b_read(a1+1);
    word w2res = w_read(a1);
    printf("%02hhx%02hhx == %04hx\n", b3, b2, w2res);
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
    byte b1 = ((byte)(w >> 8));
    byte b0 = ((byte)(w & 0xFF));
    mem[adr] = b0;
    mem[adr+1] = b1;
}

word w_read(Adress a){
    word w =  ((word)mem[a+1]) << 8; //Сдвинули старший байт
    w = w | mem[a];
    printf("w = %x\n",w);
    return w;
}
