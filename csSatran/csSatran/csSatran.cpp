#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Taslar.h"
#include "Piyon.h"
#include "At.h"
#include "Fil.h"
#include "Kale.h"
#include "Vezir.h"
#include "Sah.h"

using namespace std;




int main()
{

	ifstream dosya("board1.txt");

	if (!dosya.is_open()) {
		cerr << "Dosya hatası!" << endl;
		return 1;
	}


	const int matrisBoyutu = 8;
	char tahta[matrisBoyutu][matrisBoyutu][3];


	for (int i = 0; i < matrisBoyutu; i++) {
		string satir;
		getline(dosya, satir);

		istringstream ss(satir);

		for (int j = 0; j < matrisBoyutu; j++) {
			ss >> tahta[i][j];
		}
	}


	for (int a = 0; a < matrisBoyutu; a++) {
		for (int b = 0; b < matrisBoyutu; b++) {
			cout << tahta[a][b] << " ";
		}
		cout << endl;
	}
	dosya.close();

	float beyazPuan = 0.0;
	float siyahPuan = 0.0;
	int sayac = 0;

	for (int k = 0; k < 8; k++) {
		for (int l = 0; l < 8; l++) {
			if (tahta[k][l][0] != '-') {
				Taslar* tas = nullptr;
				char karakter = tahta[k][l][0];
				char renk = tahta[k][l][1];

				switch (karakter) {
				case 'p':
					tas = new Piyon(renk);
					break;
				case 'a':
					tas = new At(renk);
					break;
				case 'f':
					tas = new Fil(renk);
					break;
				case 'k':
					tas = new Kale(renk);
					break;
				case 'v':
					tas = new Vezir(renk);
					break;
				case 's':
					tas = new Sah(renk);
					break;
				default:
					cout << "Geçersiz karakter." << endl;
					break;
				}

				if (tas != nullptr) {
					
					tas->kontrol(tahta,k,l);
					float puan = tas->getPuan();
					
					if (tahta[k][l][1] == 's') {
						siyahPuan += puan;
					}
					else if (tahta[k][l][1] == 'b') {
						beyazPuan += puan;
					}
					sayac = tas->getSayac();
					delete tas;
				}
			}
		}
	}





	

	cout << endl;
	cout << "Toplam tas :" << sayac << endl;
	cout << "-------PUANLAR-------" << endl;
	cout << "Siyah :" << siyahPuan << endl;
	cout << "Beyaz :" << beyazPuan << endl;

	
	return 0;
}

