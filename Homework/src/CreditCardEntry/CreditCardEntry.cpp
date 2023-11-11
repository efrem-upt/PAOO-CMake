#include "CreditCardEntry.h"

using namespace Vaultify::Entries;

CreditCardEntry::CreditCardEntry(const char* new_title, const char* new_number, const char* new_cvv, const char* new_exp, const char* new_pin) : Entry(new_title), cardNumber(new char[strlen(new_number) + 1]), cvv(new char[strlen(new_cvv) + 1]), expirationDate(new char[strlen(new_exp) + 1]) {
    strcpy(this->cardNumber, new_number);
    strcpy(this->cvv, new_cvv);
    strcpy(this->expirationDate, new_exp);
    strcpy(this->pin, new_pin);
}

CreditCardEntry::CreditCardEntry(const CreditCardEntry& other) : Entry(other), cardNumber(new char[strlen(other.cardNumber) + 1]), cvv(new char[strlen(other.cvv) + 1]), expirationDate(new char[strlen(other.expirationDate) + 1]), pin(new char[strlen(other.pin) + 1]) {
    strcpy(this->cardNumber, other.cardNumber);
    strcpy(this->cvv, other.cvv);
    strcpy(this->expirationDate, other.expirationDate);
    strcpy(this->pin, other.pin);
}

CreditCardEntry::CreditCardEntry(CreditCardEntry&& other) noexcept : Entry(std::move(other)), cardNumber(other.cardNumber), cvv(other.cvv), expirationDate(other.expirationDate), pin(other.pin) {
    other.cardNumber = nullptr;
    other.cvv = nullptr;
    other.expirationDate = nullptr;
    other.pin = nullptr;
}

CreditCardEntry::~CreditCardEntry() {
    delete[] this->cardNumber;
    delete[] this->cvv;
    delete[] this->expirationDate;
    delete[] this->pin;
}

CreditCardEntry& CreditCardEntry::operator=(const CreditCardEntry& other) {
    if (this != &other) {
        delete[] this->cardNumber;
        delete[] this->cvv;
        delete[] this->expirationDate;
        delete[] this->pin;
        this->cardNumber = new char[strlen(other.cardNumber) + 1];
        this->cvv = new char[strlen(other.cvv) + 1];
        this->expirationDate = new char[strlen(other.expirationDate) + 1];
        this->pin = new char[strlen(other.pin) + 1];
        strcpy(this->cardNumber, other.cardNumber);
        strcpy(this->cvv, other.cvv);
        strcpy(this->expirationDate, other.expirationDate);
        strcpy(this->pin, other.pin);
    }
    return *this;
}

CreditCardEntry& CreditCardEntry::operator=(CreditCardEntry&& other) noexcept {
    if (this != &other) {
        delete[] this->cardNumber;
        delete[] this->cvv;
        delete[] this->expirationDate;
        delete[] this->pin;
        this->cardNumber = other.cardNumber;
        this->cvv = other.cvv;
        this->expirationDate = other.expirationDate;
        this->pin = other.pin;
        other.cardNumber = nullptr;
        other.cvv = nullptr;
        other.expirationDate = nullptr;
        other.pin = nullptr;
    }
    return *this;
}

const char* CreditCardEntry::getCardNumber() const {
    return this->cardNumber;
}

const char* CreditCardEntry::getExpirationDate() const {
    return this->expirationDate;
}

const char* CreditCardEntry::getCvv() const {
    return this->cvv;
}

const char* CreditCardEntry::getPin() const {
    return this->pin;
}


void CreditCardEntry::setCardNumber(const char* cardNumber) {
    delete[] this->cardNumber;
    this->cardNumber = new char[strlen(cardNumber) + 1];
    strcpy(this->cardNumber, cardNumber);
}

void CreditCardEntry::setExpirationDate(const char* expirationDate) {
    delete[] this->expirationDate;
    this->expirationDate = new char[strlen(expirationDate) + 1];
    strcpy(this->expirationDate, expirationDate);
}

void CreditCardEntry::setCvv(const char* cvv) {
    delete[] this->cvv;
    this->cvv = new char[strlen(cvv) + 1];
    strcpy(this->cvv, cvv);
}

void CreditCardEntry::setPin(const char* pin) {
    delete[] this->pin;
    this->pin = new char[strlen(pin) + 1];
    strcpy(this->pin, pin);
}


void CreditCardEntry::display() const {
    std::cout << "Credit Card Entry\n";
    std::cout << "Title: " << this->title << "\n";
    std::cout << "Card Number: " << this->cardNumber << "\n";
    std::cout << "Expiration Date: " << this->expirationDate << "\n";
    std::cout << "CVV: " << this->cvv << "\n";
    std::cout << "PIN: " << this->pin << "\n";
}

