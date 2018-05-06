//---------------------------------------------HEADER FILES NECESSARY-------------------------------------------------
#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<string.h>                      //header files necessary
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
//--------------------------------------------------------------------------------------------------------------------
//_____________________________________________GAME__CLASS______MEMBERS_DEFINED_______________________________________
 class game{  public:

char letter1[7],play1[20];                //letter1 is the buffer for user characters, play1 is used to store user name

int j[7],leng1,score1,flag;  int a,b;

static char alpha[100];
static int chance;
static int testNumber;

static int scoreUser1,scoreUser2,scoreUser3,scoreUser4;               //scores of users
game()			//___________________________________________________________________________constructor_______________
{  leng1=0,score1=0;



}

 //__________________________________________________Member__Functions___Defined_______________________________________
 void boardnum(char orig[15][15]);
 void initial(char orig[15][15]);
 void playgame(char orig[15][15],char test[300][15],int allScore);
 void playgameagain(char orig[15][15],char test[300][15],int allScore);
 void call_random(char orig[15][15]);
 char input(char orig[15][15]);
 void coor(char,char orig[15][15]);
 void reduceAlpha(char,char orig[15][15]);
 void reduceUser(char,char orig[15][15]);
 void word(char orig[15][15],char test[300][15],int allScore);

}obj[4];// 4 objects as 4 players are defined
//_____________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________
