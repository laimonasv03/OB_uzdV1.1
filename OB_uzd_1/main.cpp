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
		std::string filename = "emokymai_studentai10000.txt.txt";
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
		vector<studentas> grupe_1000;
		vector<studentas> grupe_10000;
		vector<studentas> grupe_100000;
		vector<studentas> grupe_1000000;
		vector<long> durations_read;
		vector<long> durations_sort;
		vector<long> durations_split;
		vector<long> durations_write;
		vector<long> durations_proccess;
		
		for (int i = 0; i < 3; ++i) {

			//nuskaitymas
			auto start_time = std::chrono::high_resolution_clock::now();
			read_from_file("Studentai1000.txt", grupe_1000);
			auto end_time = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
			durations_read.push_back(duration.count());
			start_time = std::chrono::high_resolution_clock::now();
			for (studentas& Laikinas : grupe_1000) {
				Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
				Laikinas.nd_pazymiai.clear();
			}
			end_time = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
			durations_proccess.push_back(duration.count());
			/*long average_duration_read_1000 = accumulate(durations.begin(), durations.end(), 0) / durations.size();
			durations.clear();
			cout <<"Vidutinis laikas (3 bandymai) nuskaityti 1000 faila: " << average_duration_read_1000 << " milliseconds (" << average_duration_read_1000 / 1000.0 << " seconds)" << endl;*/
			//rusiavimas

			 start_time = std::chrono::high_resolution_clock::now();
			sort(grupe_1000.begin(), grupe_1000.end(), palygintiPavarde);
			 end_time = std::chrono::high_resolution_clock::now();
			 duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
			durations_sort.push_back(duration.count());

			//long average_duration_sort_1000 = accumulate(durations.begin(), durations.end(), 0) / durations.size();
			//durations.clear();
			//cout << "Vidutinis laikas (3 bandymai) surusiuoti 1000 studentu: " << average_duration_sort_1000 << " milliseconds (" << average_duration_sort_1000 / 1000.0 << " seconds)" << endl;

			////isskirstymas i kategorijas

			 start_time = std::chrono::high_resolution_clock::now();
			pair<vector<studentas>, vector<studentas>> dvi_grupes = gudruciai_vargsiukai(grupe_1000);
			vector<studentas> gudrociai = dvi_grupes.first;
			vector<studentas> vargsiukai = dvi_grupes.second;
			 end_time = std::chrono::high_resolution_clock::now();
			 duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
			durations_split.push_back(duration.count());

			/*long average_duration_split_1000 = accumulate(durations.begin(), durations.end(), 0) / durations.size();
			durations.clear();
			cout << "Vidutinis laikas (3 bandymai) isskirstyti i grupes 1000 studentu: " << average_duration_split_1000 << " milliseconds (" << average_duration_split_1000 / 1000.0 << " seconds)" << endl;
			*/
			//surusiuotu isvedimas i 2 naujus failus

			 start_time = std::chrono::high_resolution_clock::now();
			iraso_faila(gudrociai, "gudrociai_bim.txt");
			iraso_faila(vargsiukai, "vargsiukai_bam.txt");
			 end_time = std::chrono::high_resolution_clock::now();
			 duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
			durations_write.push_back(duration.count());
			gudrociai.clear();
			vargsiukai.clear();
		}
		double avg_read = rezultatai(durations_read);
		double avg_sort = rezultatai(durations_sort);
		double avg_split = rezultatai(durations_split);
		double avg_write = rezultatai(durations_write);
		double avg_process = rezultatai(durations_proccess);
		cout << avg_read << " " << avg_sort << " " << avg_split << " " << avg_write << " " << avg_process;
		//long average_duration_write_1000 = accumulate(durations.begin(), durations.end(), 0) / durations.size();
		/*durations.clear();
		cout << "Vidutinis laikas (3 bandymai) surusiuotu i grupes isvesti i 2 failus 1000 studentu: " << average_duration_write_1000 << " milliseconds (" << average_duration_write_1000 / 1000.0 << " seconds)" << endl;*/

	/*cia dar parasyta if ir ar daryt su 10 ^ 7 vector<studentas> grupe_10000000;
		read_from_file("Studentai1000.txt", grupe_1000);*/
	}
	else {
		cout << "ivedei netinkama skaiciu";
	}
}
