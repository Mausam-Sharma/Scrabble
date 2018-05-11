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
//______________________________________playgame again____________________________________________________________
void game::playgameagain(char orig[15][15],char test[300][15],int allScore)
{   char inp,cont;        int i;
    fflush(stdin);
    clrscr();  cleardevice();  boardnum(orig);
   cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);                                        //code for playing if users are playing second time with first player given 7 characters
    cout<<"\n\n letters left : "<<chance;                     //clears out prevous game buffer
    cout<<"\n\nletter set is : \n";


    randomize();
for(i=leng1;i<7;i++)
{
j[i]=random(chance);                                    //randomly gives 7 characters to a user
letter1[i]=alpha[j[i]];
leng1++;
  }

for(i=0;i<7;i++)
printf("%c,",letter1[i]);
  cout<<"\n______________________";

    inp=input(orig);                                   //   input function call for alphabet

    cout<<"letter chosen is "<<inp;
    cout<<"\n____________________";
    coor(inp,orig);                                           // coordinate input
    boardnum(orig);
    reduceAlpha(inp,orig);
    reduceUser(inp,orig);
    label1:
   printf("\nDo u want to use more\nletters ???\n______________________\nPRESS :\n'y' for YES\n'n' to form a WORD\n'm' to quit your turn\n'e' for Exit\n");
    cont=getche();
if((cont=='n')||(cont=='N'))
    {word(orig,test,allScore);}                           

else if((cont=='e')||(cont=='E'))
    {exit(0);}
else if((cont!='e')&&(cont!='E')&&(cont!='m')&&(cont!='M')&&(cont!='n')&&(cont!='N')&&(cont!='y')&&(cont!='Y'))
   {  clrscr();  cleardevice();  boardnum(orig);
    cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);
    cout<<"\n\nYou pressed '"<<cont<<"'";
    cout<<"\nWrong option opted !!\n______________________"; goto label1;
   }



while((cont=='y')||(cont=='Y'))
{ fflush(stdin);
    clrscr();  cleardevice();  boardnum(orig);                      // refreshed gameboard
    cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);
    cout<<"\n\n letters left : "<<chance;
    cout<<"\n\nletter set is : \n";

for(i=0;i<leng1;i++)
{ printf("%c,",letter1[i]);        // reduced character set
}
cout<<"\n______________________";
    inp=input(orig);                                   //   input function call for alphabet

    cout<<"letter chosen is "<<inp;
    cout<<"\n____________________";
    coor(inp,orig);                                           // coordinate input
    boardnum(orig);
    reduceAlpha(inp,orig);
    reduceUser(inp,orig);
    label2:
   printf("\nDo u want to use more\nletters ???\n______________________\nPRESS :\n'y' for YES\n'n' to form a WORD\n'm' to quit your turn\n'e' for Exit\n");
    cont=getche();
    if((cont=='n')||(cont=='N'))
    {
        word(orig,test,allScore); break;
    }
    else if((cont=='m')||(cont=='M'))
    {break;}
    else if((cont=='e')||(cont=='E'))
    {exit(0);}
    else if((cont!='e')&&(cont!='E')&&(cont!='m')&&(cont!='M')&&(cont!='n')&&(cont!='N')&&(cont!='y')&&(cont!='Y'))
   {  clrscr();  cleardevice();  boardnum(orig);
    cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);                                                   
    line(0,30,200,30);                                      // refreshed gameboard
    line(0,32,200,32);
    cout<<"\n\nYou pressed '"<<cont<<"'";
    cout<<"\nWrong option opted !!\n______________________"; goto label2;
   }

  }

    getch();
}


//________________________________________________________________________________________________________________
//_______________________________________playgame_________________________________________________________________
void game::playgame(char orig[15][15],char test[300][15],int allScore)
{   char inp,cont;        int i;
    fflush(stdin);
    clrscr();  cleardevice();  boardnum(orig);
    cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);
    cout<<"\n\n letters left : "<<chance;
    cout<<"\n\nletter set is : \n";


    call_random(orig);  cout<<"\n______________________";

    inp=input(orig);                                   //   input function call for alphabet

    cout<<"letter chosen is "<<inp;
    cout<<"\n____________________";
    coor(inp,orig);                                           // coordinate input
    boardnum(orig);
    reduceAlpha(inp,orig);
    reduceUser(inp,orig);
   label3:
   printf("\nDo u want to use more\nletters ???\n______________________\nPRESS :\n'y' for YES\n'n' to form a WORD\n'm' to quit your turn\n'e' for Exit\n");

    cont=getche();
if((cont=='n')||(cont=='N'))
    {word(orig,test,allScore);}

else if((cont=='e')||(cont=='E'))
    {exit(0);}
 else if((cont!='e')&&(cont!='E')&&(cont!='m')&&(cont!='M')&&(cont!='n')&&(cont!='N')&&(cont!='y')&&(cont!='Y'))
   {  clrscr();  cleardevice();  boardnum(orig);
    cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);
    cout<<"\n\nYou pressed '"<<cont<<"'";
    cout<<"\nWrong option opted !!\n______________________"; goto label3;
   }



while((cont=='y')||(cont=='Y'))
{ fflush(stdin);
    clrscr();  cleardevice();  boardnum(orig);
    cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);
    cout<<"\n\n letters left : "<<chance;
    cout<<"\n\nletter set is : \n";

for(i=0;i<leng1;i++)
{ printf("%c,",letter1[i]);        // reduced character set
}
cout<<"\n______________________";
    inp=input(orig);                                   //   input function call for alphabet

    cout<<"letter chosen is "<<inp;
    cout<<"\n____________________";
    coor(inp,orig);                                           // coordinate input
    boardnum(orig);
    reduceAlpha(inp,orig);
    reduceUser(inp,orig);
    label4:
   printf("\nDo u want to use more\nletters ???\n______________________\nPRESS :\n'y' for YES\n'n' to form a WORD\n'm' to quit your turn\n'e' for Exit\n");

    cont=getche();
    if((cont=='n')||(cont=='N'))
    {
        word(orig,test,allScore); break;
    }
    else if((cont=='m')||(cont=='M'))
    {break;}

    else if((cont=='e')||(cont=='E'))
    {exit(0);}
     else if((cont!='e')&&(cont!='E')&&(cont!='m')&&(cont!='M')&&(cont!='n')&&(cont!='N')&&(cont!='y')&&(cont!='Y'))
   {  clrscr();  cleardevice();  boardnum(orig);
    cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);
    cout<<"\n\nYou pressed '"<<cont<<"'";
    cout<<"\nWrong option opted !!\n______________________"; goto label4;
   }


  }

    getch();
}
//________________________________________________
//_______________WORD FINDING__________________________
void game::word(char orig[15][15],char test[300][15],int allScore)
{   int c,d,e,f,getpoint,cmp,flagLocal=0;        int itr1=0,itr2=0;  char wordFile[40];
    int point1=0;                                int itr3=0,itr4=0,itrTest=0;
    char wordForm[15];
    int flagTest=0;

    clrscr(); cleardevice();
     boardnum(orig);
                                cout<<"\n"<<play1<<"'s "<<"turn";
                                    setcolor(GREEN);
                                    line(0,30,200,30);
                                    line(0,32,200,32);
    testphase:
    
     cout<<"\n\nEnter start coordinates\nof your word formed";
     cin>>c>>d;
     cout<<"\nEnter end coordinates\nof your word formed";
     cin>>e>>f;
                     if((c>15)||(d>15)||(c<1)||(d<1)||(e>15)||(f>15)||(e<1)||(f<1))       //constaints for coordinates to be inbetween 1and 15
                            {  clrscr();  cleardevice();  boardnum(orig);
                                cout<<"\n"<<play1<<"'s "<<"turn";
                                    setcolor(GREEN);
                                    line(0,30,200,30);
                                    line(0,32,200,32);
                                cout<<"\n\n Wrong coordinates\nInput again\n_____________________";

                                goto testphase;
                            }
      if(c==e)
     {

          if(d<f)
           {
            for(itr1=d,itr2=0;itr1<=f;itr1++,itr2++)
                    {   wordForm[itr2]=orig[c][itr1]; wordForm[itr2+1]='\0';}
           }
           else if(f<d)
           {
            for(itr1=d,itr2=0;itr1>=f;itr1--,itr2++)
                    {   wordForm[itr2]=orig[c][itr1]; wordForm[itr2+1]='\0';}       //wordformation
           }
          strlwr(wordForm);
          cout<<"\n____________________\n"<<wordForm<<"\n____________________";
          for(itrTest=0;itrTest<=testNumber;itrTest++)
{
    if(strcmp(wordForm,test[itrTest])==0)
    {
        cout<<"\nWord already formed!!!\n0 points for this word";  point1=0;
        score1=score1+point1;
         flagTest=1; break;
    }
}
if(flagTest==0)
{ ifstream fout;
fout.open("loop.txt",ios::in||ios::out||ios::noreplace);
while(!fout.eof())
    {
        fout.getline(wordFile,40);
        cmp=strcmp(wordFile,wordForm);                        //checking if word exists with dictionary
        if(cmp==0)
        { cout<<"\nword found\n\""; cout<<wordFile<<"\" is at position "<<fout.tellg(); flagLocal=1;
          ++testNumber;
          strcpy(test[testNumber],wordForm);
        break;
        }
    }

    if(flagLocal==0)
{cout<<"\nWord not found in dictionary!!!!!\n0 points for this word"; point1=0;}              //points calculation according to coordinates
else if(flagLocal==1)
    {    int doubleWord=0,tripleWord=0; itr3=0; itr4=0;
       if(d<f)
        {for(itr1=d;itr1<=f;itr1++)
            { getpoint=0;
              switch(orig[c][itr1])
                    {   case 'A':
                        case 'a':                   
                        case 'E':
                        case 'e':
                        case 'I':
                        case 'i':
                        case 'L':
                        case 'l':
                        case 'N':
                        case 'n':
                        case 'O':
                        case 'o':
                        case 'R':
                        case 'r':
                        case 'S':
                        case 's':
                        case 'T':
                        case 't':
                        case 'U':
                        case 'u':   getpoint=1; break;

                        case 'D':
                        case 'd':
                        case 'G':
                        case 'g':   getpoint=2; break;

                        case 'B':
                        case 'b':
                        case 'C':
                        case 'c':
                        case 'M':
                        case 'm':
                        case 'P':
                        case 'p':   getpoint=3; break;

                        case 'F':
                        case 'f':
                        case 'H':
                        case 'h':
                        case 'V':
                        case 'v':
                        case 'W':
                        case 'w':
                        case 'Y':
                        case 'y':   getpoint=4; break;

                        case 'K':
                        case 'k':   getpoint=5; break;

                        case 'J':
                        case 'j':
                        case 'X':
                        case 'x':   getpoint=8; break;

                        case 'Q':
                        case 'q':
                        case 'Z':
                        case 'z':  getpoint=10; break;

                        case '_':  getpoint=0;  break;
                        default:  cout<<"\nNon-allowed character\nencountered";
                    }
                    if((c==1)&&((itr1==4)||(itr1==12)))
     getpoint=getpoint*2;
       if((c==8)&&((itr1==4)||(itr1==12)))
     getpoint=getpoint*2;
       if((c==15)&&((itr1==4)||(itr1==12)))
     getpoint=getpoint*2;

       if((c==3)&&((itr1==7)||(itr1==9)))
     getpoint=getpoint*2;
       if((c==13)&&((itr1==7)||(itr1==9)))
     getpoint=getpoint*2;

       if((c==4)&&((itr1==1)||(itr1==8)||(itr1==15)))
     getpoint=getpoint*2;
       if((c==12)&&((itr1==1)||(itr1==8)||(itr1==15)))
     getpoint=getpoint*2;

       if((c==7)&&((itr1==3)||(itr1==7)))
     getpoint=getpoint*2;
       if((c==7)&&((itr1==9)||(itr1==13)))
     getpoint=getpoint*2;
       if((c==9)&&((itr1==3)||(itr1==7)))
     getpoint=getpoint*2;
       if((c==9)&&((itr1==9)||(itr1==13)))
     getpoint=getpoint*2;

   if((c==2)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==14)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==6)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==10)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==6)&&((itr1==2)||(itr1==14)))
     getpoint=getpoint*3;
     if((c==10)&&((itr1==2)||(itr1==14)))
     getpoint=getpoint*3;

   if((c==2)&&((itr1==2)||(itr1==14)))
        doubleWord=doubleWord+1;
       if((c==3)&&((itr1==3)||(itr1==13)))
        doubleWord=doubleWord+1;
       if((c==4)&&((itr1==4)||(itr1==12)))
        doubleWord=doubleWord+1;
       if((c==5)&&((itr1==5)||(itr1==11)))
         doubleWord=doubleWord+1;
       if((c==8)&&(itr1==8))
         doubleWord=doubleWord+1;
       if((c==11)&&((itr1==5)||(itr1==11)))
          doubleWord=doubleWord+1;
       if((c==12)&&((itr1==4)||(itr1==12)))
          doubleWord=doubleWord+1;
       if((c==13)&&((itr1==3)||(itr1==13)))
           doubleWord=doubleWord+1;
       if((c==14)&&((itr1==2)||(itr1==14)))
           doubleWord=doubleWord+1;

         if((c==1)&&((itr1==1)||(itr1==8)||(itr1==15)))
    tripleWord=tripleWord+1;
  if((c==8)&&((itr1==1)||(itr1==15)))
      tripleWord=tripleWord+1;
  if((c==15)&&((itr1==1)||(itr1==8)||(itr1==15)))
       tripleWord=tripleWord+1;



//-------------------------------
  point1=point1+getpoint;
            }
}   // ( d<f ) ends here
if(f<d)
        {for(itr1=d;itr1>=f;itr1--)
            { getpoint=0;
              switch(orig[c][itr1])
                    {   case 'A':
                        case 'a':
                        case 'E':
                        case 'e':
                        case 'I':
                        case 'i':
                        case 'L':
                        case 'l':
                        case 'N':
                        case 'n':
                        case 'O':
                        case 'o':
                        case 'R':
                        case 'r':
                        case 'S':
                        case 's':
                        case 'T':
                        case 't':
                        case 'U':
                        case 'u':   getpoint=1; break;

                        case 'D':
                        case 'd':
                        case 'G':
                        case 'g':   getpoint=2; break;

                        case 'B':
                        case 'b':
                        case 'C':
                        case 'c':
                        case 'M':
                        case 'm':
                        case 'P':
                        case 'p':   getpoint=3; break;

                        case 'F':
                        case 'f':
                        case 'H':
                        case 'h':
                        case 'V':
                        case 'v':
                        case 'W':
                        case 'w':
                        case 'Y':
                        case 'y':   getpoint=4; break;

                        case 'K':
                        case 'k':   getpoint=5; break;

                        case 'J':
                        case 'j':
                        case 'X':
                        case 'x':   getpoint=8; break;

                        case 'Q':
                        case 'q':
                        case 'Z':
                        case 'z':  getpoint=10; break;

                        case '_':  getpoint=0;  break;
                        default:  cout<<"\nNon-allowed character\nencountered";
                    }
if((c==1)&&((itr1==4)||(itr1==12)))
     getpoint=getpoint*2;
       if((c==8)&&((itr1==4)||(itr1==12)))
     getpoint=getpoint*2;
       if((c==15)&&((itr1==4)||(itr1==12)))
     getpoint=getpoint*2;

       if((c==3)&&((itr1==7)||(itr1==9)))
     getpoint=getpoint*2;
       if((c==13)&&((itr1==7)||(itr1==9)))
     getpoint=getpoint*2;

       if((c==4)&&((itr1==1)||(itr1==8)||(itr1==15)))
     getpoint=getpoint*2;
       if((c==12)&&((itr1==1)||(itr1==8)||(itr1==15)))
     getpoint=getpoint*2;

       if((c==7)&&((itr1==3)||(itr1==7)))
     getpoint=getpoint*2;
       if((c==7)&&((itr1==9)||(itr1==13)))
     getpoint=getpoint*2;
       if((c==9)&&((itr1==3)||(itr1==7)))
     getpoint=getpoint*2;
       if((c==9)&&((itr1==9)||(itr1==13)))
     getpoint=getpoint*2;

   if((c==2)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==14)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==6)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==10)&&((itr1==6)||(itr1==10)))
     getpoint=getpoint*3;
     if((c==6)&&((itr1==2)||(itr1==14)))
     getpoint=getpoint*3;
     if((c==10)&&((itr1==2)||(itr1==14)))
     getpoint=getpoint*3;

   if((c==2)&&((itr1==2)||(itr1==14)))
        doubleWord=doubleWord+1;
       if((c==3)&&((itr1==3)||(itr1==13)))
        doubleWord=doubleWord+1;
       if((c==4)&&((itr1==4)||(itr1==12)))
        doubleWord=doubleWord+1;
       if((c==5)&&((itr1==5)||(itr1==11)))
         doubleWord=doubleWord+1;
       if((c==8)&&(itr1==8))
         doubleWord=doubleWord+1;
       if((c==11)&&((itr1==5)||(itr1==11)))
          doubleWord=doubleWord+1;
       if((c==12)&&((itr1==4)||(itr1==12)))
          doubleWord=doubleWord+1;
       if((c==13)&&((itr1==3)||(itr1==13)))
           doubleWord=doubleWord+1;
       if((c==14)&&((itr1==2)||(itr1==14)))
           doubleWord=doubleWord+1;

         if((c==1)&&((itr1==1)||(itr1==8)||(itr1==15)))
    tripleWord=tripleWord+1;
  if((c==8)&&((itr1==1)||(itr1==15)))
      tripleWord=tripleWord+1;
  if((c==15)&&((itr1==1)||(itr1==8)||(itr1==15)))
       tripleWord=tripleWord+1;



//-------------------------------
  point1=point1+getpoint;
            }
