#include "Database.h"
#include <iostream>
#include <cstring>

int main() {
    Database db;

    {
        Entry e1("example.com", "username", "password");
        Entry e2("example2.com", "username2", "password2");
        Entry e3("example3.com", "username3", "password3");

        db.addEntry(e1);
        db.addEntry(e2);
        db.addEntry(e3);

        Entry e4(e1);  
        Entry e5 = std::move(e2);
    } 

    const Entry& e = db.getEntry("example.com");
    if (strlen(e.getWebsite()) && strlen(e.getUsername()) && strlen(e.getPassword())) {
        std::cout << "Website: " << e.getWebsite() << "\n";
        std::cout << "Username: " << e.getUsername() << "\n";
        std::cout << "Password: " << e.getPassword() << "\n";
    } else {
        std::cout << "Not found!'";
    }
 
    
    return 0;
}
