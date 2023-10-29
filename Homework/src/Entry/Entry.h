#pragma once
#include <iostream>
#include <cstring>
#include <cstdint>

class Entry {
private:
    static uint32_t idCounter;
    uint32_t id;
    char* website;
    char* username;
    char* password;

public:
    Entry(const char* site, const char* user, const char* pass);
    Entry(const Entry& other); 
    Entry(Entry&& other) noexcept; 
    ~Entry(); 
    
    const char* getWebsite() const;
    const char* getUsername() const;
    const char* getPassword() const;
    void setWebsite(const char*);
    void setUsername(const char*);
    void setPassword(const char*);
};

