#include <iostream>
#include <malloc.h>
#include <cstring>

enum alimentare {Benzina, Motorina, Electric, GPL};


class Masina {

    int id;
    alimentare alimentare;
    char *nume;
    float consum;
    bool esteSH;

public:
    Masina(){
        this->id = 00000000;
        this->alimentare = Benzina;
        this->nume = new char[strlen("Masina noua")+1];
        strcpy(this->nume, "Masina noua");
        this->consum = 0.00;
        this->esteSH = false;
    }

    Masina( int id, enum alimentare alimentare, char *nume, float consum, bool esteSH){
        this->id = id;
        this->alimentare = alimentare;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->consum = consum;
        this->esteSH = esteSH;
    }

    Masina(Masina& m){
        this->id = m.id;
        this->alimentare = m.alimentare;
        this->nume = new char [strlen(m.nume)+1];
        strcpy(this->nume, m.nume);
        this->consum = m.consum;
        this->esteSH = m.esteSH;
    }

    ~Masina(){
        if(this->nume){
            delete[] this->nume;
        }

    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Masina::id = id;
    }

   enum alimentare getAlimentare() const {
        return alimentare;
    }

    void setAlimentare(enum alimentare alimentare) {
        Masina::alimentare = alimentare;
    }

    char *getNume() const {
        return nume;
    }

    void setNume(char *nume) {
        Masina::nume = nume;
    }

    float getConsum() const {
        return consum;
    }

    void setConsum(float consum) {
        Masina::consum = consum;
    }


    /*Nu modifica obiectul*/
    Masina operator!(){
        Masina copie  = *this;
        copie.esteSH = !copie.esteSH;
        return *this;
    }
    // modifica obiectul

    /*Masina operator!(){
        this->esteSH = !this->esteSH;
        return *this;
    }*/

};

//is a
class Suv :public Masina{
protected:
    bool is4x4;

public:
    Suv():Masina(){
        this->is4x4 = false;
    }

    Suv(int id, enum alimentare alimentare, char *nume, float consum, bool esteSH, bool is4x4): Masina(id,  alimentare, *nume, consum, esteSH){
        this->is4x4 = is4x4;
    }


};

//has a
class Atelier{

    int id;
    char* nume;
    Masina masina;
    float suprafata;
    int angajati;

public:
    Atelier(){
        this->id = 00000000000000;
        this->nume = new char[strlen("Atelier nou")+1];
        strcpy(this->nume, "Atelier nou");
        this->masina = Masina();
        this->suprafata = 0;
        this->angajati = 0;

    };

    Atelier(int id, char* nume, Masina masina, float suprafata, int angajati){
        this->id = id;
        this->nume = new char [strlen(nume)+1];
        strcpy(this->nume, nume);
        this->masina = masina;
        this->suprafata = suprafata;
        this->angajati = angajati;
    };

    Atelier(Atelier& a){
        this->id = a.id;
        this->nume = new char [strlen(a.nume)+1];
        strcpy(this->nume, a.nume);
        this->masina = a.masina;
        this->suprafata = a.suprafata;
        this->angajati = a.angajati;
    }

    Atelier operator=(const Atelier& a){ //merge si cu void! insa nu e ok pt apelare in cascada
       if(this != &a) {
           if (this->nume != nullptr) {
               delete[] this->nume;
           }
           this->id = a.id;
           this->nume = new char[strlen(a.nume) + 1];
           strcpy(this->nume, a.nume);
           this->masina = a.masina;
           this->suprafata = a.suprafata;
           this->angajati = a.angajati;
       }
        return *this;
    }



    ~Atelier(){
        if (this->nume!=nullptr){
            delete[] this->nume;
        }
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Atelier::id = id;
    }

    char *getNume() const {
        return nume;
    }

    void setNume(char *nume) {
        Atelier::nume = nume;
    }

    const Masina &getMasina() const {
        return masina;
    }

    void setMasina(const Masina &masina) {
        Atelier::masina = masina;
    }

    float getSuprafata() const {
        return suprafata;
    }

    void setSuprafata(float suprafata) {
        Atelier::suprafata = suprafata;
    }

    int getAngajati() const {
        return angajati;
    }

    void setAngajati(int angajati) {
        Atelier::angajati = angajati;
    }

};



int main() {
    Masina masina_fara_nume;
    printf("%s", masina_fara_nume.getNume());

    Atelier* atelier_fara_nume = new Atelier();
    printf("%s", atelier_fara_nume->getNume());
    delete atelier_fara_nume;
    return 0;
}
