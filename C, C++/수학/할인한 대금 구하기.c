#include <stdio.h>

void main()
{
	int danga=0, gaesu=0, payment=0;;
	
	printf("�ܰ�=");
	scanf("%d", &danga);
	
	printf("�Ż� ���� = ");
	scanf("%d",&gaesu);
	
	if(gaesu >= 1000) // �ֹ� ������ 1000�� �̻��̸� 20% ���� 
	{
		payment = (danga*gaesu)-((danga*gaesu) * 0.20 );
	}
	else
	{
		payment = (danga*gaesu)-((danga*gaesu) * 0.10 );
	}
	
	printf("��� = %d\n",payment);
}

