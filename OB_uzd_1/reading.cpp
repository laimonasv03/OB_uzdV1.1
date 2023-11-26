#include "my_lib.h";

void read_from_file_vec_c(const string& filename, vector<Studentas>& grupe)
{
    std::ifstream file(filename); //naudoti failo pavadinima
    Studentas Laik;

    if (!file.is_open()) {
        cout << "Klaida atidarant faila ";
        return;
    }

    std::string dummyLine;
    getline(file, dummyLine);
    while (file) { //ziuri kol yra mokiniu kuriuos galima nuskaityt
        Laik.read_Student(file); //nuskaito eilute
        Laik.suskaiciuojaRez(); // calculates final result
        grupe.push_back(Laik);
    }

    file.close();
}


