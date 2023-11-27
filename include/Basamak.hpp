/**
* @file Basamak.hpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/
class Basamak {
public:
    int digit;     // Basamak
    Basamak* next; // Basamak 'sonrasi'

    Basamak(int value); // Constructor
    ~Basamak();  		// Destructor

};