#include <iostream>
#include <string>
using namespace std;

//class mahasiswa
class mahasiswa 
{
private :
    string nama;
    string nim;
    float nilai;

public :
    mahasiswa (string nanam, string nim);

void tampilkan () 
{
    cout << "mahasiswa: " << this->nama << "nim: " << this-> nim << "nilai: " << this->nilai << endl;
}

friend class dosen;
};

//membuat class dosen
class dosen 
{
private :
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public: 
    dosen(string nama, string NIDN, string pangkat, float gaji);

void bernilai(mahasiswa * m, float n) {
    m-> nilai = n;
}

void tampilkan() 
{
    cout << "dosen: " << nama << "NIDN: " << NIDN << "pangkat: " << pangkat << "gaji: " << gaji << endl;
}

friend class staff;
friend float lihatgajidosen(dosen * d);
};