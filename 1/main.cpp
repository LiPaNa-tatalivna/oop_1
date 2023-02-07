 #include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Adress{
    string gorod;
    string ylica;
    int nomer_doma; 
    int nomer_kvartire;
public:
    Adress(){
        gorod = "Москва";
        ylica = "Ленино";
        nomer_doma = 0; 
        nomer_kvartire = 0;
    }
    void new_Adress(string gorod, string ylica, int nomer_doma, int nomer_kvartire){
        this -> gorod = gorod;
        this -> ylica = ylica;
        this -> nomer_doma = nomer_doma;
        this -> nomer_kvartire = nomer_kvartire;
        // cout << gorod << gorod;
    }
    string get_gorod() {return gorod;} // геттер
    string get_ylica() {return ylica;}
    int get_nomer_doma() {return nomer_doma;}
    int get_nomer_kvartire() {return nomer_kvartire;}
};

int main()
{
    
    string s, line;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    fin >> s;
    int n = atoi(s.c_str());
    Adress* adress = new Adress[n];
    string gorod, ylica;
    int nomer_doma, nomer_kvartire; 
    
    
    for (int i = 0; i < n; i++){
        fin >> s;
        gorod = s;
        fin >> s;
        ylica = s;
        fin >> s;
        nomer_doma = atoi(s.c_str());
        fin >> s;
        nomer_kvartire = atoi(s.c_str());
        (adress + i) -> new_Adress(gorod, ylica, nomer_doma, nomer_kvartire);
    }

    
    fout << n << endl;
    for (int i = n-1 ; i >= 0; i--){
        fout << (adress + i) -> get_gorod() << ", ";
        fout << (adress + i) -> get_ylica() << ", ";
        fout << (adress + i) -> get_nomer_doma() << ", ";
        fout << (adress + i) -> get_nomer_kvartire() << endl;
    }
    
    
    fin.close();
    fout.close();
    delete[] adress;
    
    return 0;
}
