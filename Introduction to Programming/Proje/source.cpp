/*******************************************************************
**           SAKARYA �N�VERS�TES�
**    B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**       B�LG�SAYAR M�HEND�SL��� B�L�M�
**         PROGRAMLAMAYA G�R�� DERS�
**
**         �DEV NUMARASI.........: PROJE
**         ��RENC� ADI...........: MEL�H ENSAR BARI�IK
**         ��RENC� NUMARASI......: 
**         DERS GRUBU............: D
*********************************************************************/

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
using namespace std;


enum YON
{
	YON_SOL = 1,
	YON_SAG = 2,
	YON_ASAGI = 3,
	YON_YUKARI = 4,
	YON_YOK = 5,
	YON_MERM� = 6,
	YON_MERM�1 = 7,
	YON_MERM�2 = 8,
	YON_MERM�3 = 9
};
struct mermiHucre
{
	int x;
	int y;
	YON yon;
	char karakter;
};
struct ucakHucre
{
	int x;
	int y;
	YON yon;
	char karakter;

};
struct dusmanHucre
{
	int x[9];
	int y[9];
	YON yon;
	char karakter[9];
};

const int genislik = 80;

const int yukseklik = 20;

char tuslar[256];

int mermiSayisi = 0;

char sahne[genislik][yukseklik];

const int ucakBirimSayisi = 5;

const int maxMermiSayisi = 200;

const int dusmanSayisi = 10;

int dusmanSayaci = 0;

int mermiSayaci = 0;

int dusmanGelmeSayaci = 0;

char dusmanKarakteri = 176;

mermiHucre mermi[200];
ucakHucre ucak[ucakBirimSayisi];
dusmanHucre dusman[dusmanSayisi];

void dusmanOlustur()
{

	int random = (rand() % 13) + 2; // d��man�n hep ayn� yerde ��kmamas� i�in her seferinde farkl� de�er bas�yor.

	int xsiniri;
	int ysiniri;

	xsiniri = 70;
	ysiniri = random;

	dusman[dusmanSayaci].x[0] = xsiniri;
	dusman[dusmanSayaci].y[0] = ysiniri;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[1] = xsiniri + 1;
	dusman[dusmanSayaci].y[1] = ysiniri;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[2] = xsiniri + 2;
	dusman[dusmanSayaci].y[2] = ysiniri;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[3] = xsiniri;
	dusman[dusmanSayaci].y[3] = ysiniri + 1;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[4] = xsiniri + 1;
	dusman[dusmanSayaci].y[4] = ysiniri + 1;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[5] = xsiniri + 2;
	dusman[dusmanSayaci].y[5] = ysiniri + 1;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[6] = xsiniri;
	dusman[dusmanSayaci].y[6] = ysiniri + 2;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[7] = xsiniri + 1;
	dusman[dusmanSayaci].y[7] = ysiniri + 2;
	dusman[dusmanSayaci].yon = YON_SOL;

	dusman[dusmanSayaci].x[8] = xsiniri + 2;
	dusman[dusmanSayaci].y[8] = ysiniri + 2;
	dusman[dusmanSayaci].yon = YON_SOL;
	dusmanSayaci++;

}
void dusman�SahneyeCiz()
{


	for (int i = 0; i < dusmanSayaci; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			if (dusman[i].x[j] > 1) // d��man vurulmadan sahneyi a�ar ise hata olmamas� i�in d��man� yazm�yor.
			{
				int x = dusman[i].x[j];
				int y = dusman[i].y[j];

				sahne[x][y] = dusmanKarakteri;
			}
		}
	}

}
void dusman�HareketEttir()
{
	for (int i = 0; i < dusmanSayaci; i++) // her bir d�n��te d��man� bir sola kayd�r�p yazd�r�yor.
	{
		for (int j = 0; j < 9; j++)
		{
			dusman[i].x[j]--;

		}
	}
}


void klavyeOku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
	{
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}
void kursoruGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO  cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void sahneyiCiz()
{
	for (int y = 0; y < yukseklik; y++) // sahnenin y�ksekli�ini ayarl�yor.
	{
		for (int x = 0; x < genislik; x++) // sahnenin genisl�ini ayarl�yor
		{
			cout << sahne[x][y];
		}
		cout << endl;
	}
}
void sinirlariOlustur()
{


	for (int x = 0; x < genislik; x++) // sahne etraf�na g�rsel s�n�r olusturuyor. Genislik i�in.
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}
	for (int y = 0; y < yukseklik; y++) // sahne etraf�na g�rsel s�n�r olusturuyor. Yukseklik i�in.
	{
		sahne[0][y] = 219;
		sahne[genislik - 1][y] = 219;
	}


}
void sahneTemizle()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			sahne[x][y] = ' '; // t�m dong�ler tamamlan�nca yeni ekran gelmeden sahneyi temizliyor.
		}

	}
}

void ucakOlustur()
{  // ucag�n par�alar�n� olusturuyor.
	ucak[0].x = 1;
	ucak[0].y = 10;
	ucak[0].karakter = 219;

	ucak[1].x = 2;
	ucak[1].y = 11;
	ucak[1].karakter = 219;

	ucak[2].x = 3;
	ucak[2].y = 12;
	ucak[2].karakter = 219;

	ucak[3].x = 2;
	ucak[3].y = 13;
	ucak[3].karakter = 219;

	ucak[4].x = 1;
	ucak[4].y = 14;
	ucak[4].karakter = 219;




}
void ucagiSahneyeYerlestir()
{
	for (int i = 0; i < ucakBirimSayisi; i++) // ucag� sahnedeki yerine yaz�yor.
	{
		int x = ucak[i].x;
		int y = ucak[i].y;

		sahne[x][y] = ucak[i].karakter;
	}
	for (int i = 0; i < ucakBirimSayisi; i++) //ucag�n �st s�n�r� a�mas�n� engelliyor.
	{
		if (ucak[0 + i].y == 0 + i)
		{
			ucak[0 + i].y = i + 1;
		}
	}
	for (int i = 0; i < ucakBirimSayisi; i++) // ucag�n alt s�n�r� a�mas�n� engelliyor.
	{
		if (ucak[4 - i].y == 19 - i)
		{
			ucak[4 - i].y = 18 - i;
		}
	}
}
void ucagiHaraketEttir()
{
	for (int i = 0; i < ucakBirimSayisi; i++)
	{
		switch (ucak->yon)  // bas�lan tu�lara atanan y�ne g�re u�a�� a�a��-yukar� haraket ettiriyor.
		{
		case YON_YUKARI:
			ucak[i].y--;
			break;
		case YON_ASAGI:
			ucak[i].y++;
			break;
		}
	}

}

void mermiOlustur(int xkonum, int ykonum)
{


	mermi[mermiSayisi].x = xkonum; // mermi u�a��n orta par�as�na gelicek �ekilde ayarlan�yor.
	mermi[mermiSayisi].y = ykonum;
	mermi->karakter = 219;
	mermiSayaci++;

}
void mermiyiSahneyeYerlestir()
{
	for (int i = 0; i < maxMermiSayisi; i++)
	{
		if (mermi[i].x < 80)  // mermi sahneyi a��p d��ar� ��karsa hata ��kmamas� i�in mermiyi yazd�rm�yor.
		{
			int x = mermi[i].x;
			int y = mermi[i].y;

			sahne[x][y] = mermi->karakter;
		}
	}
}
void mermiyiHarekterEttir()
{
	for (int i = 0; i < mermiSayisi; i++) // mermiyi sahneye bas�yor.
	{
		if (mermi[i].x == genislik) 
		{

		}
		else
		{
			mermi[i].x++; // mermi sahneyi a�mam�� ise x ini artt�r�p mermiyi saa� do�ru haraket ettiriyor.
		}
	}
}

void klavyeKontrol()
{
	klavyeOku(tuslar); // klavyeden tu�lara de�er atamas� yap�yor.
	if (tuslar['W'] != 0) // w ye bas�lm�s ise yon yukar�.
	{
		mermi->yon = YON_YUKARI;
		ucak[0].yon = YON_YUKARI;

	}
	if (tuslar['S'] != 0) // s ye bas�lm�s ise y�n asag�.
	{
		mermi->yon = YON_ASAGI;
		ucak[0].yon = YON_ASAGI;

	}
	if (tuslar['W'] == 0 && tuslar['S'] == 0) // tu�a bas�lmam�s ise yon yok sabit duruyor.
	{
		ucak[0].yon = YON_YOK;
		mermi->yon = YON_YOK;

	}

	if (tuslar[' '] != 0) // bosluk tusuna bas�lm�s ise mermi olusturuyor.
	{

		int xkonum = ucak[2].x;
		int ykonum = ucak[2].y;
		mermiOlustur(xkonum, ykonum);
		mermiSayisi++;          // olusan mermi at�ld��� i�in yerni mermi haz�rl�yor.
	}
}
void carpismaKontrol()
{
	for (int j = 0; j < dusmanSayaci; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int k = 0; k < mermiSayaci; k++)
			{
				if (mermi[k].x == dusman[j].x[i] && mermi[k].y == dusman[j].y[i]) // dusman ve merminin x - y de�erli ayni ise �arp��ma var demektir.
				{
					for (int i = 0; i < 9; i++) // �arp�sma var ise d�sman� alan�n d���na g�nderiyor. �st fonksiyonlarda alan d���nda d��man yaz�lmad��� i�in d��man silinmi� oluyor.
					{
						dusman[j].x[i] = 0;
						dusman[j].y[i] = 0;
					}
				}
			}

		}
	}
}



int main()
{
	srand(time(NULL));
	kursoruGizle();
	ucakOlustur();


	while (true)
	{
		sahneTemizle();

		klavyeKontrol();

		carpismaKontrol();

		if (dusmanGelmeSayaci % 20 == 0)
			dusmanOlustur();


		dusman�SahneyeCiz();
		dusman�HareketEttir();



		mermiyiSahneyeYerlestir();
		mermiyiHarekterEttir();

		ucagiSahneyeYerlestir();
		ucagiHaraketEttir();

		sinirlariOlustur();



		gotoxy(0, 0);
		sahneyiCiz();

		dusmanGelmeSayaci++;

	}


	return 0;
}