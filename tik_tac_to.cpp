#include<iostream>
using namespace std;
char board[30][60];

void setBoundary()
{
	int i,j;
	for(i=0;i<60;i++)
	{
		board[0][i]='*';
		board[i][20]='*';
		board[i][40]='*';
		board[29][i]='*';
		board[i][0]='*';
		board[i][59]='*';
		board[10][i]='*';
		board[20][i]='*';
	}

	
}

void printBoundary()
{
		cout<<"              .....DIRECTIONS........."<<endl;
	cout<<"press given number to insert at that position"<<endl;
	cout<<"7  8  9"<<endl<<"4  5  6"<<endl<<"1  2  3"<<endl;
	cout<<endl<<"For player 1  -> X"<<endl;
	cout<<endl<<"For player 2  -> 0"<<endl;
	int i,j;
	for(i=0;i<30;i++)
	{
		for(j=0;j<60;j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}

void setInput(int n,char x)
{
	if(n==1)
	{
		board[25][10]=x;
	}
		if(n==2)
	{
		board[25][30]=x;
	}
		if(n==3)
	{
		board[25][50]=x;
	}
		if(n==4)
	{
		board[15][10]=x;
	}
		if(n==5)
	{
		board[15][30]=x;
	}
	
		if(n==6)
	{
		board[15][50]=x;
	}
		if(n==7)
	{
		board[5][10]=x;
	}
		if(n==8)
	{
		board[5][30]=x;
	}
		if(n==9)
	{
		board[5][50]=x;
	}
}

int checkWinner(char c)
{
int f=0;
	if(board[5][10]==c)
	{
		if(board[5][30]==c&&board[5][50]==c)
		{
		f=1;	
		}
		if(board[15][10]==c&&board[25][10]==c)
		f=1;
		if(board[15][30]==c&&board[25][50]==c)
		f=1;	
	}
	 if(board[25][50]==c)
	{
		if(board[25][30]==c&&board[25][10]==c)
		{
		f=1;	
		}
		else if(board[15][50]==c&&board[5][50]==c)
		f=1;		
	}
	 if(board[15][30]==c)
	{
		if(board[5][30]==c&&board[25][30]==c)
		{
		f=1;	
		}
		 if(board[15][10]==c&&board[15][50]==c)
		{
		f=1;
		}
		else if(board[25][10]==c&&board[5][50]==c)
		f=1;	
	}	
	return f;
	
}
int main()
{
	int turn;
	int w;
	setBoundary();
	int i=0;

	printBoundary();
	while(i<9)
	{
		if(i%2==0)
		cout<<"player 1 turn"<<endl;
		else
		cout<<"player 2 turn"<<endl;
		cin>>turn;
		if(i%2==0)
		{
		setInput(turn,'X');
		w=checkWinner('X');
		if(w)
		{
		system("cls");
		printBoundary();
		cout<<"Winner player 1";
		break;	
		}	
		}
		else
		{
			
		setInput(turn,'0');
		w=checkWinner('0');
		if(w)
		{
		system("cls");
		printBoundary();
		cout<<"Winner player 2";
		break;	
		}
		}
		system("cls");
		printBoundary();
		i++;
		
	}
	if(i==9)
	{
		cout<<"              ....MATCH TIE....";
	}

	return 0;
}
