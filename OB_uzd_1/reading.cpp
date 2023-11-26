#include "my_lib.h";

std::istream& Studentas::read_from_file(std::istream& is) {
    std::string vardas;
    is >> vardas;
    vardasC = vardas; 

    std::string pavarde;
    is >> pavarde;
    pavardeC = pavarde; 
    std::vector<double> pazymiai; 
    double pazymys;
    while (is >> pazymys) {
        pazymiai.push_back(pazymys);
    }
    ndC = pazymiai; 

    double egzaminas = pazymiai.back(); 
    pazymiai.pop_back();
    egzC = egzaminas; 

    return is;
}


