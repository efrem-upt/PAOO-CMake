#pragma once
#include <string>

class Entry {
private:
    char* website;
    char* username;
    char* password;

public:
    Entry(const char* site, const char* user, const char* pass);
    Entry(const Entry& other); 
    Entry(Entry&& other) noexcept; 
    ~Entry(); 
    
    char* getWebsite() const;
    char* getUsername() const;
    char* getPassword() const;
};

