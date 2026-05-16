#include<stdio.h>
struct bitfield
{
    unsigned int firstbit:1;
    unsigned int secondbit:2;
    unsigned int thirdbit:3;
};




int main()
    {
        struct bitfield b;

        b.firstbit=1;
        b.secondbit=2;
        b.thirdbit=6;

        printf("first bit:=%u\n",b.firstbit);
        printf("second bit:=%u\n",b.secondbit);
        printf("third bit:=%u\n",b.thirdbit);

       printf("size of the bitfield:%u\n",sizeof( struct bitfield));

       return 0;


    }
