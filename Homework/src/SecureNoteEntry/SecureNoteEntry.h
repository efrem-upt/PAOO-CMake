#pragma once
#include "Entry.h"

namespace Vaultify::Entries {
    class SecureNoteEntry : public Entry {
    private:
        char* note;
    public:
        SecureNoteEntry(const char* title, const char* note);
        SecureNoteEntry(const SecureNoteEntry& other);
        SecureNoteEntry(SecureNoteEntry&& other) noexcept;
        ~SecureNoteEntry();
        SecureNoteEntry& operator=(const SecureNoteEntry& other);
        SecureNoteEntry& operator=(SecureNoteEntry&& other) noexcept;
        virtual void display() const override;
        const char* getNote() const;
        void setNote(const char* note);
    };
}