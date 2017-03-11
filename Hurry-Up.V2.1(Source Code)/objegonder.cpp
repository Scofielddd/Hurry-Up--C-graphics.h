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

extern int objects_konum[20][4];    //easy map 1 obje kordinalari
extern int objects_konum1[20][4];   //easy map 2 obje kordinalari
extern int objects_konum2[20][4];   //medium map 1 obje kordinalari
extern int objects_konum3[20][4];   //medium map 2 obje kordinalari
extern int objects_konum4[20][4];   //hard map 1 obje kordinalari
extern int objects_konum5[20][4];   //hard map 2 obje kordinalari
extern int karakterkonum[4];
extern int objectsRandDeger;
extern int difficulty;

/* objenin yok olup olmadýðýný denetleme */
void objectsControl(int yon)
{
    if (difficulty==0)
    {
        if(yon==1)
        {
            if ((karakterkonum[2]+2>=objects_konum[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum[objectsRandDeger][3])
            ||(karakterkonum[1]-2<=objects_konum[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum[objectsRandDeger][2])
            ||(karakterkonum[3]+2>=objects_konum[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum[objectsRandDeger][2]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();                                
                randObjectsFunc();
            }
        }
        else if(yon==2)
        {
            if ((karakterkonum[0]-2<=objects_konum[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum[objectsRandDeger][3])
            ||(karakterkonum[1]-2<=objects_konum[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum[objectsRandDeger][2])
            ||(karakterkonum[3]+2>=objects_konum[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum[objectsRandDeger][2]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();  
                randObjectsFunc();
            }
        }
        else if(yon==3)
        {
            if ((karakterkonum[1]-2<=objects_konum[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum[objectsRandDeger][2])
			||(karakterkonum[2]+2>=objects_konum[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum[objectsRandDeger][3])
			||(karakterkonum[0]-2<=objects_konum[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();  
                randObjectsFunc();
            }
        }
        else if(yon==4)
        {
            if (karakterkonum[3]+2>=objects_konum[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum[objectsRandDeger][2]
			||(karakterkonum[2]+2>=objects_konum[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum[objectsRandDeger][3])
			||(karakterkonum[0]-2<=objects_konum[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();  
                randObjectsFunc();
            }
        }
    }
    else if (difficulty==1)
    {
        if(yon==1)
        {
            if ((karakterkonum[3]+2>=objects_konum1[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum1[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum1[objectsRandDeger][2])
            ||(karakterkonum[1]-2<=objects_konum1[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum1[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum1[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum1[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum1[objectsRandDeger][3]))
            {
                printf("%d",objectsRandDeger);
                readimagefile("resource\\backpaint.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==2)
        {
            if ((karakterkonum[3]+2>=objects_konum1[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum1[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum1[objectsRandDeger][2])
            ||(karakterkonum[1]-2<=objects_konum1[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum1[objectsRandDeger][2])
            ||(karakterkonum[0]-2<=objects_konum1[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum1[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==3)
        {
			if ((karakterkonum[1]-2<=objects_konum1[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum1[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum1[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum1[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum1[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum1[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum1[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==4)
        {
            if ((karakterkonum[3]+2>=objects_konum1[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum1[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum1[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum1[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum1[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum1[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum1[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum1[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum1[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum1[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
    }
    else if (difficulty==2)
    {
        if(yon==1)
        {
            if ((karakterkonum[2]+2>=objects_konum2[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum2[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3])
            ||(karakterkonum[1]-2<=objects_konum2[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum2[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum2[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum2[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum2[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3]))
			{
                readimagefile("resource\\backpaint.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==2)
        {
            if ((karakterkonum[0]-2<=objects_konum2[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum2[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3])
            ||(karakterkonum[1]-2<=objects_konum2[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum2[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum2[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum2[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum2[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==3)
        {
            if ((karakterkonum[0]-2<=objects_konum2[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum2[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3])
            ||(karakterkonum[2]+2>=objects_konum2[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum2[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3])
            ||(karakterkonum[1]-2<=objects_konum2[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum2[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum2[objectsRandDeger][2]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==4)
        {
            if ((karakterkonum[3]+2>=objects_konum2[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum2[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum2[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum2[objectsRandDeger][2])
            ||(karakterkonum[0]-2<=objects_konum2[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum2[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3])
            ||(karakterkonum[2]+2>=objects_konum2[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum2[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum2[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum2[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
    }
    else if (difficulty==3)
    {
        if(yon==1)
        {
            if ((karakterkonum[2]+2>=objects_konum3[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum3[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum3[objectsRandDeger][3])
            ||(karakterkonum[3]+2>=objects_konum3[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum3[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum3[objectsRandDeger][2])
            ||(karakterkonum[1]-2<=objects_konum3[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum3[objectsRandDeger][2]))
			{
                printf("%d",objectsRandDeger);
                readimagefile("resource\\backpaint.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==2)
        {
            if ((karakterkonum[0]-2<=objects_konum3[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum3[objectsRandDeger][3])
            ||(karakterkonum[3]+2>=objects_konum3[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum3[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum3[objectsRandDeger][2])
            ||(karakterkonum[1]-2<=objects_konum3[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum3[objectsRandDeger][2]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==3)
        {
			if ((karakterkonum[1]-2<=objects_konum3[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum3[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum3[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum3[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum3[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum3[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum3[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==4)
        {
            if ((karakterkonum[3]+2>=objects_konum3[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum3[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum3[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum3[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum3[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum3[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum3[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum3[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum3[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum3[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
    }
    else if (difficulty==4)
    {
        if(yon==1)
        {
            if ((karakterkonum[2]+2>=objects_konum4[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum4[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum4[objectsRandDeger][3])
            ||(karakterkonum[3]+2>=objects_konum4[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum4[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum4[objectsRandDeger][2])
            ||(karakterkonum[1]-2<=objects_konum4[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum4[objectsRandDeger][2]))
			{
                readimagefile("resource\\backpaint.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==2)
        {
            if ((karakterkonum[0]-2<=objects_konum4[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum4[objectsRandDeger][3])
            ||(karakterkonum[3]+2>=objects_konum4[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum4[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum4[objectsRandDeger][2])
            ||(karakterkonum[1]-2<=objects_konum4[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum4[objectsRandDeger][2]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==3)
        {
            if ((karakterkonum[1]-2<=objects_konum4[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum4[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum4[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum4[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum4[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum4[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum4[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==4)
        {
            if ((karakterkonum[3]+2>=objects_konum4[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum4[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum4[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum4[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum4[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum4[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum4[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum4[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum4[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum4[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
    }
    else if (difficulty==5)
    {
        if(yon==1)
        {
            if ((karakterkonum[2]+2>=objects_konum5[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum5[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum5[objectsRandDeger][3])
            ||(karakterkonum[1]-2<=objects_konum5[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum5[objectsRandDeger][2])
            ||(karakterkonum[3]+2>=objects_konum5[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum5[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum5[objectsRandDeger][2]))
			{
                readimagefile("resource\\backpaint.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==2)
        {
            if ((karakterkonum[0]-2<=objects_konum5[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum5[objectsRandDeger][3])
            ||(karakterkonum[1]-2<=objects_konum5[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum5[objectsRandDeger][2])
            ||(karakterkonum[3]+2>=objects_konum5[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum5[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum5[objectsRandDeger][2]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==3)
        {
            if ((karakterkonum[1]-2<=objects_konum5[objectsRandDeger][3]&&karakterkonum[1]-2>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum5[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum5[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum5[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum5[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum5[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum5[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
        else if(yon==4)
        {
            if ((karakterkonum[3]+2>=objects_konum5[objectsRandDeger][1]&&karakterkonum[3]+2<=objects_konum5[objectsRandDeger][3]&&(karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2)>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[2]-(karakterkonum[2]-karakterkonum[0])/2)<=objects_konum5[objectsRandDeger][2])
            ||(karakterkonum[2]+2>=objects_konum5[objectsRandDeger][0]&&karakterkonum[2]+2<=objects_konum5[objectsRandDeger][2]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum5[objectsRandDeger][3])
            ||(karakterkonum[0]-2<=objects_konum5[objectsRandDeger][2]&&karakterkonum[0]-2>=objects_konum5[objectsRandDeger][0]&&(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2)>=objects_konum5[objectsRandDeger][1]&&(karakterkonum[1]-(karakterkonum[3]-karakterkonum[1])/2)<=objects_konum5[objectsRandDeger][3]))
            {
                readimagefile("resource\\backpaint.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]);
                PlaySound("resource\\sounds\\gold.wav",NULL,SND_FILENAME|SND_ASYNC);
                moneyShow();
                randObjectsFunc();
            }
        }
    }
}
