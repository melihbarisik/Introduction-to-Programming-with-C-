/*******************************************************************
**           SAKARYA �N�VERS�TES�
**    B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**       B�LG�SAYAR M�HEND�SL��� B�L�M�
**         PROGRAMLAMAYA G�R�� DERS�
**
**         �DEV NUMARASI.........: 4
**         ��RENC� ADI...........: MEL�H ENSAR BARI�IK
**         ��RENC� NUMARASI......: 
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



	void alfabeOlusturVeSay(); // bir alfabe olu�turluyor, olu�turulan alfabenin i�indeki harfler say�l�r.
	void sifreOlusturVeSay(); // sifre olu�turulup olu�turulan sifrenin i�indeki harfler say�l�yor.
	void metinOlusturVeSay(); // metin olu�turuluyor olu�an metnin i�indeki harfler say�l�r.
	


	void sifreyeHarfAta(); // alfabenin harfleri ile e�le�en �ifrelerin harflerine alfabe s�ra de�eri(i) atan�yor. �leride toplama i�lemi yapmak i�in.
	void metneHarfAta(); // alfabe ile e�le�en metin harfleri bulunup s�ra de�eri (i) atan�yor. �leride toplama i�lemi yapabilmek i�in
	

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
	cout << endl; // �al���yor.
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
			if (sifre[j] == alfabe[i]) // �ifrenin her harfi alfabe ile kontrol ediliyor e�itlik var m� diye.
			{
				sifreTut[j] = i;  // e�le�me varsa e�le�en de�erin atamas� yap�l�yor.
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
				metinTut[j] = i; // e�itlik var ise e�le�en de�er atamas� yap�l�yor.

			}
		}
	}

}

void Sifre::sifreliMetniOlustur()
{
	int j = 1;
	for (int i = 1; i < metinHarfSayisi; i++)
	{
		sifreliMetin[i] = metinTut[i] + sifreTut[j]; // atamas� yap�lan metin ve sifre de�erleri toplan�p �ifreli bir metin olu�turuluyor.

		j++;
		if (j == sifreHarfSayisi) // �ifre metinden k�sa oldu�u i�in sifre sonuna gelince ilk de�erine d�nd�r�l�yor.
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
		if (sifreliMetin[i] > alfabeHarfSayisi) // sifreli metin alfabe harf sayisindan b�y�k ise ta�ma olaca��ndan de�er ayarlan�yor.
		{
			sifreliMetin[i] = sifreliMetin[i] - alfabeHarfSayisi + 1;
			cout << alfabe[sifreliMetin[i]] << "  ";        // bulunan say�sal de�er alfabe nin i�nie yaz�l�p harf kar��l��� al�n�yor.
		}
		else
		{
			cout << alfabe[sifreliMetin[i]] << "  "; // bulunan say�sal de�er alfabe nin i�nie yaz�l�p harf kar��l��� al�n�yor.
		}
	}
	cout << endl;
}

void Sifre::desifreMetinOlstur()
{
	int j = 1;
	for (int i = 1; i < metinHarfSayisi; i++)
	{
		desifreMetin[i] = sifreliMetin[i] - sifreTut[j]; // sifre olusurken olan a�malar� d�zeltmek i�in tersine ��karma i�lemi yap�l�yor
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
			cout << alfabe[desifreMetin[i]] << " ";  // desifre metin say�lar� alfabe nin i�ine yaz�larak harf kar��l��� al�n�yor.
		}
		else
		{
			cout << alfabe[desifreMetin[i]] << " "; // desifre metin say�lar� alfabe nin i�ine yaz�larak harf kar��l��� al�n�yor.
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
