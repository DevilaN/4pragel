#include <iostream>
#include <fstream>
using namespace std;


/** Procedura wypisujaca zawartosc pliku */
void wypisz(const char* fileName);

/** Procedura mnozaca plik? */
void mnoz(const char* fileName);


/**
 * @param int argc Ilosc argumentow podanych z linii polecen
 * @param char* argv[] Tablica zawierajaca stringi z poszczegolnymi parametrami (tutaj nazwa otwieranego pliku)
 * @return int Status zwracany do systemu operacyjnego
*/
int main(int argc, char* argv[])
{
	/* Jesli podano parametr, to traktuj go jako nazwe pliku, w przeciwnym wypadku domyslna nazwa pliku to add.txt */
	const char* fileName = (argc == 2 ? argv[1] : "add.txt");
	wypisz(fileName);
	mnoz(fileName);

	// Dawid! Po co te dwie linijki ponizej? To nic nie robi!
	ofstream plik;
	plik.open("add.txt", ios::app);

	return 0;
}




/**
 * @param char* fileName Nazwa pliku, ktory ma zostac przetworzony
 */
void wypisz(const char* fileName)
{
	ofstream plik;
	plik.open(fileName, ios::app);
	if (!plik.good()) {
		cerr << "blad otwarcia pliku!";
	} else {
		for(int i = 0; i < 100; i++) {
			plik << (i + 1) << endl;
		}
		plik.close();
	}
}

/**
 * @param char* fileName Nazwa pliku, ktory ma zostac przetworzony
 */
void mnoz(const char* fileName)
{
	ifstream plik(fileName);
	if (plik) {
		string linia;
		while (getline(plik, linia)) {
			cout << linia << endl;
		}
	} else {
		cout << "BLAD: nie mozna otworzyc pliku do odczytu." << endl;
	}
}
