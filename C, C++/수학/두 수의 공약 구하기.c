#include <windows.h>
#include <stdio.h>

int main(void)
{
	int a=0;
	int b=0;
	int i=0;
	int toggle=0;
	
	printf("����� ����\n"); 
	
	printf("���� ���� �Է�\nA: ");
	scanf("%d",&a);
	printf("B: ");
	scanf("%d",&b);
	
	int min;
	if(a>=b)
	min=b;
	else
	min=a;
	
	printf("�ּ� ����: %d\n",min);
	

	for(i=1;i<=min;i++)
	{
		
		if(a % i == 0 && b % i == 0)
		{
		printf("\n�� ���� ������� :%d \n",i);
		
		toggle++;
		}
		

		
	}

	if(toggle==1)
	printf("\n[�μ��� ���μ�!]\a\n");
	system("pause");
	return 0;
}
