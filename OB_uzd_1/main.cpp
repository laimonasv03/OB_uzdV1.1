#include "my_lib.h"


int main() {
	studentas Laikinas;
	vector<studentas> grupe;
	cout << "kiek moksleiviu ivesi: ";
	int n;
	cin >> n;

	for (int j=0; j < n; j++) {
		Laikinas = input_data();
		Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
		Laikinas.galutinis_mediana = galutinisM(Laikinas);
		grupe.push_back(Laikinas);
		Laikinas.nd_pazymiai.clear();
	}

	cout << Laikinas.vardas << "  " << Laikinas.pavarde << " ";

	for (auto& a : grupe) {
		cout << a.vardas << "  " << a.pavarde << a.egz << a.galutinis_vidurkis << a.galutinis_mediana << " ";
	}
}