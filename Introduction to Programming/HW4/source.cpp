/*******************************************************************
**           SAKARYA ÜNÝVERSÝTESÝ
**    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**       BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**         PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**         ÖDEV NUMARASI.........: 4
**         ÖÐRENCÝ ADI...........: MELÝH ENSAR BARIÞIK
**         ÖÐRENCÝ NUMARASI......: 
**         DERS GRUBU............: D
*********************************************************************/


#include <iostream>
#include <conio.h>
using namespace std;


class Sifre
{
private:

	int alfabeHarfSayisi; 
	int metinHarfSayisi;
	int sifreHarfSayisi;


	char alfabe[26];
	char ikinciAlfabe[26]; 
	char metin[50];
	char sifre[26];

	int sifreTut[26];
	int metinTut[26];
	int sifreliMetin[50];
	int desifreMetin[50];

public:



	void alfabeOlusturVeSay(); // bir alfabe oluþturluyor, oluþturulan alfabenin içindeki harfler sayýlýr.
	void sifreOlusturVeSay(); // sifre oluþturulup oluþturulan sifrenin içindeki harfler sayýlýyor.
	void metinOlusturVeSay(); // metin oluþturuluyor oluþan metnin içindeki harfler sayýlýr.
	


	void sifreyeHarfAta(); // alfabenin harfleri ile eþleþen þifrelerin harflerine alfabe sýra deðeri(i) atanýyor. Ýleride toplama iþlemi yapmak için.
	void metneHarfAta(); // alfabe ile eþleþen metin harfleri bulunup sýra deðeri (i) atanýyor. Ýleride toplama iþlemi yapabilmek için
	

	void sifreliMetniOlustur(); 
	void sifreliMetniYaz();
	
	void desifreMetinOlstur();
	void desifreMetniYaz();




};


void Sifre::alfabeOlusturVeSay()
{
	char ch = 'z';
	cout << "ALFABE \t ";
	int i = 0;
	while (ch != '\r')
	{
		alfabe[i] = ch;
		ch = _getwche();
		i++;
	}
	alfabeHarfSayisi = (i);
	cout << endl;
}
void Sifre::sifreOlusturVeSay()
{
	char ch = 'z';
	cout << "SIFRE \t";
	int i = 0;
	while (ch != '\r')
	{
		sifre[i] = ch;
		ch = _getwche();
		i++;
	}
	sifreHarfSayisi = (i);
	cout << endl; // çalýþýyor.
}
void Sifre::metinOlusturVeSay()
{
	char ch = 'z';
	cout << "METIN \t";
	int i = 0;
	while (ch != '\r')
	{
		metin[i] = ch;
		ch = _getwche();
		i++;
	}
	metinHarfSayisi = (i);
	cout << endl;
}

void Sifre::sifreyeHarfAta()
{
	for (int i = 1; i < alfabeHarfSayisi; i++)
	{
		for (int j = 1; j < sifreHarfSayisi; j++)
		{
			if (sifre[j] == alfabe[i]) // þifrenin her harfi alfabe ile kontrol ediliyor eþitlik var mý diye.
			{
				sifreTut[j] = i;  // eþleþme varsa eþleþen deðerin atamasý yapýlýyor.
			}
		}
	}
}
void Sifre::metneHarfAta()
{
	for (int i = 1; i < alfabeHarfSayisi; i++)
	{
		for (int j = 1; j < metinHarfSayisi; j++)
		{
			if (alfabe[i] == metin[j]) // metnin her harfi alfabe ile kontrol ediliyor.
			{
				metinTut[j] = i; // eþitlik var ise eþleþen deðer atamasý yapýlýyor.

			}
		}
	}

}

void Sifre::sifreliMetniOlustur()
{
	int j = 1;
	for (int i = 1; i < metinHarfSayisi; i++)
	{
		sifreliMetin[i] = metinTut[i] + sifreTut[j]; // atamasý yapýlan metin ve sifre deðerleri toplanýp þifreli bir metin oluþturuluyor.

		j++;
		if (j == sifreHarfSayisi) // þifre metinden kýsa olduðu için sifre sonuna gelince ilk deðerine döndürülüyor.
		{
			j = 1;
		}
	}
}
void Sifre::sifreliMetniYaz()
{
	cout << "SIFRLENMIS METIN \t :";

	for (int i = 1; i < metinHarfSayisi; i++)
	{
		if (sifreliMetin[i] > alfabeHarfSayisi) // sifreli metin alfabe harf sayisindan büyük ise taþma olacaðýndan deðer ayarlanýyor.
		{
			sifreliMetin[i] = sifreliMetin[i] - alfabeHarfSayisi + 1;
			cout << alfabe[sifreliMetin[i]] << "  ";        // bulunan sayýsal deðer alfabe nin içnie yazýlýp harf karþýlýðý alýnýyor.
		}
		else
		{
			cout << alfabe[sifreliMetin[i]] << "  "; // bulunan sayýsal deðer alfabe nin içnie yazýlýp harf karþýlýðý alýnýyor.
		}
	}
	cout << endl;
}

void Sifre::desifreMetinOlstur()
{
	int j = 1;
	for (int i = 1; i < metinHarfSayisi; i++)
	{
		desifreMetin[i] = sifreliMetin[i] - sifreTut[j]; // sifre olusurken olan aþmalarý düzeltmek için tersine çýkarma iþlemi yapýlýyor
		j++;
		if (j == sifreHarfSayisi)
		{
			j = 1;
		}
	}

}
void Sifre::desifreMetniYaz()
{
	cout << "DESIFRE METIN \t :";

	for (int i = 1; i < metinHarfSayisi; i++)
	{
		if (desifreMetin[i] < 1)
		{
			desifreMetin[i] = desifreMetin[i] + alfabeHarfSayisi - 1;
			cout << alfabe[desifreMetin[i]] << " ";  // desifre metin sayýlarý alfabe nin içine yazýlarak harf karþýlýðý alýnýyor.
		}
		else
		{
			cout << alfabe[desifreMetin[i]] << " "; // desifre metin sayýlarý alfabe nin içine yazýlarak harf karþýlýðý alýnýyor.
		}
	}
	cout << endl;
}







int main()
{
	Sifre d1;

	d1.alfabeOlusturVeSay();
	d1.sifreOlusturVeSay();
	d1.metinOlusturVeSay();

	d1.sifreyeHarfAta();
	d1.metneHarfAta();

	d1.sifreliMetniOlustur();
	d1.sifreliMetniYaz();

	d1.desifreMetinOlstur();
	d1.desifreMetniYaz();





	system("pause");
	return 0;
}
