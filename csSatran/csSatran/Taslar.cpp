#include "Taslar.h"
#include <iostream>


using namespace std;

int Taslar::sayac = 0;
Taslar::Taslar(char ch, char rnk, float points)
	:karakter(ch), renk(rnk), puan(points), tehtid(false) {
	sayac++;
}
int Taslar::getSayac() {
	return sayac;
}

float Taslar::getPuan() const {
	return tehtid ? puan / 2 : puan;
}

bool Taslar::getTehtid() const {
	return tehtid;
}

char Taslar::getChar() const {
	return karakter;
}

char Taslar::getRenk() const {
	return renk;
}

void Taslar::kontrol(char matris[8][8][3], int x, int y){
	char renkK = this->renk;
	
	// at kontrol
	int atHareket[8][2] = {
		{-2,-1},{-2,1},
		{-1,-2},{-1,2},
		{1,-2},{1,2},
		{2,-1},{2,1}
	};

	for (int k = 0; k < 8; k++) {
		int targetX = x + atHareket[k][0];
		int targetY = y + atHareket[k][1];

		if (targetX >= 0 && targetX <= 7 && targetY >= 0 && targetY <= 7) {
			char targetAk = matris[targetX][targetY][0];
			char targetAr = matris[targetX][targetY][1];

			if ((targetAk == 'a') && (targetAr != renkK)) {
				this->tehtid = true;
			}
		}
	}



	// vezir
	// Yatay kontrol 
	for (int yon : {-1, 1}) {
		for (int j = y + yon; j >= 0 && j < 8; j += yon) {
			if (matris[x][j][0] != '-') {
				if ((matris[x][j][1] != renkK) && (matris[x][j][0]=='v')) {
					this->tehtid = true;
				}
				break;
			}
		}
	}

	//dikey
	for (int yon : {-1, 1}) {
		for (int j = x + yon; j >= 0 && j < 8; j += yon) {
			if (matris[j][y][0] != '-') {
				if ((matris[j][y][1] != renkK) && (matris[j][y][0]=='v')) {
					this->tehtid = true;
					break;
				}
				break;
			}
		}
	}

	//çapraz vezir

	int dx[4] = { 1, -1, -1, 1 };
	int dy[4] = { 1, -1, 1, -1 };

	for (int i = 0; i < 4; i++) {

		for (int k = 1; k < 8; k++) {
			int newX = x + (k * dx[i]);
			int newY = y + (k * dy[i]);
			if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8) {
				break;  
			}

			/*if (matris[newX][newY][0] != '-') {
				if ((matris[newX][newY][0] == 'v') && (matris[newX][newY][1] == renkK)) {
					this->tehtid = true;

				}
				break;
			}*/

			char hucredekiTaþ = matris[newX][newY][0];

			if (hucredekiTaþ == '-') {
				continue;
			}
			else if (hucredekiTaþ == 'v' && matris[newX][newY][1] != renkK) {
				this->tehtid = true;
				break;
			}
			else {
				break;
			}
		}
		
	}

	
	
	//piyon
	for (int k = 0; k < 4; k++) {
		if (renkK == 's') {
			if (dx[k] > 0) {
				int newX = x + dx[k];
				int newY = y + dy[k];

				if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8) {
					continue;
				}
				char hucredekiTas = matris[newX][newY][0];

				if (hucredekiTas == '-') {
					continue;
				}
				else if (hucredekiTas == 'p' && matris[newX][newY][1] != renkK) {
					this->tehtid = true;
					break;
				}
				else {
					continue;
				}
			}
		}
		else if (renkK == 'b') {
			if (dx[k] < 0) {
				int newX = x + dx[k];
				int newY = y + dy[k];

				if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8) {
					continue;
				}
				char hucredekiTas = matris[newX][newY][0];

				if (hucredekiTas == '-') {
					continue;
				}
				else if (hucredekiTas == 'p' && matris[newX][newY][1] != renkK) {
					this->tehtid = true;
					break;
				}
				else {
					continue;
				}
			}
		}


	}
	

}
