#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

void KartlariOlustur(int[][15], int); //0-9 aral���nda rastgele kart olu�tur.
void Yazdir(int[][15], int, int); //Olu�turulan rastgele kartlar� ve oyunuclara atanan kartlar� ekrana yazd�r.
void KartAta(int[][15], int[5][15], int); //Olu�turulan rastgele kartlar� oyunculara ata.
void TombalaNumaralariCek(int[90]); //Tombala torbas�ndan rastgele numaralar �ek.
void CekilenNumaralariYazdir(int[90]); //�ekilen numaralar� ekrana yazd�r.
void TombalaOynat(int[5][15], int[90], int, int[5], int[5]); //Tombala oyununu oynat.
void TombalaYazdir(int[5][15], int); //Tombala oyunu s�ras�nda oyuncular�n kartlar�n�n son durmunu yazd�r.
void KazananPuanlariYazdir(int[5], int); //Oyun sonu puanlar�n� yazd�r
void KazananYaz(int[5], int); //Oyunu kazanan ki�inin ka��nc� oyuncu oldu�unu yazd�r.
int main()
{

    int oyuncuSayisi; //Oyuncular�n say�s�n�n de�i�keni.
    int tombalaKarti[10][15]; //0-9 aral���ndaki tombala kartlar�n�n sat�r ve s�tunlar�ndaki eleman say�s�n�n de�i�keni.
    int oyuncuKartlari[5][15]; //Oyunculara atanacak kartlar�n sat�r ve s�tunlar�ndaki eleman say�s�n�n de�i�keni.
    int cekilenNumaralar[90]; //Tombala torbas�ndaki elemanlar�n de�i�keni.
    int puanlar[5]; //Birinci �inko, ikinci �inko ve tombala de�erlerini tutan ve kontrol�n�n de�i�keni. Toplam oyuncu say�s� maksimum 5 ki�i olabilece�i i�in boyutu 5 olan bir dizi olu�uruldu.
    int kazananPuanlar[5]; //Oyuncular�n oyun sonu puanlar� ve kazanan oyuncunun puan�n�n de�i�keni.

    cout << "TOMBALA KARTLARI HAZIRLANIYOR...\n\n";
    KartlariOlustur(tombalaKarti, 10);
    Yazdir(tombalaKarti, 10, 1);
    cout << endl;
    cout << "2-5 Araliginda Oyuncu Sayisi Giriniz." << endl;
    cout << "Oyuncu Sayisi: ";
    cin >> oyuncuSayisi;
    cout << endl;
    while (oyuncuSayisi > 5 || oyuncuSayisi < 2) //Oyuncu say�s� 2-5 aral���nda girilmezse tekrardan oyuncu say�s� gir.
    {
        cout << "Yanlis Bir Deger Girdiniz! Lutfen Yeniden Giriniz." << endl;
        cout << "Oyuncu Sayisi: ";
        cin >> oyuncuSayisi;
        cout << endl;
    }

    KartAta(tombalaKarti, oyuncuKartlari, oyuncuSayisi);
    cout << endl;
    Yazdir(oyuncuKartlari, oyuncuSayisi, 2);
    TombalaNumaralariCek(cekilenNumaralar);
    CekilenNumaralariYazdir(cekilenNumaralar);
    TombalaOynat(oyuncuKartlari, cekilenNumaralar, oyuncuSayisi, puanlar, kazananPuanlar);
    cout << endl;
    TombalaYazdir(oyuncuKartlari, oyuncuSayisi);

    KartAta(tombalaKarti, oyuncuKartlari, oyuncuSayisi);
    cout << endl;
    Yazdir(oyuncuKartlari, oyuncuSayisi, 2);
    TombalaNumaralariCek(cekilenNumaralar);
    CekilenNumaralariYazdir(cekilenNumaralar);
    TombalaOynat(oyuncuKartlari, cekilenNumaralar, oyuncuSayisi, puanlar, kazananPuanlar);
    cout << endl;
    TombalaYazdir(oyuncuKartlari, oyuncuSayisi);

    KartAta(tombalaKarti, oyuncuKartlari, oyuncuSayisi);
    cout << endl;
    Yazdir(oyuncuKartlari, oyuncuSayisi, 2);
    TombalaNumaralariCek(cekilenNumaralar);
    CekilenNumaralariYazdir(cekilenNumaralar);
    TombalaOynat(oyuncuKartlari, cekilenNumaralar, oyuncuSayisi, puanlar, kazananPuanlar);
    cout << endl;
    TombalaYazdir(oyuncuKartlari, oyuncuSayisi);

    KazananPuanlariYazdir(kazananPuanlar, oyuncuSayisi);

    KazananYaz(kazananPuanlar, oyuncuSayisi);

    return 0;
}

void KartlariOlustur(int tombalaKarti[][15], int toplamKartSayisi) //0-9 aral���nda rastgele kart olu�turan fonksiyon.
{
    srand(time(0));

    for (int i = 0; i < toplamKartSayisi; i++) //Toplam kart say�s� kere d�nen bir for d�ng�s�.
    {
        for (int j = 0; j < 15; j++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
        {
            tombalaKarti[i][j] = (rand() % 89 + 1); //Her oyuncuya 1-90 aras�nda rastgele say�lar �reten bir rand() fonksiyonu.
            if (j != 0) //i. kart�n j'lerini bir �nceki j'ye g�re kontrol eder ancak 0'dan �ncesi olmad��� i�in 0 ile ba�layamaz ve bu y�zden e�it de�il 0'l�k bir if bloku
            {
                for (int k = 0; k < j; k++) //Bir sat�rda olu�turulan random say�lar�n birbirine e�itli�ini kontrol eden for f�ng�s�.
                {
                    if (tombalaKarti[i][j] == tombalaKarti[i][k]) //Olu�turulan kartlar�n i. sat�r�ndaki random say�lar�n birbirine e�iti�i durumunda �al���r.
                    {
                        int geciciSayi = tombalaKarti[i][j]; //Elimizde bulunan rastgele say�y� ge�ici bir de�i�kene ata.
                        tombalaKarti[i][j] = (rand() % 89 + 1); //Her oyuncuya 1-90 aras�nda yeniden rastgele say�lar �reten bir rand() fonksiyonu.
                        while (tombalaKarti[i][j] == geciciSayi) //Ge�ici de�i�ken�n yeniden olu�turulan rasgele say�ya e�itli�i durumunda ayn� i�lemi devam ettirecek bir while d�ng�s�.
                        {
                            tombalaKarti[i][j] = (rand() % 89 + 1);
                        }
                    }
                }
            }
        }
    }
}

void KartAta(int tombalaKarti[][15], int oyuncuKartlari[5][15], int oyuncuSayisi) //Olu�turulan rastgele kartlar� oyunculara ata.
{
    int atanmisKartlar[5]; //Oyuncu say�s�na g�re atanacak kartlar� tutan bir dizi.
    for (int i = 0; i < 5; i++) //Maksimum oyuncu say�s� kadar kere d�nen bir for d�ng�s�.
    {
        for (int j = 0; j < 15; j++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
        {
            oyuncuKartlari[i][j] = 0; //Kartlar�n her birinin i�ine sonras�nda de�i�tirilmek �zere 0 atan�r.
        }
        atanmisKartlar[i] = 0; //Kartlar�n her birine ka��nc� oyuncuyu temsil edece�i bilgisi sonras�nda de�i�tirilmek �zere 0 atand�.
    }

    for (int i = 0; i < oyuncuSayisi; i++) //Oyuncu say�s� kadar atanacak kartlar� belirleyen bir for d�ng�s�.
    {
        int oyuncuKart = (rand() % 9 + 1); //Her bir oyuncu i�in rastgele kart numaras� olu�turan bir rand() fonksiyonu.
        atanmisKartlar[i] = oyuncuKart; //oyuncuKart ad�ndaki de�i�kendeki random �retilen say� i. oyuncuya atan�r.
        if (i != 0) //i. oyuncunun kart numaras�n� bir �nceki kart numaralar�na g�re kontrol eder ancak 0'dan �ncesi olmad��� i�in 0 ile ba�layamaz ve bu y�zden e�it de�il 0'l�k bir if.
        {
            for (int j = 0; j < i; j++) //Olu�turulan kart numaralar�n�n birbirine e�itli�ini kontrol eder.
            {
                if (atanmisKartlar[i] == atanmisKartlar[j]) //Olu�turulan kartlar�n birbirine e�iti�i durumunda �al���r.
                {
                    int geciciSayi = atanmisKartlar[i]; //Elimizde bulunan rastgele kart� ge�ici bir de�i�kene ata.
                    atanmisKartlar[i] = (rand() % 9); //Her bir oyuncu i�in yeniden rastgele kart numaras� olu�turan bir rand() fonksiyonu.
                    while (atanmisKartlar[i] == geciciSayi) //Ge�ici de�i�ken�n yeniden olu�turulan rasgele kart numaras�na e�itli�i durumunda ayn� i�lemi devam ettirecek bir while d�ng�s�.
                    {
                        atanmisKartlar[i] = (rand() % 9);
                    }
                }
            }
        }
    }

    for (int i = 0; i < oyuncuSayisi; i++) //Oyuncu say�s� kadar kere d�nen bir for d�ng�s�.
    {
        for (int j = 0; j < 15; j++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
        {
            oyuncuKartlari[i][j] = tombalaKarti[atanmisKartlar[i]][j]; //Oyuncu kartlar�na tombala kartlar�n�n oyuncular i�in rastgele se�ilen numaralar�n�n oldu�u kartlar atan�r.
        }
    }
    cout << "Oyuncular icin secilen kart numaralari: " << endl;
    for (int i = 0; i < oyuncuSayisi; i++) //Oyuncu say�s� kadar kere d�nen bir for d�ng�s�.
    {
        cout << setw(4) << atanmisKartlar[i]; //Oyunculara atanan kartlar� s�ras�yla ekrana yazd�r.
    }
    cout << endl;
}
void TombalaNumaralariCek(int cekilenNumaralar[90]) //Tombala torbas�ndan rastgele numaralar �ek.
{
    for (int i = 1; i <= 90; i++) //1'den 90'a kadar s�ral� bir �ekilde say�lar� diziye atayacak bir for d�ng�s�.
    {
        cekilenNumaralar[i - 1] = i; //S�ras�yla dizi indislerine 1'den 90'a kadar say�lar atar.
    }

    for (int i = 0; i < 89; i++) //1-90 aral���nda tombala torbas�ndan rasgele say�lar �eken bir for d�ng�s�.
    {
        int rastgeleSecilen = rand() % (89 - i) + 1; //rastgeleSecilen de�i�kenine 1 ile 89'dan i. say�y� eksilterek Olu�turulan rand() fonksiyonu atan�r.
        int gecici1 = cekilenNumaralar[rastgeleSecilen]; //gecici olarak olu�turulan 1. de�i�kene cekilenNumaralar dizisinin rastgele say�lardan olu�an rastgeleSecilen de�i�keninin kullan�m� atan�r.
        int gecici2 = cekilenNumaralar[89 - i]; //gecici olarak olu�turulan 2. de�i�kene cekilenNumaralar dizisinin (89-i). indisi atan�r.
        cekilenNumaralar[89 - i] = gecici1; //cekilenNumaralar de�i�keninin (89-i). de�eri gecici olarak olu�turulan 1. de�i�kene atanarak yer de�i�tirme i�lemi yap�ld�.
        cekilenNumaralar[rastgeleSecilen] = gecici2; //cekilenNumaralar de�i�kenin rastgeleSecilen de�i�keninde 1-90 aral���nda �retilen rastgele say�lar� aras�nda yer de�i�tirme yap�l�r.
    }

    int rastgele = rand() % 89;
    int gecici1 = cekilenNumaralar[0];
    int gecici2 = cekilenNumaralar[rastgele];
    cekilenNumaralar[0] = gecici2;
    cekilenNumaralar[rastgele] = gecici1;
    //Bu b�l�mde 0. indis her zaman sabit kaldi�i i�in 0. indis �zel bir rastgele say� atand�. Bu sayi ile 0nci index yer degistirildi.
}

void Yazdir(int tombalaKarti[][15], int satir, int opsiyon) //Olu�turulan rastgele kartlar� ve oyunuclara atanan kartlar� ekrana yazd�r.
{
    if (opsiyon == 1) //Kart numaralar�n� yazd�rmak i�in 1. opsiyonu kullan.
    {
        for (int i = 0; i < satir; i++) //Sat�r say�s� kere d�nen bir for d�ng�s�.
        {
            cout << "Kart No" << (i) << ":";
            for (int j = 0; j < 15; j++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
            {
                cout << setw(4) << tombalaKarti[i][j]; //Ekrana rastgele olu�turulan kartlar� yazd�r.
            }
            cout << endl;
        }
        cout << endl;
    }
    else if (opsiyon == 2) //Oyunculara atanan kart numaralar�n� yazd�rmak i�in 2. opsiyonu kullan.
    {
        for (int i = 0; i < satir; i++) //Sat�r say�s� kere d�nen bir for d�ng�s�.
        {
            cout << i << ". Oyuncunun Tombala Karti: ";
            for (int j = 0; j < 15; j++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
            {
                cout << setw(4) << tombalaKarti[i][j]; //Ekrana oyuncular i�in atanan kartlar� yazd�r.
            }
            cout << endl;
        }
        cout << endl;
    }
}

void CekilenNumaralariYazdir(int cekilenNumaralar[90]) //�ekilen numaralar� ekrana yazd�r.
{
    cout << "CEKILEN NUMARALAR: \n" << endl;

    for (int i = 1; i <= 90; i++) //1-90 aral���nda rastgele fonksiyonlar� yazd�rmak i�in bir for d�ng�s�.
    {
        cout << setw(4) << cekilenNumaralar[i - 1];
        if (!(i % 10)) //10 s�tundan olu�an tek boyutlu bir dizi olmas� istendi�i i�in i. say�n�n 10 ile modu 0 yani yanl�� oldu�unda �al�a�acak bir if bloku
        {
            cout << endl;
        }
    }
}

void TombalaOynat(int oyuncuKartlari[5][15], int cekilenNumaralar[90], int oyuncuSayisi, int puanlar[5], int kazananPuanlar[5]) //Tombala oyununu oynat.
{
    bool tombala = false; //Tombala ad�nda 1. �inko, 2. �inko ve tombala i�leminin ger�ekle�mesi i�in bir de�i�ken olu�turuldu.
    puanlar[5] = 0; //Puanlar�n 5. indisi 1. �inko, 2. �inko ve tombala i�leminin kontrol� i�in var.
    for (int t = 0; t < 5; t++)
    {
        puanlar[t] = 0; //Sonradan de�i�tirilmek �zere puanlar adl� dizinin her bir indisine 0 de�eri atand�.
    }

    for (int i = 0; i < 90; i++) //�ekilen tombala numaralar� kere d�nen bir for d�ng�s�.
    {
        for (int j = 0; j < oyuncuSayisi; j++) //Oyuncu say�s� kere d�nen bir for d�ng�s�.
        {
            for (int k = 0; k < 15; k++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
            {
                if (!tombala) //Tombala de�i�keni yanl�� yani 0 oldu�u durumlda �al��acak if bloku.
                {
                    if (oyuncuKartlari[j][k] == cekilenNumaralar[i]) //j. oyuncunun kart�ndaki k. de�er rastgele �ekilmi� olan tombala torbas�ndaki i. de�ere e�itse �al��acak if bloku.
                    {
                        oyuncuKartlari[j][k] = -1; //j. oyuncunun kart�ndaki k. de�er �ekilen i. tombala numaras�na e�itse k. de�eri -1 olarak g�ncelle.
                        puanlar[j] += 1; //j. oyuncunun kart�ndaki -1 say�s�n� kontrol eder.
                        if ((puanlar[j] == 5) && (puanlar[5] == 0)) //Puanlar dizisindeki j. indisin 5 olmas� durumunda ve puanlar dizisinin 5. indisinin de�erinin 0 olmas� durumunda �al��acak bir if bloku.
                        {
                            puanlar[5] += 1; //Puanlar�n 5. indisi 1 artt�r�larak birinci �inko da olundu�u g�sterilir.
                            cout << "Birinci Cinko kazanan " << j << " numarali oyuncu" << endl;
                            for (int l = 0; l < oyuncuSayisi; l++) //Oyuncu say�s� kere d�nen bir for d�ng�s�.
                            {
                                for (int m = 0; m < 15; m++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
                                {
                                    cout << setw(4) << oyuncuKartlari[l][m]; //Ekrana birinci �inko sonras�ndaki kartlar�n g�r�n�m�n� yazd�r.
                                }
                                cout << endl;
                            }
                            kazananPuanlar[j] += 5; //Birinci �inkoyu yapan j. oyuncunun puan�na 5 ekle.

                        }
                        else if (puanlar[j] == 10 && puanlar[5] == 1) //Puanlar dizisindeki j. indisin 10 olmas� durumunda ve puanlar dizisinin 5. indisinin de�erinin 1 olmas� durumunda �al��acak bir if bloku.
                        {
                            puanlar[5] += 1; //Puanlar�n 5. indisi 1 artt�r�larak ikinci �inko da olundu�u g�sterilir.
                            cout << "Ikinci Cinko kazanan " << j << " numarali oyuncu" << endl;
                            for (int l = 0; l < oyuncuSayisi; l++) //Oyuncu say�s� kere d�nen bir for d�ng�s�.
                            {
                                for (int m = 0; m < 15; m++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
                                {
                                    cout << setw(4) << oyuncuKartlari[l][m];  //Ekrana ikinci �inko sonras�ndaki kartlar�n g�r�n�m�n� yazd�r.
                                }
                                cout << endl;
                            }
                            kazananPuanlar[j] += 10; //�kinci �inkoyu yapan j. oyuncunun puan�na 10 ekle.
                        }
                        else if (puanlar[j] == 15 && puanlar[5] == 2) //Puanlar dizisindeki j. indisin 15 olmas� durumunda ve puanlar dizisinin 5. indisinin de�erinin 1 olmas� durumunda �al��acak bir if bloku.
                        {
                            puanlar[5] += 1; //Puanlar�n 5. indisi 1 artt�r�larak tombala da olundu�u g�sterilir.
                            cout << "Tombala Yapan " << j << " numarali oyuncu" << endl;
                            for (int l = 0; l < oyuncuSayisi; l++) //Oyuncu say�s� kere d�nen bir for d�ng�s�.
                            {
                                for (int m = 0; m < 15; m++)  //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
                                {
                                    cout << setw(4) << oyuncuKartlari[l][m]; //Ekrana tombala sonras�ndaki kartlar�n g�r�n�m�n� yazd�r.
                                }
                                cout << endl;
                            }
                            tombala = true;
                            kazananPuanlar[j] += 15; //Tombala yapan j. oyuncunun puan�na 15 ekle.
                        }
                    }
                }
            }
        }
    }
}


void KazananPuanlariYazdir(int kazananPuanlar[5], int oyuncuSayisi) //Oyun sonu puanlar�n� yazd�r
{
    for (int i = 0; i < oyuncuSayisi; i++) //Oyuncu say�s� kere d�nen for dong�s�.
    {
        cout << setw(4) << kazananPuanlar[i] << endl; //Oyun sonu oyuncular�n puanlar�n� ekrana yazd�r.
    }
}

void TombalaYazdir(int oyuncuKartlari[5][15], int oyuncuSayisi) //Tombala oyunu s�ras�nda oyuncular�n kartlar�n�n son durmunu yazd�r.
{
    for (int i = 0; i < oyuncuSayisi; i++) //Oyuncu say�s� kere d�nen for dong�s�.
    {
        cout << (i) << ". Oyuncunun Tombala Karti: ";
        for (int j = 0; j < 15; j++) //Her oyuncunun kart�nda 15 hane olacag� i�in 15 kere d�nen bir for d�ng�s�.
        {
            cout << setw(4) << oyuncuKartlari[i][j]; //Oyuncular�n kartlar�n�n son durumunu ekrana yazd�r.
        }
        cout << endl;
    }
    cout << endl;
}

void KazananYaz(int kazananPuanlar[5], int oyuncuSayisi) //Oyunu kazanan ki�inin ka��nc� oyuncu oldu�unu yazd�r.
{
    int enYuksekPuan = kazananPuanlar[0]; //1. oyuncunun puan�n�n en y�ksek puan olarak de�i�kene ata.
    int enYuksekPuanKazananOyuncu = 0; //En y�ksek puan� kazanan oyunuya 0 ata.
    bool berabere = false; //Berabere kalma durumu i�in bir de�i�ken atan�r ve bu de�i�kene ba�lang�� i�in false de�eri atan�r.
    for (int i = 1; i < oyuncuSayisi; i++) //Oyuncu say�s� kere d�nen for d�ng�s�.
    {
        if (enYuksekPuan < kazananPuanlar[i]) //En y�ksek puan kazanan puanlar�n i. indisinden k���kse �al��acak if bloku.
        {
            berabere = false; //Bu if bloku i�erisinde berabere de�i�kenini durumu false olarak devam ettirilir.
            enYuksekPuan = kazananPuanlar[i]; //enYuksekPuan de�i�kenine kazananPuanlar dizisinin i. de�eri yani i. oyuncunun puan� atan�r.
            enYuksekPuanKazananOyuncu = i; //enYuksekPuanKazananOyuncu de�i�kenine i. ki�i atan�r.
        }
        else if (enYuksekPuan == kazananPuanlar[i]) //En y�ksek puan kazanan puanlar�n i. indisinde e�itse �al��acak if bloku.
        {
            berabere = true; //Bu if bloku i�erisinde berabere de�i�kenini durumu true olarak de�i�tirilir..
        }
    }
    if (berabere) //Berabere de�i�keni true ise �al��acak if bloku.
    {
        cout << "Oyun Berabere bitmistir." << endl;
    }
    else
    {
        cout << "En yuksek puan kazanan " << enYuksekPuanKazananOyuncu << " numarali oyuncu oldu." << endl;
    }

}
