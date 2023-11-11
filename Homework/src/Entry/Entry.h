#pragma once
#include "IEntry.h"
#include <iostream>
#include <cstring>
#include <cstdint>
#define MOVED_ID_VALUE -1

namespace Vaultify::Entries {

    class Entry : public IEntry {
    protected:
        char* title;
        static uint32_t idCounter;
        uint32_t id;    
    public:
        Entry();
        Entry(const char* title);
        Entry(const Entry& other); 
        Entry(Entry&& other) noexcept; 
        ~Entry(); 
        int getId() const;
    };

}


