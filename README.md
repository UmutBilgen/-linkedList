Liste yapısını tuttuğum liste.h referans dosyası
Kayıt yapısını tuttuğum kayit.h referans dosyası
Liste yapısında olan fonksiyonlarının içeriğinin bulunduğu 
Listeislem.cpp dosyası
Ve Main Dosyası

Liste.h’ın içindekiler
• Öğrenci listesinin başını tutan bas pointerı
• Kayıtların alınacağı dosyanın adresini belirtecek olan FILE nesnesinin adresi
• Listeyi oluşturacak void oluştur()fonksiyonu
• Düğüm oluşturacak fonksiyon
• Listeyi boşaltmaya yarayan fonksiyon
• Listenin başından düğüm silmeye yarayan fonksiyon
• Listenin sonundan düğüm silmeye yarayan fonksiyon
• Öğrenci silmeye yarayan fonksiyon
• Kesişimler bulacak fonksiyon
• Ders düğümünden veri silmeye yarayan fonksiyon
• Kayıt edilecek öğrenci listede var mı diye kontrol eden fonksiyon
• Kayıt ekleyen fonksiyon
• Listede olan öğrenciye ders ekleyen fonksiyon
• Listede isimle arama yapan fonksiyon
• Listede öğrenci numarasıyla arama yapan fonksiyon
• Tüm listeyi yazdıran Fonksiyon
• Dosyadan verileri okumaya yarayan fonksiyon
• Dosyaya veri yazan fonksiyon

Kayıt.h’ın içindekiler
• Ders düğümünün taşıyacağı özelliklerin belirtildiği struct
• Öğrenci düğümünün taşıyacağı özelliklerin belirtildiği struct

listeslem.cpp ‘in içeriği
Bu dosyada liste.h dosyasının içinde ki fonksiyonların gövdeleri 
yazılmıştır.

• dugumolustur Fonksiyonu öğrenci türünden değer döndürüp
düğüm oluşturup işaretçileri sonraki düğüme işaret ettirir

• araad Fonksiyonu listede bulunan düğümleri işaret eden tara 
işaretçisi kadar dönecek bir döngü oluşturup listede bulunan 
tara’nın işaret ettiği isimleri girilen isimle karşılaştırır eğer 
karşılaştırma olumluysa öğrenciyi yada öğrencileri ekrana 
yazdırır 

• kesisimbul fonksiyonu düğümleri gösteren bir tara 
fonksiyonunu düğüm basına eşitleyip düğüm sayısı kadar 
dönecek bir döngü oluşturup ders düğümlerini işaret eden pn 
işaretçisine tara’nın dersdüğümlerini gönderip listede bulunan 
öğrenicilerin hangilerinin kullanıcıdan alınan ders koduna 
sahip olduğunu kontrol eder bu şartı sağlayan kullanıcılar için 
ders düğümlerinin başını işaret eden pb işaretçisiyle de 
kullanıcıdan alınan 2. Ders koduna aynı anda sahip olan 
öğrencileri listeler ve ekrana yazar

• derssil fonksiyonu düğümleri gösteren bir tara fonksiyonunu 
düğüm basına eşitleyip düğüm sayısı kadar dönecek bir döngü 
oluşturup kullanıcıdan gönderilen öğrenci numarası listede var 
mı onu kontrol ediyor kontrol sağlanırsa ders düğümlerini 
gösteren pn işaretçisine öğrenci numarası girilen öğrencinin 
aldığı dersleri işaret eden tara->dersdüğümü ataması yapılır ve 
numarası girilen öğrencinin dersleri arasında girilen ders var 
mı kontrol eder eğer varsa sonraki düğümü işaret edecek kısmı 
geçici bir düğüme atanır pn düğümü silinip pn işaretçisine 
geçici düğümde ki değer atanır böylece silinmiş düğüm listeden
çıkmış olur

• sondansil fonksiyonu düğümün sonunu gösterecek bir işaretçi 
yardımıyla düğüm sonuna gider ve son düğümün işaret ettiği 
işaretçiyi null yaparak listeden silmiş olur

• Bastansil fonksiyonu bas işaretçisinden sonrasını geçici bi 
işaretçiye atayıp baş düğümünü silip işaretçisini null yapar 
daha sonra geçici işaretçinin adresini bas değişkenine atayarak 
baştaki düğümü silmiş olur

• Ogrencisil fonskiyonu girilen sıra numarası 1 ise bastansil 
fonksiyonunu kullanarak son öğrencinin sıra numarasıysa 
sondan sil fonksiyonunu kullanarak silme işlemi yapar ara 
sıralar içinse düğüm başından girilen sıra numarasına saça 
değişkenini eşitlemek için while ile düğüm sonuna gelene kadar 
ve sıranumarası sayaca eşit olana kadar dönen bir döngü 
oluştururuz daha sonra sayaç ve sira numarasının kontrollerini 
yapıp eşitse tara işaretçisinin dersdüğümlerini pn işaretçisine 
atayıp ders düğümlerini silen ve tara düğümünün sonrakini 
işaret eden işaretçiyi geçici bir işaretçiye atayıp tara düğümünü 
silerek geçici düğümün adresini de tara adresine atayarak 
aradan silme işlemini gerçekleştirir

• Ogrencivarmı fonksiyonu bas düğümüne eşitlediğimiz tara 
düğümü null olana kadar dönen bir while döngüsü oluşturup 
öğrenci numarasının listede olup olmadığını kontrol eder varsa 
fonksiyon içinde tanımlanmış olan kactane değişkenini arttırır 
bu değişkenin amacı ise olup olmadığını daha net anlamak 
fonksiyon int fonksiyonu olduğu için return olarakta kaçtane 
değişkenini döndürür

• Dersekle eğer listede öğrenci varsa öğrenci numarası 
parametresi ile tara null olana kadar dönen ve öğrenci 
numarasının taranın işaret ettiği öğrencinin numarasına eşit 
olup olmadığını kontrol eder eğer eşitse o öğrenciye girilen 
dersi ekler

• Ekle fonksiyonu eğer listede hiç düğüm yoksa düğüm oluştur 
fonksiyonunu çağırarak baş işaretçisine oranın adresini verir 
eğer listede düğüm varsa listenin sonuna gidip sonu işaret eden 
işaretçinin sonraki kısmına yeni düğümü ekler ve son düğümün 
işaretçisini arttırıp son düğümün sonraki işaretçisini de null 
yapar

• Dosyadanoku fonksiyonu içinde tanımlanmış str dizisinin 
içinde metin belgelerinin isimlerini tutar ve bunları for 
yardımıyla sıra sıra açarak dosya işlemleri ile öğrencivarmı 
fonksiyonunu kullanarak dosyada ki öğrencinin listede olup 
olmadığını kontrol eder eğer yoksa ekle fonksiyonunu varsa 
ders ekle fonksiyonunu çağırır

• Tümliste fonksiyonu tara işaretçisine düğümlerin başını işaret 
eden bas işaretçisinin adresini verir ve düğümlerin sonuna 
kadar gidecek while döngüsünü başlatır her düğümün içinde 
bulunan bilgileri ekrana yazdırır

• Dosyaya yaz fonksiyonu tara işaretçisine düğümlerin başını 
işaret eden bas işaretçisinin adresini verir ve düğümün sonuna 
kadar dönecek olan while döngüsünü oluşturur (while(tara))
Kayıt structının içeriğini tutuğu öğrenci bilgileri taranın işaret 
ettiği düğümlerden alır dosyaya yazma komutu fprintf ile 
dosyaya kaydeder 

• Oluştur fonksiyonu ise listeyi oluşturur ilk başta düğüm 
olmadığı için bas isretçisi nullu işaret eder ve kişisayısı 0 olur
daha sonra dosyadanoku fonksiyonunu çağırarak dosyada ki 
bilgileri listeye kaydeder
