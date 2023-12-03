#include "CreditCardEntry.h"
#include <cstring>
#include <iostream>

using namespace Vaultify::Entries;

CreditCardEntry::CreditCardEntry(const char* new_title, const char* new_number, const char* new_exp, const char* new_cvv, const char* new_pin) 
    : Entry(new_title),
      cardNumber(std::make_unique<char[]>(strlen(new_number) + 1)),
      expirationDate(std::make_unique<char[]>(strlen(new_exp) + 1)),
      cvv(std::make_unique<char[]>(strlen(new_cvv) + 1)),
      pin(std::make_unique<char[]>(strlen(new_pin) + 1)) {
    strcpy(cardNumber.get(), new_number);
    strcpy(expirationDate.get(), new_exp);
    strcpy(cvv.get(), new_cvv);
    strcpy(pin.get(), new_pin);
}

CreditCardEntry::CreditCardEntry(const CreditCardEntry& other) 
    : Entry(other),
      cardNumber(std::make_unique<char[]>(strlen(other.cardNumber.get()) + 1)),
      expirationDate(std::make_unique<char[]>(strlen(other.expirationDate.get()) + 1)),
      cvv(std::make_unique<char[]>(strlen(other.cvv.get()) + 1)),
      pin(std::make_unique<char[]>(strlen(other.pin.get()) + 1)) {
    strcpy(cardNumber.get(), other.cardNumber.get());
    strcpy(expirationDate.get(), other.expirationDate.get());
    strcpy(cvv.get(), other.cvv.get());
    strcpy(pin.get(), other.pin.get());
}

CreditCardEntry::CreditCardEntry(CreditCardEntry&& other) noexcept 
    : Entry(std::move(other)),
      cardNumber(std::move(other.cardNumber)),
      expirationDate(std::move(other.expirationDate)),
      cvv(std::move(other.cvv)),
      pin(std::move(other.pin)) {
}

CreditCardEntry& CreditCardEntry::operator=(const CreditCardEntry& other) {
    if (this != &other) {
        Entry::operator=(other);  // Call base class assignment operator
        cardNumber = std::make_unique<char[]>(strlen(other.cardNumber.get()) + 1);
        expirationDate = std::make_unique<char[]>(strlen(other.expirationDate.get()) + 1);
        cvv = std::make_unique<char[]>(strlen(other.cvv.get()) + 1);
        pin = std::make_unique<char[]>(strlen(other.pin.get()) + 1);
        strcpy(cardNumber.get(), other.cardNumber.get());
        strcpy(expirationDate.get(), other.expirationDate.get());
        strcpy(cvv.get(), other.cvv.get());
        strcpy(pin.get(), other.pin.get());
    }
    return *this;
}

CreditCardEntry& CreditCardEntry::operator=(CreditCardEntry&& other) noexcept {
    if (this != &other) {
        Entry::operator=(std::move(other)); // Call base class move assignment operator
        cardNumber = std::move(other.cardNumber);
        expirationDate = std::move(other.expirationDate);
        cvv = std::move(other.cvv);
        pin = std::move(other.pin);
    }
    return *this;
}

void CreditCardEntry::setCardNumber(const char* new_number) {
    cardNumber = std::make_unique<char[]>(strlen(new_number) + 1);
    strcpy(cardNumber.get(), new_number);
}

void CreditCardEntry::setExpirationDate(const char* new_exp) {
    expirationDate = std::make_unique<char[]>(strlen(new_exp) + 1);
    strcpy(expirationDate.get(), new_exp);
}

void CreditCardEntry::setCvv(const char* new_cvv) {
    cvv = std::make_unique<char[]>(strlen(new_cvv) + 1);
    strcpy(cvv.get(), new_cvv);
}

void CreditCardEntry::setPin(const char* new_pin) {
    pin = std::make_unique<char[]>(strlen(new_pin) + 1);
    strcpy(pin.get(), new_pin);
}

void CreditCardEntry::display() const {
    std::cout << "--------------------------------------------------\n";
    std::cout << "Credit Card Entry\n";
    std::cout << "Title: " << getTitle() << "\n";  // Assuming getTitle() is a method of Entry
    std::cout << "Card Number: " << cardNumber.get() << "\n";
    std::cout << "Expiration Date: " << expirationDate.get() << "\n";
    std::cout << "CVV: " << cvv.get() << "\n";
    std::cout << "PIN: " << pin.get() << "\n";
    std::cout << "--------------------------------------------------\n";
}
