/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 2. ÖDEV
**				ÖÐRENCÝ ADI...............:MELÝH ENSAR BARIÞIK
**				ÖÐRENCÝ NUMARASI.:
**				DERS GRUBU…………:D GRUBU
****************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int karsilastirma(int random, int harf[5][10]) { // Gelen harf matrisini random deðer ile karþýlaþtýrýp tekrar olup olmadýðýna bakýyor.
	for (int c = 0; c < 5; c++)
	{
		for (int d = 0; d < 10; d++)    // 2 for ile bir harf[c][d] matrisi oluþturuluyor.
		{
			if (random == harf[c][d])  // random deðer ile oluþan matrisi karþýlaþtýrýp tekrarý kontrol ediyor.
			{
				return 0;   //tekrar eden sayý var.
			}
		}
	}
	return 1;  //tekrar eden sayý yok.
}

void siralama(int harf[5][10]) {    // Gelen harf matrisini sýralama iþlemini yapýyor.
	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)    // harf[a][b] matrisini döndürüyor.
		{
			harf[a][b];                // harf matirsi dönerken deðerli bir bir tutuyor.
			for (int c = 0; c < 5; c++)
			{
				for (int d = 0; d < 10; d++)
				{
					if (harf[a][b] < harf[c][d])  // tutulan deðeri kalan deðerlerle karþýlaþtýrýp küçük deðer varsa kaydýrma iþlemi yapýyor.
					{
						int gecici = harf[a][b];  // kabarcýk sýralama gibi bir yöntemle deðer kaybý olmadan kaydýrma yapýlýyor.
						harf[a][b] = harf[c][d];
						harf[c][d] = gecici;
					}
				}
			}
		}
	}



}


int main() {
	srand(time(NULL));
	int harf[5][10];
	int random;

	for (int i = 0; i < 5; i++)      // harf[i][j] matrisini oluþturuyor.
	{
		for (int j = 0; j < 10;)
		{
			if (j % 2 == 0)          // oluþan matrisin sütun sayýsý 2 nin katý ise deðerleri büyük yazmak için ayýrýyor.
			{
				random = rand() % 25 + 65;     // Random içine atanan sayý deðerleri ASCII tablosunda a dan z ye kadar olan deðerleri temsil ediyor.
				harf[i][j] = karsilastirma(random, harf); // harf[i][j] deðerlenin tekrar etmemesi için karsilastirma matrisine yolluyor.
				if (harf[i][j] == 1)
				{
					harf[i][j] = random;    // return 1 saðlanýr ise harf[i][j] matrisi random deðere eþleniyor.
					j++;
				}

			}
			else
			{
				random = rand() % 25 + 97;  // Random içine atanan deðerler ASCII tablosundaki A dan Z ye kadar olan deðerleri temsil ediyor.
				harf[i][j] = karsilastirma(random, harf);  // harf[i][j] deðerlenin tekrar etmemesi için karsilastirma matrisine yolluyor.
				if (harf[i][j] == 1)
				{
					harf[i][j] = random;      // return 1 saðlanýr ise harf[i][j] matrisi random deðere eþleniyor.
					j++;
				}
			}
		}
	}

	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)    // Ýçinde tekrar eden deðer olmayan harf matrisini basan kýsým.
		{
			cout << char(harf[a][b]) << "   ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	
	// Sýrlama Kýsmý
	
	siralama(harf);  // Yukarýda oluþturulan tekrarsýz matrisi sýralamak için fonksiyona gönderiyor.
	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			cout << char(harf[a][b]) << "   ";  // Oluþan sýralý tekrarsýz matrisindeki sayý deðerlerini char komutu ile ASCII tablosunaki harflere çeviriyor.
		}
		cout << endl;
	}


	system("pause");
	return 0;
}