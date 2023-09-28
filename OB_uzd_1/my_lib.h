#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <iomanip> 
#include <random>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::left;
using std::setw;
using std::random_device;
using std::uniform_int_distribution;
using std::fixed;
using std::setprecision;
using std::printf;
using std::ifstream;


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
int atsitiktinis();
float suapvalink(float value);
void read_from_file(const string& filename, vector<studentas>& students);