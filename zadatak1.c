#include <iostream>
#include <vector>

int main() {
	std::vector<int> niz = { 1, 2, 3, 4, 5, 6 };

	auto isParan = [](int x) { return x % 2 == 0; };
	auto isNeparan = [](int x) { return x % 2 != 0; };

	auto udvostruci = [](int x) { return x * 2; };
	auto prepolovi = [](int x) { return x / 2; };

	int suma = 0;
	int produkt = 1;
	auto dodajUSumu = [&](int x) { suma += x; };
	auto dodajUProdukt = [&](int x) { produkt *= x; };

	int prag = 3;
	int sumaVecih = 0;
	auto dodajAkoVeciOdPraga = [prag, &sumaVecih](int x) {
		if (x > prag)
			sumaVecih += x;
	};

	for (auto &x : niz) {
		if (isParan(x))
			x = prepolovi(x);
		else
			x = udvostruci(x);
	}

	std::cout << "Nakon obrade (parni prepolovljeni, neparni udvostruceni): ";
	for (int x : niz)
		std::cout << x << " ";
	std::cout << std::endl;

	for (int x : niz) {
		dodajUSumu(x);
		dodajUProdukt(x);
	}
	std::cout << "Suma: " << suma << std::endl;
	std::cout << "Produkt: " << produkt << std::endl;

	for (int x : niz)
		dodajAkoVeciOdPraga(x);

	std::cout << "Suma brojeva vecih od " << prag << ": " << sumaVecih << std::endl;

	return 0;
}
