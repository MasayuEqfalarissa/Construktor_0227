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

//menambahkan friend class dosen
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

//menambahkan friend class staff dan friend function
friend class staff;
friend float lihatgajidosen(dosen * d);
};

//fungsi friend lihatgajidosen
float lihatgajidosen(dosen * d) 
{
    return d->gaji;
}

//membuat class staff
class staff
{
private :
    string nama;
    int id;
    float gaji;

public: 
    staff (string nama, int id, float gaji);

void ubahpangkat (dosen * d, string pangkatbaru)
{
    d->pangkat = pangkatbaru;
}

//menambahkan friend function lihatgajistaff
friend float lihatgajistaff (staff * s);

void tampilkan () 
{
    cout << "staf: " << nama << "id: " << id << "gaji: " << gaji << endl;
}
};

//implementasi friend function lihatgajistaff
float lihatgajistaff (staff * s)
 {
    return s->gaji;
}

//fungsi main
int main()
{
    mahasiswa * m = new mahasiswa("lia", "2211001");
    dosen * d = new dosen ("pak budi", "199001", "lektor", 12000000);
    staff * s = new staff ("bu rina", 101, 9000000);

    d->bernilai(m, 90.5);
    m->tampilkan();
    d->tampilkan();

    s->ubahpangkat(d, "guru besar");

    cout << "\nsetelah diubah pangkat oleh staff:\n";
    d->tampilkan();
    s->tampilkan();

    cout << "\nakses gaji : \n";
    cout << "gaji dosen (via university): " << lihatgajidosen(d) << endl;
    cout << "daji staff (via university): " << lihatgajistaff(s) << endl;

    delete m;
    delete d;
    delete s;

    return 0;
}