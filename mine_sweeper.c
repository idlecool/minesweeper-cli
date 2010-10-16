/*
*	Copyright 2009 idleCool. All rights reserved.
*
*	Redistribution and use in source and binary forms, with or without modification, are
*	permitted provided that the following conditions are met:
*
*	   1. Redistributions of source code must retain the above copyright notice, this list of
*	      conditions and the following disclaimer.
*
*	   2. Redistributions in binary form must reproduce the above copyright notice, this list
*	      of conditions and the following disclaimer in the documentation and/or other materials
*	      provided with the distribution.
*
*	THIS SOFTWARE IS PROVIDED BY iDLECOOL ``AS IS'' AND ANY EXPRESS OR IMPLIED
*	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
*	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL iDLECOOL OR
*	CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
*	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
*	ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*	The views and conclusions contained in the software and documentation are those of the
*	authors and should not be interpreted as representing official policies, either expressed
*	or implied, of idleCool.
*/

//mine sweeper implementation in C


#include <stdio.h>
#include <time.h>
main()
{
int a[4][4],inst[8],dummy[4][4],i,j,ro,row,col,co,n,flag=0,win=0,dead=0;

for (i=0;i<4;i++)				//2D array initialised with intial value zero
  {
  for (j=0;j<4;j++)
    {
    a[i][j]=0;
    }
  }						//end of intialisation

time_t t;					//seeding srand for random number generation
t=time(NULL);
srand(t);					//seeding complete

for(i=0;i<8;i++)
  {
  inst[i]=rand()%4;				//loading random values in an array
  }
a[inst[0]][inst[1]]=9;				//during this coding process i dicovered that
a[inst[2]][inst[3]]=9;				//arrays can also be nested.. lolzz..
a[inst[4]][inst[5]]=9;				//so loading mines at random places
a[inst[6]][inst[7]]=9;				//if you want to reduce mines comment this line

for (i=0;i<4;i++)				//most important part: loading numbers to the adjecent
  {						//blocks of the mines so to figure out how many mines are
  for (j=0;j<4;j++)				//around that particular block
    {
    if (a[i][j]==9)
    {
    if (j<3 && a[i][j+1]!=9)
      {
      a[i][j+1]=a[i][j+1]+1;
      }
    if (j>0 && a[i][j-1]!=9)
      {
      a[i][j-1]=a[i][j-1]+1;
      }
    if (i<3 && a[i+1][j]!=9)
      {
      a[i+1][j]=a[i+1][j]+1;
      }
    if (i>0 && a[i-1][j]!=9)
      {
      a[i-1][j]=a[i-1][j]+1;
      }
    if (i<3 && j<3 && a[i+1][j+1]!=9)
      {
      a[i+1][j+1]=a[i+1][j+1]+1;
      }
    if (i>0 && j<3 && a[i-1][j+1]!=9)
      {
      a[i-1][j+1]=a[i-1][j+1]+1;
      }
    if (i<3 && j>0 && a[i+1][j-1]!=9)
      {
      a[i+1][j-1]=a[i+1][j-1]+1;
      }
    if (i>0 && j>0 && a[i-1][j-1]!=9)
      {
      a[i-1][j-1]=a[i-1][j-1]+1;
      }
    }
    }
  }							//end of loading values to the 2D array

// end of master array

for (i=0;i<4;i++)					//printing master array, for testing..
  {printf("\n");					//do comment this while actual game session
  for (j=0;j<4;j++)
    {
    printf("%d\t",a[i][j]);
    }
  }
printf("\n");						//end of master array printing

for (i=0;i<4;i++)					//loading values to dummy array starts
  {
  for (j=0;j<4;j++)
    {
    dummy[i][j]=88;
    }
  }							//loading values to dummy array complete

while(1)						//an infinite while loop for game run
{
for (row=0;row<4;row++)					//printing the masked array
  {printf("\n");
  for (col=0;col<4;col++)
    {
    printf("%d\t",dummy[row][col]);
    }
  }
printf("\n");						//printing of masked array complete

printf("Enter Your Choice:\n1.Step\n2.Flag\n3.Deflag\nYour Choice: ");	//loading choice for switch case
scanf("%d",&n);
switch (n)						//switch starts here
{
case 1:
  printf("Enter the value of row and column you want to step\n(Input Format: <row>,<column> ) ");
  scanf("%d,%d",&ro,&co);
  i=ro-1;
  j=co-1;
  if (dummy[i][j]==99)
    {
    printf("First deflag this location");		//if a location is flaged, you cannot step on that
    break;
    }
  else if (a[i][j]==0)					//if the block turn out to be empty the all the
      {							//adjacent blockes will be opened
      dummy[i][j]=0;
      if (j<3 && dummy[i][j+1]==88)
	{
	dummy[i][j+1]=a[i][j+1];
	}
      if (j>0 && dummy[i][j-1]==88)
	{
	dummy[i][j-1]=a[i][j-1];
	}
      if (i<3 && dummy[i+1][j]==88)
	{
	dummy[i+1][j]=a[i+1][j];
	}
      if (i>0 && dummy[i-1][j]==88)
	{
	dummy[i-1][j]=a[i-1][j];
	}
      if (i<3 && j<3 && dummy[i+1][j+1]==88)
	{
	dummy[i+1][j+1]=a[i+1][j+1];
	}
      if (i>0 && j<3 && dummy[i-1][j+1]==88)
	{
	dummy[i-1][j+1]=a[i-1][j+1];
	}
      if (i<3 && j>0 && dummy[i+1][j-1]==88)
	{
	dummy[i+1][j-1]=a[i+1][j-1];
	}
      if (i>0 && j>0 && dummy[i-1][j-1]==88)
	{
	dummy[i-1][j-1]=a[i-1][j-1];
	}							//end of the opening of adjacent blocks
      for(i=0;i<4;i++)						//if a empty block is opened again then
	{							//rest of the adjacent blocks will be opened
	for(j=0;j<4;j++)					//succession
	  {
	  if (dummy[i][j]==0)
	    {
	    if (j<3 && dummy[i][j+1]==88)
	      {
	      dummy[i][j+1]=a[i][j+1];
	      }
	    if (j>0 && dummy[i][j-1]==88)
	      {
	      dummy[i][j-1]=a[i][j-1];
	      }
	    if (i<3 && dummy[i+1][j]==88)
	      {
	      dummy[i+1][j]=a[i+1][j];
	      }
	    if (i>0 && dummy[i-1][j]==88)
	      {
	      dummy[i-1][j]=a[i-1][j];
	      }
	    if (i<3 && j<3 && dummy[i+1][j+1]==88)
	      {
	      dummy[i+1][j+1]=a[i+1][j+1];
	      }
	    if (i>0 && j<3 && dummy[i-1][j+1]==88)
	      {
	      dummy[i-1][j+1]=a[i-1][j+1];
	      }
	    if (i<3 && j>0 && dummy[i+1][j-1]==88)
	      {
	      dummy[i+1][j-1]=a[i+1][j-1];
	      }
	    if (i>0 && j>0 && dummy[i-1][j-1]==88)
	      {
	      dummy[i-1][j-1]=a[i-1][j-1];
	      }
	    }
	  }
	}						//end of case when zero encounter
      }
  else if(a[i][j]==9)					//case when a mine is stepped i.e. game over
    {
    printf("You Have Kept your step on a mine!!!\nYou Are Dead!!\nGame Over\n ");
    dead=1;						//makes the dead counter enabled
    }
  else if(dummy[i][j]==88)				//case when a masked and numbered block
    {							//is stepped
    dummy[i][j]=a[i][j];
    }

    break;
case 2:							//flag case
  printf("Enter the value of row and column you want to flag\n(Input Format: <row>,<column> ) ");
  scanf("%d,%d",&ro,&co);
  i=ro-1;
  j=co-1;
if (dummy[i][j]==88)
  dummy[i][j]=99;
else
  printf("You Have already steped into that location");		//case in which flag has to be diabled
  break;

case 3:							//deflag case
  printf("Enter the value of row and column you want to deflag\n(Input Format: <row>,<column> ) ");
  scanf("%d,%d",&ro,&co);
  i=ro-1;
  j=co-1;
  if (dummy[i][j]==99)
    {
    dummy[i][j]=88;
    }
  else
    printf("The block is not flagged");
  break;						//end of deflag case
default:
  printf("Enter a Valid Value\n");
}							//end of switch case

win=1;							//intialising win counter
for(i=0;i<4;i++)
  {
  for(j=0;j<4;j++)
    {
    if (a[i][j]!=9)
      {
	if(dummy[i][j]== 99 || dummy[i][j]== 88)	//this decides that the game is won or not
	  {
	  win=0;
	  }
	}
      }
    }
if(win==1)
  {
  printf("You Win the Game!! Cheers!! :)\n");		//player wins the game
  break;
  }
if(dead==1)
  {
  break;						//player is dead
  }
}
}