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


	 //Stulpeliu pavadinimai
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(15) << "Galutinis (vid.)" << setw(15) << "Galutinis (med.)\n";

    // studentai 
    for (auto& student : grupe) {
        cout << left << setw(20) << student.pavarde << setw(20) << student.vardas << setw(20) << student.galutinis_vidurkis << std::setw(20) << student.galutinis_mediana << "\n";
    }
}