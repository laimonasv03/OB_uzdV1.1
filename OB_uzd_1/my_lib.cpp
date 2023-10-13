#include "my_lib.h";

vector<int> input_vector() {
	vector<int> data;

	int i = 0;
	int pazimys = 0;
	cout << "Ivesk -1 kai baigsi vesti namu darbu pazymius" << endl;
	while (true) {
		cout << i << "_nd pazimys: " << " ";
		cin >> pazimys;
		if (pazimys == -1) break;
		data.push_back(pazimys);
		i++;
	}
	return data;
}

float suapvalink(float value) {
	
	return round(value * 100) / 100;
}

studentas input_data() {
	studentas studentas;
	int egz;
	int pasirinkimas;
	int n_paz;

	cout << "Ar nori, kad nd_pazymiai bei egzamino balas butu sugeneruoti atsitiktinai?\n(ivesk viena is skaiciu)" << endl;
	cout << "1. Ne\n2. taip\n";
	patikrink(pasirinkimas);
	if(pasirinkimas == 1){
	cout << "Ivesk studento Varda: ";
	cin >> studentas.vardas;
	cout << "Ivesk studento Pavarde: ";
	cin >> studentas.pavarde;
	cout << "Ivesk egzamino rezultata (sveikas skaicius): ";
	cin >> studentas.egz;

	studentas.nd_pazymiai = input_vector();
	}
	else if (pasirinkimas == 2) {
		cout << "Ivesk studento Varda: ";
		cin >> studentas.vardas;
		cout << "Ivesk studento Pavarde: ";
		cin >> studentas.pavarde;
		cout << "Ivesk sveika skaiciu, nurodanti nd pazymiu kieki: " << " ";
		while (true) {
			try {
				cin >> n_paz;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
					throw std::invalid_argument("ivedei netinkama duomeni, ivesks sveika skaiciu");
				}
				break; // exit the loop if input is valid
			}
			catch (const std::invalid_argument& e) {
				std::cerr << e.what() << endl;
			}
		}
		for (int i = 0; i < n_paz; ++i) {
			studentas.nd_pazymiai.push_back(atsitiktinis());
		}
		studentas.egz = atsitiktinis();
	}


	return studentas;
}



float galutinisV(studentas& stud) {
	int pazimiu_suma = 0;
	float vidurkis;
	float galutinis_vidurkis;

	for (int pazimys : stud.nd_pazymiai) {
		pazimiu_suma += pazimys;
	}

	if (stud.nd_pazymiai.size() == 0) {
		vidurkis = 0.0f; // 0 jei tuscias vektorius
	}
	else {
		vidurkis = static_cast<float>(pazimiu_suma) / stud.nd_pazymiai.size();
	}

	galutinis_vidurkis = 0.4 * vidurkis + 0.6 * stud.egz;

	return suapvalink(galutinis_vidurkis);
}

float galutinisM(studentas& stud) {
	vector<int> vektorius = stud.nd_pazymiai;
	sort(vektorius.begin(), vektorius.end()); //issirusiuojam

	int ilgis = vektorius.size();
	float mediana;
	float galutinis_mediana;

	if (ilgis % 2 == 0) { //jei lyginis skaiciuojam vidurki 2 salimu
		int vid1 = vektorius[ilgis / 2 - 1];
		int vid2 = vektorius[ilgis / 2 + 1];
		mediana = (vid1 + vid2) / 2;
	}
	else {
	mediana = vektorius[ilgis / 2];
	}
	galutinis_mediana = 0.4 * mediana + 0.6 * stud.egz;
	return galutinis_mediana;
}

int atsitiktinis() {
	random_device rd; //random generator
	uniform_int_distribution<int> dist(1, 10); //intervalas
	return dist(rd);
}

void printTableMed(const vector<studentas>& grupe) {
	// Print column headers
	cout << "+---------------------+---------------------+-------------------+\n";
	cout << "| " << left << setw(20) << "Pavarde" << "| " << setw(20) << "Vardas" << "| " << setw(18) << "Galutinis(med.)" << "|\n";
	cout << "+---------------------+---------------------+-------------------+\n";

	// Print student data
	for (const studentas& student : grupe) {
		cout << "| " << left << setw(20) << student.pavarde << "| " << setw(20) << student.vardas << "| " << setw(18) << student.galutinis_mediana << "|\n";
		cout << "+---------------------+---------------------+-------------------+\n";
	}
}

void printTableVid(const vector<studentas>& grupe) {
	cout << "+---------------------+---------------------+-------------------+\n";
	cout << "| " << left << setw(20) << "Pavarde" << "| " << setw(20) << "Vardas" << "| " << setw(18) << "Galutinis(v1d.)" << "|\n";
	// Print student data
	for (const studentas& student : grupe) {
		cout << "| " << left << setw(20) << student.pavarde << "| " << setw(20) << student.vardas << "| " << setw(18) << student.galutinis_vidurkis << "|\n";
		cout << "+---------------------+---------------------+-------------------+\n";
	}
}

bool palygintiPavarde(studentas& a, studentas& b) {
	return a.pavarde < b.pavarde;
}

bool palygintiVarda(studentas& a, studentas& b) {
	return a.pavarde < b.pavarde;
}

void patikrink(int& value) {
	while (!(std::cin >> value) || (value != 1 && value != 2)) {
		std::cout << "Ivedei netinkama skaiciu, ivesk 1 arba 2 " << endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void patikrink_daug(int& value) {
	while (!(std::cin >> value)) {
		std::cout << "Ivedei netinkama skaiciu, ivesk sveika skaiciu " << endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

