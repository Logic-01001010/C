#include <stdio.h>

void main()
{
	int input=0;
	printf("���� �Է�: ");
	scanf("%d",&input);
	
	int hour= input/60;
	int min = input%60;
	
	printf("%d���� %d�� %d���̴�.\n",input ,hour,min);
	
}

