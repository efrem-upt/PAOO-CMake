#pragma once
#include <vector>
#include <memory>
#include <semaphore>
#include <barrier>

#define MAX_ACCOUNTS_PROCESSED 3

namespace Vaultify::Entries {
    class Entry;  
}

namespace Vaultify {
    class Database {
    private:
        std::counting_semaphore<1> sem;
        std::barrier<> checkAccountsBarrier;
        std::vector<std::shared_ptr<Vaultify::Entries::Entry>> entries; 

    public:
        Database();
        ~Database();
        void addEntry(std::shared_ptr<Vaultify::Entries::Entry> entry); 
        const std::vector<std::shared_ptr<Vaultify::Entries::Entry>>& getEntries() const; 
        void checkAccounts();
    };
}
