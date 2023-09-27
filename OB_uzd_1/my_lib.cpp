#include "my_lib.h";

void input_vector(std::vector<int>& v) {
	int a;

	//pridedam skaicius
	while (std::cin >> a) {
		v.push_back(a);
	}
}

studentas input_data() { // &pasakom kokio tipo bus 
	studentas studentas;
	int egz;
	cout << "Ivesk studento Varda: ";
	cin >> studentas.vardas;
	cout << "Ivesk studento Pavarde: ";
	cin >> studentas.pavarde;
	cout << "Ivesk egzamino rezultata (sveikas skaicius): ";
	cin >> studentas.egz;

	cout << "Ivesk nd pazymius, pabaigus ivesk bet kokia raide : \n";
	input_vector(studentas.nd_pazymiai);
	
	return studentas;
}
float galutinis(studentas& stud) {
	int pazimiu_suma = 0;
	float vidurkis;
	float galutinis;

	for (int pazimys : stud.nd_pazymiai) {
		pazimiu_suma += pazimys;
	}

	if (stud.nd_pazymiai.size() == 0) {
		vidurkis = 0.0f; // 0 jei tuscias vektorius
	}
	else {
		vidurkis = static_cast<float>(pazimiu_suma) / stud.nd_pazymiai.size();
	}

	galutinis = 0.4 * vidurkis + 0.6 * stud.egz;

	return galutinis;
}