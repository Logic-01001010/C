#include <stdio.h>
#include <time.h>

typedef struct RandomStruct
{
	int num;
	
	int i;
	
	int win;
	
	int ran;
	
	int count;
		
} RAN;


int main(void)
{
	srand(time(NULL)); // ���� ���� (�ð��� ��������)
	
	RAN R;
	
	R.win=0; // ��÷ Ƚ�� 0���� �ʱ�ȭ. 
	
	
	printf("��í�� ��� �ݺ��ұ��?\n�Է�$> ");
	scanf("%d",&R.count);
	
	
	printf("\n\nȮ���� ����ּ���!\n\tex) 20, 40, 60, 80, 100\n�Է�$> ");
	scanf("%d", &R.ran);
	printf("�Է��Ͻ� Ȯ���� %d%%�Դϴ�.\n\n",R.ran);
	
	for(R.i=0;R.i<R.count;R.i++) // 10�� �ݺ� 
	{
		R.num = rand()%100; // 0~99���� ���� ���ڸ� ���մϴ�. 
		
		printf("[%d��°] %d\n",R.i,R.num);
		
		
		if(R.num < R.ran) // ���� ���ڰ� ����� Ȯ�� ���ں��� ���� ���. 
		{
			printf("�� ��÷! = %d\n",R.num);
			R.win++;
		}
		
		
	}
	
	
	printf("\n��÷ Ƚ�� = %d\n", R.win);
	
	
	return 0;
}

