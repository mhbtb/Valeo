#ifndef PCSIMUTYPES_H
#define PCSIMUTYPES_H


#define word unsigned int
#define uByte unsigned char                /* unsigned 8 bit type definition  */
#define uWord unsigned int                 /* unsigned 16 bit type definition */
#define sbyte signed char
#define sword signed int



typedef unsigned char * pbyte;
typedef unsigned char * psbyte;
typedef unsigned int * pword;
typedef signed int * psword;
typedef const unsigned char cbyte;
typedef const signed char csbyte;
typedef const unsigned int cword;
typedef const signed int csword;

typedef unsigned char byte ;
typedef struct
  {
    unsigned char B0:1;
    unsigned char B1:1;
    unsigned char B2:1;
    unsigned char B3:1;
    unsigned char B4:1;
    unsigned char B5:1;
    unsigned char B6:1;
    unsigned char B7:1;
  } Bit_Feld;

typedef union
  {
    Bit_Feld Bit;
    unsigned char AllBit;
  } Flag;
#undef TRUE
#undef FALSE
#define TRUE 1
#define FALSE 0


#endif // PCSIMUTYPES_H
