#ifndef _AFIO_H_
#define _AFIO_H_

#define AFIO_Base	0x40010000
#define AFIO_EXTICR1	*((volatile unsigned int *)(AFIO_Base + 0x08))

#endif
