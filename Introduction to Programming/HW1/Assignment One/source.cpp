/**************************************************
**                 SAKARYA ÜNÝVERSÝTESÝ
**      BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**           BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**             PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**            ÖDEV NUMARASI : 1
**            ÖÐRENCÝ ADI : MELÝH ENSAR BARIÞIK
**            ÖÐRENCÝ NUMARASI :
**            DERS GRUBU : D
***************************************************/
#include <iostream>
using namespace std;

int main()
{    // bu kýsým içerideki bütün forlarý satýr sayýsý kadar döndürmek için.
	for (int i = 0; i <= 5; i++) {   
		
        // þekli 4 e bölersek bu kýsýmdaki for sol üst köþedeki üçgenleri basýyor
		for (int ucgen1 = i; ucgen1 <= 5; ucgen1++) {
			cout << "*";
		}

		// þekli 4 bölersek bu kýsým ilk üçgenden sonra býrakýlmasý gereken boþluðu basýyor
		for (int bosluk = 5 - i; bosluk <= 5; bosluk++) {
			cout << "  ";
		}

        // sað üst kýsým da kalan üçgeni basýyor
		for (int ucgen2 = i; ucgen2 <= 5; ucgen2++) {
			cout << "*";
		}
		cout << endl;
		
		 }// Alt kýsým
	cout << endl;
	
	 //içerideki tüm forlarý satýr sayýsý kadar döndürmek için
	for (int i = 0; i <= 5; i++) { 
		 
		//sol alt kýsým da bulunan üçgeni basýyor
		for (int ucgen3 = 5 - i; ucgen3 <= 5; ucgen3++) {
			cout << "*";
		}
		
		// üçgenden sonra býraklýn üçgen þeklindeki boþluðu basýyor
		for (int bosluk3 = i; bosluk3 <= 5; bosluk3++) {
			cout << "  ";
		}
		
		// son sað alt köþede kalan üçgeni basýyor
		for (int ucgen4 = 5 - i; ucgen4 <= 5; ucgen4++) {
			cout << "*";
		}
		cout << endl;
	}


		system("pause");
		return 0;
	
}