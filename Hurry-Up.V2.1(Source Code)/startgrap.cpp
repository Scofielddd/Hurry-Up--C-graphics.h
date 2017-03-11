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

int delayArray[3]={3000,3500,450};  //delay degiskenleri 1-logo 2-logo 3-loading
int startscreen; //graphics.h ekran degiskeni
int keyboardactive = 1; //klavye ekrani acip kapama
int keyboardlocation = 1,old_keyboardlocation=1;  //klavye etrafi magenta cerceve konumu 
int textlocationx = 150,textlocationy = 150; //klavye aciklama kordinatlari
char nick_harf; //tus algilama degiskeni
char nickname[8]; //nickin tamamini tutan degisken
char old_nickname[8]; 
int gamescreenactive = 0;
int mouseX=0,mouseY=0;   //tiklama kordinatlarini tutan degisken
int cursorsira1,cursorsira2;
int dongu1=0,dongu2=0,sira=0;  //top players okuma for dongusu degiskenleri
int language=0,difficulty=0; //setting kýsmi parametreleri
int total_gold=3000;
char tgoldch[5];
int chr_lvl=1;
FILE *filecontrol;  //dosya yoksa olusturmak icin isaretçi
FILE *scoredbp;  //skor dosyasi iþaretçi

void scoreShow(int deger,int k);
void loadstart(void);
void shopFunc(void);
void gamestartscreen(); //gamestartfonksiyonu üst bildirge

/*satin alma eminmisiniz fonksiyonu */
void buyNow(int lvl)
{
    readimagefile("resource\\store\\satinal.bmp",0,0,1280,720);
    clearmouseclick(WM_LBUTTONDOWN);
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if((mouseX>=475 && mouseX<=850)&&(mouseY>=175 && mouseY<=260))
        {     
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);  
            chr_lvl=lvl;
            if(lvl==2)
                total_gold-=100;
            else if(lvl==3)
                total_gold-=150;
            else if(lvl==4)
                total_gold-=200;
            else if(lvl==5)
                total_gold-=300;
            shopFunc();
        }
        else if((mouseX>=615 && mouseX<=720)&&(mouseY>=470 && mouseY<=550))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            shopFunc();
        }
        else
            clearmouseclick(WM_LBUTTONDOWN);
    }
}
/* Market Fonksiyonu yönetimi */
void shopFunc(void)
{
    if(language==0)
        readimagefile("resource\\store\\store_en.bmp",0,0,1280,720);
    else if(language==1)
        readimagefile("resource\\store\\store_tr.bmp",0,0,1280,720);
    clearmouseclick(WM_LBUTTONDOWN);
    sprintf(tgoldch,"%d",total_gold);
    outtextxy(1130,85,tgoldch);
    if(chr_lvl==1)
       outtextxy(1150,160,"Android"); 
    else if(chr_lvl==2)
       outtextxy(1150,160,"Spider"); 
    else if(chr_lvl==3)
        outtextxy(1150,160,"Lobster");
    else if(chr_lvl==4)
        outtextxy(1150,160,"Monkey");
    else if(chr_lvl==5)
        outtextxy(1150,160,"Alien");
        
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if((mouseX>=85 && mouseX<=260)&&(mouseY>=295 && mouseY<=460)&&chr_lvl!=1)
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            buyNow(1);
        }
        else if((mouseX>=485 && mouseX<=655)&&(mouseY>=275 && mouseY<=470)&&total_gold>=100&&chr_lvl!=2)
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            buyNow(2);
        }  
        else if((mouseX>=920 && mouseX<=1055)&&(mouseY>=305 && mouseY<=475)&&total_gold>=150&&chr_lvl!=3)
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            buyNow(3);
        }  
        else if((mouseX>=315 && mouseX<=445)&&(mouseY>=450 && mouseY<=645)&&total_gold>=200&&chr_lvl!=4)
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            buyNow(4);
        }  
        else if((mouseX>=735 && mouseX<=885)&&(mouseY>=450 && mouseY<=645)&&total_gold>=300&&chr_lvl!=5)
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            buyNow(5);  
        }    
        else if((mouseX>=1145 && mouseX<=1260)&&(mouseY>=595 && mouseY<=695))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gamestartscreen();
        }
        else
            clearmouseclick(WM_LBUTTONDOWN);
    } 
}


/* Setting fonksiyonu */
void settingsFunc()
{
    if(language==0 && difficulty==0)
    {
        readimagefile("resource\\settings\\settings_en_e.bmp",0,0,1280,720);
    }
    else if(language==0 && difficulty==2)
    {
        readimagefile("resource\\settings\\settings_en_m.bmp",0,0,1280,720);
    }
    else if(language==0 && difficulty==4)
    {
        readimagefile("resource\\settings\\settings_en_h.bmp",0,0,1280,720);
    }
    else if(language==1 && difficulty==0)
    {
        readimagefile("resource\\settings\\settings_tr_e.bmp",0,0,1280,720);
    }
    else if(language==1 && difficulty==2)
    {
        readimagefile("resource\\settings\\settings_tr_m.bmp",0,0,1280,720);
    }
    else if(language==1 && difficulty==4)
    {
        readimagefile("resource\\settings\\settings_tr_h.bmp",0,0,1280,720);
    }
    clearmouseclick(WM_LBUTTONDOWN);
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if((mouseX>=475 && mouseX<=622)&&(mouseY>=250 && mouseY<=291))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            language=0;   //0 için dil ingilizce
            settingsFunc();
        }
        else if((mouseX>=642 && mouseX<=795)&&(mouseY>=250 && mouseY<=291))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            language=1;          //1 için dil türkçe
            settingsFunc();
        }  
        else if((mouseX>=455 && mouseX<=569)&&(mouseY>=412 && mouseY<=455))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            difficulty=0;   //zorluk kolay
            settingsFunc();
        }  
        else if((mouseX>=576 && mouseX<=713)&&(mouseY>=412 && mouseY<=455))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            difficulty=2;    //zorluk orta
            settingsFunc(); 
        }  
        else if((mouseX>=725 && mouseX<=825)&&(mouseY>=412 && mouseY<=455))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            difficulty=4;        //zorluk zor
            settingsFunc();  
        }    
        else if((mouseX>=605 && mouseX<=675)&&(mouseY>=485 && mouseY<=555))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gamestartscreen();
        }
        else
            clearmouseclick(WM_LBUTTONDOWN);  
    }
}
/* highscore struct yapýsý */
typedef struct TPplayer
{
		char nicknamedb[9];
		int scoredb;
}topplayer;
struct  sortplayer
{
    char nicknamesb[9];
	int scoresb;
}sortp[100];

/* Highscore Ekrani siralama algoritmasi */
void scoreSort(int konum,int goldc)
{
    int i=0;
    struct TPplayer tp;
    total_gold=goldc;
    if(konum==0)
    {
        scoredbp =  fopen("resource\\score.dat","r");  //score.dat dosyasi acildi
        fread(&tp,sizeof(tp),1, scoredbp);
        while (!feof(scoredbp))
        {
            strcpy(sortp[i].nicknamesb,tp.nicknamedb);      //okunanlari biz diziye atiyoruz.
            sortp[i].scoresb=tp.scoredb;
            i++;
            fread(&tp,sizeof(tp),1, scoredbp);   
        }
        /*
        siralama algoritmasi baslangici kendinden buyuk kac sayi varsa o siraya koyuyor.
        10 dan buyukse listeye alinmaz
        */
        for(dongu1=0 ; dongu1< i ;dongu1++)
        {
            for(dongu2=0;dongu2< i ; dongu2++)
            {
                if(sortp[dongu1].scoresb<sortp[dongu2].scoresb)
                {
                   sira++;    
                   if(sira>10)
                   break;
                }
            }
            scoreShow(sira,dongu1);
            sira=0;
        }
        fclose(scoredbp);            
    }          
    if(konum==1)
    {
        scoredbp =  fopen("resource\\score.dat","a+");
        strcpy(tp.nicknamedb,nickname);
        tp.scoredb=goldc;
        fwrite(&tp,sizeof(tp),1,scoredbp);
        fclose(scoredbp);
        scoreSort(0,total_gold);
    }
}
/* Highscore Ekrani ekrana yazdirma  */
void scoreShow(int deger,int k)
{
    char nickyaz[8];
    sprintf(nickyaz,"%d",sortp[k].scoresb);
    if(deger==0)
    {
        outtextxy(500,208,nickyaz); 
        outtextxy(200,208,sortp[k].nicknamesb); 
    }
    else if(deger==1)
    {
        outtextxy(500,297,nickyaz); 
        outtextxy(200,297,sortp[k].nicknamesb); 
    }
    else if(deger==2)
    {
        outtextxy(500,380,nickyaz); 
        outtextxy(200,380,sortp[k].nicknamesb); 
    }   
    else if(deger==3)
    {
        outtextxy(500,445,nickyaz); 
        outtextxy(200,445,sortp[k].nicknamesb); 
    }   
    else if(deger==4)
    {
        outtextxy(500,520,nickyaz); 
        outtextxy(200,520,sortp[k].nicknamesb); 
    }   
    else if(deger==5)
    {
        outtextxy(1080,208,nickyaz); 
        outtextxy(780,208,sortp[k].nicknamesb); 
    }   
    else if(deger==6)
    {
        outtextxy(1080,297,nickyaz);
        outtextxy(780,297,sortp[k].nicknamesb); 
    }   
    else if(deger==7)
    {
        outtextxy(1080,380,nickyaz);
        outtextxy(780,380,sortp[k].nicknamesb); 
    }
    else if(deger==8)
    {
        outtextxy(1080,445,nickyaz);
        outtextxy(780,445,sortp[k].nicknamesb); 
    }   
    else if(deger==9)
    {
        outtextxy(1080,520,nickyaz);
        outtextxy(780,520,sortp[k].nicknamesb); 
    }
}


/* high score ekrani gösterim fonksiyonu */
void scoreFunc(int knm,int goldcount)  //ilk parametre giris ekranindan mý  yoksa oyun sonundan mi fonksiyonu cagirdimizi belirtiyor.
                                        //ikinci parametre  gold miktari
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    settextjustify(LEFT_TEXT,CENTER_TEXT);
    if(language==0)
        readimagefile("resource\\highscore_en.bmp", 0, 0, 1280, 720);
    else if(language==1)
        readimagefile("resource\\highscore_tr.bmp", 0, 0, 1280, 720);
    filecontrol =  fopen("resource\\score.dat","a+");  //skor dosyasi silinmisse oluþturuldu. ***OLUÞMADIYSA skorlar listelenmedi 
    if(filecontrol!=NULL)
        scoreSort(knm,goldcount); //dosya baþarýyla oluþtuysa skor siralama algoritmasi calisti.
    fclose(filecontrol);
    clearmouseclick(WM_LBUTTONDOWN);
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if((mouseX>=1095 && mouseX<=1240)&&(mouseY>=620 && mouseY<=700))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gamestartscreen();  //geridonus icin giris ekrani fonk çaðýrýldý.
        }  
        else
            clearmouseclick(WM_LBUTTONDOWN);  //ekranin herhangi bir yerinden cikis yapmamak için
    }
}
/* hakkinda kýsmý gösterim fonksiyonu */
void creditsFunc()
{
    if(language==0)
        readimagefile("resource\\credits_en.bmp", 0, 0, 1280, 720);
    else if(language==1)
        readimagefile("resource\\credits_tr.bmp", 0, 0, 1280, 720);
    clearmouseclick(WM_LBUTTONDOWN);
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if((mouseX>=60 && mouseX<=200)&&(mouseY>=40 && mouseY<=120))
        {
            PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
            gamestartscreen();  //geridonus icin giris ekrani fonk çaðýrýldý.
        }
        else
            clearmouseclick(WM_LBUTTONDOWN);  //ekranin herhangi bir yerinden cikis yapmamak için
    }
}
/* OYUN GIRIS EKRANI MOUSE FONKSIYONLARI  */
void gamestartscreen()
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    if(language==0)
        readimagefile("resource\\main_en.bmp", 0, 0, 1280, 720);
    else
        readimagefile("resource\\main_tr.bmp", 0, 0, 1280, 720);
    clearmouseclick(WM_LBUTTONDOWN);
       while (!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(100);
            getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
            if((mouseX>=460 && mouseX<=785)&&(mouseY>=270 && mouseY<=430))
            {
                PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
                delay(300);
                loadstart();  //loading ekrani aktif edildi
                cleardevice();
                gameStart(); //oyun baþlatýldý.
                break;      
            }
            if((mouseX>=50 && mouseX<=360)&&(mouseY>=540 &&mouseY<=615))
            {
                PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
                creditsFunc(); //hakkinda kismi çaðýrýldý.
            }
            else if((mouseX>=430 && mouseX<=855)&&(mouseY>=535 &&mouseY<=620))
            {
                PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
                scoreFunc(0,total_gold);  //score ekrani çaðýrýldý ilk parametre 0 için giriþ ekranindan tiklama yapýldýðýný belirtmekte.
                                    //ikinci parametre ise -1 gold miktari giriþ ekranindan tikladimiz için önemsiz.   
            }
            else if((mouseX>=925 && mouseX<=1180)&&(mouseY>=530 &&mouseY<=605))
            {
                PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
                delay(300);
                exit(0);        //cikis butonu
            }
            else if((mouseX>=10 && mouseX<=110)&&(mouseY>=10 &&mouseY<=110))
            {
                PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
                settingsFunc();
            }
            else if((mouseX>=32 && mouseX<=115)&&(mouseY>=165 &&mouseY<=250))
            {
                PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
                shopFunc();
            }
            else
                clearmouseclick(WM_LBUTTONDOWN);
               
        }
}

/* Ana Ekran Aktive edici & klavye while deaktif edici*/
void mainscreenactivator()
{
    keyboardactive = 0;
    gamescreenactive = 1;
}

/* Space tusu Fonksiyonlar */
void skeyboardSpaceFunc()
{
    PlaySound("resource\\sounds\\click.wav",NULL,SND_FILENAME|SND_ASYNC);
    if(strlen(nickname)<8)    //max 8  nick girmek icin
    {
        if(keyboardlocation==1)
            strcat(nickname,"1");
        else if(keyboardlocation==2)
            strcat(nickname,"2");
        else if(keyboardlocation==3)
            strcat(nickname,"3");
        else if(keyboardlocation==4)
            strcat(nickname,"4");
        else if(keyboardlocation==5)
            strcat(nickname,"5");
        else if(keyboardlocation==6)
            strcat(nickname,"6");
        else if(keyboardlocation==7)
            strcat(nickname,"7");
        else if(keyboardlocation==8)
            strcat(nickname,"8");
        else if(keyboardlocation==9)
            strcat(nickname,"9");
        else if(keyboardlocation==10)
            strcat(nickname,"0");
        else if(keyboardlocation==11)
            strcat(nickname,"q");
        else if(keyboardlocation==12)
            strcat(nickname,"w");
        else if(keyboardlocation==13)
            strcat(nickname,"e");
        else if(keyboardlocation==14)
            strcat(nickname,"r");
        else if(keyboardlocation==15)
            strcat(nickname,"t");
        else if(keyboardlocation==16)
            strcat(nickname,"y");
        else if(keyboardlocation==17)
            strcat(nickname,"u");
        else if(keyboardlocation==18)
            strcat(nickname,"i");
        else if(keyboardlocation==19)
            strcat(nickname,"o");
        else if(keyboardlocation==20)
            strcat(nickname,"p");
        else if(keyboardlocation==21)
            strcat(nickname,"a");
        else if(keyboardlocation==22)
            strcat(nickname,"s");
        else if(keyboardlocation==23)
            strcat(nickname,"d");
        else if(keyboardlocation==24)
            strcat(nickname,"f");
        else if(keyboardlocation==25)
            strcat(nickname,"g");
        else if(keyboardlocation==26)
            strcat(nickname,"h");
        else if(keyboardlocation==27)
            strcat(nickname,"j");
        else if(keyboardlocation==28)
            strcat(nickname,"k");
        else if(keyboardlocation==29)
            strcat(nickname,"l");
        //burada del tusu olabilirdi ama olmadý alta koyduk, niye cunku bug oluyor neden if in sarti ile alakalý neyse neyse
        else if(keyboardlocation==31)
            strcat(nickname,"z");
        else if(keyboardlocation==32)
            strcat(nickname,"x");
        else if(keyboardlocation==33)
            strcat(nickname,"c");
        else if(keyboardlocation==34)
            strcat(nickname,"v");
        else if(keyboardlocation==35)
            strcat(nickname,"b");
        else if(keyboardlocation==36)
            strcat(nickname,"n");
        else if(keyboardlocation==37)
            strcat(nickname,"m");
    }
    if(keyboardlocation==30)             //bu kýsýmda nick karakterinden yanlis yazimda silme islemi "del " tusu
        nickname[strlen(nickname)-1]='\0';
    if(keyboardlocation==38 && strlen(nickname)>=1)
        mainscreenactivator();
    if (keyboardlocation!=38)
        skeyboardFunc();
}


/* GIRIS EKRANI SECILI TUS YONETIMI */
void skeyboardFunc()
{
    if (keyboardlocation<1 || keyboardlocation>40)
        keyboardlocation=old_keyboardlocation;
        
    readimagefile("resource\\keyboardScreen.bmp", 0, 0, 1280, 720);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(getmaxx()/2,textlocationy,nickname);
    
    if(keyboardlocation==1)
        rectangle(63,261,160,331);  //1 tusu
    else if(keyboardlocation==2)
        rectangle(177,261,276,331); //2 tusu
    else if(keyboardlocation==3)
        rectangle(291,261,392,331); //3 tusu
    else if(keyboardlocation==4)
        rectangle(405,261,505,331);  //4 tusu
    else if(keyboardlocation==5)
        rectangle(520,261,621,331);   //5 tusu
    else if(keyboardlocation==6)
        rectangle(635,261,736,331);   //6 tusu
    else if(keyboardlocation==7)
        rectangle(750,261,851,331);  //7 tusu
    else if(keyboardlocation==8)
        rectangle(865,261,964,331);   //8 tusu
    else if(keyboardlocation==9)
        rectangle(980,261,1080,331);  //9 tusu
    else if(keyboardlocation==10)
        rectangle(1095,261,1195,331);  //0 tusu
    else if(keyboardlocation==11)
        rectangle(63,350,160,418); //q tusu
    else if(keyboardlocation==12)
        rectangle(177,350,276,418); //w tusu
    else if(keyboardlocation==13)
        rectangle(291,350,392,418); //e tusu
    else if(keyboardlocation==14)
        rectangle(405,350,505,418);  //r tusu       
    else if(keyboardlocation==15)
        rectangle(520,350,621,418);   //t tusu
    else if(keyboardlocation==16)
        rectangle(635,350,736,418);   //y tusu
    else if(keyboardlocation==17)
        rectangle(750,350,851,418);  //u tusu
    else if(keyboardlocation==18)
        rectangle(865,350,964,418);   //i tusu
    else if(keyboardlocation==19)
        rectangle(980,350,1080,418);  //o tusu
    else if(keyboardlocation==20)
        rectangle(1095,350,1195,418);  //p tusu
    else if(keyboardlocation==21)
        rectangle(63,438,160,505); //a tusu
    else if(keyboardlocation==22)
        rectangle(177,438,276,505); //s tusu
    else if(keyboardlocation==23)
        rectangle(291,438,392,505); //d tusu
    else if(keyboardlocation==24)
        rectangle(405,438,505,505);  //f tusu       
    else if(keyboardlocation==25)
        rectangle(520,438,621,505);   //g tusu
    else if(keyboardlocation==26)
        rectangle(635,438,736,505);   //h tusu
    else if(keyboardlocation==27)
        rectangle(750,438,851,505);  //j tusu
    else if(keyboardlocation==28)
        rectangle(865,438,964,505);   //k tusu
    else if(keyboardlocation==29)
        rectangle(980,438,1080,505);  //l tusu
    else if(keyboardlocation==30)
        rectangle(1095,438,1195,505);  //del tusu
    else if(keyboardlocation==31)
        rectangle(63,525,160,591); //z tusu
    else if(keyboardlocation==32)
        rectangle(177,525,276,591); //x tusu
    else if(keyboardlocation==33)
        rectangle(291,525,392,591); //c tusu
    else if(keyboardlocation==34)
        rectangle(405,525,505,591);  //v tusu       
    else if(keyboardlocation==35)
        rectangle(520,525,621,591);   //b tusu
    else if(keyboardlocation==36)
        rectangle(635,525,736,591);   //n tusu
    else if(keyboardlocation==37)
        rectangle(750,525,851,591);  //m tusu
    else if(keyboardlocation==38||keyboardlocation==39||keyboardlocation==40)
    {
        rectangle(865,525,1200,591);   //done tusu
        if(keyboardlocation==39||keyboardlocation==40)
            keyboardlocation=38;
    }
}

/* KLAVYE TUS FONKSIYOLARI */
void skeyboardMovement()
{
    if(keyboardactive==1)
    {
        setcolor(CYAN);
        setlinestyle(0,0,5);
        rectangle(63,261,160,331);  //baslangic ta 1 tusu üzerine secim yapilmasi
    }
    while(keyboardactive)
    {
        old_keyboardlocation=keyboardlocation;
        nick_harf=getch();
        switch(nick_harf)
        {
            case 32 : skeyboardSpaceFunc();break; //harf sec bosluk tusu ve ses
            case 77 : keyboardlocation+=1;skeyboardFunc();break; //sag git
            case 75 : keyboardlocation-=1;skeyboardFunc();break; //sola git
            case 72 : keyboardlocation-=10;skeyboardFunc();break; //yukari git
            case 80 : keyboardlocation+=10;skeyboardFunc();break; //asagi git
            default:continue;
        }
    }
    while(gamescreenactive)
       gamestartscreen();
    
}
/* klavye ekrani yönetim baþlangýcý  & klavye resim ekrani & kullaným yönergesi  */
void skeyboardStarting()
{
    //PlaySound("resource\\backmusic.wav",NULL,SND_FILENAME|SND_ASYNC | SND_LOOP);  //arkaplan sesi
    readimagefile("resource\\keyboardwarn.bmp", 0, 0, 1280 , 720);  //klavye uyari ekranli bmp resmi
    delay(delayArray[1]);
    readimagefile("resource\\keyboardScreen.bmp", 0, 0,  1280, 720);  //klavye resmi basildi.
    skeyboardMovement(); 

}

/* Ana Ekran Logo gösterimi & logoda bekleme süresi ayarý & aktif ekran ayari*/
void sstartScreenFunc()
{
    startscreen = initwindow( 1280 , 720 , "Maze Game-Hurry UP!" ,20,20,true,true); //grafik ekrani olusturuldu
    setactivepage(0);
    setvisualpage(0);
    readimagefile("resource\\girisLogo.bmp", 0, 0, 1280, 720);
    delay(delayArray[0]);
    skeyboardStarting();
}

/* OYUN LOADING SIMILASYONU */
void loadstart(void)
{
    int load1;
    readimagefile("resource\\load\\loadback.bmp",0,0,1280,720);
    delay(100);
    for(load1=0;load1<9;load1++)
    {
        if(load1==0)
        {
            readimagefile("resource\\load\\load1.bmp",0,0,1280,720);
        }
        if(load1==1)
        {
            readimagefile("resource\\load\\load2.bmp",0,0,1280,720);
        }
        if(load1==2)
        {
            readimagefile("resource\\load\\load3.bmp",0,0,1280,720);
        }
        if(load1==3)
        {
            readimagefile("resource\\load\\load4.bmp",0,0,1280,720);
        }
        if(load1==4)
        {
            readimagefile("resource\\load\\load5.bmp",0,0,1280,720);
        }
        if(load1==5)
        {
            readimagefile("resource\\load\\load6.bmp",0,0,1280,720);
        }
        if(load1==6)
        {
            readimagefile("resource\\load\\load7.bmp",0,0,1280,720);
            delay(150);
        }
        if(load1==7)
        {
            readimagefile("resource\\load\\load8.bmp",0,0,1280,720);
        }
        if(load1==8)
        {
            readimagefile("resource\\load\\load9.bmp",0,0,1280,720);
        }    
        delay(delayArray[2]);
    }
}
