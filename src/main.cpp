/**
* @file main.cpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/

#include "Fonksiyonlar.hpp"
#include "SayilarListesi.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    SayilarListesi mainList;
    int menuChoice;
    ifstream sayilarDosyasi("sayilar.txt"); // Dosyayi tanimla
    if (!sayilarDosyasi.is_open()) { 		// Dosya acik degilse, bulunamadiysa uyari ver
        cout << "Dosya acilamadi!" << endl;
        return 1;
    }

    string numbers;
    while (sayilarDosyasi >> numbers) { // Sirasiyla sayilari oku ve ilgili
        Sayi number;				 	// Duzene gore listelere, dugumlere ekle
        for (char digitChar : numbers) {
            if (isdigit(digitChar)) {
                int digit = digitChar - '0';
                number.insertBasamak(digit);
            }
        }
        mainList.insertDugum(number);
    }
    sayilarDosyasi.close(); // Dosyayi kapat

    mainList.printList();   // Listeleri(ana listeyi) yazdir

    do { // Menu islemleri
        cout << "\n1. Tek Basamaklari Basa Al\n"
                  << "2. Basamaklari Tersle\n"
                  << "3. En Buyuk Cikar\n"
                  << "4. Cikis" << endl;

        cin >> menuChoice;
        if (menuChoice == 1) { 		  // Tercih 1 ise basamaklari basa al
            mainList.moveOddDigitsToFrontForAll();
            mainList.printList();
        } else if (menuChoice == 2) { // Tercih 2 ise basamaklari ters cevir
            mainList.reverseAllDigits();
            mainList.printList();
        } else if (menuChoice == 3) { // Tercih 3 ise en buyuk basamagi sil
            mainList.removeLargestDigitFromAll();
            mainList.printList();
        }
    } while (menuChoice != 4); 		  // Tercih 4 ise bitir

    return 0;
}
