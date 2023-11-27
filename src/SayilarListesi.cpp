/**
* @file SayilarListesi.cpp
* @description Tek Yonlu Bagli Listeler Kullanilarak Islemler Yapilmasi
* @course Veri Yapilari - 1. Ogretim B Grubu
* @assignment 1. Odev
* @date 13.11.2023
* @author Enes SOYLU B221210081 enes.soylu3@ogr.sakarya.edu.tr
*/
#include "SayilarListesi.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

SayilarListesi::SayilarListesi() : head(nullptr) {
    // Constructor implementation (if needed)
}

SayilarListesi::~SayilarListesi() {
    // Destructor implementation (if needed)
    // Deallocate dynamically allocated Dugum nodes
    Dugum* current = head;
    while (current != nullptr) {
        Dugum* next = current->next;
        delete current;
        current = next;
    }
}

void SayilarListesi::insertDugum(const Sayi& value) {
    Dugum* newNode = new Dugum();
    newNode->numberList = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Dugum* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void SayilarListesi::printList() const {
    Dugum* current = head;
    while (current != nullptr) {
        current->numberList.printAddresses(reinterpret_cast<uintptr_t>(current));
        current->numberList.printList();
        cout << setw(0);
        current = current->next;
    }
}

void SayilarListesi::moveOddDigitsToFrontForAll() {
    Dugum* current = head;
    while (current != nullptr) {
        current->numberList.moveOddDigitsToFront();
        current = current->next;
    }
}

void SayilarListesi::reverseAllDigits() {
    Dugum* current = head;
    while (current != nullptr) {
        current->numberList.reverseDigits();
        current = current->next;
    }
}

void SayilarListesi::removeLargestDigitFromAll() {
    Dugum* current = head;
    while (current != nullptr) {
        current->numberList.removeLargestDigit();
        current = current->next;
    }
}
