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

studentas input_data() { // &pasakom kokio tipo bus 
	studentas studentas;
	int egz;
	cout << "Ivesk studento Varda: ";
	cin >> studentas.vardas;
	cout << "Ivesk studento Pavarde: ";
	cin >> studentas.pavarde;
	cout << "Ivesk egzamino rezultata (sveikas skaicius): ";
	cin >> studentas.egz;

	studentas.nd_pazymiai = input_vector();

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

	return galutinis_vidurkis;
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