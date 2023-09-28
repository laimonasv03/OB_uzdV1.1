#include "my_lib.h"


int main() {
	/*studentas Laikinas;
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

	/*cout << "Ar nori, kad "
	 //Stulpeliu pavadinimai
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(15) << "Galutinis(vid.)" << setw(15) << "Galutinis(med.)\n";
	
	int pasirinkimas_balo;
	cout << "Pasirink su kuo skaiciuoti galutini bala\n(ivesk viena is skaiciu)" << endl;
	cout << "1. vidurkiu\n2. mediana\n";
	cin >> pasirinkimas_balo;
	if (pasirinkimas_balo == 1) {
		cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(15) << "Galutinis(vid.)\n";
		for (auto& student : grupe) {
			cout << left << setw(20) << student.pavarde << setw(20) << student.vardas << setw(20) << student.galutinis_vidurkis <<"\n";
		}
	}
	else if (pasirinkimas_balo == 2) {
		cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(15) << "Galutinis(med.)\n";
		// studentai 
		for (auto& student : grupe) {
			cout << left << setw(20) << student.pavarde << setw(20) << student.vardas << setw(20) << student.galutinis_mediana << "\n";
		}
	}*/
	std::vector<studentas> grupe;
	std::string filename = "C:\\Users\\laimo\\Desktop\\OB_Testavimas.txt"; // Change this to your file's name

	// Call the function to read students from the file
	read_from_file(filename, grupe);

	// Now, the 'students' vector contains the parsed student data

	// You can iterate through the vector and work with the student data as needed
	for (studentas& Laikinas : grupe) {
		Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
		Laikinas.galutinis_mediana = galutinisM(Laikinas);
		Laikinas.nd_pazymiai.clear();
	}
}