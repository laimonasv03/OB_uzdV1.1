#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <iomanip> 
#include <random>
#include <fstream>
#include <sstream>
#include <limits>
#include <string> 
#include <chrono>


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
using std::streamsize;
using std::numeric_limits;
using std::runtime_error;
using std::to_string;
using std::ofstream;
using std::pair;

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
void printTableMed(const vector<studentas>& grupe);
void printTableVid(const vector<studentas>& grupe);
bool palygintiPavarde(studentas& a, studentas& b);
bool palygintiVarda(studentas& a, studentas& b);
void patikrink(int& value);
void patikrink_daug(int& value);
void generuoja_sarasa(int& n);
pair<vector<studentas>, vector<studentas>> gudruciai_vargsiukai(const std::vector<studentas>& grupe);
void iraso_faila(const vector<studentas>& grupe, string file_name);

