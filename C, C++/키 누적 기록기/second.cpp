#include <windows.h>
#include <stdio.h>
#include <iostream>

int main(void)
{
	char input=0;
	

	
	int array[10]={0,}; // 1
	int count[10]={0,}; // 1
	
	
	for(int i=0;i<10;i++) // 1
	{
		scanf("%d",&input);
		
		for(int j=0;j<11;j++) // �����°� 
		{
	
			if(j==10)
			{
				array[i]=input;
				count[i]++;
				printf("array[%d]=%d\n",i,input);
				printf("������ ����.\n");
				break;
			}	
			
			if(input==array[j]) // �Է��Ѱ� ��̶� ����? �� 1 == 0 
			{
				printf("Ż�� �Է�: %d == ���[j]: %d \n",input,array[j]);
				count[j]++;
				break;
			}
			
	

		}
		
	}
	
	for(int i=0;i<10;i++)
	{
		printf("%d: ",array[i]);
		printf("%d\n",count[i]);
	}
	
	
}
