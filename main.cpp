#include <iostream>
#include <fstream>
using namespace std;


/** Procedura wypisujaca zawartosc pliku */
void wypisz();

/** Procedura mnozaca plik? */
void mnoz();


/**
 * @param int argc Ilosc argumentow podanych z linii polecen
 * @param char* argv[] Tablica zawierajaca stringi z poszczegolnymi parametrami (tutaj nazwa otwieranego pliku)
 * @return int Status zwracany do systemu operacyjnego
*/
int main(int argc, char* argv[])
{
	wypisz();
	mnoz();
	
	ofstream plik;
	plik.open("add.txt",ios::app);
	return 0;
}




void wypisz()
{
	ofstream plik;
	plik.open("add.txt",ios::app);
	if (!plik.good())
			cerr << "blad otwarcia pliku!";
		else{
		for(int i = 0; i < 100; i++){
			plik << i+1 << endl;
			}
	plik.close();
	}
}

void mnoz()
{

	ifstream plik("add.txt");
 	if(plik)
	{
	  	string linia;	 
 		while(getline(plik, linia))	
		{
			cout << linia << endl;						  
		}
	}
	else
	{
		cout << "B£¥D: nie mo¿na otworzyæ pliku do odczytu." << endl;
	}
}
