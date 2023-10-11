#include "my_lib.h"



int main() {
	std::string filename = "studentai10000.txt";
	int vesti_nuskaityti;
	studentas Laikinas;
	vector<studentas> grupe;
	int n;
	cout << "Ar nori vesti duomenis, ar generuoti, generuoti txt faila (ivesk tinkama skaiciu)" << endl;
	cout << "1 Vesti\n2 Nuskaityti\n3 generuoti txt faila" << endl;
	patikrink(vesti_nuskaityti);
	if (vesti_nuskaityti == 1) {
		cout << "kiek moksleiviu ivesi: ";
		patikrink_daug(n);
		for (int j = 0; j < n; j++) {
			Laikinas = input_data();
			Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
			Laikinas.galutinis_mediana = galutinisM(Laikinas);
			grupe.push_back(Laikinas);
			Laikinas.nd_pazymiai.clear();
		}
		sort(grupe.begin(), grupe.end(), palygintiPavarde);
		int pasirinkimas_balo;
		cout << "Pasirink su kuo skaiciuoti galutini bala\n(ivesk viena is skaiciu)" << endl;
		cout << "1. vidurkiu\n2. mediana\n";
		patikrink(pasirinkimas_balo);
		if (pasirinkimas_balo == 1) {
			cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(15) << "Galutinis(vid.)\n";
			for (auto& student : grupe) {
				cout << left << setw(20) << student.pavarde << setw(20) << student.vardas << setw(20) << student.galutinis_vidurkis << "\n";
			}
		}
		else if (pasirinkimas_balo == 2) {
			cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(15) << "Galutinis(med.)\n";
			// studentai 
			for (auto& student : grupe) {
				cout << left << setw(20) << student.pavarde << setw(20) << student.vardas << setw(20) << student.galutinis_mediana << "\n";
			}
		}
	}
	else if (vesti_nuskaityti == 2) {
		read_from_file(filename, grupe);
		sort(grupe.begin(), grupe.end(), palygintiPavarde);

		for (studentas& Laikinas : grupe) {
			Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
			Laikinas.galutinis_mediana = galutinisM(Laikinas);
			Laikinas.nd_pazymiai.clear();
		}
		int pasirinkimas_balo_2;
		cout << "Pasirink su kuo skaiciuoti galutini bala\n(ivesk viena is skaiciu)" << endl;
		cout << "1. vidurkiu\n2. mediana\n";
		patikrink(pasirinkimas_balo_2);
		if (pasirinkimas_balo_2 == 1) {
			printTableVid(grupe);
		}
		else if (pasirinkimas_balo_2 == 2) {
			printTableMed(grupe);
		}

	}
	else if (vesti_nuskaityti == 3) {
		int moksleiviu_skaicius;
		cout << "kiek moksleiviu generuoti: ";
		patikrink_daug(moksleiviu_skaicius);
		generuoja_sarasa(moksleiviu_skaicius);

	}
	else {
		cout << "ivedei netinkama skaiciu";
	}
}
