#include <stdio.h>

void main()
{
	int arr[10]={0,};
	int i=0;
	
	
	for(i=0;i<10;i++)
	{
	printf("[%d/10]���ڵ��� �Է�: ",i+1);
	scanf("%d",&arr[i]);
	
	}
	
	
	int max=0;
	int min=100;
	
	for(i=0;i<10;i++)
	{
		if(max<=arr[i])
		max=arr[i];
		if(min>=arr[i])
		min=arr[i];	
	}
	
	printf("�ִ밪: %d\n",max);
	printf("�ּҰ�: %d\n",min);
}

