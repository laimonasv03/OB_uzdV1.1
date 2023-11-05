#include "my_lib.h"



int main() {

	int vesti_nuskaityti;
	studentas Laikinas;
	vector<studentas> grupe;
	int n;
	cout << "Ar nori vesti duomenis, ar generuoti, generuoti txt faila (ivesk tinkama skaiciu)" << endl;
	cout << "1 Vesti\n2 Nuskaityti\n3 generuoti txt faila\n4 testavimas" << endl;
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
		std::cout << "Pasirinkite kaip rusiuoti:\n1) Varda\n2) Pavarde\n3) Rezultata" << std::endl;
		int lygina;
		patikrink(lygina);
		if (lygina == 1) {
			sort(grupe.begin(), grupe.end(), palygintiVarda);
		}
		else if (lygina == 2) {
			sort(grupe.begin(), grupe.end(), palygintiPavarde);
		}
		sort(grupe.begin(), grupe.end(), palygintiRezultata);{
		}
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
		std::string filename = "emokymai_studentai10000.txt.txt";
		read_from_file(filename, grupe);
		std::cout << "Pasirinkite kaip rusiuoti:\n1) Varda\n2) Pavarde\n3) Rezultata" << std::endl;
		int lygina;
		patikrink(lygina);
		if (lygina == 1) {
			sort(grupe.begin(), grupe.end(), palygintiVarda);
		}
		else if (lygina == 2) {
			sort(grupe.begin(), grupe.end(), palygintiPavarde);
		}
		sort(grupe.begin(), grupe.end(), palygintiRezultata); {
		}

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
		auto start_time = std::chrono::high_resolution_clock::now();
		generuoja_sarasa(moksleiviu_skaicius, "generuoti_studentai.txt");
		read_from_file("generuoti_studentai.txt", grupe);
		for (studentas& Laikinas : grupe) {
			Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
			Laikinas.nd_pazymiai.clear();
		}
		pair<vector<studentas>, vector<studentas>> dvi_grupes = gudruciai_vargsiukai(grupe);
		vector<studentas> gudrociai = dvi_grupes.first;
		vector<studentas> vargsiukai = dvi_grupes.second;
		sort(gudrociai.begin(), gudrociai.end(), palygintiPavarde);
		sort(vargsiukai.begin(), vargsiukai.end(), palygintiPavarde);
		cout << "Gudrociai:" << endl;
		printTableVid(gudrociai);
		cout << "Vargsiukai:" << endl;
		printTableVid(vargsiukai);
		iraso_faila(gudrociai,"gudrociai_bim.txt");
		iraso_faila(vargsiukai, "vargsiukai_bam.txt");
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		cout << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;
	}
	else if (vesti_nuskaityti == 4) {
		testFileSizes();
	}
	else {
		cout << "ivedei netinkama skaiciu";
	}
}
