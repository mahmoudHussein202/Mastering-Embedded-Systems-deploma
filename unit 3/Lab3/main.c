typedef volatile unsigned int vuint32_t;
typedef unsigned int uint32_t;

#define RCC_Base_Address 0x40021000
#define GPIO_PA_Base_Address 0x40010800

#define APB2ENR *((vuint32_t*)(RCC_Base_Address + 0x18))
#define CRH_REG *((vuint32_t*)(GPIO_PA_Base_Address + 0x04))
#define GPIO_ODR_REG *((vuint32_t*)(GPIO_PA_Base_Address+0x0C))


void main()
{
    APB2ENR |= 1<<2;
    CRH_REG &= 0xFF0FFFFF;
    CRH_REG |= 0x00200000;
    while (1)
    {
        GPIO_ODR_REG = 0xFFFFFFFF;
        for (int i = 0 ; i<5000; i++);
        GPIO_ODR_REG = 0x00000000;
        for (int i = 0 ; i<5000; i++);
    }
    
}