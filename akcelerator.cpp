
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int znajdzPierwszeWystapienie(const vector<long long>& tab, long long target) {
    int lewy = 0;
    int prawy = tab.size();
    while (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        if (tab[srodek] >= target) {
            prawy = srodek;
        } else {
            lewy = srodek + 1;
        }
    }
    return lewy;
}


int znajdzOstatnieWystapienie(const vector<long long>& tab, long long target) {
    int lewy = 0;
    int prawy = tab.size();
    while (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        if (tab[srodek] > target) {
            prawy = srodek;
        } else {
            lewy = srodek + 1;
        }
    }
    return lewy;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
     
    string linia;
    getline(cin, linia);
    stringstream ss(linia);

    vector<long long> predkosci(n);
    for (int i = 0; i < n; ++i) {
        ss >> predkosci[i];
    }

    int q;
    
    vector<long long> pytania(q);
    for (int i = 0; i < q; ++i) {
        cin >> pytania[i];
    }

    //vector<int> wyniki(q);
    int tmp;
    for (int i = 0; i < q; ++i) {
        int poczatek = znajdzPierwszeWystapienie(predkosci, pytania[i]);
        int koniec = znajdzOstatnieWystapienie(predkosci, pytania[i]);
        //wyniki[i] = koniec - poczatek;
	tmp = koniec-poczatek;
	cout<<tmp;
    }
	/*
    for (int i = 0; i < q; ++i) {
        cout << wyniki[i] << "\n";
    }
	*/
    return 0;
}
