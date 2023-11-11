#pragma once
#include "Entry.h"
#include <vector>

using namespace Vaultify::Entries;

namespace Vaultify {
    class Database {
    private:
        char* masterPassword;
        std::vector<Entry*> entries;

    public:
        Database();
        ~Database();
        void addEntry(Entry* entry);
        const std::vector<Entry*>& getEntries() const;
        void setMasterPassword(const char* pass);
        const char* getMasterPassword() const;
    };
}
