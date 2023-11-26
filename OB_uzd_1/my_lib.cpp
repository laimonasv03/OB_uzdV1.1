//#include "my_lib.h";
//
//list<int> input_vector() {
//	list<int> data;
//
//	int i = 0;
//	int pazimys = 0;
//	cout << "Ivesk -1 kai baigsi vesti namu darbu pazymius" << endl;
//	while (true) {
//		cout << i << "_nd pazimys: " << " ";
//		cin >> pazimys;
//		if (pazimys == -1) break;
//		data.push_back(pazimys);
//		i++;
//	}
//	return data;
//}
//
//float suapvalink(float value) {
//	
//	return round(value * 100) / 100;
//}
//
//Studentas input_data() {
//	Studentas studentas;
//	int egz;
//	int pasirinkimas;
//	int n_paz;
//
//	cout << "Ar nori, kad nd_pazymiai bei egzamino balas butu sugeneruoti atsitiktinai?\n(ivesk viena is skaiciu)" << endl;
//	cout << "1. Ne\n2. taip\n";
//	patikrink(pasirinkimas);
//	if(pasirinkimas == 1){
//	cout << "Ivesk studento Varda: ";
//	cin >> studentas.vardas;
//	cout << "Ivesk studento Pavarde: ";
//	cin >> studentas.pavarde;
//	cout << "Ivesk egzamino rezultata (sveikas skaicius): ";
//	cin >> studentas.egz;
//
//	studentas.nd_pazymiai = input_vector();
//	}
//	else if (pasirinkimas == 2) {
//		cout << "Ivesk studento Varda: ";
//		cin >> studentas.vardas;
//		cout << "Ivesk studento Pavarde: ";
//		cin >> studentas.pavarde;
//		cout << "Ivesk sveika skaiciu, nurodanti nd pazymiu kieki: " << " ";
//		cin >> n_paz;
//		for (int i = 0; i < n_paz; ++i) {
//			studentas.nd_pazymiai.push_back(atsitiktinis());
//		}
//		studentas.egz = atsitiktinis();
//	}
//	return Studentas;
//}
//
//
//
//float galutinisV(studentas& stud) {
//	int pazimiu_suma = 0;
//	float vidurkis;
//	float galutinis_vidurkis;
//
//	for (int pazimys : stud.nd_pazymiai) {
//		pazimiu_suma += pazimys;
//	}
//
//	if (stud.nd_pazymiai.empty()) {
//		vidurkis = 0.0f; // 0 jei listas tuscias
//	}
//	else {
//		vidurkis = static_cast<float>(pazimiu_suma) / stud.nd_pazymiai.size();
//	}
//
//	galutinis_vidurkis = 0.4 * vidurkis + 0.6 * stud.egz;
//
//	return suapvalink(galutinis_vidurkis);
//}
//
//float galutinisM(studentas& stud) {
//	list<int> listas = stud.nd_pazymiai;
//	listas.sort(); //issirusiuojam
//
//	int ilgis = listas.size();
//	float mediana;
//	float galutinis_mediana;
//
//	if (ilgis % 2 == 0) { // jei lyginis mediana is 2 viduriniu
//		auto it1 = std::next(listas.begin(), ilgis / 2 - 1);
//		auto it2 = std::next(listas.begin(), ilgis / 2);
//		mediana = (*it1 + *it2) / 2.0;
//	}
//	else { // vidurinis, jei nelyginis
//		auto it = std::next(listas.begin(), ilgis / 2);
//		mediana = *it;
//	}
//
//	galutinis_mediana = 0.4 * mediana + 0.6 * stud.egz;
//	return galutinis_mediana;
//}
//
//int atsitiktinis() {
//	random_device rd; //random generator
//	uniform_int_distribution<int> dist(1, 10); //intervalas
//	return dist(rd);
//}
//
//void printTableMed(const list<studentas>& grupe) {
//	// Print column headers
//	cout << "+---------------------+---------------------+-------------------+\n";
//	cout << "| " << left << setw(20) << "Pavarde" << "| " << setw(20) << "Vardas" << "| " << setw(18) << "Galutinis(med.)" << "|\n";
//	cout << "+---------------------+---------------------+-------------------+\n";
//
//	// Print student data
//	for (const studentas& student : grupe) {
//		cout << "| " << left << setw(20) << student.pavarde << "| " << setw(20) << student.vardas << "| " << setw(18) << student.galutinis_mediana << "|\n";
//		cout << "+---------------------+---------------------+-------------------+\n";
//	}
//}
//
//void printTableVid(const list<studentas>& grupe) {
//	cout << "+---------------------+---------------------+-------------------+\n";
//	cout << "| " << left << setw(20) << "Pavarde" << "| " << setw(20) << "Vardas" << "| " << setw(18) << "Galutinis(v1d.)" << "|\n";
//	// Print student data
//	for (const studentas& student : grupe) {
//		cout << "| " << left << setw(20) << student.pavarde << "| " << setw(20) << student.vardas << "| " << setw(18) << student.galutinis_vidurkis << "|\n";
//		cout << "+---------------------+---------------------+-------------------+\n";
//	}
//}
//
//bool palygintiPavarde(studentas& a, studentas& b) {
//	return a.pavarde < b.pavarde;
//}
//
//bool palygintiVarda(studentas& a, studentas& b) {
//	return a.pavarde < b.pavarde;
//}
//
//bool palygintiRez(studentas& a, studentas& b) {
//	return a.rez < b.rez;
//}

//void patikrink(int& value) {
//	while (!(std::cin >> value) || (value != 1 && value != 2 && value != 3 && value != 4 && value != 5)) {
//		std::cout << "Ivedei netinkama skaiciu, ivesk 1,2,3 arba 4 " << endl;
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	}
//}
//
//void patikrink_daug(int& value) {
//	while (!(std::cin >> value)) {
//		std::cout << "Ivedei netinkama skaiciu, ivesk sveika skaiciu " << endl;
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	}
//}

//void generuoja_sarasa(int& n, string file_name) {
//	list<string> data;
//	data.push_back("Vardas\t\tPavarde\t\tND1\tND2\tND3\tND4\tND5\tND6\tND7\tND8\tND9\tND10\tND11\tND12\tND13\tND14\tND15\tEgz");
//
//	for (int i = 1; i <= n; i++) {
//		string irasas;
//		irasas = "Vardenis" + to_string(i) + "\tPavardenis" + to_string(i);
//
//		for (int j = 0; j < 16; ++j) {
//			int pazimys = atsitiktinis();
//			irasas += "\t" + to_string(pazimys);
//		}
//
//		data.push_back(irasas);
//	}
//
//	ofstream outputFile(file_name);
//	for (const string& irasas : data) {
//		outputFile << irasas << endl;
//	}
//	outputFile.close();
//}
//
//pair<list<studentas>, list<studentas>> gudruciai_vargsiukai(const list<studentas>& grupe) {
//	list<studentas> gudrociai_bim;
//	list<studentas> vargsiukai_bam;
//	for (const studentas& mok : grupe) {
//		if (mok.galutinis_vidurkis < 5.0) {
//			vargsiukai_bam.push_back(mok);
//		}
//		else if (mok.galutinis_vidurkis >= 5.0) {
//			gudrociai_bim.push_back(mok);
//		}
//
//	}
//	return std::make_pair(gudrociai_bim, vargsiukai_bam);
//}
//
//
//
//void iraso_faila(const list<studentas>& grupe, string file_name) {
//	ofstream outputFile(file_name);
//
//	if (!grupe.empty()) {
//		// Header
//		outputFile << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
//		for (int i = 1; i <= grupe.front().nd_pazymiai.size(); i++) {
//			outputFile << setw(20) << "ND" + to_string(i);
//		}
//		outputFile << setw(20) << "Egzaminas" << setw(20) << "Rezultatas" << endl;
//
//		// Writing data
//		for (const studentas& mok : grupe) {
//			outputFile << left << setw(20) << mok.vardas << setw(20) << mok.pavarde;
//			for (int pazimys : mok.nd_pazymiai) {
//				outputFile << setw(20) << pazimys;
//			}
//			outputFile << setw(20) << mok.egz << setw(20) << mok.galutinis_vidurkis << endl;
//		}
//	}
//
//	outputFile.close();
//}
//
//
//void iraso_faila_be_galutinio(const list<studentas>& grupe, string file_name) {
//	ofstream outputFile(file_name);
//
//	if (!grupe.empty()) {
//		// Header
//		outputFile << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
//		for (int i = 1; i <= grupe.front().nd_pazymiai.size(); i++) {
//			outputFile << setw(20) << "ND" + to_string(i);
//		}
//		outputFile << setw(20) << "Egzaminas" << setw(20) << endl;
//
//		// Writing data
//		for (const studentas& mok : grupe) {
//			outputFile << left << setw(20) << mok.vardas << setw(20) << mok.pavarde;
//			for (int pazimys : mok.nd_pazymiai) {
//				outputFile << setw(20) << pazimys;
//			}
//			outputFile << setw(20) << mok.egz << setw(20) << endl;
//		}
//	}
//
//	outputFile.close();
//}
//
//
//double rezultatai(const list<long>& durations) {
//	return accumulate(durations.begin(), durations.end(), 0) / durations.size();
//}
//
//void testFileSizes() {
//	std::list<std::string> filenames = {
//		   "Studentai1000.txt",
//		   "Studentai10000.txt",
//		   "Studentai100000.txt",
//		   "Studentai1000000.txt",
//		   "Studentai10000000.txt"
//	};
//
//	for (const std::string& filename : filenames) {
//		std::list<studentas> grupe;
//		std::list<long> durations_read;
//		std::list<long> durations_sort;
//		std::list<long> durations_split;
//		std::list<long> durations_write;
//		std::list<long> durations_process;
//
//		for (int i = 0; i < 5; ++i) {  // 3 kart kartojam kiekvienam failui
//			auto start_time = std::chrono::high_resolution_clock::now();
//			read_from_file(filename, grupe);
//			auto end_time = std::chrono::high_resolution_clock::now();
//			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_read.push_back(duration.count());
//
//			start_time = std::chrono::high_resolution_clock::now();
//			for (studentas& Laikinas : grupe) {
//				Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
//				Laikinas.nd_pazymiai.clear();
//			}
//			end_time = std::chrono::high_resolution_clock::now();
//			duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_process.push_back(duration.count());
//
//			start_time = std::chrono::high_resolution_clock::now();
//			grupe.sort(palygintiVidurki);
//			end_time = std::chrono::high_resolution_clock::now();
//			duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_sort.push_back(duration.count());
//
//			start_time = std::chrono::high_resolution_clock::now();
//			pair<list<studentas>, list<studentas>> dvi_grupes = gudruciai_vargsiukai(grupe);
//			list<studentas> gudrociai = dvi_grupes.first;
//			list<studentas> vargsiukai = dvi_grupes.second;
//			end_time = std::chrono::high_resolution_clock::now();
//			duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_split.push_back(duration.count());
//
//			start_time = std::chrono::high_resolution_clock::now();
//			iraso_faila(gudrociai, "gudrociai_bim.txt");
//			iraso_faila(vargsiukai, "vargsiukai_bam.txt");
//			end_time = std::chrono::high_resolution_clock::now();
//			duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_write.push_back(duration.count());
//
//			gudrociai.clear();
//			vargsiukai.clear();
//		}
//
//		double avg_read = rezultatai(durations_read);  // vidurkis
//		double avg_sort = rezultatai(durations_sort); 
//		double avg_split = rezultatai(durations_split); 
//		double avg_write = rezultatai(durations_write); 
//		double avg_process = rezultatai(durations_process); 
//
//		// Print the average times for each operation and each file size
//		cout << "File Size: " << filename << std::endl;
//		cout << "Vidutinis skaitymo laikas: " << avg_read / 1000.0 << " seconds\n";
//		cout << "Vidutinis rusiavimo laikas: " << avg_sort / 1000.0 << " seconds\n";
//		cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";
//		cout << "Vidutinis irasymo laikas: " << avg_write / 1000.0 << " seconds\n";
//		cout << "Vidutinis apdorojimo laikas(suskaiciuoja vidurki): " << avg_process / 1000.0 << " seconds\n";
//		cout << "failo vieta" << endl;
//	}
//}
//
//void read_from_file(const string& filename, list<studentas>& students)
//{
//	ifstream inputFile(filename);
//
//	try {
//		if (filename.empty())
//		{
//			throw std::invalid_argument::invalid_argument("Error: nera failo nuorodos.");
//		}
//
//		if (!inputFile.is_open())
//		{
//			throw runtime_error("Error: failo negalima atidaryti.");
//		}
//
//		string line;
//		bool firstLine = true; // Skip the first line with headers
//		int lineCount = 0;
//
//		while (getline(inputFile, line))
//		{
//			++lineCount;
//
//			if (firstLine)
//			{
//				firstLine = false;
//				continue; // Skip the header line
//			}
//
//			studentas student;
//			std::istringstream iss(line);
//			string name, surname;
//			int mark;
//
//			iss >> student.vardas >> student.pavarde;
//
//			while (iss >> mark)
//			{
//				student.nd_pazymiai.push_back(mark);
//			}
//
//			// Assign the last value in marks as the exam mark
//			if (!student.nd_pazymiai.empty())
//			{
//				student.egz = student.nd_pazymiai.back();
//				student.nd_pazymiai.pop_back(); // Remove the last element from marks
//			}
//
//			if (iss.eof())
//			{
//				iss.clear();
//				iss >> student.egz;
//			}
//
//			students.push_back(student);
//		}
//
//		inputFile.close();
//	}
//	catch (const std::invalid_argument& e) {
//		std::cerr << e.what() << endl;
//		cout << "nera failo nuorodos." << endl;
//	}
//	catch (const runtime_error& e) {
//		std::cerr << e.what() << endl;
//		cout << "Error'as atidarant faila: " << e.what() << endl;
//	}
//}
//
//
//bool palygintiVidurki(const studentas& a, const studentas& b) {
//	return a.galutinis_vidurkis < b.galutinis_vidurkis;
//}
//
//bool palygintiMediana(const studentas& a, const studentas& b) {
//	return a.galutinis_mediana < b.galutinis_mediana;
//}
//
//void testFileSizes_list1() {
//	std::list<std::string> filenames = {
//		   "Studentai1000.txt",  
//		   "Studentai10000.txt",
//		   "Studentai100000.txt",
//		   "Studentai1000000.txt"
//		   //"Studentai10000000.txt"
//	};
//
//	for (const std::string& filename : filenames) {
//		std::list<studentas> grupe;
//		std::list<long> durations_split;
//
//		for (int i = 0; i < 5; ++i) {  // 5 kart kartojam kiekvienam failui
//			
//			read_from_file(filename, grupe);
//
//			for (studentas& Laikinas : grupe) {
//				Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
//				Laikinas.nd_pazymiai.clear();
//			}
//
//			grupe.sort(palygintiVidurki);
//
//			auto start_time = std::chrono::high_resolution_clock::now();
//			start_time = std::chrono::high_resolution_clock::now();
//			pair<list<studentas>, list<studentas>> dvi_grupes = gudruciai_vargsiukai(grupe);
//			list<studentas> gudrociai = dvi_grupes.first;
//			list<studentas> vargsiukai = dvi_grupes.second;
//			auto end_time = std::chrono::high_resolution_clock::now();
//			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_split.push_back(duration.count());
//
//			start_time = std::chrono::high_resolution_clock::now();
//			iraso_faila(gudrociai, "gudrociai_bim.txt");
//			iraso_faila(vargsiukai, "vargsiukai_bam.txt");
//
//
//			gudrociai.clear();
//			vargsiukai.clear();
//		}
//
//		double avg_split = rezultatai(durations_split);
//
//		// Print the average times for each operation and each file size
//		cout << "Container - List, strategy 1" << std::endl;
//		cout << "Container - List, File Size : " << filename << std::endl;
//		
//		cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";
//		
//		
//	}
//}
//
//
//
//
//list<studentas> gudruciai_vargsiukai2(std::list<studentas>& grupe) {
//	list<studentas> vargsiukai_bam;
//
//	for (auto mok = grupe.begin(); mok != grupe.end();) {
//		if (mok->galutinis_vidurkis < 5.0) {
//			vargsiukai_bam.push_back(*mok);
//			mok = grupe.erase(mok); // Remove the student from grupe
//		}
//		else {
//			++mok;
//		}
//	}
//
//	return vargsiukai_bam;
//}
//
//
//void testFileSizes_list2() {
//	std::list<std::string> filenames = {
//		   "Studentai1000.txt",
//		   "Studentai10000.txt",
//		   "Studentai100000.txt",
//		   "Studentai1000000.txt"
//		   //"Studentai10000000.txt"
//	};
//
//	for (const std::string& filename : filenames) {
//		std::list<studentas> grupe;
//		std::list<long> durations_split;
//
//		for (int i = 0; i < 5; ++i) {  // 5 kart kartojam kiekvienam failui
//
//			read_from_file(filename, grupe);
//
//			for (studentas& Laikinas : grupe) {
//				Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
//				Laikinas.nd_pazymiai.clear();
//			}
//
//			grupe.sort(palygintiVidurki);
//
//			auto start_time = std::chrono::high_resolution_clock::now();
//			start_time = std::chrono::high_resolution_clock::now();
//			list<studentas> vargsiukai = gudruciai_vargsiukai2(grupe);
//			auto end_time = std::chrono::high_resolution_clock::now();
//			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_split.push_back(duration.count());
//
//			start_time = std::chrono::high_resolution_clock::now();
//			iraso_faila(grupe, "gudrociai_bim.txt");
//			iraso_faila(vargsiukai, "vargsiukai_bam.txt");
//
//			grupe.clear();
//			vargsiukai.clear();
//		}
//
//		double avg_split = rezultatai(durations_split);
//
//		// Print the average times for each operation and each file size
//		cout << "Container - List, strategy 2" << std::endl;
//		cout << "Container - List, File Size : " << filename << std::endl;
//		cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";
//
//
//	}
//}
//
//
//void testFileSizes_list3() {
//	std::list<std::string> filenames = {
//		   "Studentai1000.txt",
//		   "Studentai10000.txt",
//		   "Studentai100000.txt",
//		   "Studentai1000000.txt"
//		   //"Studentai10000000.txt"
//	};
//
//	for (const std::string& filename : filenames) {
//		std::list<studentas> grupe;
//		std::list<long> durations_split;
//
//		for (int i = 0; i < 5; ++i) {  // 5 kart kartojam kiekvienam failui
//
//			read_from_file(filename, grupe);
//
//			for (studentas& Laikinas : grupe) {
//				Laikinas.galutinis_vidurkis = galutinisV(Laikinas);
//				Laikinas.nd_pazymiai.clear();
//			}
//
//			grupe.sort(palygintiVidurki);
//
//			auto start_time = std::chrono::high_resolution_clock::now();
//			start_time = std::chrono::high_resolution_clock::now();
//			list<studentas> vargsiukai = gudruciai_vargsiukai3(grupe);
//			auto end_time = std::chrono::high_resolution_clock::now();
//			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//			durations_split.push_back(duration.count());
//
//			start_time = std::chrono::high_resolution_clock::now();
//			iraso_faila(grupe, "gudrociai_bim.txt");
//			iraso_faila(vargsiukai, "vargsiukai_bam.txt");
//
//			grupe.clear();
//			vargsiukai.clear();
//		}
//
//		double avg_split = rezultatai(durations_split);
//
//		// Print the average times for each operation and each file size
//		cout << "Container - List, strategy 3" << std::endl;
//		cout << "Container - List, File Size : " << filename << std::endl;
//		cout << "Vidutinis isskirstymo i 2 grupes laikas: " << avg_split / 1000.0 << " seconds\n";
//
//
//	}
//}
//
//bool yraVargsiukas(const studentas& s) {
//	return s.galutinis_vidurkis < 5.0;
//}
//
//list<studentas>gudruciai_vargsiukai3(list<studentas>& grupe) {
//	list<studentas> vargsiukai_bam;
//
//	auto partition_point = std::partition(grupe.begin(), grupe.end(), yraVargsiukas);//suskaido pagal kondicija yraVargsiukas
//	std::move(partition_point, grupe.end(), std::back_inserter(vargsiukai_bam)); //jei kondicija T permeta i vargsiukus
//	grupe.erase(partition_point, grupe.end()); // istrina is orginalaus, jei vargsiukas
//
//	return vargsiukai_bam;
//}
