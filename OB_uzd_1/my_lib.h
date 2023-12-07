#ifndef MY_LIB_H
#define MY_LIB_H

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
#include <numeric>
#include <list>


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
using std::accumulate;
using std::list;
using std::vector;

class Studentas {
private:
	string vardasC, pavardeC;
	vector<int> ndC;
	int egzC;
	double galutinisRez;
public:
	//konstruktorius
	Studentas() {
		vardasC = "Jonukas";
		pavardeC = "Bim";
		egzC = 5;
		galutinisRez = 5.00;
		ndC = vector<int>(5,5);
	}
	//konstruktorius su input parametrais
	Studentas(string vardasC, string pavardeC, int egzC, double galutinisRez, vector<int> ndC) {
		this -> vardasC = vardasC;
		this-> pavardeC = pavardeC;
		this-> egzC = egzC;
		this-> galutinisRez = galutinisRez;
		this-> ndC = ndC;
	}
	//konstruktorius nuskaitant
	Studentas(std::istream& is);
	//destruktorius
	~Studentas() {}

	//copy constructor
	//Stundentas(const Studentas& s) : vardasC(s.vardasC)

	inline string getVardas() const { return vardasC; }
	void setVardas(const string& v) { vardasC = v; }

	inline string getPavarde() const {return pavardeC;}
	void setPavarde(const string& p) {pavardeC = p;}

	inline vector<int> getNd() const { return ndC; }
	void setNd(const vector<int>& nd) { ndC = nd; }

	inline int getEgz() const { return egzC; }
	void setEgz(int egz) { egzC = egz; }

	double getRez() const { return galutinisRez; }

	void suskaiciuojaRez() {
		// default naudojamas mediana
		sort(ndC.begin(), ndC.end());
		double median = 0;
		if (ndC.size() % 2 == 0)
		{
			median = (ndC[ndC.size() / 2 - 1] + ndC[ndC.size() / 2]) / 2.0;
		}
		else
		{
			median = ndC[ndC.size() / 2];
		}
		galutinisRez = 0.4 * median + 0.6 * egzC;
	}
	std::istream& read_Student(std::istream& is);

	static bool pagalMediana_vec_C(const Studentas& a, const Studentas& b);

	bool comparePagalPavarde(const Studentas&, const Studentas&);
	bool comparePagalEgza(const Studentas&, const Studentas&);
	bool yraVargsiukas_vec_C() const;
	};

std::vector<Studentas> gudruciai_vargsiukai3_vec_C(std::vector<Studentas>& grupe);
void iraso_faila_C(const vector<Studentas>& grupe, string file_name);
void testFileSizes_vec3_C();
double rezultatai_vec(const vector<long>& durations);
void read_from_file_vec_c(std::vector<Studentas>& grupe, const std::string& duom_vard);//void patikrink(int& value);

#endif // MY_LIB_H

//void input_vector(std::list<int>& v);
//float galutinisV(studentas& stud);
//float galutinisM(studentas& stud);
//int atsitiktinis();
//float suapvalink(float value);
//void read_from_file(const string& filename, list<studentas>& students);
//void printTableMed(const list<studentas>& grupe);
//void printTableVid(const list<studentas>& grupe);
//bool palygintiPavarde(studentas& a, studentas& b);
//bool palygintiVarda(studentas& a, studentas& b);
//bool palygintiRez(studentas& a, studentas& b);

//void patikrink_daug(int& value);
//void generuoja_sarasa(int& n, string file_name);
//pair<list<studentas>, list<studentas>> gudruciai_vargsiukai(const std::list<studentas>& grupe);
//void iraso_faila(const list<studentas>& grupe, string file_name);
//void iraso_faila_be_galutinio(const list<studentas>& grupe, string file_name);
//double  rezultatai(const list<long>& durations);
//void testFileSizes();
//void sort_list(std::list<studentas>& grupe);
//bool sortByLastName(const studentas& a, const studentas& b);
//bool palygintiVidurki(const studentas& a, const studentas& b);
//bool palygintiMediana(const studentas& a, const studentas& b);
//bool yraVargsiukas(const studentas& s);
//
//void testFileSizes_list1();
//void testFileSizes_list2();
//void testFileSizes_list3();
//
//list<studentas> gudruciai_vargsiukai2(std::list<studentas>& grupe);
//list<studentas>gudruciai_vargsiukai3(list<studentas>& grupe);
//
////reikiamos funckijos su vektoriumi
//struct studentas_vec {
//	string vardas, pavarde;
//	vector<int> nd_pazymiai;
//	int egz;
//	float rez;
//	float galutinis_vidurkis;
//	float galutinis_mediana;
//};
//
//void testFileSizes_vec1();
//void testFileSizes_vec2();
//void testFileSizes_vec3();
//
//void read_from_file_vec(const string& filename, vector<studentas_vec>& grupe);
//bool pagalVidurki_vec(studentas_vec& a, studentas_vec& b);
//float galutinisV_vec(studentas_vec& stud);
//pair<vector<studentas_vec>, vector<studentas_vec>> gudruciai_vargsiukai_vec(const vector<studentas_vec>& grupe);
//void iraso_faila_vec(const vector<studentas_vec>& grupe, string file_name);

//vector<studentas_vec> gudruciai_vargsiukai_vec2(vector<studentas_vec>& grupe);
//bool yraVargsiukas_vec(const studentas_vec& s);
//vector<studentas_vec>gudruciai_vargsiukai3_vec(vector<studentas_vec>& grupe);