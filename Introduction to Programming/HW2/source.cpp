/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 2. �DEV
**				��RENC� ADI...............:MEL�H ENSAR BARI�IK
**				��RENC� NUMARASI.:
**				DERS GRUBU����:D GRUBU
****************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int karsilastirma(int random, int harf[5][10]) { // Gelen harf matrisini random de�er ile kar��la�t�r�p tekrar olup olmad���na bak�yor.
	for (int c = 0; c < 5; c++)
	{
		for (int d = 0; d < 10; d++)    // 2 for ile bir harf[c][d] matrisi olu�turuluyor.
		{
			if (random == harf[c][d])  // random de�er ile olu�an matrisi kar��la�t�r�p tekrar� kontrol ediyor.
			{
				return 0;   //tekrar eden say� var.
			}
		}
	}
	return 1;  //tekrar eden say� yok.
}

void siralama(int harf[5][10]) {    // Gelen harf matrisini s�ralama i�lemini yap�yor.
	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)    // harf[a][b] matrisini d�nd�r�yor.
		{
			harf[a][b];                // harf matirsi d�nerken de�erli bir bir tutuyor.
			for (int c = 0; c < 5; c++)
			{
				for (int d = 0; d < 10; d++)
				{
					if (harf[a][b] < harf[c][d])  // tutulan de�eri kalan de�erlerle kar��la�t�r�p k���k de�er varsa kayd�rma i�lemi yap�yor.
					{
						int gecici = harf[a][b];  // kabarc�k s�ralama gibi bir y�ntemle de�er kayb� olmadan kayd�rma yap�l�yor.
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

	for (int i = 0; i < 5; i++)      // harf[i][j] matrisini olu�turuyor.
	{
		for (int j = 0; j < 10;)
		{
			if (j % 2 == 0)          // olu�an matrisin s�tun say�s� 2 nin kat� ise de�erleri b�y�k yazmak i�in ay�r�yor.
			{
				random = rand() % 25 + 65;     // Random i�ine atanan say� de�erleri ASCII tablosunda a dan z ye kadar olan de�erleri temsil ediyor.
				harf[i][j] = karsilastirma(random, harf); // harf[i][j] de�erlenin tekrar etmemesi i�in karsilastirma matrisine yolluyor.
				if (harf[i][j] == 1)
				{
					harf[i][j] = random;    // return 1 sa�lan�r ise harf[i][j] matrisi random de�ere e�leniyor.
					j++;
				}

			}
			else
			{
				random = rand() % 25 + 97;  // Random i�ine atanan de�erler ASCII tablosundaki A dan Z ye kadar olan de�erleri temsil ediyor.
				harf[i][j] = karsilastirma(random, harf);  // harf[i][j] de�erlenin tekrar etmemesi i�in karsilastirma matrisine yolluyor.
				if (harf[i][j] == 1)
				{
					harf[i][j] = random;      // return 1 sa�lan�r ise harf[i][j] matrisi random de�ere e�leniyor.
					j++;
				}
			}
		}
	}

	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)    // ��inde tekrar eden de�er olmayan harf matrisini basan k�s�m.
		{
			cout << char(harf[a][b]) << "   ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	
	// S�rlama K�sm�
	
	siralama(harf);  // Yukar�da olu�turulan tekrars�z matrisi s�ralamak i�in fonksiyona g�nderiyor.
	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			cout << char(harf[a][b]) << "   ";  // Olu�an s�ral� tekrars�z matrisindeki say� de�erlerini char komutu ile ASCII tablosunaki harflere �eviriyor.
		}
		cout << endl;
	}


	system("pause");
	return 0;
}