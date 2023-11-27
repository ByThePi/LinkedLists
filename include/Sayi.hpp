/**
* @file Sayi.hpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp" // Include necessary headers
#include <stdint.h>

class Sayi {
public:
    Basamak* head; // Basamagin basinin ilani

    Sayi();  // Costructor
    ~Sayi(); // Destructor

    void insertBasamak(int value); 					  // Basamak ekleyen fonksiyon
    void printAddresses(uintptr_t listAddress) const; // Adres yazdiran fonksiyon
    void printList() const;							  // Liste yazdiran fonksiyon
    void moveOddDigitsToFront();					  // Tek basamagi basa alan fonksiyon
    void reverseDigits();							  // Basamaklari ters ceviren fonksiyon
    void removeLargestDigit();						  // En buyuk basamagi cikaran fonksiyon

};