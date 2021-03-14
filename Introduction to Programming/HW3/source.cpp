/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 3
**				��RENC� ADI...............: MEL�H ENSAR BARI�IK
**				��RENC� NUMARASI.:
**				DERS GRUBU����: D
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

int sonuchesaplama(int girissatir, int cekirdek_boyutu, int kayma_miktari); // verilen form�le g�re cekirdek matrisin sat�r sutun say�s�n� bulur.

int main() {


	islem islem;

	int r = sizeof(islem.giris) / sizeof(islem.giris[0]); // giri� matrisinin boyutunu hesaplar.



	int girissatir = r;
	int girissutun = r;


	cout << "cekirdek boyutunu giriniz : "; cin >> islem.cekirdek_boyutu; cout << endl;
	cout << "kayma miktarini giriniz : "; cin >> islem.kayma_miktari; cout << endl;

	// Ko�ul B�l�m� 

	int kosul = (girissatir - islem.cekirdek_boyutu);  // i�lemin yap�labilmesi / yap�lamamas� i�in form�ller .
	int kosul1 = (girissatir + islem.cekirdek_boyutu);


	if (kosul % islem.kayma_miktari != 0 || kosul1 % islem.kayma_miktari == 2 || girissatir < islem.cekirdek_boyutu) { // girilen de�erler ve formullere g�re i�lemin yap�labilir / yap�lamaz oldu�unu s�yl�yor.
		cout << "islem yapilamaz .";
		system("pause");

	}
	else {

		for (int cekirdeksatir = 0; cekirdeksatir < islem.cekirdek_boyutu; cekirdeksatir++) {      // ��kt�da bulunan cekirdek[][] g�rselini bast�r�yor.
			for (int cekirdeksutun = 0; cekirdeksutun < islem.cekirdek_boyutu; cekirdeksutun++) {

				cout << "cekirdek" << "[" << cekirdeksatir << "][" << cekirdeksutun << "]" << " = ";
				cin >> islem.cekirdek[cekirdeksatir][cekirdeksutun]; cout << endl;
			}
		}




		int sonucsatir = sonuchesaplama(girissatir, islem.cekirdek_boyutu, islem.kayma_miktari); // al�nan de�erleri sonuchesaplama fonksiyonuna yolluyor
		int sonucsutun = sonucsatir;

		int d1 = 0;
		int d2 = 0;


		// Matrislerin �arp�p Topland��� K�s�m

		for (int a = 0; a < sonucsatir; a++) {       // sonu� matrsinin sat�r�n�  d�nd�r�r.
			for (int b = 0; b < sonucsutun; b++) {   // sonu� matrsinin sutununu d�nd�r�r.

				d1 = a;       // giris matrisinin sat�r�n� sonuc matririsin sat�r�na e�itleniyor.
				int toplam = 0;                                       // de�erler kar��mas�n diye toplam de�eri her sat�r / sutun de�i�iminde s�f�rlan�yor.
				for (int i = 0; i < islem.cekirdek_boyutu; i++) {     // cekirdek matrisin sat�r�n� d�nd�r�yor.

					d2 = b;

					for (int j = 0; j < islem.cekirdek_boyutu; j++) {  // cekirdek matrisin sutununu d�nd�r�yor.

						toplam += islem.cekirdek[i][j] * islem.giris[d1][d2];

						d2 += islem.kayma_miktari;         // giris matrisini sutun say�s�n� kayma miktar� kadar artt�r�yor.
					}
					d1 += islem.kayma_miktari;         // giris matrisini sat�r say�s�n� kayma miktar� kadar artt�r�yor.
				}
				islem.sonuc[a][b] = toplam;    // olu�an toplam� matrise b�rak�yor.

			}
		}
		for (int k = 0; k < sonucsatir; k++) {    // sonuc matrisinin bas�ld��� b�l�m 
			for (int l = 0; l < sonucsutun; l++) {

				cout << islem.sonuc[k][l] << " ";
			}
			cout << endl;
		}

		system("pause");
		return 0;
	}
}

int sonuchesaplama(int girissatir, int cekirdek_boyutu, int kayma_miktari) { // verilen form�le g�re cekirdek matrisin sat�r sutun say�s�n� bulur.

	int sonucsatir = ((girissatir - cekirdek_boyutu) / kayma_miktari) + 1;

	return sonucsatir;

}
