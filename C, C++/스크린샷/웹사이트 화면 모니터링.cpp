#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ole2.h>
#include <olectl.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


bool saveBitmap(LPCSTR filename, HBITMAP bmp, HPALETTE pal);
bool screenCapturePart(int x, int y, int w, int h, LPCSTR fname);


int main(void)
{
	system("title 1.0");
	FreeConsole();
	while(1){

	

	char filename[127] = { 0, };
	//char tmp[10];

	time_t timer;
	struct tm *t;

	timer = time(NULL); // ���� �ð��� �� ������ ���

	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�


	/*
	strcat(filename, "C:\\Users\\annas\\Documents\\����\\screenshot\\"); // ���� ���.
	strcat(filename, _itoa(t->tm_year + 1900,tmp,10)); // �⵵
	strcat(filename, "-");
	strcat(filename, _itoa(t->tm_mon + 1, tmp, 10)); // ��
	strcat(filename, "-");
	strcat(filename, _itoa(t->tm_mday, tmp, 10)); // ��
	strcat(filename, "-");
	strcat(filename, _itoa(t->tm_hour, tmp, 10)); // �ð�
	strcat(filename, "-");
	strcat(filename, _itoa(t->tm_min, tmp, 10)); // ��
	

	strcat(filename, ".bmp");
	*/

	int width = GetSystemMetrics(SM_CXVIRTUALSCREEN); // ȭ�� ���� ũ�� ���ϱ�(��� ����� ����)
	int height = GetSystemMetrics(SM_CYVIRTUALSCREEN); // ȭ�� ���� ũ�� ���ϱ�(��� ����� ����)


	screenCapturePart(0, 0, width, height, "C:\\Apache24\\htdocs\\test.bmp");
	Sleep(5000);
	}
}

bool screenCapturePart(int x, int y, int w, int h, LPCSTR fname)
{


	HDC hdcSource = GetDC(NULL);
	HDC hdcMemory = CreateCompatibleDC(hdcSource);

	int capX = GetDeviceCaps(hdcSource, HORZRES);
	int capY = GetDeviceCaps(hdcSource, VERTRES);

	HBITMAP hBitmap = CreateCompatibleBitmap(hdcSource, w, h);


	HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcMemory, hBitmap);

	BitBlt(hdcMemory, 0, 0, w, h, hdcSource, x, y, SRCCOPY);


	hBitmap = (HBITMAP)SelectObject(hdcMemory, hBitmapOld);

	DeleteDC(hdcSource);
	DeleteDC(hdcMemory);

	HPALETTE hpal = NULL;
	if (saveBitmap(fname, hBitmap, hpal)) return true;
	return false;
}

bool saveBitmap(LPCSTR filename, HBITMAP bmp, HPALETTE pal)
{
	bool result = false;
	PICTDESC pd;

	pd.cbSizeofstruct = sizeof(PICTDESC);
	pd.picType = PICTYPE_BITMAP;
	pd.bmp.hbitmap = bmp;
	pd.bmp.hpal = pal;

	LPPICTURE picture;
	HRESULT res = OleCreatePictureIndirect(&pd, IID_IPicture, false,
		reinterpret_cast<void**>(&picture));

	if (!SUCCEEDED(res))
		return false;

	LPSTREAM stream;
	res = CreateStreamOnHGlobal(0, true, &stream);

	if (!SUCCEEDED(res))
	{
		picture->Release();
		return false;
	}

	LONG bytes_streamed;
	res = picture->SaveAsFile(stream, true, &bytes_streamed);

	HANDLE file = CreateFile(filename, GENERIC_WRITE, FILE_SHARE_READ, 0,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (!SUCCEEDED(res) || !file)
	{
		stream->Release();
		picture->Release();
		return false;
	}

	HGLOBAL mem = 0;
	GetHGlobalFromStream(stream, &mem);
	LPVOID data = GlobalLock(mem);

	DWORD bytes_written;

	result = !!WriteFile(file, data, bytes_streamed, &bytes_written, 0);
	result &= (bytes_written == static_cast<DWORD>(bytes_streamed));

	GlobalUnlock(mem);
	CloseHandle(file);

	stream->Release();
	picture->Release();

	return result;
}
