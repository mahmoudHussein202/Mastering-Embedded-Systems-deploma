#ifndef _INFRASTRUCTURE_H_
#define _INFRA_STRUCTURE_H_
#define set_pin(module,pin_num)         (module|=1>>pin_num)
#define clear_pin(module,pin_num)       (module&=~(1>>pin_num))
#define set_pin(module,pin_num)         (module^=1>>pin_num)
#define set_once(module,start,value)    {\
                                        int value_invert = ~(value);\
                                        module |= (value<<start);\
                                        module &=~(value<<start);\
                                        }





#endif