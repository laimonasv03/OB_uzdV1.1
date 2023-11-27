#include "my_lib.h"


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

bool Studentas :: pagalMediana_vec_C(const Studentas& a, const Studentas& b) {
    return a.getRez() < b.getRez();
}

bool Studentas :: comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.getPavarde() < b.getPavarde();
}

bool Studentas::comparePagalEgza(const Studentas& a, const Studentas& b) {
    return a.getEgz() < b.getEgz();
}

bool Studentas::yraVargsiukas_vec_C() const {
    return getRez() < 5;
}



std::vector<Studentas> gudruciai_vargsiukai3_vec_C(std::vector<Studentas>& grupe) {
    std::vector<Studentas> vargsiukai_bam;

    // Use std::partition to split the vector based on the condition
    auto partition_point = std::partition(grupe.begin(), grupe.end(), [](const Studentas& s) {
        return s.yraVargsiukas_vec_C(); // Assuming yraVargsiukas_vec_C is your condition
        });

    // Move the elements that satisfy the condition to vargsiukai_bam
    std::move(partition_point, grupe.end(), std::back_inserter(vargsiukai_bam));

    // Erase the elements that satisfy the condition from the original vector
    grupe.erase(partition_point, grupe.end());

    return vargsiukai_bam;
}


void iraso_faila_C(const vector<Studentas>& grupe, string file_name) {
    ofstream outputFile(file_name);

    // Check if grupe is not empty before accessing its elements
    if (!grupe.empty()) {
        //headeris
        outputFile << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
        for (int i = 1; i <= grupe[0].getNd().size(); i++) {
            outputFile << setw(20) << "ND" + to_string(i);
        }
        outputFile << setw(20) << "Egzaminas" << setw(20) << "Rezultatas" << endl;

        //irasymas
        for (const Studentas& mok : grupe) {
            outputFile << left << setw(20) << mok.getVardas() << setw(20) << mok.getPavarde();
            for (int pazimys : mok.getNd()) {
                outputFile << setw(20) << pazimys;
            }
            outputFile << setw(20) << mok.getEgz() << setw(20) << mok.getRez() << endl;
        }
    }

    outputFile.close();
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

            read_from_file_vec_c(grupe, filename);


            sort(grupe.begin(), grupe.end(), Studentas:: pagalMediana_vec_C);

            auto start_time = std::chrono::high_resolution_clock::now();
            start_time = std::chrono::high_resolution_clock::now();
            vector<Studentas> vargsiukai = gudruciai_vargsiukai3_vec_C(grupe);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
            durations_split.push_back(duration.count());

            start_time = std::chrono::high_resolution_clock::now();
            iraso_faila_C(grupe, "gudrociai_bim.txt");
            iraso_faila_C(vargsiukai, "vargsiukai_bam.txt");


            grupe.clear();
            vargsiukai.clear();
        }

        double avg_split = rezultatai_vec(durations_split);

        cout << "Container - Vector, strategy 3" << std::endl;

        cout << "Container - Vector, File Size: " << filename << std::endl;

        cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";


    }
}

double rezultatai_vec(const vector<long>& durations) {
    return accumulate(durations.begin(), durations.end(), 0) / durations.size();
}
