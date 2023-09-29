#include "my_lib.h";

void read_from_file(const string& filename, vector<studentas>& grupe)
{
    std::ifstream file(filename); //naudoti failo pavadinima
    studentas Laik;

    if (!file.is_open()) {
        cout <<"Klaida atidarant faila ";
        return; 
    }

    std::string dummyLine;
    getline(file, dummyLine);
    while (file >> Laik.pavarde >> Laik.vardas) { 
        std::string line;
        getline(file, line);
        std::istringstream iss(line);
        int nd;
        std::vector<int> temp;
        while (iss >> nd) {
            temp.push_back(nd);
        }
        for (int i = 0; i < temp.size() - 1; i++) {
            Laik.nd_pazymiai.push_back(temp[i]); 
        }
        Laik.egz = temp.back();
        Laik.galutinis_mediana = galutinisM(Laik); // su mediana
        Laik.galutinis_vidurkis = galutinisV(Laik); // su vidurkiu
        grupe.push_back(Laik); 
        Laik.nd_pazymiai.clear();
    }

    file.close();
}