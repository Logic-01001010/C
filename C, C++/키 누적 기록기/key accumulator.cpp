#include <iostream>
#include <stdio.h>
#include <conio.h> 
#include <windows.h>

int main(void)
{
	printf("key accumulator\n");
	char accumulator[128]={0,};
	
	

	
	
	
	int getkey=0; //���� getkey ����
	
	 while(1) //�ð��� �帧
	
	 {

	
	  if(kbhit()==1) //���ǹ�: Ű�� ����, Ű�� ������ ����
	  {
	
	   
	   
	
		for(int i=0;i<128;i++)
		{
			
			getkey = getch(); //���ڸ� �Է� �޾Ƽ� ���� getkey�� ����
			printf("[%d]<%c>\n",i,getkey); //getkey�� ���
			
			FILE *fp;
		
			fp=fopen("accumulator.txt","wt");
			if(fp==NULL)
			{
				printf("���� ����.\n");
				return 0;
			}
			
			
			
			
			accumulator[getkey]++;
		

			for(int i=0;i<128;i++)
			{
				printf("[%c]: ",i);
				printf("%d",accumulator[i]);
				printf("\n");
				
				
				fprintf(fp,"%c: ",i);
				fprintf(fp,"%d\n",accumulator[i]);
			
			}				
			
	
		fclose(fp);		
		}
		
	
	
	
	  }
	
	  
	
	  //printf("<UnhitKeyboard>\n"); //Ű���带 �ƹ��͵� ������ ������ ���
	
	  Sleep(100); //�ð��� �帧�� ����
	
	 }
	

	
	
	
	
	return 0;
}
