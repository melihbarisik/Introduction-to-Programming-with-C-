/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 3
**				ÖÐRENCÝ ADI...............: MELÝH ENSAR BARIÞIK
**				ÖÐRENCÝ NUMARASI.:
**				DERS GRUBU…………: D
****************************************************************************/



#include<iostream>
#include<string.h>
#include<locale.h> 
using namespace std;

struct islem {

	int giris[5][5] = { {3,2,5,1,4},{6,2,1,0,7},{3,0,0,2,0},{1,1,3,2,2},{0,3,1,0,0} };

	int cekirdek_boyutu;
	int cekirdek[7][7];
	int sonuc[100][100];
	int kayma_miktari;


};

int sonuchesaplama(int girissatir, int cekirdek_boyutu, int kayma_miktari); // verilen formüle göre cekirdek matrisin satýr sutun sayýsýný bulur.

int main() {


	islem islem;

	int r = sizeof(islem.giris) / sizeof(islem.giris[0]); // giriþ matrisinin boyutunu hesaplar.



	int girissatir = r;
	int girissutun = r;


	cout << "cekirdek boyutunu giriniz : "; cin >> islem.cekirdek_boyutu; cout << endl;
	cout << "kayma miktarini giriniz : "; cin >> islem.kayma_miktari; cout << endl;

	// Koþul Bölümü 

	int kosul = (girissatir - islem.cekirdek_boyutu);  // iþlemin yapýlabilmesi / yapýlamamasý için formüller .
	int kosul1 = (girissatir + islem.cekirdek_boyutu);


	if (kosul % islem.kayma_miktari != 0 || kosul1 % islem.kayma_miktari == 2 || girissatir < islem.cekirdek_boyutu) { // girilen deðerler ve formullere göre iþlemin yapýlabilir / yapýlamaz olduðunu söylüyor.
		cout << "islem yapilamaz .";
		system("pause");

	}
	else {

		for (int cekirdeksatir = 0; cekirdeksatir < islem.cekirdek_boyutu; cekirdeksatir++) {      // çýktýda bulunan cekirdek[][] görselini bastýrýyor.
			for (int cekirdeksutun = 0; cekirdeksutun < islem.cekirdek_boyutu; cekirdeksutun++) {

				cout << "cekirdek" << "[" << cekirdeksatir << "][" << cekirdeksutun << "]" << " = ";
				cin >> islem.cekirdek[cekirdeksatir][cekirdeksutun]; cout << endl;
			}
		}




		int sonucsatir = sonuchesaplama(girissatir, islem.cekirdek_boyutu, islem.kayma_miktari); // alýnan deðerleri sonuchesaplama fonksiyonuna yolluyor
		int sonucsutun = sonucsatir;

		int d1 = 0;
		int d2 = 0;


		// Matrislerin Çarpýp Toplandýðý Kýsým

		for (int a = 0; a < sonucsatir; a++) {       // sonuç matrsinin satýrýný  döndürür.
			for (int b = 0; b < sonucsutun; b++) {   // sonuç matrsinin sutununu döndürür.

				d1 = a;       // giris matrisinin satýrýný sonuc matririsin satýrýna eþitleniyor.
				int toplam = 0;                                       // deðerler karýþmasýn diye toplam deðeri her satýr / sutun deðiþiminde sýfýrlanýyor.
				for (int i = 0; i < islem.cekirdek_boyutu; i++) {     // cekirdek matrisin satýrýný döndürüyor.

					d2 = b;

					for (int j = 0; j < islem.cekirdek_boyutu; j++) {  // cekirdek matrisin sutununu döndürüyor.

						toplam += islem.cekirdek[i][j] * islem.giris[d1][d2];

						d2 += islem.kayma_miktari;         // giris matrisini sutun sayýsýný kayma miktarý kadar arttýrýyor.
					}
					d1 += islem.kayma_miktari;         // giris matrisini satýr sayýsýný kayma miktarý kadar arttýrýyor.
				}
				islem.sonuc[a][b] = toplam;    // oluþan toplamý matrise býrakýyor.

			}
		}
		for (int k = 0; k < sonucsatir; k++) {    // sonuc matrisinin basýldýðý bölüm 
			for (int l = 0; l < sonucsutun; l++) {

				cout << islem.sonuc[k][l] << " ";
			}
			cout << endl;
		}

		system("pause");
		return 0;
	}
}

int sonuchesaplama(int girissatir, int cekirdek_boyutu, int kayma_miktari) { // verilen formüle göre cekirdek matrisin satýr sutun sayýsýný bulur.

	int sonucsatir = ((girissatir - cekirdek_boyutu) / kayma_miktari) + 1;

	return sonucsatir;

}
