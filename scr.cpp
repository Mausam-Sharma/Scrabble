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
//___________________________________________________
 class game{  public:

char letter1[7],play1[20];                //letter1 is the buffer for user characters, play1 is used to store user name

int j[7],leng1,score1,flag;  int a,b;

static char alpha[100];
static int chance;
static int testNumber;

static int scoreUser1,scoreUser2,scoreUser3,scoreUser4;               //scores of users
game()
{  leng1=0,score1=0;



}


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


}obj[4];
//____________
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
int userNumber=0; char names[4][20];
void winner();
//_______________________________________________
 //___________________________________________________
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
//__________________________________________________
//__________________________________________________
void winner()
{  clrscr();  cleardevice();
    if(userNumber==2)
    {cout<<"\n"<<obj[0].play1<<"'s final score is "<<game::scoreUser1;
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
exit(0);}
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
    { cout<<"\n"<<obj[3].play1<<" is winner of the game !!!!!! ";}
    getch();
exit(0);}

}
//___________________playgameagain___________________
//___________________________________________________
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

//___________________________________________________
//___________________________________________________
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
}   // ( f<d ) ends here
      if(doubleWord>0)
      {
          for(itr3=doubleWord;itr3>0;itr3--)
          {
              point1=point1*2;
          }
      }

       if(tripleWord>0)
      {
          for(itr4=tripleWord;itr4>0;itr4--)
          {
              point1=point1*3;
          }
      }

//----------------------------------
     score1=score1+point1;
     }


fout.close();
}
getch();
clrscr(); cleardevice();
if(allScore==0){scoreUser1=score1;}
if(allScore==1){scoreUser2=score1;}
if(allScore==2){scoreUser3=score1;}
if(allScore==3){scoreUser4=score1;}
    cout<<"\n\n\n\t\t\t\t"<<play1<<"'s "<<"score board :\n\t\t\t\t____________________";      //scoreboard
     cout<<"\n\nWord formed is : "<<wordForm;
     printf("\n\n\n\ncurrent word score is %d ",point1);
     printf("\n\n\n\n total score is %d ",score1);



     }                                   //if(c==e) ends here


//___________if(d==f)_______________________starts here
if(d==f)
     {

            if(c<e)
                {for(itr1=c,itr2=0;itr1<=e;itr1++,itr2++)
                    {  wordForm[itr2]=orig[itr1][d];  wordForm[itr2+1]='\0';}
                }
         else if(e<c)
           {
            for(itr1=c,itr2=0;itr1>=e;itr1--,itr2++)
                    {   wordForm[itr2]=orig[itr1][d]; wordForm[itr2+1]='\0';}
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
{   ifstream fout;
fout.open("loop.txt",ios::in||ios::out||ios::noreplace);
while(!fout.eof())
    {
        fout.getline(wordFile,40);
        cmp=strcmp(wordFile,wordForm);
        if(cmp==0)
        { cout<<"\nword found\n\""; cout<<wordFile<<"\" is at position "<<fout.tellg(); flagLocal=1;
          ++testNumber;
          strcpy(test[testNumber],wordForm);
        break;
         }

    }
if(flagLocal==0)
{cout<<"\nWord not found in dictionary!!!!!\n 0 points for this word";}
else if(flagLocal==1)
    {    int doubleWord=0,tripleWord=0;     itr3=0; itr4=0;
       if(c<e)
        {for(itr1=c;itr1<=e;itr1++)
            { getpoint=0;
              switch(orig[itr1][d])
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



       if((itr1==1)&&((d==4)||(d==12)))
     getpoint=getpoint*2;
       if((itr1==8)&&((d==4)||(d==12)))
     getpoint=getpoint*2;
       if((itr1==15)&&((d==4)||(d==12)))
     getpoint=getpoint*2;

       if((itr1==3)&&((d==7)||(d==9)))
     getpoint=getpoint*2;
       if((itr1==13)&&((d==7)||(d==9)))
     getpoint=getpoint*2;

       if((itr1==4)&&((d==1)||(d==8)||(d==15)))
     getpoint=getpoint*2;
       if((itr1==12)&&((d==1)||(d==8)||(d==15)))
     getpoint=getpoint*2;

       if((itr1==7)&&((d==3)||(d==7)))
     getpoint=getpoint*2;
       if((itr1==7)&&((d==9)||(d==13)))
     getpoint=getpoint*2;
       if((itr1==9)&&((d==3)||(d==7)))
     getpoint=getpoint*2;
       if((itr1==9)&&((d==9)||(d==13)))
     getpoint=getpoint*2;




       if((itr1==2)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==14)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==6)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==10)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==6)&&((d==2)||(d==14)))
     getpoint=getpoint*3;
     if((itr1==10)&&((d==2)||(d==14)))
     getpoint=getpoint*3;



       if((itr1==2)&&((d==2)||(d==14)))
        doubleWord=doubleWord+1;
       if((itr1==3)&&((d==3)||(d==13)))
        doubleWord=doubleWord+1;
       if((itr1==4)&&((d==4)||(d==12)))
        doubleWord=doubleWord+1;
       if((itr1==5)&&((d==5)||(d==11)))
         doubleWord=doubleWord+1;
       if((itr1==8)&&(d==8))
         doubleWord=doubleWord+1;
       if((itr1==11)&&((d==5)||(d==11)))
          doubleWord=doubleWord+1;
       if((itr1==12)&&((d==4)||(d==12)))
          doubleWord=doubleWord+1;
       if((itr1==13)&&((d==3)||(d==13)))
           doubleWord=doubleWord+1;
       if((itr1==14)&&((d==2)||(d==14)))
           doubleWord=doubleWord+1;



  if((itr1==1)&&((d==1)||(d==8)||(d==15)))
    tripleWord=tripleWord+1;
  if((itr1==8)&&((d==1)||(d==15)))
      tripleWord=tripleWord+1;
  if((itr1==15)&&((d==1)||(d==8)||(d==15)))
       tripleWord=tripleWord+1;




//-------------------------------
  point1=point1+getpoint;
            }
    }          //  (c<e  ends here)

  else if(e<c)
        {for(itr1=c;itr1>=e;itr1--)
            { getpoint=0;
              switch(orig[itr1][d])
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



       if((itr1==1)&&((d==4)||(d==12)))
     getpoint=getpoint*2;
       if((itr1==8)&&((d==4)||(d==12)))
     getpoint=getpoint*2;
       if((itr1==15)&&((d==4)||(d==12)))
     getpoint=getpoint*2;

       if((itr1==3)&&((d==7)||(d==9)))
     getpoint=getpoint*2;
       if((itr1==13)&&((d==7)||(d==9)))
     getpoint=getpoint*2;

       if((itr1==4)&&((d==1)||(d==8)||(d==15)))
     getpoint=getpoint*2;
       if((itr1==12)&&((d==1)||(d==8)||(d==15)))
     getpoint=getpoint*2;

       if((itr1==7)&&((d==3)||(d==7)))
     getpoint=getpoint*2;
       if((itr1==7)&&((d==9)||(d==13)))
     getpoint=getpoint*2;
       if((itr1==9)&&((d==3)||(d==7)))
     getpoint=getpoint*2;
       if((itr1==9)&&((d==9)||(d==13)))
     getpoint=getpoint*2;




       if((itr1==2)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==14)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==6)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==10)&&((d==6)||(d==10)))
     getpoint=getpoint*3;
     if((itr1==6)&&((d==2)||(d==14)))
     getpoint=getpoint*3;
     if((itr1==10)&&((d==2)||(d==14)))
     getpoint=getpoint*3;



       if((itr1==2)&&((d==2)||(d==14)))
        doubleWord=doubleWord+1;
       if((itr1==3)&&((d==3)||(d==13)))
        doubleWord=doubleWord+1;
       if((itr1==4)&&((d==4)||(d==12)))
        doubleWord=doubleWord+1;
       if((itr1==5)&&((d==5)||(d==11)))
         doubleWord=doubleWord+1;
       if((itr1==8)&&(d==8))
         doubleWord=doubleWord+1;
       if((itr1==11)&&((d==5)||(d==11)))
          doubleWord=doubleWord+1;
       if((itr1==12)&&((d==4)||(d==12)))
          doubleWord=doubleWord+1;
       if((itr1==13)&&((d==3)||(d==13)))
           doubleWord=doubleWord+1;
       if((itr1==14)&&((d==2)||(d==14)))
           doubleWord=doubleWord+1;



  if((itr1==1)&&((d==1)||(d==8)||(d==15)))
    tripleWord=tripleWord+1;
  if((itr1==8)&&((d==1)||(d==15)))
      tripleWord=tripleWord+1;
  if((itr1==15)&&((d==1)||(d==8)||(d==15)))
       tripleWord=tripleWord+1;




//-------------------------------
  point1=point1+getpoint;
            }
    }  // (e<c)  ends here
         if(doubleWord>0)
      {
          for(itr3=doubleWord;itr3>0;itr3--)
          {
              point1=point1*2;
          }
      }

       if(tripleWord>0)
      {
          for(itr4=tripleWord;itr4>0;itr4--)
          {
              point1=point1*3;
          }
      }

//----------------------------------
     score1=score1+point1;
     }


fout.close();
}
getch();
clrscr(); cleardevice();
if(allScore==0){scoreUser1=score1;}
if(allScore==1){scoreUser2=score1;}
if(allScore==2){scoreUser3=score1;}
if(allScore==3){scoreUser4=score1;}

     cout<<"\n\n\n\t\t\t\t"<<play1<<"'s "<<"score board :\n\t\t\t\t____________________";
     cout<<"\n\nWord formed is : "<<wordForm;
     printf("\n\n\n\ncurrent word score is %d ",point1);
     printf("\n\n\n\n total score is %d ",score1);



     }
//_________if(d==f)_______________________ends here
                                          //if(const!=y)  ends here

}
//________________________________________________
//________________reducing the character set__________________________
void game::reduceUser(char inp,char orig[15][15])
{  int itr,pos;

    for(itr=0;itr<leng1;itr++)
{ if(letter1[itr]==inp)
  { pos=itr;

   for(itr=pos;itr<leng1-1;itr++)              // to reduce user set
      letter1[itr]=letter1[itr+1];
      leng1--;
    break;
  }
}
}
//________________________________________________
//________________reducing the character set__________________________
void game::reduceAlpha(char inp,char orig[15][15])
{  int itr,pos;
for(itr=0;itr<chance;itr++)
{ if(alpha[itr]==inp)
  { pos=itr;
    for(itr=pos;itr<chance-1;itr++)            // to reduce alphabets
  alpha[itr]=alpha[itr+1];
  chance--;
    break;
  }
}
}
//________________________________________________
//__________coordinates input_____________________
void game::coor(char inp,char orig[15][15])
{

                            C:
                            cout<<"\nEnter position in x & y\ncoordinates  (e.g 2 3)\n ";
                            cin>>a>>b;
                            if((a>15)||(b>15)||(a<1)||(b<1))
                            {  clrscr();  cleardevice();  boardnum(orig);
                                cout<<"\n"<<play1<<"'s "<<"turn";
                                    setcolor(GREEN);
                                    line(0,30,200,30);
                                    line(0,32,200,32);
                                cout<<"\n\n Wrong coordinates\n";

                                goto C;
                            }
                    else if(isalpha(a))
                    {
                         clrscr();  cleardevice();  boardnum(orig);
                                cout<<"\n"<<play1<<"'s "<<"turn";
                                    setcolor(GREEN);
                                    line(0,30,200,30);
                                    line(0,32,200,32);
                                cout<<"\n\nyou pressed '"<<a<<"' & '"<<b<<"'";
                                cout<<"\nWRONG COORDINATES\n";
                                goto C;
                    }
                     else if(ispunct(a))
                    {
                         clrscr();  cleardevice();  boardnum(orig);
                                cout<<"\n"<<play1<<"'s "<<"turn";
                                    setcolor(GREEN);
                                    line(0,30,200,30);
                                    line(0,32,200,32);
                                cout<<"\n\nyou pressed '"<<a<<"' & '"<<b<<"'";
                                cout<<"\nWRONG COORDINATES\n";
                                goto C;
                    }
                            else if(isalpha(orig[a][b]))
                            {   clrscr();  cleardevice();  boardnum(orig);
                                cout<<"\n"<<play1<<"'s "<<"turn";
                                    setcolor(GREEN);
                                    line(0,30,200,30);
                                    line(0,32,200,32);
                                cout<<"\n\n Position already filled\n";
                                cout<<"\nWRONG COORDINATES\n";
                                goto C;
                            }
                            orig[a][b]=inp; // input of coordinates
}             // coordinate function

//____________________________________________________
//_____________alpha input function___________________
char game::input(char orig[15][15])
{  char inp;int i;
    B:
    cout<<"\nPut letter from your set:\n";
inp=getche();

    for(i=0;i<leng1;i++)
{ if(letter1[i]==inp)
    { flag=1;
      break;
      }
   else
     flag=0;
}
if(flag==0)
{ clrscr();  cleardevice();  boardnum(orig);
  cout<<"\n"<<play1<<"'s "<<"turn";
   setcolor(GREEN);
    line(0,30,200,30);
    line(0,32,200,32);
  cout<<"\n\nYou pressed '"<<inp<<"'";
  cout<<"\nwrong letter\nThat's not in your set";cout<<"\n______________________\n";
  for(i=0;i<leng1;i++)
{ printf("%c,",letter1[i]);        // reduced character set
}

  goto B;
  }
return inp;
}

//____________________________________________________
//_____________random alphabet generating function_____
void game::call_random(char orig[15][15])
{  int itr;
    randomize();
for(itr=0;itr<7;itr++)
{
j[itr]=random(chance);
cout<<alpha[j[itr]]<<",";
letter1[itr]=alpha[j[itr]];
leng1++;
  }
}

//___________________________________________________
//___________initialising board graphics_______________________________
    void game::initial(char orig[15][15])
    { int itr1,itr2;
       for(itr1=0;itr1<16;itr1++)
       for(itr2=0;itr2<16;itr2++)
      orig[itr1][itr2]=' ';
    }

//______________________________________________
//_____________________board__drawing__function________________________
void game::boardnum(char orig[15][15])
{ int itr1,itr2;

  setcolor(RED);
   for(itr1=1;itr1<=16;itr1++)
      { line(210,10+(itr1*25)-12,610-13,10+(itr1*25)-12);
         line(210+(itr1*25)-13,10,210+(itr1*25)-13,410-12);
      }
setcolor(BLUE);

    outtextxy(390+200-13,7,"15");  outtextxy(40+200-13,7,"1"); outtextxy(65+200-13,7,"2");
    outtextxy(90+200-13,7,"3");  outtextxy(115+200-13,7,"4"); outtextxy(140+200-13,7,"5");
    outtextxy(165+200-13,7,"6");  outtextxy(190+200-13,7,"7"); outtextxy(215+200-13,7,"8");
    outtextxy(240+200-13,7,"9");  outtextxy(265+200-13,7,"10"); outtextxy(290+200-13,7,"11");
    outtextxy(315+200-13,7,"12");  outtextxy(340+200-13,7,"13"); outtextxy(365+200-13,7,"14");

    outtextxy(5+200,390,"15");  outtextxy(5+200,40,"1"); outtextxy(5+200,65,"2");
    outtextxy(5+200,90,"3");  outtextxy(5+200,115,"4"); outtextxy(5+200,140,"5");
    outtextxy(5+200,165,"6");  outtextxy(5+200,190,"7"); outtextxy(5+200,215,"8");
    outtextxy(5+200,240,"9");  outtextxy(5+200,265,"10"); outtextxy(5+200,290,"11");
    outtextxy(5+200,315,"12");  outtextxy(5+200,340,"13"); outtextxy(5+200,365,"14");


setcolor(LIGHTGREEN);   setfillstyle(SOLID_FILL,LIGHTGREEN);
{  for(itr1=1;itr1<=15;itr1++)
     {  for(itr2=1;itr2<=15;itr2++)
    {  floodfill(220+(itr1*25)-13,20+(itr2*25)-12,RED);
    }
     }


}


setcolor(LIGHTMAGENTA);   setfillstyle(SOLID_FILL,LIGHTMAGENTA);
 {
   floodfill(220+(50)-13,20+(50)-12,RED);   floodfill(220+(350)-13,20+(50)-12,RED);
   floodfill(220+(75)-13,20+(75)-12,RED);   floodfill(220+(325)-13,20+(75)-12,RED);
  floodfill(220+(100)-13,20+(100)-12,RED);  floodfill(220+(300)-13,20+(100)-12,RED);
  floodfill(220+(125)-13,20+(125)-12,RED);  floodfill(220+(275)-13,20+(125)-12,RED);

  floodfill(220+(50)-13,20+(350)-12,RED);    floodfill(220+(350)-13,20+(350)-12,RED);
  floodfill(220+(75)-13,20+(325)-12,RED);    floodfill(220+(325)-13,20+(325)-12,RED);
  floodfill(220+(100)-13,20+(300)-12,RED);    floodfill(220+(300)-13,20+(300)-12,RED);
  floodfill(220+(125)-13,20+(275)-12,RED);    floodfill(220+(275)-13,20+(275)-12,RED);
  floodfill(220+(200)-13,20+(200)-12,RED);
  }


setcolor(WHITE);  setfillstyle(SOLID_FILL,WHITE);
{
floodfill(220+(225)-13,20+(225)-12,RED);
floodfill(220+(175)-13,20+(175)-12,RED);
floodfill(220+(175)-13,20+(225)-12,RED);
floodfill(220+(225)-13,20+(175)-12,RED);
floodfill(220+(175)-13,20+(75)-12,RED);
floodfill(220+(225)-13,20+(75)-12,RED);
floodfill(220+(100)-13,20+(25)-12,RED);
floodfill(220+(300)-13,20+(25)-12,RED);
floodfill(220+(25)-13,20+(100)-12,RED);
floodfill(220+(375)-13,20+(100)-12,RED);
floodfill(220+(25)-13,20+(300)-12,RED);
floodfill(220+(375)-13,20+(300)-12,RED);
floodfill(220+(175)-13,20+(325)-12,RED);
floodfill(220+(225)-13,20+(325)-12,RED);
floodfill(220+(200)-13,20+(100)-12,RED);
floodfill(220+(200)-13,20+(300)-12,RED);
floodfill(220+(75)-13,20+(175)-12,RED);
floodfill(220+(325)-13,20+(175)-12,RED);
floodfill(220+(100)-13,20+(200)-12,RED);
floodfill(220+(300)-13,20+(200)-12,RED);
floodfill(220+(75)-13,20+(225)-12,RED);
floodfill(220+(325)-13,20+(225)-12,RED);

floodfill(220+(100)-13,20+(375)-12,RED);
floodfill(220+(300)-13,20+(375)-12,RED);


}

setcolor(LIGHTRED);  setfillstyle(SOLID_FILL,LIGHTRED);
{  floodfill(220+(25)-13,20+(25)-12,RED);   floodfill(220+(375)-13,20+(375)-12,RED);
  floodfill(220+(25)-13,20+(375)-12,RED);   floodfill(220+(375)-13,20+(25)-12,RED);
  floodfill(220+(25)-13,20+(200)-12,RED);   floodfill(220+(200)-13,20+(25)-12,RED);
  floodfill(220+(200)-13,20+(375)-12,RED);   floodfill(220+(375)-13,20+(200)-12,RED);
}

setcolor(LIGHTBLUE);  setfillstyle(SOLID_FILL,LIGHTBLUE);
{
floodfill(220+(150)-13,20+(50)-12,RED);   floodfill(220+(250)-13,20+(50)-12,RED);
floodfill(220+(50)-13,20+(150)-12,RED);   floodfill(220+(150)-13,20+(150)-12,RED);
floodfill(220+(250)-13,20+(150)-12,RED);   floodfill(220+(350)-13,20+(150)-12,RED);
floodfill(220+(50)-13,20+(250)-12,RED);   floodfill(220+(150)-13,20+(250)-12,RED);
floodfill(220+(250)-13,20+(250)-12,RED);   floodfill(220+(350)-13,20+(250)-12,RED);
floodfill(220+(150)-13,20+(350)-12,RED);   floodfill(220+(250)-13,20+(350)-12,RED);

 }

setcolor(BLACK);

for(itr1=0;itr1<16;itr1++)
 for(itr2=0;itr2<16;itr2++)
  { if(isalpha(orig[itr1][itr2]))
    {    switch(orig[itr1][itr2])
      { case 'A':
        case 'a':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"A");
       break;
        case 'B':
        case 'b':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"B");
       break;
        case 'C':
        case 'c':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"C");
       break;
        case 'D':
        case 'd':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"D");
       break;
        case 'E':
        case 'e':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"E");
       break;
        case 'F':
        case 'f':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"F");
       break;
        case 'G':
        case 'g':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"G");
       break;
        case 'H':
        case 'h':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"H");
       break;
        case 'I':
        case 'i':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"I");
       break;
        case 'J':
        case 'j':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"J");
       break;
        case 'K':
        case 'k':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"K");
       break;
        case 'L':
        case 'l':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"L");
       break;
        case 'M':
        case 'm':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"M");
       break;
        case 'N':
        case 'n':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"N");
       break;
        case 'O':
        case 'o':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"O");
       break;
        case 'P':
        case 'p':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"P");
       break;
        case 'Q':
        case 'q':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"Q");
       break;
        case 'R':
        case 'r':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"R");
       break;
        case 'S':
        case 's':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"S");
       break;
        case 'T':
        case 't':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"T");
       break;
        case 'U':
        case 'u':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"U");
       break;
        case 'V':
        case 'v':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"V");
       break;
        case 'W':
        case 'w':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"W");
       break;
        case 'X':
        case 'x':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"X");
       break;
        case 'Y':
        case 'y':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"Y");
       break;
        case 'Z':
        case 'z':  outtextxy(220+(itr1*25)-13,20+(itr2*25)-12,"Z");
       break;
       }
  }
    }

setcolor(BLUE);
rectangle(220,435+5,240,455+5);

setcolor(WHITE);
rectangle(315,435+5,335,455+5);

rectangle(410,435+5,430,455+5);
rectangle(505,435+5,525,455+5);

setcolor(WHITE);
outtextxy(250,438+5,"Double");
outtextxy(250,448+5,"letter");
outtextxy(345,438+5,"Triple");
outtextxy(345,448+5,"letter");
outtextxy(440,438+5,"Double");
outtextxy(440,448+5,"word");
outtextxy(535,438+5,"Triple");
outtextxy(535,448+5,"word");

setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
floodfill(230,445+5,BLUE);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
floodfill(325,445+5,WHITE);
setcolor(MAGENTA);
setfillstyle(SOLID_FILL,MAGENTA);
floodfill(420,445+5,WHITE);
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
floodfill(515,445+5,WHITE);
line(210,460+5,630,460+5);
line(210,460+6,630,460+6);
setcolor(WHITE);
outtextxy(320,470,"Created by MAUSAM SHARMA");

char TEXT[5];
if(userNumber==2)
{
setcolor(RED);
outtextxy(380,412,"{SCORES)");
setcolor(WHITE);
 outtextxy(245,405,names[0]);
 sprintf(TEXT,"%d",scoreUser1); outtextxy(220,405,TEXT); outtextxy(235,405,":");
fflush(stdin);
 outtextxy(475,405,names[1]);
 sprintf(TEXT,"%d",scoreUser2); outtextxy(450,405,TEXT); outtextxy(465,405,":");
fflush(stdin);

}

if(userNumber==3)
{
setcolor(RED);
outtextxy(380,412,"{SCORES)");
setcolor(WHITE);
 outtextxy(245,405,names[0]);
 sprintf(TEXT,"%d",scoreUser1); outtextxy(220,405,TEXT); outtextxy(235,405,":");
fflush(stdin);
 outtextxy(475,405,names[1]);
 sprintf(TEXT,"%d",scoreUser2); outtextxy(450,405,TEXT); outtextxy(465,405,":");
fflush(stdin);
 outtextxy(245,420,names[2]);
 sprintf(TEXT,"%d",scoreUser3); outtextxy(220,420,TEXT); outtextxy(235,420,":");
fflush(stdin);

}


if(userNumber==4)
{
setcolor(RED);
outtextxy(380,412,"{SCORES)");
setcolor(WHITE);
 outtextxy(245,405,names[0]);
 sprintf(TEXT,"%d",scoreUser1); outtextxy(220,405,TEXT); outtextxy(235,405,":");
fflush(stdin);
 outtextxy(475,405,names[1]);
 sprintf(TEXT,"%d",scoreUser2); outtextxy(450,405,TEXT); outtextxy(465,405,":");
fflush(stdin);
 outtextxy(245,420,names[2]);
 sprintf(TEXT,"%d",scoreUser3); outtextxy(220,420,TEXT); outtextxy(235,420,":");
fflush(stdin);
 outtextxy(475,420,names[3]);
 sprintf(TEXT,"%d",scoreUser4); outtextxy(450,420,TEXT); outtextxy(465,420,":");
fflush(stdin);
}

}
//_______________________________________________
