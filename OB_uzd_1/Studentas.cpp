#include "my_lib.h"
#include "reading.cpp"

Studentas::Studentas(std::istream& is) {
    read_Student(is);
}

std::istream& Studentas::read_Student(std::istream& is) {
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

bool pagalMediana_vec_C(const Studentas& a, const Studentas& b) {
    return a.getRez() < b.getRez();
}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.getPavarde() < b.getPavarde();
}

bool comparePagalEgza(const Studentas& a, const Studentas& b) {
    return a.getEgz() < b.getEgz();
}

bool yraVargsiukas_vec_C(const Studentas& s) {
    return s.getRez() < 5;
}

vector<Studentas> gudruciai_vargsiukai3_C(vector<Studentas>& grupe) {
    vector<Studentas> vargsiukai_bam;

    auto partition_point = std::partition(grupe.begin(), grupe.end(), yraVargsiukas_vec_C); //suskaido pagal kondicija yraVargsiukas
    std::move(partition_point, grupe.end(), std::back_inserter(vargsiukai_bam)); //jei kondicija T permeta i vargsiukus
    grupe.erase(partition_point, grupe.end()); // istrina is orginalaus, jei vargsiukas

    return vargsiukai_bam;
}


void testFileSizes_vec3_C() {
    std::vector<std::string> filenames = {
           "Studentai100000.txt",
           "Studentai1000000.txt"

    };

    for (const std::string& filename : filenames) {
        std::vector<Studentas> grupe;
        std::vector<long> durations_split;

        for (int i = 0; i < 5; ++i) {  // 5 kart kartojam kiekvienam failui

            read_from_file_vec_c(filename, grupe);


            sort(grupe.begin(), grupe.end(), pagalMediana_vec_C);

            auto start_time = std::chrono::high_resolution_clock::now();
            start_time = std::chrono::high_resolution_clock::now();
            vector<Studentas> vargsiukai = gudruciai_vargsiukai3_vec_C(grupe);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
            durations_split.push_back(duration.count());

            start_time = std::chrono::high_resolution_clock::now();
            iraso_faila_vec(grupe, "gudrociai_bim.txt");
            iraso_faila_vec(vargsiukai, "vargsiukai_bam.txt");


            grupe.clear();
            vargsiukai.clear();
        }

        double avg_split = rezultatai_vec(durations_split);

        cout << "Container - Vector, strategy 3" << std::endl;

        cout << "Container - Vector, File Size: " << filename << std::endl;

        cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";


    }
}






