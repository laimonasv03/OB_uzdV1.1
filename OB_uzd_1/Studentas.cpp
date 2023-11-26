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

bool compare(const Studentas&, const Studentas&) {
    // realizacija 
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


            sort(grupe.begin(), grupe.end(), pagalVidurki_vec);

            auto start_time = std::chrono::high_resolution_clock::now();
            start_time = std::chrono::high_resolution_clock::now();
            vector<studentas_vec> vargsiukai = gudruciai_vargsiukai3_vec(grupe);
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





void ivedimas_is_file_c(vector<Studentas>& grupe, char vm_pasirinkimas, const string& duom_vard)
{
    ifstream duomenys(duom_vard);

    if (!duomenys.is_open())
    {
        cout << "Neatsidare duomenys " << endl;
        return;
    }

    string pirma_eilute;
    getline(duomenys, pirma_eilute);

    string eilute;
    while (getline(duomenys, eilute))
    { // kol nera pasiekta failo pabaiga skaitome po eilute
        Studentas laikinas;

        if (eilute.empty() || all_of(eilute.begin(), eilute.end(), ::isspace))
        {
            continue;
        }

        istringstream iss(eilute); // pasiverciame eilute i srauta is kurio galima skaityti lengviau

        string v, p;
        iss >> v >> p;
        laikinas.setVardas(v);
        laikinas.setPavarde(p);

        int pazymiai;

        while (iss >> pazymiai)
        { // kol yra skaiciu tol skaitome
            laikinas.setPazs(pazymiai);
        }

        if (!laikinas.getPaz().empty())
        {
            laikinas.setEgz(laikinas.getPaz().back());
            laikinas.getPaz().pop_back();
        }
        else
        {
            cout << "Error: Vector is empty." << endl;
        }
        // skaiciuojamas galutinis balas
        laikinas.calculateRez(vm_pasirinkimas);

        grupe.push_back(laikinas);
    }

    duomenys.close();
}
