/**************************************************
**                 SAKARYA �N�VERS�TES�
**      B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**           B�LG�SAYAR M�HEND�SL��� B�L�M�
**             PROGRAMLAMAYA G�R�� DERS�
**
**            �DEV NUMARASI : 1
**            ��RENC� ADI : MEL�H ENSAR BARI�IK
**            ��RENC� NUMARASI :
**            DERS GRUBU : D
***************************************************/
#include <iostream>
using namespace std;

int main()
{    // bu k�s�m i�erideki b�t�n forlar� sat�r say�s� kadar d�nd�rmek i�in.
	for (int i = 0; i <= 5; i++) {   
		
        // �ekli 4 e b�lersek bu k�s�mdaki for sol �st k��edeki ��genleri bas�yor
		for (int ucgen1 = i; ucgen1 <= 5; ucgen1++) {
			cout << "*";
		}

		// �ekli 4 b�lersek bu k�s�m ilk ��genden sonra b�rak�lmas� gereken bo�lu�u bas�yor
		for (int bosluk = 5 - i; bosluk <= 5; bosluk++) {
			cout << "  ";
		}

        // sa� �st k�s�m da kalan ��geni bas�yor
		for (int ucgen2 = i; ucgen2 <= 5; ucgen2++) {
			cout << "*";
		}
		cout << endl;
		
		 }// Alt k�s�m
	cout << endl;
	
	 //i�erideki t�m forlar� sat�r say�s� kadar d�nd�rmek i�in
	for (int i = 0; i <= 5; i++) { 
		 
		//sol alt k�s�m da bulunan ��geni bas�yor
		for (int ucgen3 = 5 - i; ucgen3 <= 5; ucgen3++) {
			cout << "*";
		}
		
		// ��genden sonra b�rakl�n ��gen �eklindeki bo�lu�u bas�yor
		for (int bosluk3 = i; bosluk3 <= 5; bosluk3++) {
			cout << "  ";
		}
		
		// son sa� alt k��ede kalan ��geni bas�yor
		for (int ucgen4 = 5 - i; ucgen4 <= 5; ucgen4++) {
			cout << "*";
		}
		cout << endl;
	}


		system("pause");
		return 0;
	
}