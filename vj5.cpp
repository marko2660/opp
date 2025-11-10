#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Karta {
public:
	string broj;
	string boja;

	Karta(string b, string bo) : broj(b), boja(bo) {}

	// Ispis karte
	void ispis() const {
		cout << broj << " od " << boja;
	}
};

class Mac {
private:
	vector<Karta> karte;

public:
	Mac() {
		// Kreiramo 40 karata (4 boje i 10 brojeva: As, 2, 3, 4, 5, 6, 7, 8, 9, 10)
		vector<string> brojevi = { "As", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
		vector<string> boje = { "Karo", "Pik", "Tref", "Herc" };

		for (auto& boja : boje) {
			for (auto& broj : brojevi) {
				karte.push_back(Karta(broj, boja));
			}
		}
	}

	// Funkcija za miješanje karata
	void mijesaj() {
		random_shuffle(karte.begin(), karte.end());
	}

	// Funkcija za podjelu karata igra?ima (po 10 karata)
	vector<vector<Karta>> podijeli(int brojIgraca) {
		vector<vector<Karta>> ruke(brojIgraca);

		int i = 0;
		for (auto& karta : karte) {
			ruke[i % brojIgraca].push_back(karta);
			i++;
		}
		return ruke;
	}

	// Funkcija za ispis svih karata
	void ispis() {
		for (const auto& karta : karte) {
			karta.ispis();
			cout << endl;
		}
	}
};

class Igrac {
public:
	string ime;
	vector<Karta> ruka;
	int bodovi;

	Igrac(string imeIgraca) : ime(imeIgraca), bodovi(0) {}

	// Funkcija za ispis ruke igra?a
	void ispisRuku() {
		cout << ime << "'s ruka: ";
		for (auto& karta : ruka) {
			karta.ispis();
			cout << " | ";
		}
		cout << endl;
	}

	// Funkcija za akužiranje (provjerava napolitanu ili tri iste karte)
	void akuziraj() {
		map<string, int> brojevi;
		map<string, int> boje;
		for (const auto& karta : ruka) {
			brojevi[karta.broj]++;
			boje[karta.boja]++;
		}

		// Provjera za napolitanu (1, 2, 3 iste boje)
		bool napolitana = false;
		for (auto& boja : boje) {
			if (boja.second == 3) {  // Ako ima 3 karte iste boje
				vector<string> napolitanaKarte = { "As", "2", "3" };
				vector<string> karteKrozBoje = { "As", "2", "3" };
				sort(karteKrozBoje.begin(), karteKrozBoje.end());
				if (find(napolitanaKarte.begin(), napolitanaKarte.end(), "As") != napolitanaKarte.end()) {
					bodovi += 3;
					napolitana = true;
				}
				if (napolitana) { break; }
			}
		}

		// Provjera za Tri iste karte
		for (auto& broj : brojevi) {
			if (broj.second == 3) {
				bodovi += 3;
			}
			else if (broj.second == 4) {
				bodovi += 4;
			}
		}
	}
};

int main() {
	int brojIgraca;
	cout << "Unesite broj igraca (2 ili 4): ";
	cin >> brojIgraca;

	if (brojIgraca != 2 && brojIgraca != 4) {
		cout << "Neispravan broj igraca!" << endl;
		return 1;
	}

	// Unos imena igraca
	vector<Igrac> igraci;
	string ime;
	for (int i = 0; i < brojIgraca; i++) {
		cout << "Unesite ime " << i + 1 << ". igraca: ";
		cin >> ime;
		igraci.push_back(Igrac(ime));
	}

	// Kreiranje i miješanje špila
	Mac mac;
	mac.mijesaj();

	// Podjela karata igra?ima
	vector<vector<Karta>> ruke = mac.podijeli(brojIgraca);

	// Dijeljenje karata svakom igra?u
	for (int i = 0; i < brojIgraca; i++) {
		igraci[i].ruka = ruke[i];
		igraci[i].ispisRuku();
	}

	// Akužiranje i ispis bodova za svakog igra?a
	for (auto& igrac : igraci) {
		igrac.akuziraj();
		cout << igrac.ime << " ima " << igrac.bodovi << " bodova." << endl;
	}

	return 0;
}
