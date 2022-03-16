#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class buget {
public:
    buget(int nevoi, int dorinte);
    buget();
    buget(const buget&);
    ~buget();
    void set_nevoi(int nevoi);
    void set_dorinte(int dorinte);
    int get_nevoi();
    int get_dorinte();
    friend int buget_total(buget b1);
    friend istream& operator >> (istream& stream, buget& buget);
    friend ostream& operator << (ostream& stream, buget& buget);
    friend buget operator + (buget b1, buget b2);
    friend buget operator - (buget b1, buget b2);
    buget& operator += (const buget& b1);
    buget& operator -= (const buget& b1);
    friend bool operator ==(buget b1, buget b2);
    friend bool operator !=(buget b1, buget b2);
    friend bool operator <(buget b1, buget b2);
    friend bool operator >(buget b1, buget b2);
private:
    int nevoi;
    int dorinte;
};


buget::buget() {
}

buget::buget(int nevoi, int dorinte) {
   this->nevoi = nevoi;
   this->dorinte = dorinte;

}

buget::buget(const buget& b) {
    nevoi = b.nevoi;
    dorinte = b.dorinte;
}

buget::~buget() {
    this->nevoi = 0;
    this->dorinte = 0;
}

 
void buget::set_nevoi(int nevoi) {
    this->nevoi = nevoi;
}

void buget::set_dorinte(int dorinte) {
    this->dorinte = dorinte;
}

int buget::get_dorinte() {
    return this->dorinte;
}

int buget::get_nevoi() {
    return this->nevoi;
}


buget operator + (buget b1, buget b2) {
    buget b3;
    b3.nevoi = b1.nevoi + b2.nevoi;
    b3.dorinte = b1.dorinte + b2.dorinte;
    return b3;
}

buget operator - (buget b1, buget b2) {
    buget b3;
    b3.nevoi = b1.nevoi - b2.nevoi;
    b3.dorinte = b1.dorinte - b2.dorinte;
    return b3;
}

istream& operator >> (istream& stream, buget& buget) {
    stream >> buget.nevoi >> buget.dorinte;
    return stream;
}

ostream& operator << (ostream& stream, buget& buget) {
    stream << buget.nevoi << " " << buget.dorinte;
    return stream;
}

bool operator ==(buget b1, buget b2) {
    if (b1.nevoi == b2.nevoi)
        if (b1.dorinte == b2.dorinte)
            return 1;
    return 0;
}

bool operator !=(buget b1, buget b2) {
    if (b1.nevoi != b2.nevoi)
        if (b1.dorinte != b2.dorinte)
            return 1;
    return 0;
}

bool operator <(buget b1, buget b2) {
    if (buget_total(b1) < buget_total(b2))
        return 1;
    return 0;
}

bool operator >(buget b1, buget b2) {
    if (buget_total(b1)> buget_total(b2))
        return 1;
    return 0;
}

buget& buget:: operator +=(const buget& b1)
{
    nevoi = b1.nevoi + nevoi;
    dorinte = b1.dorinte + dorinte;
    return * this;
}

buget& buget :: operator -=(const buget & b1) {
    nevoi = nevoi - b1.nevoi;
    dorinte = dorinte - b1.dorinte;
    return *this;
}

int buget_total(buget b1) {
    return b1.dorinte + b1.nevoi;
}




class persoana {
public:
    persoana(buget b,string nume,int salariu);
    persoana(const persoana&);
    persoana();
    ~persoana();
    void set_b(buget);
    void set_nume(string);
    void set_salariu(int);
    string get_nume();
    int get_salariu();
    buget get_b();
    friend void ordonare_buget(vector<persoana>& grup);
    friend void ordonare_salariu(vector<persoana>& grup);
    friend persoana castigator_loto(vector<persoana>& grup);
    friend istream& operator >> (istream& stream, persoana& persoana);
    friend ostream& operator << (ostream& stream, persoana& persoana);
    friend persoana operator +(persoana p1, persoana p2);
    friend persoana operator -(persoana p1, persoana p2);
    persoana& operator +=(const persoana& p1);
    persoana& operator -=(const persoana& p1);
    friend bool operator ==(persoana p1, persoana p2);
    friend bool operator !=(persoana p1, persoana p2);
private:
    buget b;
    string nume;
    int salariu;
};

persoana::persoana(buget b,string nume,int salariu) {
    this->nume = nume;
    this->b = b;
    this->salariu = salariu;
}

persoana::persoana(const persoana& persoana) {
    nume = persoana.nume;
    b = persoana.b;
    salariu = persoana.salariu;

}

persoana::persoana() {}

persoana::~persoana() {
    this->nume = "";
    this->b.~buget();
    this->salariu = 0;
}

int persoana::get_salariu()
{
    return this->salariu;
}

string persoana::get_nume() {
    return this->nume;
}

buget persoana::get_b() {
    return this->b;
}


void persoana::set_nume(string nume) {
    this->nume = nume;
}


void persoana::set_salariu(int salariu) {
    this->salariu =salariu;
}

void persoana::set_b(buget b) {
    this->b = b;
}

istream& operator >> (istream& stream, persoana& persoana) {
    stream >> persoana.b >> persoana.nume >> persoana.salariu;
    return stream;
}

ostream& operator << (ostream& stream, persoana& persoana) {
    stream << persoana.b << " " << persoana.nume << " " << persoana.salariu;
    return stream;
}

persoana operator +(persoana p1, persoana p2) {
    persoana p3;
    p3.nume = "";
    p1.nume.push_back('+');
    p1.nume.append(p2.nume);
    p3.nume = p1.nume;
    p3.b = p1.b + p2.b;
    p3.salariu = p1.salariu + p2.salariu;
    return p3;
}


persoana operator -(persoana p1, persoana p2) {
    persoana p3;
    p3.nume = "";
    p1.nume.push_back('-');
    p1.nume.append(p2.nume);
    p3.nume = p1.nume;
    p3.b = p1.b-p2.b;
    p3.salariu = p1.salariu - p2.salariu;
    return p3;
}
bool operator ==(persoana p1, persoana p2) {
    if (p1.b == p2.b)
        if (p1.salariu == p2.salariu)
            return 1;
    return 0;
}

bool operator !=(persoana p1, persoana p2) {
    if (p1.b != p2.b)
        if (p1.salariu != p2.salariu)
            return 1;
    return 0;
}

persoana& persoana:: operator+=(const persoana& p1) {
    b = b + p1.b;
    nume.push_back('+');
    nume.append(p1.nume);
    salariu = salariu + p1.salariu;
    return * this;
}

persoana& persoana :: operator-=(const persoana& p1) {
    b = b - p1.b;
    nume.push_back('-');
    nume.append(p1.nume);
    salariu = salariu - p1.salariu;
    return *this;
}


void ordonare_salariu(vector<persoana>& grup) {
    int i, j;
    for (i = 0; i < grup.size() - 1; i++)
        for (j = i; j < grup.size(); j++)
            if (grup[j].salariu < grup[i].salariu)
                swap(grup[j], grup[i]);
 }


void ordonare_buget(vector<persoana>& grup) {
    int i, j;
    for (i = 0; i < grup.size() - 1; i++)
        for (j = i; j < grup.size(); j++)
            if (grup[j].b < grup[i].b)
                swap(grup[j], grup[i]);
}

persoana castigator_loto(vector<persoana>& grup) {
    srand(time(NULL));
    int i;
    int castigator = rand() % grup.size();
    for (i = 0; i < grup.size(); i++)
        if (i == castigator)
        {
            grup[i].salariu = 0;
            grup[i].b.set_dorinte(1000000);
  

            return grup[i];
        }
}
int main()
{
    int i, numar_persoane = 5;
    vector<persoana> grup;
    buget b1, b2, b3, b4, b5, b_max, b_min;
    persoana p, castigator;
   
    for (i = 0; i < numar_persoane; i++)
    {
        cin >> p;
        grup.push_back(p);
    }
    ordonare_salariu(grup);
    cout << "Persoana cu cel mai mare salariu este " << grup[numar_persoane - 1].get_nume()
        << " si are salariul de " << grup[numar_persoane - 1].get_salariu() << "\n";

    cout << "Persoana cu cel mai mic salariu este " << grup[0].get_nume()
        << " si are salariul de " << grup[0].get_salariu() << "\n";

    ordonare_buget(grup);

    cout << "Persoana cu cel mai mare buget este " << grup[numar_persoane - 1].get_nume()
        << " si are bugetul de " << buget_total(grup[numar_persoane - 1].get_b()) << "\n";


    cout << "Persoana cu cel mai mic buget este " << grup[0].get_nume()
        << " si are bugetul de " << buget_total(grup[0].get_b()) << "\n";
    

    castigator = castigator_loto(grup);
    cout << "Castigatorul la loto este " << castigator.get_nume() << "\n" << castigator << "\n";


    buget buget_grup = buget(0,0);
    for (i = 0; i < grup.size(); i++)
        if (grup[i] != castigator)
        buget_grup = grup[i].get_b() + buget_grup;
    buget dif = castigator.get_b() - buget_grup;
    

    cout << "Diferenta dintre bugetul restului grpului si castigator este de " << dif;
    
    cout << "\n" << "\n" << "\n" << "\n";

    b1 = buget(500, 250);
    b2 = buget(300, 350);
    b3 = buget(700, 500);
    b4 = buget(500, 500);
    b5 = buget(300, 700);

    persoana p1 = persoana(b1, "rares", 2200);
    persoana p2 = persoana(b2, "teo", 1345);
    persoana p3 = p1 + p2;
    cout << p3 << "\n";
    p3 = persoana(p1);
    cout << p3 << "\n";
    p1 += p2;
    cout << p1 << "\n";
    p1.set_nume("rares");
    p1 -= p2;
    cout << p1 << "\n";
    p1.set_nume("rares");
    p3 = p1 - p2;
    cout << p3 << "\n";
    p1.set_b(b3);
    p2.set_b(b4);
    cout << p1 << "    " << p2 << "\n";
    p1.~persoana();
    cout << p1;
   






    return 0;
}