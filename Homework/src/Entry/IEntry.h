#pragma once
#include <memory>
#include <cstdint>

namespace Vaultify::Entries {
    class IEntry {
    public:
        virtual const char* getTitle() const = 0;
        virtual void setTitle(const char* title) = 0;
        virtual void display() const = 0;
    };
}