#pragma once
#include "Entry.h"

namespace Vaultify::Entries {
    class CreditCardEntry : public Entry {
    private:
        char* cardNumber;
        char* expirationDate;
        char* cvv;
        char* pin;
    public:
        CreditCardEntry(const char* title, const char* cardNumber, const char* expirationDate, const char* cvv, const char* pin);
        CreditCardEntry(const CreditCardEntry& other);
        CreditCardEntry(CreditCardEntry&& other) noexcept;
        ~CreditCardEntry();
        CreditCardEntry& operator=(const CreditCardEntry& other);
        CreditCardEntry& operator=(CreditCardEntry&& other) noexcept;
        virtual void display() const override;
        const char* getCardNumber() const;
        const char* getExpirationDate() const;
        const char* getCvv() const;
        const char* getPin() const;
        void setCardNumber(const char* cardNumber);
        void setExpirationDate(const char* expirationDate);
        void setCvv(const char* cvv);
        void setPin(const char* pin);
    };
}