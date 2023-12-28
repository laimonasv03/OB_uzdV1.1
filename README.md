**In release v2**
Doxygen documentation  was created

**In release v1.5**
Sukurta abstrakti klase zmogus, norint pademonstruoti, kad negalima sukurti obijekto Zmogus, atkomentuoti Zmogus zmogus1 dali

```cpp
if (vesti_nuskaityti == 4) {
	//Zmogus zmogus1; //Atkomentuoti norint pademonstruoti neveikima
	Zmogus::CannotCreateObject();
}
```

Studentas klase dabar yra isvestine (derived) is Zmogaus 

Programa veiksni v1.2 logika



**In release  v1.2**
Implemetuota Rule of three

Studento klase turi: 5 Konstruktorius: Default, Ivedant su parametrais, nuskaitant is failo

Copy konstruktorius - sukuriamas naujas obijektas (Studentas) su jau sukuro atributais 

Copy assignment - jau esancio obijekto(Studento) reiksmes priskiriamos kitam jau sukurtam Studento obijektui

**Perdengti metodai**:
ivesties istream& operator>> perdengimas leidizia ranka vartotojui irasyti studento varda bei pavarde formatu {vardas} {pavarde} naudojamisetVardas bei setPavarde 

isvesties leidzia isvesti studenta << operatoriumi implementacijoje naudojami getVardas getPavarde

Defaul konstruktorius priskiria default reiksmias

Konstruktorius Studentas(string vardasC, string pavardeC, int egzC, double galutinisRez, vector<int> ndC) priskiria irasytas reiksmias

Studentas(std::istream& is) nuskaito is failo

Metodas writeToFile iraso studenta i faila
**In release v1.1**



**In release v1.0** 
CMake 

testing different strategys on different containers

CPU - AMD Ryzen 5 5600H with Radeon Graphics, 3301 Mhz, 6 Core(s), 12 Logical Processor(s)
GPU - NVIDIA GeForce RTX 3050 Laptop GPU
RAM - 16GB

| Container | File Size | Strategy 1 | Strategy 2 | Strategy 3 |
|-----------|-----------|------------|------------|------------|
| List      | 1000      | 0.013      | 0.002      | 0.002      |
| List      | 10000     | 0.128      | 0.03       | 0.03       |
| List      | 100000    | 1.149      | 0.334      | 0.351      |
| List      | 1000000   | N/A        | 3.85       | 4.019      |
| Vector    | 1000      | 0.019      | 0.247      | 0.009      |
| Vector    | 10000     | 0.208      | 27.963     | 0.107      |
| Vector    | 100000    | 1.515      | N/A        | 0.635      |
| Vector    | 1000000   | 16.76      | N/A        | 7.089      |

﻿

instructions:
after cloning repo, run provided commands from RUNME txt document to powershell

**In release v1.1** 
CMake 
Studentas structure was implemented as a class
testing v3 strategy (stored in vector, students meeting condition argsiukai are erased from original and writen to a new one) with class and structure

CPU - AMD Ryzen 5 5600H with Radeon Graphics, 3301 Mhz, 6 Core(s), 12 Logical Processor(s)
GPU - NVIDIA GeForce RTX 3050 Laptop GPU
RAM - 16GB

| Container | File Size |  Structure 1 | Class | 
|-----------|-----------|------------|------------|
| Vector    | 100000    | 1.515      |        0.318 | 
| Vector    | 1000000   | 16.76      | 4.618       | 
