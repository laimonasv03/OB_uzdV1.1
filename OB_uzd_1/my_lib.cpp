#include "my_lib.h";

void input_vector(std::vector<int>& v) {
	int a;

	//pridedam skaicius
	while (std::cin >> a) {
		v.push_back(a);
	}
}

void input_data(studentas& studentas) { // &pasakom kokio tipo bus 
	string vardas, pavarde;
	vector<int> nd_pazymiai;
	int egz;
	cout << "Ivesk studento Varda: ";
	cin >> studentas.vardas;
	cout << "Ivesk studento Pavarde: ";
	cin >> studentas.pavarde;
	cout << "Ivesk egzamino rezultata (sveikas skaicius): ";
	cin >> studentas.egz;

	cout << "Ivesk nd pazymius, pabaigus ivesk bet kokia raide : \n";
	input_vector(studentas.nd_pazymiai);
	
}