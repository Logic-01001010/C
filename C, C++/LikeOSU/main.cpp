#include <iostream>
#include <windows.h>


void TITLE(void)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("[Like ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
	printf("OSU");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("]\n");
}

int main(void)

{
HWND consoleWindow = GetConsoleWindow();	

::SetWindowPos(consoleWindow, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
::ShowWindow(consoleWindow, SW_NORMAL);

system("mode con:cols=30 lines=10");

 
 SetWindowPos( consoleWindow, 0, 2700, 1700, 0, 0, SWP_NOSIZE | SWP_NOZORDER ); 
 char i;
 bool toggle=true;

	TITLE();

 while(1)
 {

 Sleep(10);

 for(i=8;i<=255;i++)
 {
 SetWindowPos( consoleWindow, 0, 2700, 1700, 0, 0, SWP_NOSIZE | SWP_NOZORDER ); 
 	

  if(GetAsyncKeyState(i)==-32767)  
 {
 	
	if(i==VK_MBUTTON)
	{
	//printf("���콺 ��� ��ư Ŭ��\n");
	
	if(toggle==true)
	{
	system("cls");
	TITLE();
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
	printf("\nOSU��� OFF\a\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	toggle=false;
	}
	else if(toggle==false)
	{
	system("cls");
	TITLE();
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
	printf("\nOSU��� ON\a\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	toggle=true;
	}
	}
 }
 
 
 
 if(toggle==true)
 {

 if(GetAsyncKeyState(0x5A))  
 {
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); 
 Sleep(10);
	 
	  if(!GetAsyncKeyState(0x5A))
	 {
	 	Sleep(10);
	 	//printf("'z'�� ������ ��Ȳ\n");
	 	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	 }

 }
 
 if(GetAsyncKeyState(0x58))  
 {
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); 
 Sleep(10);
	 
	  if(!GetAsyncKeyState(0x58))
	 {
	 	Sleep(10);
	 	//printf("'x'�� ������ ��Ȳ\n");
	 	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	 }

 }
}

 }
 }

 

 return 0;

}
