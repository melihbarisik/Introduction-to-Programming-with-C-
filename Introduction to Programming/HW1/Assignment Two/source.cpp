/**************************************************
**                 SAKARYA ÜNÝVERSÝTESÝ
**      BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**           BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**             PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**            ÖDEV NUMARASI : 2
**            ÖÐRENCÝ ADI : MELÝH ENSAR BARIÞIK
**            ÖÐRENCÝ NUMARASI :
**            DERS GRUBU : D
***************************************************/



#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	setlocale(LC_ALL, "Turkish");
	int a = 0, e = 0, ý = 0, i = 0, o = 0, ö=0, u = 0, ü=0 ;
	char ch = 'm';
	cout << "bir cumle giriniz:" << endl;
	// enter tuþunua basýlana kadar döngü dönüyor.
	while (ch != '\r') {
		ch = _getche();
		
		// eðer a yada A girilir ise int a 1 arttýrýlacak.
		if (ch == 'a' || ch == 'A')
			a++;
		
		//eðer e yada E girilir ise int e 1 arttýrýlacak
		else if (ch == 'e' || ch == 'E')
			e++;

		//eðer ý yada I girilir ise int ý 1 arttýrýlacak
		else if (ch == -115 || ch == 'I')
			ý++;

		//eðer i yada Ý girilir ise int i 1 arttýrýlacak
		else if (ch == 'i' || ch == -104)
			i++;

		//eðer o yada O girilir ise int o 1 arttýrýlacak
		else if (ch == 'o' || ch == 'O')
			o++;

		//eðer ö yada Ö girilir ise int ö 1 arttýrýlacak
		else if (ch == -108 || ch == -103)
			ö++;

	    //eðer u yada U girilir ise int u 1 arttýrýlacak
		else if (ch == 'u' || ch == 'U')
			u++;

		//eðer ü yada Ü girilir ise int ü 1 arttýrýlacak
		else if (ch == -127 || ch == -102)
			ü++;
	}
		cout << "H";  
		cout << "a harfi sayýsý :" << a << endl;
		cout << "e harfi sayýsý :" << e << endl;
		cout << "ý harfi sayýsý :" << ý << endl;
		cout << "i harfi sayýsý :" << i << endl;
		cout << "o harfi sayýsý :" << o << endl;
		cout << "ö harfi sayýsý :" << ö << endl;
		cout << "u harfi sayýsý :" << u << endl;
		cout << "ü harfi sayýsý :" << ü << endl;

		// int dizi[]={a=0,e=0,ý=0,}






















	system("pause");
	return 0;
}
