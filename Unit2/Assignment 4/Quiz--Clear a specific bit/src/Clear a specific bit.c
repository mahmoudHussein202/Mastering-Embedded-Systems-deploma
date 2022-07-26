

#include <stdio.h>
#include <stdlib.h>
int clear_bit(int num, int bit_num);
int main()
{
	int n,n_b;
	printf("enter the number : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	printf("enter bit number : ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&n_b);

	printf("Result = %d",clear_bit(n,n_b));
	return 0;
}
int clear_bit(int num, int bit_num){
	num &= ~(1<<bit_num);
	return num;
}
