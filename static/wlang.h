#include<windows.h>
#include<iostream>
#include<fstream>
#include<cstdlib> 
#include<cstdio>
#include<string>
#define CLICK 
#define W4 wc.hbrBackground 
#define LPC LPCSTR
#define A LRESULT
#define B CALLBACK
#define C xushi(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
#define P1 DefWindowProc(hwnd,msg,wp,lp)
#define WS_IT WS_OVERLAPPEDWINDOW
#define WS_EDIT WS_CHILD|WS_VISIBLE|WS_BORDER
#define WS_BUTTON WS_CHILD|WS_VISIBLE|WS_BORDER
#define WS_TEXT WS_CHILD|WS_VISIBLE|ES_READONLY 
#define CW CreateWindow
#define D WINAPI
#define E WinMain(HINSTANCE h,HINSTANCE,LPSTR aaa,int bbb)
#define W1 wc.lpfnWndProc=xushi
#define W2 wc.hInstance=h 
#define W3 wc.lpszClassName
#define R RegisterClass(&wc)
#define S ShowWindow(hwnd,bbb)
#define W W1;W2;W3
#define EZ W="xu";R;make("xu","A window",h);S;run();
#define color CreateSolidBrush
#define RED RGB(255,0,0)
#define ORANGE RGB(255,120,0)
#define YELLOW RGB(255,255,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)
#define PURPLE RGB(255,0,255)
#define WS_TWO WS_CHILD|WS_VISIBLE
WNDCLASS wc={};
HMENU BT=(HMENU)BT;
HWND hwnd;
HWND ha;
HWND hb;
HWND hc;
HWND hh;
using namespace std;
MSG msg;
void run(){
	while(GetMessage(&msg,0,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
void make(LPC a,LPC b,HINSTANCE h){
	hwnd=CW(a,b,WS_IT,1,1,3000,3000,0,0,h,0);
}
HWND Make(HWND hwn,LPC a,LPC b,DWORD c,int X,int Y,int width,int height,HMENU hmu){
	return CW(
	a,b,c,X,Y,width,height,
	hwn,hmu,0,0
	);
}
void drawimg(HWND hwn,LPCSTR a,int x,int y,int x1,int y1){
	PAINTSTRUCT pt;
	HDC b=BeginPaint(hwn,&pt);
	HBITMAP c=(HBITMAP)LoadImage(0,a,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	HDC d=CreateCompatibleDC(b);
	SelectObject(d,c);
	BitBlt(b,x,y,x1,y1,d,0,0,SRCCOPY);
	EndPaint(hwn,&pt);
}
