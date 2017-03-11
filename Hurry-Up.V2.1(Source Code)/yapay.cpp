#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include "game.h"
#include "startgrap.h"

extern int difficulty;
int yapay1[4]={278,162,308,192};
int old_yapay1[4];
int blackcolor1=0;
int color1;
int color2;
int color3;
int color4;
int a=0,b=0,c=0,d=0;
int tersCevir=0,temptersCevir=0;
int moveMonster=0;
void yapayObje(void)
{
    if(difficulty==0)
    {
        if(moveMonster==0)
        {
            readimagefile("resource\\objects\\yaratik1.bmp",yapay1[0],yapay1[1],yapay1[2],yapay1[3]);
            moveMonster=1;
        }
        else if(moveMonster==1)
        {
            readimagefile("resource\\objects\\yaratik2.bmp",yapay1[0],yapay1[1],yapay1[2],yapay1[3]);
            moveMonster=0;
        }
        if(tersCevir==0)
        {
            color1 = getpixel(yapay1[0]+(yapay1[2]-yapay1[0])/2,yapay1[3]+1);
            if(color1!=blackcolor1)
            {
                old_yapay1[0]=yapay1[0];
                old_yapay1[1]=yapay1[1];
                old_yapay1[2]=yapay1[2];
                old_yapay1[3]=yapay1[3];
                yapay1[1]++;
                yapay1[3]++;
                readimagefile("resource\\backpaint.bmp",old_yapay1[0],old_yapay1[1],yapay1[2],yapay1[1]);
            }
            else
            {
                srand(time(NULL));
                tersCevir=rand()%4;
            }   
        }
        else if(tersCevir==1)
        {
            color2 = getpixel(yapay1[0]+(yapay1[2]-yapay1[0])/2,yapay1[1]-1);
            if(color2!=blackcolor1)
            {
                old_yapay1[0]=yapay1[0];
                old_yapay1[1]=yapay1[1];
                old_yapay1[2]=yapay1[2];
                old_yapay1[3]=yapay1[3];
                yapay1[1]--;
                yapay1[3]--;
                readimagefile("resource\\backpaint.bmp",yapay1[0],yapay1[3],old_yapay1[2],old_yapay1[3]);
            }
            else
            {
                srand(time(NULL));
                tersCevir=rand()%4;
            }    
        }
        else if(tersCevir==2)
        {
             color3 = getpixel(yapay1[0]-1,yapay1[1]+(yapay1[3]-yapay1[1])/2);
             if(color3!=blackcolor1)
             {
                old_yapay1[0]=yapay1[0];
                old_yapay1[1]=yapay1[1];
                old_yapay1[2]=yapay1[2];
                old_yapay1[3]=yapay1[3];
                yapay1[0]--;
                yapay1[2]--;
                readimagefile("resource\\backpaint.bmp",yapay1[2],yapay1[1],old_yapay1[2],old_yapay1[3]);                     
             }
             else
             {
                srand(time(NULL));
                tersCevir=rand()%4;
             }
        }
        else if(tersCevir==3)
        {
             color4 = getpixel(yapay1[2]+1,yapay1[1]+(yapay1[3]-yapay1[1])/2);
             if(color4!=blackcolor1)
             {
                old_yapay1[0]=yapay1[0];
                old_yapay1[1]=yapay1[1];
                old_yapay1[2]=yapay1[2];
                old_yapay1[3]=yapay1[3];
                yapay1[0]++;
                yapay1[2]++;
                readimagefile("resource\\backpaint.bmp",old_yapay1[0],old_yapay1[1],yapay1[0],yapay1[3]);
             }
             else
             {
                    srand(time(NULL));
                    tersCevir=rand()%4;
             }
        }       
    }
}
