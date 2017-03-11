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

int karakterkonum[4]={100,110,130,140};  //karakter baslangic konumlari ve guncel konumu
char yontus;
int krMove=0; //karakter yon tayini
int old_karakterkonum[4]; //karakterin bir onceki kordinatini tutan dizi
int backPaintactive=0,gkeyActive=1;
int hiz=5,ctrl_aralik=40;  //ctrl aralik = duvarlari algilama araligi 
int objectsRandDeger,tempRandDeger=0;  //random deger ve gecici random deger
int randWhile=1;
char tgoldchwin[5];
extern int chr_lvl;  //player karakter tipini tutan degisken
extern int total_gold;    //toplam altini tutan degisken
extern int difficulty;  //zorluk degeri
extern int objects_konum[20][4];    //easy map 1 obje kordinalari
extern int objects_konum1[20][4];   //easy map 2 obje kordinalari
extern int objects_konum2[20][4];   //medium map 1 obje kordinalari
extern int objects_konum3[20][4];   //medium map 2 obje kordinalari
extern int objects_konum4[20][4];   //hard map 1 obje kordinalari
extern int objects_konum5[20][4];   //hard map 2 obje kordinalari
extern int language;
extern int mouseX,mouseY;
void ballFunc(int kr_yon);

/* Game Over Fonksiyonu  */
void gameOverFunc()
{
    if(language==0)
        readimagefile("resource\\finish\\Game_Over_en1.bmp",0,0,1280,720);
    else
        readimagefile("resource\\finish\\Game_Over_tr1.bmp",0,0,1280,720);
    sprintf(tgoldchwin,"%d",total_gold);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
    outtextxy(660,225,tgoldchwin);
    PlaySound("resource\\sounds\\alkis.wav",NULL,SND_FILENAME|SND_ASYNC); 
    clearmouseclick(WM_LBUTTONDOWN);
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if((mouseX>=110 && mouseX<=619)&&(mouseY>=572 && mouseY<=617))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gkeyActive=1;
            gamestartscreen();
        }
        else if((mouseX>=895 && mouseX<=1183)&&(mouseY>=578 && mouseY<=616))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            delay(500);
            exit(0);
        }
        else
            clearmouseclick(WM_LBUTTONDOWN);
    }
}

/* Bir Sonraki Seviye Geçiþ Ekrani */
void nextLevelFunc()
{
    if(difficulty<5)
        difficulty++;
    else
        scoreFunc(1,total_gold);
    
    if(language==0)
    {
        readimagefile("resource\\finish\\win_en1.bmp",0,0,1280,720);
    }
    else if(language==1)
    {
        readimagefile("resource\\finish\\Win_tr1.bmp",0,0,1280,720);
    }
    PlaySound("resource\\sounds\\ta-da.wav",NULL,SND_FILENAME|SND_ASYNC);    
    sprintf(tgoldchwin,"%d",total_gold);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
    outtextxy(680,295,tgoldchwin);
    delay(1500);
    PlaySound("resource\\sounds\\alkis.wav",NULL,SND_FILENAME|SND_ASYNC); 
    clearmouseclick(WM_LBUTTONDOWN);
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if((mouseX>=415 && mouseX<=975)&&(mouseY>=390 && mouseY<=445))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gkeyActive=1;
            gameStart();
        }
        else if((mouseX>=980 && mouseX<=1215)&&(mouseY>=625 && mouseY<=685))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gkeyActive=1;
            gamestartscreen();
        }
        else if((mouseX>=22 && mouseX<=453)&&(mouseY>=639 && mouseY<=685))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gkeyActive=1;
            scoreFunc(1,total_gold);
        }
        else
            clearmouseclick(WM_LBUTTONDOWN);
    } 
}
/* Cikis Kapisi Gösterim Fonksiyonu */
void objekord()
{
    if(difficulty==0)
    {
        readimagefile("resource\\objects\\door.bmp",1025,550,1065,590);
    }
    else if(difficulty==1)
    {
        readimagefile("resource\\objects\\door.bmp",1115,250,1155,290);
    }    
    else if(difficulty==2)
    {
        readimagefile("resource\\objects\\door.bmp",1020,490,1060,530);
    }
    else if(difficulty==3)
    {
        readimagefile("resource\\objects\\door.bmp",1120,85,1160,125);
    }
    else if(difficulty==4)
    {
        readimagefile("resource\\objects\\door.bmp",345,65,375,95);
    }
    else if(difficulty==5)
    {
        readimagefile("resource\\objects\\door.bmp",1170,360,1200,390);
    }
}
/* Para arttirma ve ekrana yazdirma */
void moneyShow(void)
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(940,20,1020,45);
    PlaySound("resource\\sounds\\coin.wav",NULL,SND_FILENAME|SND_ASYNC);
    total_gold++;
    char goldshow[5];
    sprintf(goldshow,"%d",total_gold);
    setcolor(CYAN);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(980,40,goldshow);
}
/* Random Haritada obje olusturma */
int randObjectsFunc()
{
    int randWhile=1;
    while(randWhile)
    {
        x:srand(time(NULL));
        objectsRandDeger=rand()%20;
         if(objectsRandDeger==tempRandDeger)
            goto x;
        
        tempRandDeger=objectsRandDeger;
        randWhile=0;
    }
	
    if(difficulty==0)
    {
        if(chr_lvl==1)
            readimagefile("resource\\objects\\ram.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]);
        else if(chr_lvl==2)
            readimagefile("resource\\objects\\web.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]); 
        else if(chr_lvl==3)    
            readimagefile("resource\\objects\\fish.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]); 
        else if(chr_lvl==4)
            readimagefile("resource\\objects\\banana.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]); 
        else if(chr_lvl==5)    
            readimagefile("resource\\objects\\meteor.bmp",objects_konum[objectsRandDeger][0],objects_konum[objectsRandDeger][1],objects_konum[objectsRandDeger][2],objects_konum[objectsRandDeger][3]);
    }
    else if(difficulty==1)
    {
        if(chr_lvl==1)
            readimagefile("resource\\objects\\ram.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]); 
        else if(chr_lvl==2)
            readimagefile("resource\\objects\\web.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]); 
        else if(chr_lvl==3)    
            readimagefile("resource\\objects\\fish.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]); 
        else if(chr_lvl==4)
            readimagefile("resource\\objects\\banana.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]); 
        else if(chr_lvl==5)    
            readimagefile("resource\\objects\\meteor.bmp",objects_konum1[objectsRandDeger][0],objects_konum1[objectsRandDeger][1],objects_konum1[objectsRandDeger][2],objects_konum1[objectsRandDeger][3]);
    }
    else if(difficulty==2)
    {
        if(chr_lvl==1)
            readimagefile("resource\\objects\\ram.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]); 
        else if(chr_lvl==2)
            readimagefile("resource\\objects\\web.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]); 
        else if(chr_lvl==3)    
            readimagefile("resource\\objects\\fish.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]); 
        else if(chr_lvl==4)
            readimagefile("resource\\objects\\banana.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]); 
        else if(chr_lvl==5)    
            readimagefile("resource\\objects\\meteor.bmp",objects_konum2[objectsRandDeger][0],objects_konum2[objectsRandDeger][1],objects_konum2[objectsRandDeger][2],objects_konum2[objectsRandDeger][3]);
    }
    else if(difficulty==3)
    {
        if(chr_lvl==1)
            readimagefile("resource\\objects\\ram.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]); 
        else if(chr_lvl==2)
            readimagefile("resource\\objects\\web.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]); 
        else if(chr_lvl==3)    
            readimagefile("resource\\objects\\fish.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]); 
        else if(chr_lvl==4)
            readimagefile("resource\\objects\\banana.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]); 
        else if(chr_lvl==5)    
            readimagefile("resource\\objects\\meteor.bmp",objects_konum3[objectsRandDeger][0],objects_konum3[objectsRandDeger][1],objects_konum3[objectsRandDeger][2],objects_konum3[objectsRandDeger][3]);
    }
    else if(difficulty==4)
    {
        if(chr_lvl==1)
            readimagefile("resource\\objects\\ram.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]); 
        else if(chr_lvl==2)
            readimagefile("resource\\objects\\web.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]); 
        else if(chr_lvl==3)    
            readimagefile("resource\\objects\\fish.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]); 
        else if(chr_lvl==4)
            readimagefile("resource\\objects\\banana.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]); 
        else if(chr_lvl==5)    
            readimagefile("resource\\objects\\meteor.bmp",objects_konum4[objectsRandDeger][0],objects_konum4[objectsRandDeger][1],objects_konum4[objectsRandDeger][2],objects_konum4[objectsRandDeger][3]);
    }
    else if(difficulty==5)
    {
        if(chr_lvl==1)
            readimagefile("resource\\objects\\ram.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]); 
        else if(chr_lvl==2)
            readimagefile("resource\\objects\\web.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]); 
        else if(chr_lvl==3)    
            readimagefile("resource\\objects\\fish.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]); 
        else if(chr_lvl==4)
            readimagefile("resource\\objects\\banana.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]); 
        else if(chr_lvl==5)    
            readimagefile("resource\\objects\\meteor.bmp",objects_konum5[objectsRandDeger][0],objects_konum5[objectsRandDeger][1],objects_konum5[objectsRandDeger][2],objects_konum5[objectsRandDeger][3]);
    }
}
/* KARAKTER HAREKET FONKSIYONLARI */
void ballMove(int yonturu)
{
    int tisblack=0;
    int colorblack=0;//COLOR(255,261,266);
    int colorBluedoor=COLOR(36,88,195); //Kapý Kontrolü
    int control1,control2;
    int colorCode,colorCode1;
    old_karakterkonum[0]=karakterkonum[0]; 
    old_karakterkonum[2]=karakterkonum[2];
    old_karakterkonum[1]=karakterkonum[1];
    old_karakterkonum[3]=karakterkonum[3];
    if(yonturu==1)
    {
        for(control1=0;control1<hiz;control1++)
        {
            for(control2=0;control2<ctrl_aralik;control2++)
            {
                colorCode=getpixel(karakterkonum[2]+control1+2,karakterkonum[1]+control2);
                colorCode1=getpixel(karakterkonum[2]+1,(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2));
                if(colorCode==colorblack)
                {
                    tisblack=1;
                    if(tisblack==1)
                    {
                        karakterkonum[0]+=control1;
                        karakterkonum[2]+=control1;
                        break;
                    }
                }
                if(colorCode1==colorBluedoor)
                    nextLevelFunc();
            }
            if(tisblack==1)
                break;
        }
        if(tisblack!=1)
        {
            karakterkonum[0]+=hiz;
            karakterkonum[2]+=hiz;
        }
    }
    if(yonturu==2)
    {
        for(control1=0;control1<hiz;control1++)
        {
            for(control2=0;control2<ctrl_aralik;control2++)
            {
                colorCode=getpixel(karakterkonum[0]-control1-1,karakterkonum[1]+control2);
                colorCode1=getpixel(karakterkonum[0]-1,(karakterkonum[1]+(karakterkonum[3]-karakterkonum[1])/2));
                if(colorCode==colorblack)
                {
                    tisblack=1;
                    if(tisblack==1)
                    {
                        karakterkonum[0]-=control1;
                        karakterkonum[2]-=control1;
                        break;
                    }
                }
                if(colorCode1==colorBluedoor)
                    nextLevelFunc();        
            }
            if(tisblack==1)
                break;
        }
        if(tisblack!=1)
        {
            karakterkonum[0]-=hiz;
            karakterkonum[2]-=hiz;
        }
    }
    
    else if(yonturu==3)
    {
        for(control1=0;control1<hiz;control1++)
        {
            for(control2=0;control2<ctrl_aralik;control2++)
            {
                colorCode=getpixel(karakterkonum[0]+control2,karakterkonum[1]-control1-1);
                colorCode1=getpixel((karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2),karakterkonum[1]-1);
                if(colorCode==colorblack)
                {
                    tisblack=1;
                    if(tisblack==1)
                    {
                        karakterkonum[1]-=control1;
                        karakterkonum[3]-=control1;
                        break;
                    } 
                }
                if(colorCode1==colorBluedoor)
                    nextLevelFunc();        
            }
            if(tisblack==1)
                break;
        }
        if(tisblack!=1)
        {
            karakterkonum[1]-=hiz;
            karakterkonum[3]-=hiz;
        }
    }
    else if(yonturu==4)
    {
        for(control1=0;control1<hiz;control1++)
        {
            for(control2=0;control2<ctrl_aralik;control2++)
            {
                colorCode=getpixel(karakterkonum[0]+control2,karakterkonum[3]+control1+1);
                colorCode1=getpixel((karakterkonum[0]+(karakterkonum[2]-karakterkonum[0])/2),karakterkonum[3]+1);
                if(colorCode==colorblack)
                {
                    tisblack=1;
                    if(tisblack==1)
                    {
                        karakterkonum[1]+=control1;
                        karakterkonum[3]+=control1;
                        break;
                    } 
                }
                if(colorCode1==colorBluedoor)
                    nextLevelFunc();        
            }
            if(tisblack==1)
                break;
        }
        if(tisblack!=1)
        {
            karakterkonum[1]+=hiz;
            karakterkonum[3]+=hiz;
        }
    }
}
/*  tuslari algilama fonksiyonu */
void gkeyFunc()
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    int timeControl=0;
    int deneme1,deneme2,saniye=1,oyunsuresi=241;
    char timeee[5];
    struct tm *zamann;
    while(gkeyActive)
    {   
        time_t t;
        time (&t);
        zamann = localtime (&t);
        if(timeControl==0)
        {
            deneme1=zamann->tm_sec;
            timeControl=1;
        }
        else
        {
            deneme2=zamann->tm_sec;
            timeControl=0;
        }
        if(deneme1!=deneme2)
        {
            oyunsuresi--;
            sprintf(timeee,"%d",oyunsuresi);
            setfillstyle(SOLID_FILL,BLACK);
            bar(415,20,495,45);
            outtextxy(455,40,timeee);
            if(oyunsuresi<=0)
            {
                gkeyActive=0;
                gameOverFunc(); 
                break;  
            }
            else if(oyunsuresi<61&&oyunsuresi%10==0&&oyunsuresi>20)
                PlaySound("resource\\sounds\\warn1.wav",NULL,SND_FILENAME|SND_ASYNC);
            else if(oyunsuresi==20)
                PlaySound("resource\\sounds\\warn2.wav",NULL,SND_FILENAME|SND_ASYNC);
        }
        yapayObje();
        if(kbhit())
        {
            yontus=getch();
            switch(yontus)
            {
                case 77 : ballMove(1);ballFunc(2);objectsControl(1);break; //sag git
                case 75 : ballMove(2);ballFunc(4);objectsControl(2);break; //sola git
                case 72 : ballMove(3);ballFunc(3);objectsControl(3);break; //yukari git
                case 80 : ballMove(4);ballFunc(1);objectsControl(4);break; //asagi git
                case 27 : gamestartscreen();break;
                default:continue; 
            }
        }
    }
    gamestartscreen();
}

/* Harita Level Secim Fonksiyonlari */ 
void mapFunc(int map_level)
{
    if(map_level==0)
    {
        karakterkonum[0]=145;karakterkonum[1]=135;karakterkonum[2]=185;karakterkonum[3]=175;
        ctrl_aralik=40;
        if(language==0)
            readimagefile("resource\\map\\map_easy_en_1.bmp",0,0,1280,720); 
        else if(language==1)
            readimagefile("resource\\map\\map_easy_tr_1.bmp",0,0,1280,720); 
    }
    else if(map_level==1)
    {
        karakterkonum[0]=140;karakterkonum[1]=105;karakterkonum[2]=180;karakterkonum[3]=145;
        ctrl_aralik=40;
        if(language==0)
            readimagefile("resource\\map\\map_easy_en_2.bmp",0,0,1280,720); 
        else if(language==1)
            readimagefile("resource\\map\\map_easy_tr_2.bmp",0,0,1280,720);
    }
    else if(map_level==2)
    {
        karakterkonum[0]=75;karakterkonum[1]=75;karakterkonum[2]=115;karakterkonum[3]=115;
        ctrl_aralik=40;
        if(language==0)
            readimagefile("resource\\map\\map_medium_en_1.bmp",0,0,1280,720); 
        else if(language==1)
            readimagefile("resource\\map\\map_medium_tr_1.bmp",0,0,1280,720);
    }
    else if(map_level==3)
    {
        karakterkonum[0]=135;karakterkonum[1]=70;karakterkonum[2]=170;karakterkonum[3]=105;
        ctrl_aralik=35;
        if(language==0)
            readimagefile("resource\\map\\map_medium_en_2.bmp",0,0,1280,720); 
        else if(language==1)
            readimagefile("resource\\map\\map_medium_tr_2.bmp",0,0,1280,720);
    }
    else if(map_level==4)
    {
        karakterkonum[0]=105;karakterkonum[1]=175;karakterkonum[2]=135;karakterkonum[3]=205;
        ctrl_aralik=30;
        if(language==0)
            readimagefile("resource\\map\\map_hard_en_1.bmp",0,0,1280,720); 
        else if(language==1)
            readimagefile("resource\\map\\map_hard_tr_1.bmp",0,0,1280,720);
    }
    else if(map_level==5)
    {
        karakterkonum[0]=515;karakterkonum[1]=350;karakterkonum[2]=545;karakterkonum[3]=380;
        ctrl_aralik=30;
        if(language==0)
            readimagefile("resource\\map\\map_hard_en_2.bmp",0,0,1280,720); 
        else if(language==1)
            readimagefile("resource\\map\\map_hard_tr_2.bmp",0,0,1280,720);
    }
}
void backPaint(int xx1,int yy1,int xx2,int yy2)
{
    if(backPaintactive)
        readimagefile("resource\\backpaint.bmp",xx1,yy1,xx2,yy2);
}
/* karakter tayini Fonksiyonlari */
void ballFunc(int kr_yon)
{
    if(chr_lvl==1)
    {
        if(kr_yon==1)
        {
            if(krMove==0)  //asagi
            {
                readimagefile("resource\\player\\android\\android_c1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\android\\android_c2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=0;
            }
        }
        else if(kr_yon==2)  //saga
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\android\\android_c1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\android\\android_c2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==3)  //yukari
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\android\\android_c1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\android\\android_c2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==4)   //sola
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\android\\android_c1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\android\\android_c2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=0;
            }
        }
        backPaintactive=1;
    }
    else if(chr_lvl==2)
    {
       if(kr_yon==1)
        {
            if(krMove==0)  //asagi
            {
                readimagefile("resource\\player\\spider\\spider_down_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\spider\\spider_down_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=0;
            }
        }
        else if(kr_yon==2)  //saga
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\spider\\spider_right_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\spider\\spider_right_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==3)  //yukari
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\spider\\spider_up_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\spider\\spider_up_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==4)   //sola
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\spider\\spider_left_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\spider\\spider_left_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=0;
            }
        }
        backPaintactive=1; 
    }
    else if(chr_lvl==3)
    {
        if(kr_yon==1)
        {
            if(krMove==0)  //asagi
            {
                readimagefile("resource\\player\\lobster\\lobster_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\lobster\\lobster_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=0;
            }
        }
        else if(kr_yon==2)  //saga
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\lobster\\lobster_3.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\lobster\\lobster_4.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==3)  //yukari
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\lobster\\lobster_5.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\lobster\\lobster_6.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==4)   //sola
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\lobster\\lobster_7.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\lobster\\lobster_8.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=0;
            }
        }
        backPaintactive=1;
    }
    else if(chr_lvl==4)
    {
        if(kr_yon==1)
        {
            if(krMove==0)  //asagi
            {
                readimagefile("resource\\player\\monkey\\monkey_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\monkey\\monkey_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=0;
            }
        }
        else if(kr_yon==2)  //saga
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\monkey\\monkey_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\monkey\\monkey_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==3)  //yukari
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\monkey\\monkey_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\monkey\\monkey_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==4)   //sola
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\monkey\\monkey_3.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\monkey\\monkey_4.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=0;
            }
        }
        backPaintactive=1;
    }
    else if(chr_lvl==5)
    {
        if(kr_yon==1)
        {
            if(krMove==0)  //asagi
            {
                readimagefile("resource\\player\\alien\\alien_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\alien\\alien_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=2;
            }
            else if(krMove==2)
            {
                readimagefile("resource\\player\\alien\\alien_3.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=3;
            }
            else if(krMove==3)
            {
                readimagefile("resource\\player\\alien\\alien_4.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],old_karakterkonum[1],karakterkonum[2],karakterkonum[1]);
                krMove=0;
            }
        }
        else if(kr_yon==2)  //saga
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\alien\\alien_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\alien\\alien_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=2;
            }
            else if(krMove==2)
            {
                readimagefile("resource\\player\\alien\\alien_3.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=3;
            }
            else if(krMove==3)
            {
                readimagefile("resource\\player\\alien\\alien_4.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(old_karakterkonum[0],karakterkonum[1],karakterkonum[0],karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==3)  //yukari
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\alien\\alien_1.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\alien\\alien_2.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=2;
            }
            else if(krMove==2)
            {
                readimagefile("resource\\player\\alien\\alien_3.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=3;
            }
            else if(krMove==3)
            {
                readimagefile("resource\\player\\alien\\alien_4.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[0],karakterkonum[3],karakterkonum[2],old_karakterkonum[3]);
                krMove=0;
            }
        }
        else if(kr_yon==4)   //sola
        {
            if(krMove==0)
            {
                readimagefile("resource\\player\\alien\\alien_5.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=1;
            }
            else if(krMove==1)
            {
                readimagefile("resource\\player\\alien\\alien_6.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=2;
            }
            else if(krMove==2)
            {
                readimagefile("resource\\player\\alien\\alien_7.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=3;
            }
            else if(krMove==3)
            {
                readimagefile("resource\\player\\alien\\alien_8.bmp",karakterkonum[0],karakterkonum[1],karakterkonum[2],karakterkonum[3]);
                backPaint(karakterkonum[2],karakterkonum[1],old_karakterkonum[2],karakterkonum[3]);
                krMove=0;
            }
        }
        backPaintactive=1;
    }
}

/*Oyun Baslatma fonksiyonlarý cagirma */
int gameStart(void)
{
    
    while(1)
    {
        mapFunc(difficulty);
        randObjectsFunc();
        moneyShow();
        old_karakterkonum[0]=karakterkonum[0]; 
        old_karakterkonum[2]=karakterkonum[2];
        old_karakterkonum[1]=karakterkonum[1];
        old_karakterkonum[3]=karakterkonum[3];
        ballFunc(1);
        objekord();
        gkeyFunc();
    }
    
}
