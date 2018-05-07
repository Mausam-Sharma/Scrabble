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
{   int gd,gm; //  graphic variables 
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"c:/turboc3/bgi");    char orig[15][15]; char test[300][15];
    int user,choice;

    menu:
    clrscr(); cleardevice();
    setcolor(RED);
    outtextxy(0,5,"SCRABBLE-(4 player)");       //home page
    setcolor(GREEN);
    line(0,16,140,16);
    line(0,19,140,19);
    settextstyle(0,0,3);
    outtextxy(10,300,"Created by Mausam Sharma");
    settextstyle(0,0,0);
    cout<<"\n\n 1. Start a New Game : \n\n 2. How to Play Game : \n\n 3. Developer info : \n\n 4. EXIT.....";   //game menu
    cout<<"\n______________________\n\n__Enter__choice__: "; cin>>choice;

    if(choice==4){exit(0);}
    else if(choice==3)
    {   clrscr(); cleardevice();
        cout<<"\n\nName:\tMausam Sharma";
        cout<<"\n\nCollege:\tNorthern India Engineering College";             // developer info
        cout<<"\n\nContact:\tmausam.awesome4@gmail.com";
        getch(); goto menu;
    }
    else if(choice==2)
    {
        clrscr(); cleardevice();
        cout<<"\n\t\t\t\tRULES OF GAME";
        cout<<"\n\t\t\t\t_____________";
		cout<<"\n\n1: This is 2-4 player word forming game.";
		cout<<"\n\n2: Every player will be given 7 random alphabets from an alphabet set \n";
    	cout<<"   and player will be allowed to make words from these 7 letters. He is \n";
		cout<<"   allowed to use letters as much as possible from his/her set of 7 letters.\n";
		cout<<"   And then player can make a word to fetch a score which is automatically \n ";      // rules of game
    	cout<<"   calculated. If no word can be formed player can quit his/her turn and\n";
    	cout<<"   pass turn to next player.";
    	cout<<"\n\n3: If your word covers a white box, this will fetch double of the letter's score\n   covering white box ";
    	cout<<"\n\n4: If your word covers a blue box, this will fetch triple of the letter's score\n   covering blue box ";
		cout<<"\n\n5: If your word covers a pink box, this will double the score of your whole \n   word";
		cout<<"\n\n6: If your word covers a red box, this will triple the score of your whole \n   word";
    	cout<<"\n\n7: Letter   a,e,i,l,n,o,r,s,t,u  fetch '1' point";
    	cout<<"\n   Letter  d,g  fetch 2 point , Letter  b,c,m,p  fetch 3 point";
    	cout<<"\n   Letter  f,h,v,w,y  fetch 4 point , Letter k  fetch 5 point";
    	cout<<"\n   Letter  j,x  fetch 8 point , Letter q,z  fetch 10 point ";
    	
        getch(); goto menu;
    }
    else if(choice==1)
{   clrscr(); cleardevice();
    obj[0].initial(orig);       //initializes the character set and empty gameboard
    obj[0].boardnum(orig);
    setcolor(RED);
    outtextxy(0,5,"SCRABBLE-(4 player)");
    setcolor(GREEN);
    line(0,16,140,16);
    line(0,19,140,19);
    getch();
    userchoice:
    cout<<"\n\nHow many players ??\n( 2/3/4 ) player\n"; cin>>user; if(user==11){exit(0);}      //no. of players selected
if(user==2)
{   userNumber=2;
    cout<<"\nEnter 1st player name :\n"; gets(obj[0].play1); strcpy(names[0],obj[0].play1);
    cout<<"\nEnter 2nd player name :\n"; gets(obj[1].play1); strcpy(names[1],obj[1].play1);
    obj[0].playgame(orig,test,0);
      if((game::chance)==0){ winner();}
    obj[1].playgame(orig,test,1);
      if((game::chance)==0){ winner();}

    label1:
     obj[0].playgameagain(orig,test,0);
        if((game::chance)==0){ winner();}                       // user info taken if user == 2
     obj[1].playgameagain(orig,test,1);
        if((game::chance)==0){ winner();}
    goto label1;
}
else if(user==3)
{   userNumber=3;
    cout<<"\nEnter 1st player name :\n"; gets(obj[0].play1);  strcpy(names[0],obj[0].play1);
    cout<<"\nEnter 2nd player name :\n"; gets(obj[1].play1);  strcpy(names[1],obj[1].play1);
    cout<<"\nEnter 3rd player name :\n"; gets(obj[2].play1);  strcpy(names[2],obj[2].play1);

     obj[0].playgame(orig,test,0);
        if((game::chance)==0){ winner();}
     obj[1].playgame(orig,test,1);
        if((game::chance)==0){ winner();}
     obj[2].playgame(orig,test,2);
        if((game::chance)==0){ winner();}

    label2:
    obj[0].playgameagain(orig,test,0);
        if((game::chance)==0){ winner();}
    obj[1].playgameagain(orig,test,1);
        if((game::chance)==0){ winner();}                        // user info taken if user == 3
    obj[2].playgameagain(orig,test,2);
        if((game::chance)==0){ winner();}
    goto label2;
}
else if(user==4)
{
    userNumber=4;
    cout<<"\nEnter 1st player name :\n"; gets(obj[0].play1); strcpy(names[0],obj[0].play1);
    cout<<"\nEnter 2nd player name :\n"; gets(obj[1].play1); strcpy(names[1],obj[1].play1);
    cout<<"\nEnter 3rd player name :\n"; gets(obj[2].play1); strcpy(names[2],obj[2].play1);
    cout<<"\nEnter 4th player name :\n"; gets(obj[3].play1); strcpy(names[3],obj[3].play1);
    obj[0].playgame(orig,test,0);
      if((game::chance)==0){ winner();}
    obj[1].playgame(orig,test,1);
      if((game::chance)==0){ winner();}
    obj[2].playgame(orig,test,2);
      if((game::chance)==0){ winner();}
    obj[3].playgame(orig,test,3);
      if((game::chance)==0){ winner();}                  // user info taken if user == 4

    label3:
     obj[0].playgameagain(orig,test,0);
      if((game::chance)==0){ winner();}
     obj[1].playgameagain(orig,test,1);
      if((game::chance)==0){ winner();}
     obj[2].playgameagain(orig,test,2);
      if((game::chance)==0){ winner();}
     obj[3].playgameagain(orig,test,3);
      if((game::chance)==0){ winner();}
    goto label3;
}
else
{
   cout<<"\nWrong choice: \nEnter again" ; getch(); goto userchoice;
}
    }
else
{
    cout<<"\nWrong choice: \nEnter again" ; goto menu;
}
    getch();
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

//________________________________________________________________________________________________________________