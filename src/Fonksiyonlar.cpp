/**
* @file Fonksiyonlar.cpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/

#include "Fonksiyonlar.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void hashPrinter(string symbol, string nextLine, string lastLine) {
    cout << "#"; // Adrese ve sayiya uygun olacak sekilde # yazdirmak
    for (int i = 0; i < 11; i++) {
        cout << symbol;
    }
    cout << "#  ";

    cout << " ";
    cout << nextLine;
    cout << lastLine;
}

void asteriskPrinter(int basamakAmount) {
	// Adrese ve sayiya uygun olacak sekilde * yazdirmak
    for (int i = 0; i < basamakAmount; i++) {
        for (int j = 0; j < 7; j++) {
            cout << "*";
        }
        cout << " ";
    }
    cout << endl;
}
