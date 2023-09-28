#include "my_lib.h";

void read_from_file(const string& filename, vector<studentas>& students)
{

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cout << "Error: Failas neatidaromas" << endl;
        return;
    }

    string line;
    bool firstLine = true; // praleidziam pirma eilute
    int lineCount = 0;

    while (getline(inputFile, line))
    {
        studentas student;
        std::istringstream iss(line);

        iss >> student.vardas >> student.pavarde;

        int grade;
        while (iss >> grade)
        {
            student.nd_pazymiai.push_back(grade);
        }

        
        if (!student.nd_pazymiai.empty())
        {
            student.egz = student.nd_pazymiai.back();
            student.nd_pazymiai.pop_back(); 
        }

        students.push_back(student);
    }

    inputFile.close();
}