#include <iostream>
#include <vector>
#include <algorithm>  
#include <cmath>      

using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesite brojeve (0 za kraj): ";
	while (true) {
		cin >> broj;
		if (broj == 0) break;
		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << " "; 
	}
	cout << endl;
}

vector<int> unique_elements(const vector<int>& v) {
	vector<int> jedinstveni;
	for (int x : v) {
		if (find(jedinstveni.begin(), jedinstveni.end(), x) == jedinstveni.end()) {
			jedinstveni.push_back(x);
		}
	}
	return jedinstveni;
}

void sort_by_abs(vector<int>& v) {
	sort(v.begin(), v.end(), [](int a, int b) {
		return abs(a) < abs(b); 
	});
}

int main() {
	vector<int> v;

	input_vector(v);

	cout << "Originalni vektor: ";
	print_vector(v);

	vector<int> jedinstveni = unique_elements(v);
	cout << "Jedinstveni elementi: ";
	print_vector(jedinstveni);

	sort_by_abs(jedinstveni);

	cout << "Sortirani po apsolutnoj vrijednosti: ";
	for (size_t i = 0; i < jedinstveni.size(); i++) {
		cout << jedinstveni[i];
		if (i != jedinstveni.size() - 1) cout << ", ";  
	}
	cout << endl;

	cout << "Apsolutne vrijednosti: ";
	for (size_t i = 0; i < jedinstveni.size(); i++) {
		cout << abs(jedinstveni[i]);
		if (i != jedinstveni.size() - 1) cout << ", "; 
	}
	cout << endl;

	return 0;
}
