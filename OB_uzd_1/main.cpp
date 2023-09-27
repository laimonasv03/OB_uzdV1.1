#include "my_lib.h"


int main() {
	studentas Laikinas;
	vector<studentas> grupe;

	Laikinas = input_data();

	cout << Laikinas.vardas << "  " << Laikinas.pavarde << " ";

	for (int nd : Laikinas.nd_pazymiai) {
		cout << nd << " ";
	}
	float galutinis_rez = galutinis(Laikinas);
	cout << galutinis_rez << " ";
}