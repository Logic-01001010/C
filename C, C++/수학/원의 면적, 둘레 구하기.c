#include <stdio.h>
#define Pi 3.14
void main()
{
	int r=0;
	float result=0;
	
	printf("���� �������� �Է��ϼ���: ");
	scanf("%d",&r);
	
	result = r*r*Pi;
	printf("���� ����: %f\n",result);
	
	result = r*2*Pi;
	printf("���� �ѷ�: %f\n",result);
}

