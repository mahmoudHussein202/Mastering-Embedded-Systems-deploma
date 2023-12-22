#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_

#define read_pin(reg,pin_num)                           ((reg&1<<pin_num)>>pin_num)
#define set_pin(reg,pin_num)                            (reg|=1<<pin_num)
#define clear_pin(reg,pin_num)                          (reg&=~(1<<pin_num))
#define toggle_pin(reg,pin_num)                         (reg^=1<<pin_num)
#define set_multiple_pins(module,first_position,value)  {\
                                                        unsigned int value_inverted = ~(value);\
                                                        module|= value<<first_position;\
                                                        module&=~(value_inverted << first_position);\
                                                        }
#define delay_us(time_out)                              for(int i=0;i<time_out;i++)   
#endif
                                                        