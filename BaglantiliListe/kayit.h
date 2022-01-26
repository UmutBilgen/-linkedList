
struct ders { char derskodu[10]; char dersadi[50]; ders* sonraki; };
struct ogrenci { char ogrno[15]; char ad[30]; char soyad[30]; ders* dersdugumu; ogrenci* sonraki; };