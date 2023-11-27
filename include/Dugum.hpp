/**
* @file Dugum.hpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/
#include "Sayi.hpp"

class Dugum {
public:
    Sayi numberList; // Sayi sinifindan degisken ilani
    Dugum* next;     // Dugum 'bir sonraki'

    Dugum();  // Constructor
    ~Dugum(); // Destructor

};

