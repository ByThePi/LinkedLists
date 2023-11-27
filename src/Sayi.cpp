/**
* @file Sayi.cpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/

#include "Fonksiyonlar.hpp"
#include "Sayi.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Sayi::Sayi() : head(nullptr) {}

Sayi::~Sayi() {
    Basamak* current = head;
    while (current != nullptr) {
        Basamak* next = current->next;
        delete current;
        current = next;
    }
}

void Sayi::insertBasamak(int value) {
    Basamak* newNode = new Basamak(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Basamak* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Sayi::printAddresses(uintptr_t listAddress) const {
    Basamak* current = head;

        int counter = 0;
        while (current != nullptr) {
            current = current->next;
            counter += 1;
        }

        hashPrinter("#", "", "");
        asteriskPrinter(counter);
        cout << "#" << setw(10) << hex << listAddress << "#   ";
        
        current = head;
        while (current != nullptr) { 
            // Zorlayici kisimlardan biri, adresi hexe ceviriyoruz
            stringstream ss;
            ss << hex << reinterpret_cast<uintptr_t>(current);
            string addressStr = ss.str();

            // Istisna duruma karsi tedbir, adres uc basamaktan azsa hepsini yazdir
            cout << "* " << setw(3) << (addressStr.length() >= 3 ? addressStr.substr(addressStr.length() - 3) : addressStr) << " * ";

            current = current->next;
        }

        cout << endl;
        hashPrinter("-", "", "");
        asteriskPrinter(counter);
}

// Istenilen duzende ciktinin yazdirilmasi
void Sayi::printList() const {
    Basamak* current = head;

        int counter = 0;
        while (current != nullptr) {
            current = current->next;
            counter += 1;
        }

        cout << "#" << right << setw(11 - counter) << " ";
        current = head;
        while (current != nullptr) {
            cout << current->digit;
            current = current->next;
        }
        cout << "#   ";

        current = head;
        while (current != nullptr) {
            cout << "*" << setw(3) << current->digit << "  * ";
            current = current->next;
        }
        cout << endl;
        
        hashPrinter("#", "", "");
        asteriskPrinter(counter);
        cout << endl;
}

void Sayi::moveOddDigitsToFront() {
    Basamak* current = head;
        Basamak* oddHead = nullptr;
        Basamak* oddTail = nullptr;
        Basamak* prev = nullptr;

        while (current != nullptr) {
            Basamak* next = current->next;

            if (current->digit % 2 != 0) {
                // Tek basamaksa basa tasi

                if (oddHead == nullptr) {
                    // Ilk tek basamak
                    oddHead = current;
                    oddTail = current;
                    oddTail->next = nullptr;
                }
                else {
                    // Tek basamaklar listesine ekle
                    oddTail->next = current;
                    oddTail = current;
                    oddTail->next = nullptr;
                }

                if (prev == nullptr) {
                    // Tek basamak head icindeyse headi guncelle
                    head = next;
                }
                else {
                    // Tek basamak head icinde degilse devam et
                    prev->next = next;
                }
            }
            else {
                // Cift basamak, devam et
                prev = current;
            }

            current = next;
        }
		
        // Tek basamaklar listesini cift basamaklar listesinin sonuna ekle
        if (oddHead != nullptr) {
            oddTail->next = head;
            head = oddHead;
        }
}

void Sayi::reverseDigits() {
    Basamak* current = head;
        Basamak* prev = nullptr;
        Basamak* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
}

void Sayi::removeLargestDigit() {
    if (head == nullptr) {
            // Liste bos, bos don
            return;
        }

	Basamak* current = head;
	Basamak* prev = nullptr;
	Basamak* maxNode = head;
	Basamak* maxPrev = nullptr;

	// Max basamagi ve onceki dugumu bul
	while (current != nullptr) {
		if (current->digit > maxNode->digit) {
			maxNode = current;
			maxPrev = prev;
		}
		prev = current;
		current = current->next;
	}

	if (maxNode != nullptr) {
		// Max basamak dugumunu listeden kaldir
		if (maxPrev == nullptr) {
			// Max basamak head icindeyse
			head = maxNode->next;
		}
		else {
			// Max basamak head icinde degilse
			maxPrev->next = maxNode->next;
		}

		delete maxNode; // Silinen basamagin yerindeki hafizayi temizleme
		maxNode = nullptr;
	}
}