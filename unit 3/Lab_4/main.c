/* Mahmoud Hussein */ 

#define SYSCTL_RGGC2_R *((volatile long *) (0x400FE108))
#define GPIO_DATA_R *((volatile long *) (0x400253FC))
#define GPIO_DIR_R *((volatile long *) (0x40025400))
#define GPIO_DEN_R *((volatile long *) (0x4002551C))

void main () 
{
	volatile int delay ;
	SYSCTL_RGGC2_R=0x00000020;
	
	for (delay=0; delay <= 200 ; delay ++) ; 
	
	
	GPIO_DIR_R |= 1<<3;
	GPIO_DEN_R |= 1<<3;
	
	while (1)
	{
	GPIO_DATA_R |= 1<<3 ; 
	for (delay=0; delay <= 200000 ; delay ++) ; 
	GPIO_DATA_R &= ~(1<<3); 
	for (delay=0; delay <= 200000 ; delay ++) ; 
	}
	
	
}
