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
};