#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int saha[80][23]={0};
int k,l;
int kuyruksutun[300],kuyruksatir[300]; // kuyruk buyusun diye
int devam=1;
void gotoxy(short x,short y){
	HANDLE hConsoleOutput;
	COORD Cursor_Pos= {x-1,y-1};
	hConsoleOutput=GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,Cursor_Pos);
}
void cerceve(int x1,int y1,int x2,int y2,int tip ){
	int i;
	for(i=x1;i<x2;i++){
		saha[i][y1]=tip;
		saha[i][y2]=tip;
	}
	for(i=y1;i<y2;i++){
		saha[x1][i]=tip;
		saha[x2][i]=tip;
	}
}
void ekranyaz(){
	int x,y;
	for(x=0;x<80;x++){
		for(y=0;y<23;y++){
			gotoxy(x+1,y+1);
			if(saha[x][y]==2){
				printf("%c",176);
			}
		}
	}
}
int randomata(){
	srand(time(NULL));
	k=4+rand()%65;
	l=4+rand()%15;
	
}
int main(){
	randomata();
	cerceve(0,0,79,22,2);
	ekranyaz();
	int sx=40,sy=12;
	unsigned char tus;
	int dx=0,dy=0,a=0,i;  // a kyruk icin
	
	do {
	if(kbhit()){
		tus=getch();
		if(tus==224){
			tus=getch();
			switch(tus){
				case 72: dy=-1;dx=0;
				    break;
				case 80: dy=1;dx=0;
				    break;
				case 77: dx=1;dy=0;
				    break;
				case 75: dx=-1;dy=0;
			}
		}
	}
	sx+=dx;
	sy+=dy;
	if(sx>78) sx=2;
	if(sx<2) sx=78;
	if(sy>22) sy=2;
	if(sx<2) sx=22;
	kuyruksutun[0]=sx;
	kuyruksatir[0]=sy;
	
	for(i=1;i<=a;i++){
		if(sx==kuyruksutun[i] && sy==kuyruksatir[i]){
		    gotoxy(sx,sy); printf("..YANDiNiZ..");
	    	getch();
	    	devam=0;	
		}
	}
	
	gotoxy(sx,sy); printf("*");
	
	for(i=0;i<=a;i++){
		gotoxy(kuyruksutun[i],kuyruksatir[i]);
		printf("*");
	}
	
	if(sx==k && sy==l){
		randomata();
		a++;
		gotoxy(2,2); printf("point:%d ",a);
	}
	
	gotoxy(k,l);for(int a=0;a<45;a++){printf("A");
	} 
	Sleep(75);
	gotoxy(sx,sy); printf(" ");
	
	for(i=0;i<=a;i++){
		gotoxy(kuyruksutun[i],kuyruksatir[i]);
		printf(" ");
	}
	
	for(i=a;i>0;i--){
		kuyruksutun[i]=kuyruksutun[i-1];
		kuyruksatir[i]=kuyruksatir[i-1];
	}
}
	while(devam==1);	
}
