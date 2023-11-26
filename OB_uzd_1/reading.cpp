#include "my_lib.h";


std::istream& Studentas::read_from_file(std::istream& is) {
    std::string vardas;
    is >> vardas;
    setVardas(vardas);

    std::string pavarde;
    is >> pavarde;
    setPavarde(pavarde);

    std::vector<int> pazymiai;
    int pazymys;
    while (is >> pazymys) {
        pazymiai.push_back(pazymys);
    }
    setNd(pazymiai);

    int egzaminas = pazymiai.back();
    pazymiai.pop_back();
    setEgz(egzaminas);

    return is;
}


