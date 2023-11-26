//#include "my_lib.h";
/////
//void read_from_file_vec(const string& filename, vector<studentas_vec>& grupe)
//{
//    std::ifstream file(filename); //naudoti failo pavadinima
//    studentas_vec Laik;
//
//    if (!file.is_open()) {
//        cout << "Klaida atidarant faila ";
//        return;
//    }
//
//    std::string dummyLine;
//    getline(file, dummyLine);
//    while (file >> Laik.pavarde >> Laik.vardas) { //ziuri kol yra mokiniu kuriuos galima nuskaityt
//        std::string line;
//        getline(file, line); //nuskaito eilute
//        std::istringstream iss(line);
//        int nd;
//        std::vector<int> temp;
//        while (iss >> nd) { //nuskaito pazymius is eilutes i laikina vektoriu
//            temp.push_back(nd);
//        }
//        for (int i = 0; i < temp.size() - 1; i++) {
//            Laik.nd_pazymiai.push_back(temp[i]); //is laikino vektoriaus perkelia i studento pazymiu vektoriu iki priespaskutinio
//        }
//        Laik.egz = temp.back();  //paskutini pazimi padaro egzamino pazymiu
//        Laik.galutinis_vidurkis = galutinisV_vec(Laik); // su vidurkiu
//        grupe.push_back(Laik);
//        Laik.nd_pazymiai.clear();
//    }
//
//    file.close();
//}
//
//bool pagalVidurki_vec(studentas_vec& a, studentas_vec& b) {
//    return a.galutinis_vidurkis < b.galutinis_vidurkis;
//}
//
//float galutinisV_vec(studentas_vec& stud) {
//    int pazimiu_suma = 0;
//    float vidurkis;
//    float galutinis_vidurkis;
//
//    for (int pazimys : stud.nd_pazymiai) {
//        pazimiu_suma += pazimys;
//    }
//
//    if (stud.nd_pazymiai.size() == 0) {
//        vidurkis = 0.0f; // 0 jei tuscias vektorius
//    }
//    else {
//        vidurkis = static_cast<float>(pazimiu_suma) / stud.nd_pazymiai.size();
//    }
//
//    galutinis_vidurkis = 0.4 * vidurkis + 0.6 * stud.egz;
//
//    return suapvalink(galutinis_vidurkis);
//}
//
//void testFileSizes_vec1() {
//    std::vector<std::string> filenames = {
//           "Studentai1000.txt",
//           "Studentai10000.txt",
//           "Studentai100000.txt",
//           "Studentai1000000.txt"
//           //"Studentai10000000.txt"
//    };
//
//    for (const std::string& filename : filenames) {
//        std::vector<studentas_vec> grupe;
//        std::vector<long> durations_split;
//
//        for (int i = 0; i < 1; ++i) {  // 3 kart kartojam kiekvienam failui
//
//            read_from_file_vec(filename, grupe);
//
//            for (studentas_vec& Laikinas : grupe) {
//                Laikinas.galutinis_vidurkis = galutinisV_vec(Laikinas);
//                Laikinas.nd_pazymiai.clear();
//            }
//
//            sort(grupe.begin(), grupe.end(), pagalVidurki_vec);
//
//            auto start_time = std::chrono::high_resolution_clock::now();
//            start_time = std::chrono::high_resolution_clock::now();
//            pair<vector<studentas_vec>, vector<studentas_vec>> dvi_grupes = gudruciai_vargsiukai_vec(grupe);
//            vector<studentas_vec> gudrociai = dvi_grupes.first;
//            vector<studentas_vec> vargsiukai = dvi_grupes.second;
//            auto end_time = std::chrono::high_resolution_clock::now();
//            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//            durations_split.push_back(duration.count());
//
//            start_time = std::chrono::high_resolution_clock::now();
//            iraso_faila_vec(gudrociai, "gudrociai_bim.txt");
//            iraso_faila_vec(vargsiukai, "vargsiukai_bam.txt");
//
//
//            gudrociai.clear();
//            vargsiukai.clear();
//        }
//
//        double avg_split = rezultatai_vec(durations_split);
//
//        // Print the average times for each operation and each file size
//        cout << "Container - Vector, File Size: " << filename << std::endl;
//
//        cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";
//
//
//    }
//}
//
//pair<vector<studentas_vec>, vector<studentas_vec>> gudruciai_vargsiukai_vec(const vector<studentas_vec>& grupe) {
//    vector<studentas_vec> gudrociai_bim;
//    vector<studentas_vec> vargsiukai_bam;
//    for (const studentas_vec& mok : grupe) {
//        if (mok.galutinis_vidurkis < 5.0) {
//            vargsiukai_bam.push_back(mok);
//        }
//        else if (mok.galutinis_vidurkis >= 5.0) {
//            gudrociai_bim.push_back(mok);
//        }
//
//    }
//    return std::make_pair(gudrociai_bim, vargsiukai_bam);
//}
//
//void iraso_faila_vec(const vector<studentas_vec>& grupe, string file_name) {
//    ofstream outputFile(file_name);
//
//    // Check if grupe is not empty before accessing its elements
//    if (!grupe.empty()) {
//        //headeris
//        outputFile << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
//        for (int i = 1; i <= grupe[0].nd_pazymiai.size(); i++) {
//            outputFile << setw(20) << "ND" + to_string(i);
//        }
//        outputFile << setw(20) << "Egzaminas" << setw(20) << "Rezultatas" << endl;
//
//        //irasymas
//        for (const studentas_vec& mok : grupe) {
//            outputFile << left << setw(20) << mok.vardas << setw(20) << mok.pavarde;
//            for (int pazimys : mok.nd_pazymiai) {
//                outputFile << setw(20) << pazimys;
//            }
//            outputFile << setw(20) << mok.egz << setw(20) << mok.galutinis_vidurkis << endl;
//        }
//    }
//
//    outputFile.close();
//}
//
//double rezultatai_vec(const vector<long>& durations) {
//    return accumulate(durations.begin(), durations.end(), 0) / durations.size();
//}
//
//void testFileSizes_vec2() {
//    std::vector<std::string> filenames = {
//           "Studentai1000.txt",
//           "Studentai10000.txt",
//           "Studentai100000.txt",
//           "Studentai1000000.txt"
//           //"Studentai10000000.txt"
//    };
//
//    for (const std::string& filename : filenames) {
//        std::vector<studentas_vec> grupe;
//        std::vector<long> durations_split;
//
//        for (int i = 0; i < 5; ++i) {  // 5 kart kartojam kiekvienam failui
//
//            read_from_file_vec(filename, grupe);
//
//            for (studentas_vec& Laikinas : grupe) {
//                Laikinas.galutinis_vidurkis = galutinisV_vec(Laikinas);
//                Laikinas.nd_pazymiai.clear();
//            }
//
//            sort(grupe.begin(), grupe.end(), pagalVidurki_vec);
//
//            auto start_time = std::chrono::high_resolution_clock::now();
//            start_time = std::chrono::high_resolution_clock::now();
//            vector<studentas_vec> vargsiukai = gudruciai_vargsiukai_vec2(grupe);
//            auto end_time = std::chrono::high_resolution_clock::now();
//            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//            durations_split.push_back(duration.count());
//
//            start_time = std::chrono::high_resolution_clock::now();
//            iraso_faila_vec(grupe, "gudrociai_bim.txt");
//            iraso_faila_vec(vargsiukai, "vargsiukai_bam.txt");
//
//
//            grupe.clear();
//            vargsiukai.clear();
//        }
//
//        double avg_split = rezultatai_vec(durations_split);
//
//        cout << "Container - Vector, strategy 2" << std::endl;
//
//        cout << "Container - Vector, File Size: " << filename << std::endl;
//
//        cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";
//
//
//    }
//}
//
//vector<studentas_vec> gudruciai_vargsiukai_vec2(vector<studentas_vec>& grupe) {
//    vector<studentas_vec> vargsiukai_bam;
//
//    for (auto mok = grupe.begin(); mok != grupe.end();) {
//        if (mok->galutinis_vidurkis < 5.0) {
//            vargsiukai_bam.push_back(*mok);
//            mok = grupe.erase(mok); // Remove the student from grupe
//        }
//        else {
//            ++mok;
//        }
//    }
//
//    return vargsiukai_bam;
//}
//
//bool yraVargsiukas_vec(const studentas_vec& s) {
//    return s.galutinis_vidurkis < 5.0;
//}
//
//
//void testFileSizes_vec3() {
//    std::vector<std::string> filenames = {
//           "Studentai1000.txt",
//           "Studentai10000.txt",
//           "Studentai100000.txt",
//           "Studentai1000000.txt"
//           //"Studentai10000000.txt"
//    };
//
//    for (const std::string& filename : filenames) {
//        std::vector<studentas_vec> grupe;
//        std::vector<long> durations_split;
//
//        for (int i = 0; i < 5; ++i) {  // 5 kart kartojam kiekvienam failui
//
//            read_from_file_vec(filename, grupe);
//
//            for (studentas_vec& Laikinas : grupe) {
//                Laikinas.galutinis_vidurkis = galutinisV_vec(Laikinas);
//                Laikinas.nd_pazymiai.clear();
//            }
//
//            sort(grupe.begin(), grupe.end(), pagalVidurki_vec);
//
//            auto start_time = std::chrono::high_resolution_clock::now();
//            start_time = std::chrono::high_resolution_clock::now();
//            vector<studentas_vec> vargsiukai = gudruciai_vargsiukai3_vec(grupe);
//            auto end_time = std::chrono::high_resolution_clock::now();
//            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//            durations_split.push_back(duration.count());
//
//            start_time = std::chrono::high_resolution_clock::now();
//            iraso_faila_vec(grupe, "gudrociai_bim.txt");
//            iraso_faila_vec(vargsiukai, "vargsiukai_bam.txt");
//
//
//            grupe.clear();
//            vargsiukai.clear();
//        }
//
//        double avg_split = rezultatai_vec(durations_split);
//
//        cout << "Container - Vector, strategy 3" << std::endl;
//
//        cout << "Container - Vector, File Size: " << filename << std::endl;
//
//        cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";
//
//
//    }
//}
//
//vector<studentas_vec>gudruciai_vargsiukai3_vec(vector<studentas_vec>& grupe) {
//    vector<studentas_vec> vargsiukai_bam;
//
//    auto partition_point = std::partition(grupe.begin(), grupe.end(), yraVargsiukas_vec);//suskaido pagal kondicija yraVargsiukas
//    std::move(partition_point, grupe.end(), std::back_inserter(vargsiukai_bam)); //jei kondicija T permeta i vargsiukus
//    grupe.erase(partition_point, grupe.end()); // istrina is orginalaus, jei vargsiukas
//
//    return vargsiukai_bam;
//}