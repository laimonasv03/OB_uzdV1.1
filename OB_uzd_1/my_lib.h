#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct studentas {
	string vardas, pavarde;
	vector <int> nd_pazymiai;
	int egz;
	float rez;
};

void input_data();