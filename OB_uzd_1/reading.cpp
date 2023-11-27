#include "my_lib.h";

void read_from_file_vec_c(vector<Studentas>& grupe, const string& duom_vard)
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

        std::istringstream iss(eilute); // pasiverciame eilute i srauta is kurio galima skaityti lengviau

        // Use read_Student to read the data directly into the Studentas object
        laikinas.read_Student(iss);

        // skaiciuojamas galutinis balas
        laikinas.suskaiciuojaRez(); // Assuming this method calculates the final result

        grupe.push_back(laikinas);
    }

    duomenys.close();
}
