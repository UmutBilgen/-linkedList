
#include "liste.h"
#include <iostream>
#include <stdlib.h>
//#include <cstdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;




ogrenci* liste::dugum_olustur(char* yeniad, char* yenisoyad, char* yeniogrno, char* yeniderskodu, char* yenidersadi)
{
    ogrenci* yenikisi;
    ders* yeniders;
    yenikisi = new ogrenci;
    strcpy(yenikisi->ad, yeniad);
     strcpy(yenikisi->soyad, yenisoyad);
      strcpy(yenikisi->ogrno, yeniogrno);
    yeniders = new ders;
    yenikisi->dersdugumu = yeniders;
    strcpy(yeniders->derskodu, yeniderskodu);
    strcpy(yeniders->dersadi, yenidersadi);
    yeniders->sonraki = NULL;
    yenikisi->sonraki = NULL;
    return yenikisi;

}



int liste::araad(char*ad)
{
    ogrenci *tara;
    ders *pn;
    tara=bas;int sayac=0;
    int bulunan=0;
    while(tara)
    {

        if(strcmp(ad,tara->ad)==0)
        {
            cout<<tara->ogrno<<" "<<tara->ad<<" "<<tara->soyad<<" ";
            pn=tara->dersdugumu;
            while(pn)
            {
                cout<<pn->derskodu<<" "<<pn->dersadi<<" ";
                pn=pn->sonraki;
            }
            bulunan++;
              cout<<"\n";
        }

        tara=tara->sonraki;
    }
    return bulunan;
}

void liste::kesisim_bul(char *ders1,char *ders2)
{
    ogrenci *tara;
    ders *pn,*pb;
    tara=bas;
    while(tara)
    {
        pn=tara->dersdugumu;
        while(pn)
        {
            if(strcmp(ders1,pn->derskodu)==0)
            {
                pb=tara->dersdugumu;
                while(pb)
                {
                    if(strcmp(ders2,pb->derskodu)==0)
                 {
                     cout<<tara->ogrno<<" "<<tara->ad<<" "<<tara->soyad<<endl;
                 }
                 pb=pb->sonraki;
                }

            }
            pn=pn->sonraki;
        }

        tara=tara->sonraki;
    }
}

void liste::derssil(char *ogrno,char *derskodu)
{
    ogrenci *tara,*onceki;
    ders *pn;

    tara=bas;
       while(tara)
    {
        if(strcmp(ogrno,tara->ogrno)==0)
        {
            pn=tara->dersdugumu;

            while(pn)
                {

                    if(strcmp(derskodu,pn->derskodu)==0)
                      {
                            tara->dersdugumu=pn->sonraki;
                            delete pn;
                            pn=tara->dersdugumu;
                            return;
                      }
                    pn=pn->sonraki;
                }
            break;
        }

        tara=tara->sonraki;
    }

}
void liste::sondansil()
{
    ogrenci *tara;
    ders *pn;
    tara=bas;
    while(tara->sonraki->sonraki!=NULL)
    {
        tara=tara->sonraki;
    }

        pn=tara->sonraki->dersdugumu;
        while(pn)
        {
            tara->sonraki->dersdugumu=pn->sonraki;
            delete pn;
            pn=tara->sonraki->dersdugumu;
        }
    delete tara->sonraki;
    tara->sonraki=NULL;
}

void liste::bastansil()
{
    ogrenci *tara,*yenikisi,*son,*onceki;
ders *ekleders,*pn;
    if(bas==NULL)
    {
        cout<<"Listede Eleman yoh"<<endl;
    }
    if(bas->sonraki==NULL)
    {

        pn=bas->dersdugumu;
        while(pn)
        {
            bas->dersdugumu=pn->sonraki;
            delete pn;
            pn=bas->dersdugumu;
        }
         bas=NULL;
    }
    tara=bas->sonraki;
    bas=tara;
}
void liste::ogrencisil( int sirano)
{
    ogrenci *tara,*son;
ders *pn;
    tara=bas;
    int sayac=1;
    if(sirano<=0)
    {
        cout<<"hatalı sira no"<<endl;
    }
    if(sirano==1)
    {
        bastansil();
        return;
    }
    while((tara!=NULL)&&(sayac<sirano))
    {
        son=tara;


        tara=tara->sonraki;
        sayac++;
    }
    if(sayac<sirano)
    {
        cout<<"Girdiğiniz sırada silinecek eleman yok";
        return;
    }
    else
    {
        son->sonraki=tara->sonraki;
        pn=tara->dersdugumu;
        while(pn)
        {
            tara->dersdugumu=pn->sonraki;
            delete pn;
            pn=tara->dersdugumu;
        }
    }
    delete tara;


}


int liste::OgrenciVarmi(char *ogrno)
{
    ogrenci *tara,*yenikisi,*son,*onceki;
ders *ekleders,*pn;

    int kactane=0;
    tara=bas;
    while(tara)
    {
        if(strcmp(ogrno,tara->ogrno)==0)
        {
            kactane++;

        }

        tara=tara->sonraki;
    }
    return kactane;
}
void liste::dersekle(char*ogrno,char*yeniderskodu,char*yenidersadi)
{
    ogrenci *tara,*yenikisi,*son,*onceki;
ders *ekleders,*pn;
    tara=bas;
       while(tara)
    {
        if(strcmp(ogrno,tara->ogrno)==0)
        {
                        ekleders=new ders;
                        ekleders->sonraki=tara->dersdugumu;
                        tara->dersdugumu=ekleders;
                        strcpy(ekleders->derskodu,yeniderskodu);
                        strcpy(ekleders->dersadi,yenidersadi);
            break;
        }

        tara=tara->sonraki;
    }
}
void  liste::ekle(char* yeniad, char* yenisoyad, char* yeniogrno, char* yeniderskodu, char* yenidersadi)
{
ogrenci *tara,*yenikisi,*son,*onceki;
ders *ekleders,*pn;

    tara=bas;
    if(bas==NULL)
    {
        bas=dugum_olustur(yeniad,yenisoyad,yeniogrno,yeniderskodu,yenidersadi);
        kisisayisi++;
    }
    else{

            son=bas;
    while(son->sonraki!=NULL)
    {
        son=son->sonraki;

    }
        yenikisi=dugum_olustur(yeniad,yenisoyad,yeniogrno,yeniderskodu,yenidersadi);

        son->sonraki=yenikisi;
        kisisayisi++;



        }


}


void liste::dosyadan_oku()
{

 struct Dosya_Kayit
    {
      char ogrno[15];
      char ad[30];
      char soyad[30];
      char derskodu[10];
      char dersadi[50];
    };
    Dosya_Kayit kayit;

        string str[3];
        str[0]="eng101.txt";
        str[1]="fiz101.txt";
        str[2]="mat101.txt";
        for(int i=0;i<3;i++)
          {
            const char *c = str[i].c_str();
            notdefteri=fopen(c,"r+");
             if(notdefteri==NULL)
               {
                cout<<"calýsmadý";
               }
            fscanf(notdefteri,"%s %s",kayit.derskodu,kayit.dersadi);
             while(!feof(notdefteri))
               {
                    fscanf(notdefteri,"%s %s",kayit.ogrno,kayit.ad);
                    fgets(kayit.soyad,31,notdefteri);
                    kayit.soyad[strlen(kayit.soyad)-1]='\0';

                     if(OgrenciVarmi(kayit.ogrno)!=0)
                        {
                          dersekle(kayit.ogrno,kayit.derskodu,kayit.dersadi);
                        }
                     else
                        {
                          ekle(kayit.ad,kayit.soyad,kayit.ogrno,kayit.derskodu,kayit.dersadi);
                        }
               }
            }
}
int liste::tumliste()
{

    ogrenci *tara;
    ders *pn;
    int sayac=0;
    int bulunan=0;
    tara=bas;
 while(tara)
    {
        sayac++;
        pn=tara->dersdugumu;
        cout<<sayac<<". "<<tara->ogrno<<" "<<tara->ad<<" ";
        if(pn==NULL)
        {
            cout<<"Ogrencinin Aktif dersi yoktur";
        }
        while(pn)
        {

            cout<<pn->derskodu<<" "<<pn->dersadi<<" ";
            pn=pn->sonraki;

         }
        bulunan++;
        tara=tara->sonraki;
        cout<<"\n";
    }
 return bulunan;
}

void liste::dosyaya_yaz()
{
    struct Dosya_Kayit
    {
      char ogrno[15];
      char ad[30];
      char soyad[30];
      char derskodu[10];
      char dersadi[50];
    };
    Dosya_Kayit kayit;
    ogrenci *tara;
    ders *pn;
    tara=bas;
    int tarasayac;
    notdefteri=fopen("DosyaCikti.txt","w+");
    if(notdefteri==NULL)
    {
    cout<<"Açılmadı";
    }
    while(tara)
    {
            pn=tara->dersdugumu;
            strcpy(kayit.ad,tara->ad);
            strcpy(kayit.soyad,tara->soyad);
            strcpy(kayit.ogrno,tara->ogrno);
            fprintf(notdefteri,"%s--%s--%s",kayit.ogrno,kayit.ad,kayit.soyad);
        while(pn)
        {
            strcpy(kayit.derskodu,pn->derskodu);
            strcpy(kayit.dersadi,pn->dersadi);
            fprintf(notdefteri,"--%s--%s--",kayit.derskodu,kayit.dersadi);
            pn=pn->sonraki;
        }
        fprintf(notdefteri,"\n");
        tara=tara->sonraki;
    }
    fclose(notdefteri);
}

void  liste::olustur()
{
    bas = NULL;
    kisisayisi=0;
    dosyadan_oku();
}
int liste::araogrno(char *ogrno)
{
    ogrenci *tara,*onceki;
    ders *pn;
    int sayac=0;
    int bulunan=0;
    tara=bas;
    bool tumu=false;
 while(tara)
    {
        sayac++;

         if(strcmp((ogrno),tara->ogrno)==0)
            {
                bulunan++;
                cout<<"\n";
                cout<<sayac<<". Kayit:"<<" Numarasi:"<<tara->ogrno<<" Adi:"<<tara->ad<<" Soyadi: "<<tara->soyad<<"\t";
                pn=tara->dersdugumu;
                cout<<"\n Dersleri  ";
                while(pn)
                {
                   cout<<pn->derskodu<<" "<<pn->dersadi<<" ";
                   pn=pn->sonraki;
                }
cout<<"\n";
            }
        tara=tara->sonraki;

    }
 return bulunan;

}

