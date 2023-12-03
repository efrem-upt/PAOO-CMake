#pragma once
#include "Entry.h"
#include <memory>
#include <cstring>

namespace Vaultify::Entries {
    class SecureNoteEntry : public Entry {
    private:
        std::unique_ptr<char[]> note;

    public:
        SecureNoteEntry(const char* title, const char* note);
        SecureNoteEntry(const SecureNoteEntry& other);
        SecureNoteEntry(SecureNoteEntry&& other) noexcept;
        ~SecureNoteEntry() = default; // Destructor is optional with smart pointers
        SecureNoteEntry& operator=(const SecureNoteEntry& other);
        SecureNoteEntry& operator=(SecureNoteEntry&& other) noexcept;
        virtual void display() const override;
        const char* getNote() const;
        void setNote(const char* note);
    };
}
