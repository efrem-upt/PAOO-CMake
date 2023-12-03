#include "Database.h"
#include "Entry.h"
#include "LoginEntry.h"

using namespace Vaultify;
using namespace Vaultify::Entries;

Database::Database() : checkAccountsBarrier(MAX_ACCOUNTS_PROCESSED), sem(1) {
    std::cout << "(constructor): Constructor for database called\n";
}

Database::~Database() {
    std::cout << "(destructor): Destructor for database called\n";
}

void Database::addEntry(std::shared_ptr<Entry> entry) {
    sem.acquire();
    this->entries.push_back(entry);
    std::cout << "(add_entry): Added entry " << entry->getId() << " to database\n";
    sem.release();
}

const std::vector<std::shared_ptr<Entry>>& Database::getEntries() const {
    return this->entries;
}

// implement check accounts using a two-stage barrier setup

void Database::checkAccounts() {
    std::vector<std::thread> threads;

    for (auto entry : entries) {
        // check if Entry is Login Entry
        auto loginEntry = std::dynamic_pointer_cast<LoginEntry>(entry);
        if (loginEntry) {
            threads.emplace_back([this, loginEntry]() {
                std::cout << "Checking if entry username is part of a data breach: " << loginEntry->getUsername() << std::endl;
                checkAccountsBarrier.arrive_and_wait();
                std::cout << "Checking if entry password is part of a data breach: " << loginEntry->getPassword() << std::endl;
            });
            continue;
        }
    }

    // Join all threads
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

}

