#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

struct studentas {
	string vardas, pavarde;
	vector <int> nd_pazymiai;
	int egz;
	float rez;
	float galutinis_vidurkis;
	float galutinis_mediana;
};

studentas input_data();
void input_vector(std::vector<int>& v);
float galutinisV(studentas& stud);
float galutinisM(studentas& stud);