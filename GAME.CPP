#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#define MAX 4


void shiftRight(int[MAX][MAX],int,int);
void shiftLeft(int[MAX][MAX],int,int);
void shiftUP(int[MAX][MAX],int,int);
void shiftDown(int[MAX][MAX],int,int);
void printMatrix(int arr[MAX][MAX]){
	clrscr();
	int x,y=9;
	textbackground(CYAN);
	textcolor(BLACK);
	gotoxy(25,23);cprintf("PRESS ENTER TWICE/THRICE TO QUIT");
	for(int i=0;i<4;i++)
	{
		x=30;
		for(int j=0;j<4;j++)
		{
		       gotoxy(x,y);
		       cprintf("%d",arr[i][j]);
		       x+=4;
		}
		y+=3;
	}

}
int generateRandom(int arr[MAX][MAX]){

	int num,status=0,ipos,jpos;
	int count=0;
	while(num!=2 && num!=4)
	{
		num=random(5);
		if(num==1) num++;
		if(num==3) num++;
	}
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			if(arr[i][j]!=0)
				count++;
	if(count==MAX*MAX)
		return -1;

	while(!status)
	{
		status=1;
		ipos=random(MAX);
		jpos=random(MAX);
		if(arr[ipos][jpos]==0)
			arr[ipos][jpos]=num;
		else
			status=0;
	}
	return 1;
}

void keyUP(int arr[MAX][MAX]){
	int ipos,jpos,temp;
	for(jpos=0;jpos<MAX;jpos++)
		for(ipos=MAX-1;ipos>0;ipos--)
			if(arr[ipos][jpos]!=0)
			{
				if(arr[ipos-1][jpos]==0){
					arr[ipos-1][jpos]=arr[ipos][jpos];
					arr[ipos][jpos]=0;
					shiftUP(arr,ipos,jpos);
				}else if(arr[ipos-1][jpos]==arr[ipos][jpos]){
					temp=2*arr[ipos][jpos];
					arr[ipos-1][jpos]=temp;
					arr[ipos][jpos]=0;
					if(ipos>1 && arr[ipos-2][jpos]!=0)
						ipos--;
					shiftUP(arr,ipos,jpos);
				}
			}
}

void keyDOWN(int arr[MAX][MAX]){
	int ipos,jpos,temp;
	for(jpos=0;jpos<MAX;jpos++)
		for(ipos=0;ipos<MAX-1;ipos++)
			if(arr[ipos][jpos]!=0)
			{
				if(arr[ipos+1][jpos]==0){
					arr[ipos+1][jpos]=arr[ipos][jpos];
					arr[ipos][jpos]=0;
					shiftDown(arr,ipos,jpos);
				}else if(arr[ipos+1][jpos]==arr[ipos][jpos]){
					arr[ipos+1][jpos]=2*arr[ipos][jpos];
					arr[ipos][jpos]=0;
					if(ipos<MAX-1 && arr[ipos+2][jpos]!=0)
						ipos++;
					shiftDown(arr,ipos,jpos);
				}
			}
}

void keyLEFT(int arr[MAX][MAX]){
	int ipos,jpos,temp;
	for(ipos=0;ipos<MAX;ipos++)
		for(jpos=MAX-1;jpos>0;jpos--)
			if(arr[ipos][jpos]!=0)
			{
				if(arr[ipos][jpos-1]==0){
					arr[ipos][jpos-1]=arr[ipos][jpos];
					arr[ipos][jpos]=0;
					shiftLeft(arr,ipos,jpos);
				}else if(arr[ipos][jpos-1]==arr[ipos][jpos]){
					arr[ipos][jpos-1]=2*arr[ipos][jpos];;
					arr[ipos][jpos]=0;
					if(jpos>1 && arr[ipos][jpos-2]!=0)
						jpos--;
					shiftLeft(arr,ipos,jpos);

				}
			}
}

void keyRIGHT(int arr[MAX][MAX]){
	int ipos,jpos,temp;
	for(ipos=0;ipos<MAX;ipos++)
		for(jpos=0;jpos<MAX-1;jpos++)
			if(arr[ipos][jpos]!=0)
			{
				if(arr[ipos][jpos+1]==0){
					arr[ipos][jpos+1]=arr[ipos][jpos];
					arr[ipos][jpos]=0;
					shiftRight(arr,ipos,jpos);
				}else if(arr[ipos][jpos+1]==arr[ipos][jpos]){
					arr[ipos][jpos+1]=2*arr[ipos][jpos];;
					arr[ipos][jpos]=0;
					if(jpos<2 && arr[ipos][jpos+2]!=0)
						jpos++;
					shiftRight(arr,ipos,jpos);
				}
			}
}

void shiftRight(int arr[MAX][MAX],int row,int ptr){
	for(int i=ptr;i>0;i--)
		if(arr[row][i]==0)
		{
			arr[row][i]=arr[row][i-1];
			arr[row][i-1]=0;
		}
}

void shiftLeft(int arr[MAX][MAX],int row,int ptr){
	for(int i=ptr;i<MAX-1;i++){
		if(arr[row][i]==0)
		{
			arr[row][i]=arr[row][i+1];
			arr[row][i+1]=0;
		}
	}
}
void shiftUP(int arr[MAX][MAX],int ptr,int column){
	for(int i=ptr;i<MAX-1;i++){
		if(arr[i][column]==0)
		{
			arr[i][column]=arr[i+1][column];
			arr[i+1][column]=0;
		}
	}
}
void shiftDown(int arr[MAX][MAX],int ptr,int column){
	for(int i=ptr;i>0;i--){
		if(arr[i][column]==0)
		{
			arr[i][column]=arr[i-1][column];
			arr[i-1][column]=0;
		}
	}
}


void main(){
	int arr[MAX][MAX]={0};
	char ch1,ch2;
	clrscr();
	textbackground(WHITE);
	textcolor(RED);
	gotoxy(25,3);
	cprintf("**********SOMYA ARORA**********");
	gotoxy(25,12);
	textcolor(BLACK);
	cprintf("USE ARROW KEYS TO PLAY GAME");
	gotoxy(22,14);
	cprintf("AND ENTER 'a' OR ENTER KEY TO QUIT\n");
	delay(2000);
	clrscr();
	randomize();
	generateRandom(arr);
	printMatrix(arr);
	do{
	ch1=getch();
	ch2=getch();
	if (ch1 == '\0')
	{
       switch(ch2) { // the real value
	case 'H':     // code for arrow up
		keyUP(arr);
		printMatrix(arr);
		if(generateRandom(arr)==-1)
		{

		      cprintf("\nMatrix Full\r\n");
		      delay(1000);
		      exit(1);
		}
		delay(400);
		printMatrix(arr);
	    break;
	case 'K':
		keyLEFT(arr);
		printMatrix(arr);
		if(generateRandom(arr) == -1)
		{

		      cprintf("\nMatrix Full\r\n");
		      delay(1000);
		      exit(1);
		}
		delay(400);
		printMatrix(arr);
		//code for arrow down
	    break;
	case 'M':
	    // code for arrow right
	    keyRIGHT(arr);
	    printMatrix(arr);
	    if(generateRandom(arr) == -1)
		{

		      cprintf("\nMatrix Full\r\n");
		      delay(1000);
		      exit(1);
		}
		delay(400);
		printMatrix(arr);
	    break;
	case 'P':
	    keyDOWN(arr);
	    printMatrix(arr);
	    if(generateRandom(arr) == -1)
		{

		      cprintf("\nMatrix Full\r\n");
		      delay(1000);
		      exit(1);
		}
		delay(400);
		printMatrix(arr);
	    break;
    }
    }
	else
	{
	if(ch1=='a' || ch2=='a' || ch1==13||ch1==33)
		break;
	}
    }while(1);
    getch();
}