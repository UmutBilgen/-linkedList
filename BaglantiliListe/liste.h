#define liste_h
#include <stdio.h>
#ifndef kiste_h

#endif // !DOSYAISLEMLERI_H

#include "kayit.h"


struct liste {

    ogrenci* bas;
    int kisisayisi;


    FILE* notdefteri;
    void olustur();
    ogrenci* dugum_olustur(char*, char*, char*, char*, char*);
    void kapat();
    void listebosalt();
    void bastansil();
     void sondansil();
    void ogrencisil( int);
    void kesisim_bul(char *,char *);
    void derssil(char *,char *);
    int OgrenciVarmi(char *);
    void ekle(char*, char*, char*, char*, char*);
     void dersekle(char*, char*, char*);

    int araad(char*);
    int araogrno(char*);
     int tumliste();
    void dosyadan_oku();
    void dosyaya_yaz();
};
