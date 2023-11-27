/**
* @file SayilarListesi.hpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

class SayilarListesi {
public:
    Dugum* head; // Dugumun basinin ilani

    SayilarListesi();   // Constructor
    ~SayilarListesi();  // Destructor

    void insertDugum(const Sayi& value); // Dugum ekleyen fonksiyon
    void printList() const;				 // Liste yazdiran fonksiyon
    void moveOddDigitsToFrontForAll();   // Tum tek basamaklari basa alan fonksiyon
    void reverseAllDigits();			 // Tum basamaklari ters ceviren fonksiyon
    void removeLargestDigitFromAll();    // Tum en buyuk basamaklari cikaran fonksiyon

};