/**** Header Files ****/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
/***** This Function is only for Cover *****/
void logo()
{
    settextstyle(9,0,8);//void settextstyle(int font=9, int direction=0, int charsize=8);
    setcolor(5);//MAGENTA Colour
    /******
    Name	Value
    BLACK 	0
    BLUE	1
    GREEN	2
    CYAN	3
    RED	4
    MAGENTA	5
    BROWN	6
    LIGHTGRAY	7
    DARKGRAY	8
    LIGHTBLUE	9
    LIGHTCYAN	11
    LIGHTRED	12
    YELLOW	14
    WHITE	15
    ******/
    outtextxy(20,200,"Gamer_UAP");//void outtextxy(int x, int y, char *textstring);
    Sleep(1);//sleep 1 mili second
    getch();
    cleardevice();//Screen cleared
    settextstyle(10,0,8);//void settextstyle(int font=5, int direction=0, int charsize=8);
    setcolor(2);//GREEN Colour
    outtextxy(40,100,"Aminul Islam");Sleep(2);setcolor(11);
    outtextxy(120,180,"presents...");Sleep(2);
    getch();cleardevice();
    settextstyle(7,0,6);setcolor(9);
    outtextxy(90,100,"Bomb_Shooting");
    setfillstyle(2,6);
    bar(0,200,680,240);
    Sleep(2);settextstyle(6,0,5);setcolor(14);
    outtextxy(0,280,"Press any key to continue");delay(100);
    getch();
    cleardevice();
    settextstyle(1,0,3);setcolor(14);
    outtextxy(250,50,"INSTRUCTIONS");
    outtextxy(50,130,"otherwise you will fall on the spikes");
    outtextxy(50,200,"Press space _ to shoot");
    outtextxy(50,250,"Use arrows '<- & ->' to move");
    delay(1000);
    setcolor(15);
    outtextxy(50,350,"Press any key to play");
    getch();
    setcolor(15);
}
void blast(int s,int cs)
{
    int e=5,i;
    if(cs==0)
        cs=1;
    for(i=0;i<6;i++)
    {
        setfillstyle(1,12);
        fillellipse(s*50+25,cs*25,e,5);
        setfillstyle(i+1,i);
        fillellipse(s*50+25,cs*25,5,e);
        delay(15);
        //sound(300);
        e=e+5;
    }
    //nosound();
}
int main()
{
    int gd=DETECT,gm;
    int a,m,s,mus,i,hits,c[11],bm,score,mute,dly;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    logo();
    //restart;
    //clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
    s=1;mus=1;hits=0;bm=2;score=0;mute=1;dly=200;
    for(i=0;i<11;i++)
    c[i]=0;
    //randomize();
    a=1;
    con:
        while(!kbhit())
        {
            a=rand()%5;
            if(c[a]==0)
            {
                c[a]=1;
            }
            if(mute%2==0)
                mus=rand()%1000;
            else
            {
                mus=0;
                //nosound();
            }
            ep1:
                cleardevice();
                setbkcolor(3);
                setcolor(15);
                settextstyle(2,0,6);
                outtextxy(575,75,"score");
                if(score>9)
                    printf("\b");
                if(score>100)
                    printf("\b");
                printf("\b%d",score);
                setfillstyle(11,9);
                bar(50,15,550,400);
                setfillstyle(5,2);
                bar(s*50+20,360,s*50+30,400);
                setcolor(15);
                rectangle(s*50+20,360,s*50+30,400);
                rectangle(50,15,550,480);
                setcolor(4);
                //if(mus!=0)
                    //sound(mus);
                for(i=50;i<550;i=i+20)
                {
                    line(i,480,i+10,440);
                    line(i+10,440,i+20,480);
                }
                setcolor(15);
                if(bm!=0)
                {
                    setfillstyle(2,bm);
                    bar(50,400,550,420);
                    rectangle(50,400,550,420);
                }
                line(50,0,50,480);
                line(550,0,550,480);
                for(i=1;i<11;i++)
                {
                    if(c[i]!=0)
                    {
                        setfillstyle(1,8);
                        bar(i*50+15,c[i]*25,i*50+35,c[i]*25+5);
                        fillellipse(i*50+25,c[i]*25-3,3,2);
                        fillellipse(i*50+35,c[i]*25-7,8,2);
                        fillellipse(i*50+25,c[i]*25+25,20,20);
                        if(bm!=0)
                            c[i]++;
                    }
                    if(c[i]==16)
                    {
                        blast(i,c[i]);
                        c[i]=0;
                        bm++;
                    }
                }
                if(bm==0)
                {
                    delay(500);
                    goto ep2;
                }
                delay(dly);
                //if(mus!=0)
                    //sound(mus+100);
                if(dly==0)
                    dly=dly+2;
                delay(dly+300);
                //if(mus!=0)
                    //sound(mus);
                dly=dly-2;
                //nosound();
                if(bm==7)
                {
                    bm=0;
                    goto ep1;
                    ep2:
                    cleardevice();
                    //nosound();
                    settextstyle(1,0,8);setcolor(15);
                    outtextxy(100,220,"GAME OVER");
                    setcolor(15);
                    printf("\n\t\t\t Score is      :%d",score);
                    printf("\n\t\t\t Shots missed  :%d",hits-score);
                    printf("\n\t\t\t Total hits    :%d",hits);
                    Sleep(2);
                    scanb:
                        settextstyle(1,0,2);
                        outtextxy(160,380,"Press HOME to restart");
                        outtextxy(160,420,"Press ESC to exit");
                        m=getch();
                        if(m==27)
                            exit(0);
                        //if(m==71)
                            //goto restart;
                        else
                            goto scanb;
                }
        }
        m=getch();
        if(m==0)
            m=getch();
        if(m==77)
        {
            if(s<10)
                s++;
        }
        if(m==75)
        {
            if(s>1)
                s--;
        }
        if(m==32)
        {
            setcolor(4);
            line(s*50+20,360,s*50+10,340);
            line(s*50+30,360,s*50+40,340);
            line(s*50+25,360,s*50+25,340);
            blast(s,c[s]);
            hits++;
            if(c[s]!=0)
                score++;
            c[s]=0;
        }
        if(m==9)
            getch();
        if(m==13)
            mute++;
        if(m==27)
        {
            //nosound();
            exit(0);
        }
        goto con;

        return 0;
}
