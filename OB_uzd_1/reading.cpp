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
    while (file >> Laik.pavarde >> Laik.vardas) { //ziuri kol yra mokiniu kuriuos galima nuskaityt
        std::string line;
        getline(file, line); //nuskaito eilute
        std::istringstream iss(line); 
        int nd;
        std::vector<int> temp;
        while (iss >> nd) { //nuskaito pazymius is eilutes i laikina vektoriu
            temp.push_back(nd);
        }
        for (int i = 0; i < temp.size() - 1; i++) {
            Laik.nd_pazymiai.push_back(temp[i]); //is laikino vektoriaus perkelia i studento pazymiu vektoriu iki priespaskutinio
        }
        Laik.egz = temp.back();  //paskutini pazimi padaro egzamino pazymiu
        Laik.galutinis_mediana = galutinisM(Laik); // su mediana
        Laik.galutinis_vidurkis = galutinisV(Laik); // su vidurkiu
        grupe.push_back(Laik); 
        Laik.nd_pazymiai.clear();
    }

    file.close();
}