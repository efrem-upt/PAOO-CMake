#include "LoginEntry.h"
#include "CreditCardEntry.h"
#include "SecureNoteEntry.h"
#include "Database.h"
#include <thread>
#include <iostream>
#include <cstring>

using namespace Vaultify;
using namespace Vaultify::Entries;


int main() {
    // Create a database
    Database db;

   // make 3 threads that add entries to the database

    std::thread t1([&db]() {
        db.addEntry(std::make_shared<LoginEntry>("Google", "google.com", "user1", "pass1"));
    });

    std::thread t2([&db]() {
        db.addEntry(std::make_shared<CreditCardEntry>("Credit Card", "1234 5678 9012 3456", "12/24", "123", "1234"));
    });

    std::thread t3([&db]() {
        db.addEntry(std::make_shared<SecureNoteEntry>("Note", "This is a note"));
    });

    std::thread t4([&db]() {
        db.addEntry(std::make_shared<LoginEntry>("Facebook", "facebook.com", "user2", "pass2"));
    });

    std::thread t5([&db]() {
        db.addEntry(std::make_shared<LoginEntry>("Twitter", "twitter.com", "user3", "pass3"));
    });

    t1.join(); 
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    
    db.checkAccounts();
    return 0;
}
