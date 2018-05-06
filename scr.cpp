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
//________________________________________________Initialisation_Of_Game_Class_Variables_______________________________
int game::chance=100;
int game::testNumber=-1;
char game::alpha[100]={
'a','a','a','a','a','a','a','a','b','b',
'c','d','d','d','d','d','e','e','e','e',
'e','e','e','f','f','g','g','g','h','h',
'i','i','i','i','i','j','k','k','k','l',
'l','l','l','l','m','m','m','n','n','n',              // 100 letters  character set for game
'n','n','n','o','o','o','o','o','p','p',
'q','q','q','r','r','r','r','r','s','s',
's','s','s','s','s','s','t','t','t','t',
't','t','t','t','u','u','u','v','v','w',
'w','x','x','y','y','z','z','z','i','a'};
int game::scoreUser1=0;
int game::scoreUser2=0;
int game::scoreUser3=0;
int game::scoreUser4=0;
int userNumber=0; 
//____________________________________________Global_Variable_and_Method_______________________________________________

char names[4][20];		// new 2d variable array to store names of players
void winner();			// function to calculate winner

//_____________________________________________________________________________________________________________________
//__________________________________________Main__Function_____________________________________________________________
void main()
{
	int gd,gm; //  graphic variables 
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"c:/turboc3/bgi");    char orig[15][15]; char test[300][15];
    int user,choice;
}
//_____________________________________________________________________________________________________________________
//__________________________________________winner_deciding_method_____________________________________________________
void winner()
{  clrscr();  cleardevice();

    if(userNumber==2){	
    		cout<<"\n"<<obj[0].play1<<"'s final score is "<<game::scoreUser1;
    		cout<<"\n\n\n"<<obj[1].play1<<"'s final score is "<<game::scoreUser2;
    		
    		if((game::scoreUser1)>(game::scoreUser2))
    			{
        			cout<<"\n"<<obj[0].play1<<" is winner of the game !!!!!! ";           //function decides who is the winner after all characters are finished
     			}

    		else                                                                     //for 2 users
     			{
        			cout<<"\n"<<obj[1].play1<<" is winner of the game !!!!!! ";

     			}
    		
    		getch();
			exit(0);
    }

    if(userNumber==3){
    	cout<<"\n"<<obj[0].play1<<"'s final score is "<<game::scoreUser1;
    	cout<<"\n\n\n"<<obj[1].play1<<"'s final score is "<<game::scoreUser2;
    	cout<<"\n\n\n"<<obj[2].play1<<"'s final score is "<<game::scoreUser3;
    	if(((game::scoreUser1)>(game::scoreUser2))&&((game::scoreUser1)>(game::scoreUser3)))
     		{
        		cout<<"\n"<<obj[0].play1<<" is winner of the game !!!!!! ";                    //function decides who is the winner after all characters are finished
     		}
  		else if(((game::scoreUser2)>(game::scoreUser1))&&((game::scoreUser2)>(game::scoreUser3)))
     		{
        		cout<<"\n"<<obj[1].play1<<" is winner of the game !!!!!! ";                   //for 3 users

     		}
    	else
     		{
        		cout<<"\n"<<obj[2].play1<<" is winner of the game !!!!!! ";

     		}
    	
    	getch();
		exit(0);
	}

    if(userNumber==4){
    	cout<<"\n"<<obj[0].play1<<"'s final score is "<<game::scoreUser1;
    	cout<<"\n\n\n"<<obj[1].play1<<"'s final score is "<<game::scoreUser2;         //function decides who is the winner after all characters are finished
    	cout<<"\n\n\n"<<obj[2].play1<<"'s final score is "<<game::scoreUser3;
    	cout<<"\n\n\n"<<obj[3].play1<<"'s final score is "<<game::scoreUser4;

    	if(((game::scoreUser1)>(game::scoreUser2))&&((game::scoreUser1)>(game::scoreUser3))&&((game::scoreUser1)>(game::scoreUser4)))
     		{
        		cout<<"\n"<<obj[0].play1<<" is winner of the game !!!!!! ";
     		}
    	else if(((game::scoreUser2)>(game::scoreUser1))&&((game::scoreUser2)>(game::scoreUser3))&&((game::scoreUser2)>(game::scoreUser4)))
     		{
        		cout<<"\n"<<obj[1].play1<<" is winner of the game !!!!!! ";
     		}
    	else if(((game::scoreUser3)>(game::scoreUser1))&&((game::scoreUser3)>(game::scoreUser2))&&((game::scoreUser3)>(game::scoreUser4)))
     		{
        		cout<<"\n"<<obj[2].play1<<" is winner of the game !!!!!! ";                         //for 4 users
     		}
    	else
    		{ cout<<"\n"<<obj[3].play1<<" is winner of the game !!!!!! ";
    		}
    	
    	getch();
		exit(0);
	}
}