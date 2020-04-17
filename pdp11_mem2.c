#include <stdio.h>
#include <assert.h>


typedef unsigned char byte; //8 bit
typedef unsigned short int word; //16 bit
typedef word Adress;  //16 bit

#define MEMSIZE (64*1024)

word mem[MEMSIZE]; //массив типа byte размера MEMSZIE
void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void w_write(Adress adr, word w);
word w_read(Adress adr);

void test_mem(){
    //Пишем байт, читаем байт
    word w0 = 0x0b0a;
    w_write(2, w0);
    word wres =  w_read(2);
    printf("04hx == %04hx",w0, wres);


    //Пишем 2 байта, читаем слово
    Adress a=4;
    byte b1 = 0x0b;
    byte b0 = 0x0a;
    word w = 0x0b0a;
    w_write(a, w);
    byte b0res = b_read(a);
    byte b1res = b_read(a+1);
    printf("%04hx=%02hhx%02hhx\n", w, b1res, b0res);
    assert(b0 = b0res);
    assert(b1 = b1res);

    // Пишем слово, читаем слово
}

int main() {
    test_mem();
    return 0;
}

void b_write(Adress adr,byte b){
    if (adr % 2 == 0){
        mem[adr] = b & 0xFF;
    } else {
        mem[adr-1] = ((word)(b << 8)) | mem[adr-1];
    }
}

byte b_read(Adress adr){
    byte b;
    if (adr % 2 == 0){
        b = mem[adr] & 0xFF;
    } else {
        word w = mem[adr-1];
        b = w >> 8 & 0xFF;// байт по адрессу 5 мы достаем из слова по адрессу 4
    }
    return b;

}

void w_write(Adress adr, word w){
    assert (adr % 2 == 0);
    mem[adr] = w;
}

word w_read(Adress adr){
    return mem[adr];
}

