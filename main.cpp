#include <iostream>
#include <fstream>

using namespace std;

class zad{
	ifstream wej;
	ofstream wyj;
	
	public:
		
		zad();
		~zad();
		
		void wczyt();
};

zad::zad() {
	wej.open("dane.txt");
	wyj.open("wynik.txt");
}

void zad::wczyt() {
 	double licznik, mianownik;
 	double minimum, min_licznik, min_mianownik;
 	
			if(wej.good()) {
				wej>>licznik;
				wej>>mianownik;	
				minimum = licznik/mianownik;
				min_licznik = licznik;
				min_mianownik = mianownik;
			
			while(!wej.eof()) {
				wej>>licznik;
				wej>>mianownik;
				
				if(licznik/mianownik<min) {
					minimum = licznik/mianownik;
					min_licznik = licznik;
					min_mianownik = mianownik;
				}
				
				if(licznik/mianownik==minimum) {
					if(mianownik<=min_mianownik) {
						min_licznik = licznik;
						min_mianownik = mianownik;
					}
				}
			}
			
		cout<<min_licznik<<" "<<min_mianownik;
		wyj<<min_licznik<<" "<<min_mianownik;
	}
}
	
zad::~zad() {		
	wej.close();
	wyj.close();
}	

int main() {
	
	zad z;
	z.wczyt();
		
	return 0;
}






