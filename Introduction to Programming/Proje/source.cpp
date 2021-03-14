/*******************************************************************
**           SAKARYA ÜNÝVERSÝTESÝ
**    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**       BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**         PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**         ÖDEV NUMARASI.........: PROJE
**         ÖÐRENCÝ ADI...........: MELÝH ENSAR BARIÞIK
**         ÖÐRENCÝ NUMARASI......: 
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
	YON_MERMÝ = 6,
	YON_MERMÝ1 = 7,
	YON_MERMÝ2 = 8,
	YON_MERMÝ3 = 9
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

	int random = (rand() % 13) + 2; // düþmanýn hep ayný yerde çýkmamasý için her seferinde farklý deðer basýyor.

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
void dusmanýSahneyeCiz()
{


	for (int i = 0; i < dusmanSayaci; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			if (dusman[i].x[j] > 1) // düþman vurulmadan sahneyi aþar ise hata olmamasý için düþmaný yazmýyor.
			{
				int x = dusman[i].x[j];
				int y = dusman[i].y[j];

				sahne[x][y] = dusmanKarakteri;
			}
		}
	}

}
void dusmanýHareketEttir()
{
	for (int i = 0; i < dusmanSayaci; i++) // her bir dönüþte düþmaný bir sola kaydýrýp yazdýrýyor.
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
	for (int y = 0; y < yukseklik; y++) // sahnenin yüksekliðini ayarlýyor.
	{
		for (int x = 0; x < genislik; x++) // sahnenin genislðini ayarlýyor
		{
			cout << sahne[x][y];
		}
		cout << endl;
	}
}
void sinirlariOlustur()
{


	for (int x = 0; x < genislik; x++) // sahne etrafýna görsel sýnýr olusturuyor. Genislik için.
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}
	for (int y = 0; y < yukseklik; y++) // sahne etrafýna görsel sýnýr olusturuyor. Yukseklik için.
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
			sahne[x][y] = ' '; // tüm dongüler tamamlanýnca yeni ekran gelmeden sahneyi temizliyor.
		}

	}
}

void ucakOlustur()
{  // ucagýn parçalarýný olusturuyor.
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
	for (int i = 0; i < ucakBirimSayisi; i++) // ucagý sahnedeki yerine yazýyor.
	{
		int x = ucak[i].x;
		int y = ucak[i].y;

		sahne[x][y] = ucak[i].karakter;
	}
	for (int i = 0; i < ucakBirimSayisi; i++) //ucagýn üst sýnýrý aþmasýný engelliyor.
	{
		if (ucak[0 + i].y == 0 + i)
		{
			ucak[0 + i].y = i + 1;
		}
	}
	for (int i = 0; i < ucakBirimSayisi; i++) // ucagýn alt sýnýrý aþmasýný engelliyor.
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
		switch (ucak->yon)  // basýlan tuþlara atanan yöne göre uçaðý aþaðý-yukarý haraket ettiriyor.
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


	mermi[mermiSayisi].x = xkonum; // mermi uçaðýn orta parçasýna gelicek þekilde ayarlanýyor.
	mermi[mermiSayisi].y = ykonum;
	mermi->karakter = 219;
	mermiSayaci++;

}
void mermiyiSahneyeYerlestir()
{
	for (int i = 0; i < maxMermiSayisi; i++)
	{
		if (mermi[i].x < 80)  // mermi sahneyi aþýp dýþarý çýkarsa hata çýkmamasý için mermiyi yazdýrmýyor.
		{
			int x = mermi[i].x;
			int y = mermi[i].y;

			sahne[x][y] = mermi->karakter;
		}
	}
}
void mermiyiHarekterEttir()
{
	for (int i = 0; i < mermiSayisi; i++) // mermiyi sahneye basýyor.
	{
		if (mermi[i].x == genislik) 
		{

		}
		else
		{
			mermi[i].x++; // mermi sahneyi aþmamýþ ise x ini arttýrýp mermiyi saað doðru haraket ettiriyor.
		}
	}
}

void klavyeKontrol()
{
	klavyeOku(tuslar); // klavyeden tuþlara deðer atamasý yapýyor.
	if (tuslar['W'] != 0) // w ye basýlmýs ise yon yukarý.
	{
		mermi->yon = YON_YUKARI;
		ucak[0].yon = YON_YUKARI;

	}
	if (tuslar['S'] != 0) // s ye basýlmýs ise yön asagý.
	{
		mermi->yon = YON_ASAGI;
		ucak[0].yon = YON_ASAGI;

	}
	if (tuslar['W'] == 0 && tuslar['S'] == 0) // tuþa basýlmamýs ise yon yok sabit duruyor.
	{
		ucak[0].yon = YON_YOK;
		mermi->yon = YON_YOK;

	}

	if (tuslar[' '] != 0) // bosluk tusuna basýlmýs ise mermi olusturuyor.
	{

		int xkonum = ucak[2].x;
		int ykonum = ucak[2].y;
		mermiOlustur(xkonum, ykonum);
		mermiSayisi++;          // olusan mermi atýldýðý için yerni mermi hazýrlýyor.
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
				if (mermi[k].x == dusman[j].x[i] && mermi[k].y == dusman[j].y[i]) // dusman ve merminin x - y deðerli ayni ise çarpýþma var demektir.
				{
					for (int i = 0; i < 9; i++) // çarpýsma var ise düsmaný alanýn dýþýna gönderiyor. üst fonksiyonlarda alan dýþýnda düþman yazýlmadýðý için düþman silinmiþ oluyor.
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


		dusmanýSahneyeCiz();
		dusmanýHareketEttir();



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