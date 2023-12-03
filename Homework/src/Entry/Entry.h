#pragma once
#include "IEntry.h"
#include <iostream>
#include <cstring>
#include <cstdint>
#include <mutex>
#include <memory>

#define MOVED_ID_VALUE -1

namespace Vaultify {
    class Database;  
}

namespace Vaultify::Entries {

    class Entry : public IEntry, public std::enable_shared_from_this<Entry> {
    protected:
        std::weak_ptr<Database> parentDatabase;
        std::unique_ptr<char[]> title;  // Changed to unique_ptr
        static uint32_t idCounter;
        uint32_t id;    
    public:
        Entry();
        Entry(const char* title);
        Entry(const Entry& other); 
        Entry(Entry&& other) noexcept; 
        Entry& operator=(const Entry& other);
        Entry& operator=(Entry&& other) noexcept;
        ~Entry(); 
        int getId() const;
        virtual const char* getTitle() const override;  // Return type remains the same
        virtual void setTitle(const char* title) override;  // Parameter type remains the same
        void setParentDatabase(std::weak_ptr<Database> parentDatabase);
        std::shared_ptr<Database> getParentDatabase() const;

        static std::mutex mtx;

    };
}