/**************************************************
**                 SAKARYA �N�VERS�TES�
**      B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**           B�LG�SAYAR M�HEND�SL��� B�L�M�
**             PROGRAMLAMAYA G�R�� DERS�
**
**            �DEV NUMARASI : 2
**            ��RENC� ADI : MEL�H ENSAR BARI�IK
**            ��RENC� NUMARASI :
**            DERS GRUBU : D
***************************************************/



#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	setlocale(LC_ALL, "Turkish");
	int a = 0, e = 0, � = 0, i = 0, o = 0, �=0, u = 0, �=0 ;
	char ch = 'm';
	cout << "bir cumle giriniz:" << endl;
	// enter tu�unua bas�lana kadar d�ng� d�n�yor.
	while (ch != '\r') {
		ch = _getche();
		
		// e�er a yada A girilir ise int a 1 artt�r�lacak.
		if (ch == 'a' || ch == 'A')
			a++;
		
		//e�er e yada E girilir ise int e 1 artt�r�lacak
		else if (ch == 'e' || ch == 'E')
			e++;

		//e�er � yada I girilir ise int � 1 artt�r�lacak
		else if (ch == -115 || ch == 'I')
			�++;

		//e�er i yada � girilir ise int i 1 artt�r�lacak
		else if (ch == 'i' || ch == -104)
			i++;

		//e�er o yada O girilir ise int o 1 artt�r�lacak
		else if (ch == 'o' || ch == 'O')
			o++;

		//e�er � yada � girilir ise int � 1 artt�r�lacak
		else if (ch == -108 || ch == -103)
			�++;

	    //e�er u yada U girilir ise int u 1 artt�r�lacak
		else if (ch == 'u' || ch == 'U')
			u++;

		//e�er � yada � girilir ise int � 1 artt�r�lacak
		else if (ch == -127 || ch == -102)
			�++;
	}
		cout << "H";  
		cout << "a harfi say�s� :" << a << endl;
		cout << "e harfi say�s� :" << e << endl;
		cout << "� harfi say�s� :" << � << endl;
		cout << "i harfi say�s� :" << i << endl;
		cout << "o harfi say�s� :" << o << endl;
		cout << "� harfi say�s� :" << � << endl;
		cout << "u harfi say�s� :" << u << endl;
		cout << "� harfi say�s� :" << � << endl;

		// int dizi[]={a=0,e=0,�=0,}






















	system("pause");
	return 0;
}
