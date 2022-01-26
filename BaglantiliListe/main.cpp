#include "liste.h"
#include <iostream>
#include <cstring>
#include <locale.h>

#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
#include<fstream>
#include <clocale>
#include <stdio.h>
typedef ogrenci ogrencikayit;
typedef ders derskayit;
typedef liste veriyapisi;



veriyapisi defter;

void derssil()
{

    char ogrno[15],derskodu[10];
     cout<<"Dersini silmek istediginiz ogrenicin numarasini girin"<<endl;
    cin>>ogrno;

     cout<<"Silmek istediginiz dersin kodunu girin"<<endl;
      cout<<"DERS KODLARI \n MATEMATIK: MAT101 \n FIZIK: FIZ101 \n INGILIZCE: ENG101"<<endl;

    cin>>derskodu;

    defter.derssil(ogrno,derskodu);



}

void kesisim_bul()
{
     cout<<"DERS KODLARI \n MATEMATIK: MAT101 \n FIZIK: FIZ101 \n INGILIZCE: ENG101"<<endl;
  char derskodu1[10],derskodu2[10];
     cout<<"1. DERS KODUNU GIRINIZ"<<endl;
     cin>>derskodu1;
     cout<<"2. DERS KODUNU GIRINIZ"<<endl;
     cin>>derskodu2;
     defter.kesisim_bul(derskodu1,derskodu2);
}
void ara_ogrno()
{
    char ogrno[15];
    cout<<"Lutfen aramak istediginiz ogrenci numarasini giriniz"<<endl;
    cin>>ogrno;
    if(defter.araogrno(ogrno)==0)
    {
         cout<<"Aradiginiz Ogrenci Numarasi Bulunamadi"<<endl;

    }
}
void ara_ad() // Hocam 3 isimlilerde soyadý alýrken sýkýntý yaþadýðým için aramayý isimle yaptým
{
    char ad[30];



    cout<<"Aramak istediginiz Adi giriniz"<<endl;
    cin>>ad;

     int indis=0;
  while(ad[indis])
    {
   int deger = ad[indis];
      if(deger>96 && deger<123) // Küçük harfi büyük harfe çevirme
            ad[indis]-=32;
        indis++;
    }
    if(defter.araad(ad)==0)
    {
        cout<<"Aradiginiz isim listede bulunamadi";
    }



}

void ogrencisil()
{
    int sirano;
     cout<<" Silmek istediginiz ögrenicin 'Sira Numarasini' girin"<<endl;
    cin>>sirano;
    defter.ogrencisil(sirano);
}


void tumliste()
{
    if(defter.tumliste()==0)
    {
        cout<<" Liste Boþ";
    }


}





void islemMenu() {

    cout <<"\n"<< "Yapmak istediginiz islem isin asagidaki durumlardan birini giriniz." << endl;
    cout << "Arama yapmak icin : A" << endl;
    cout << "Ders silmek icin : D" << endl;
    cout << "Kesisim bulmak icin : K" << endl;
    cout << "Listeyi ekrana yazdirmak icin : L" << endl;
    cout << "Ogrenci silmek icin : O" << endl;
    cout << "Dosya Yaz : Y" << endl;
    cout << "Cikis icin : C" << endl;
    cout << endl;
    cout << "Bir secenek giriniz {A , D , K , L , O , Y , C}" << endl;
}

bool islemYap(char secim)
{
    bool sonlandir = false;
switch (secim)
{

    case 'A': case 'a':
    {
         system("cls");
            char s;
            cout << "Numarayla Arama Yapmak Icin N/n Ad ile Arama yapmak icin A/a" << endl;
            cin>>s;
        switch(s)
        {
        case 'A': case 'a':
        {
            system("cls");
            ara_ad();
            break;
        }
        case 'N': case 'n':
        {
            system("cls");
            ara_ogrno();
            break;
        }
        default:
        {
            cout << "Hata belirtilen tuslamalardan farkli bir tuslama yaptiniz Anamenuye Aktarildiniz" << endl;
            islemMenu();
            cin >> secim;
            sonlandir = islemYap(secim);
            break;
        }
        }

        break;
    }
    case 'D': case 'd':
    {
        system("cls");
        derssil();

        break;
    }
    case 'K': case 'k':
    {
        system("cls");
        kesisim_bul();
        break;
    }
    case 'L': case 'l':
    {
        system("cls");
       tumliste();
        break;
    }
    case 'O': case 'o':
    {
        system("cls");
        ogrencisil();
        break;
    }
    case 'Y': case 'y':
    {
        system("cls");
        defter.dosyaya_yaz();
        break;
    }
    case 'C': case 'c':
    {
        system("cls");

        cout << "Programý sonlandirmak istediginize emin misiniz Evet (E/e) Hayir (H/h)" << endl;
        cin >> secim;
        if (secim == 'E' || secim == 'e')
        {
            sonlandir = true;
            break;
        }
        else if (secim == 'H' || secim == 'h')
        {
            sonlandir = false;
            break;
        }
        else
        {
            cout << "LÜTFEN E YADA H olarak giriþ yapýn";
        }

        break;
    }
    default:
        cout << "Hata belirtilen tuslamalardan farklý bir tuslama yaptýnýz" << endl;
        cout << "Tekrar Bir secenek giriniz {A , D , K , L , O , Y , C}" << endl;
        cin >> secim;
        islemMenu();
        sonlandir = islemYap(secim);
        break;
    }
    return sonlandir;
}

void listekur()
{
    defter.olustur();
}

int main()
{
    listekur();
  bool bitir=false;
  char secim;
  while(!bitir)
  {
      islemMenu();
      cin>>secim;
      bitir=islemYap(secim);
  }
    setlocale(LC_ALL, "Turkish");
}

