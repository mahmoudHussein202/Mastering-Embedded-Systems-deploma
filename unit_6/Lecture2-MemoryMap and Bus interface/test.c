#include "stdio.h"
#include "stdint.h"
#define print(...) fflush(stdout); fflush(stdin); printf(__VA_ARGS__); fflush(stdout); fflush(stdin);

struct test
{
    uint32_t pin0 :1 ;
    uint32_t pin1 :1 ;
    uint32_t pin2 :1 ;
    uint32_t pin3 :1 ;
    uint32_t pin4 :1 ;
    uint32_t pin5 :1 ;
    uint32_t pin6 :1 ;
    uint32_t pin7 :1 ;
    uint32_t pin8 :1 ;
    uint32_t pin9 :1 ;
    uint32_t pin10 :1 ;
    uint32_t pin11 :1 ;
};

union REGISTER
{
    uint32_t full_register;
    struct test pins;
};

int register_1;
#define ODR ((volatile union REGISTER *)&register_1)
int main()
{
    ODR->pins.pin0=1;
    print("%d",register_1);
}
