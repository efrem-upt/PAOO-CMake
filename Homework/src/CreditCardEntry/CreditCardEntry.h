#pragma once
#include "Entry.h"
#include <memory>
#include <cstring>

namespace Vaultify::Entries {
    class CreditCardEntry : public Entry {
    private:
        std::unique_ptr<char[]> cardNumber;
        std::unique_ptr<char[]> expirationDate;
        std::unique_ptr<char[]> cvv;
        std::unique_ptr<char[]> pin;

    public:
        CreditCardEntry(const char* title, const char* cardNumber, const char* expirationDate, const char* cvv, const char* pin);
        CreditCardEntry(const CreditCardEntry& other);
        CreditCardEntry(CreditCardEntry&& other) noexcept;
        ~CreditCardEntry() = default; 
        CreditCardEntry& operator=(const CreditCardEntry& other);
        CreditCardEntry& operator=(CreditCardEntry&& other) noexcept;
        virtual void display() const override;
        const char* getCardNumber() const { return cardNumber.get(); }
        const char* getExpirationDate() const { return expirationDate.get(); }
        const char* getCvv() const { return cvv.get(); }
        const char* getPin() const { return pin.get(); }
        void setCardNumber(const char* cardNumber);
        void setExpirationDate(const char* expirationDate);
        void setCvv(const char* cvv);
        void setPin(const char* pin);
    };
}
