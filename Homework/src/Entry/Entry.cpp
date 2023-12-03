#include "Database.h"
#include "Entry.h"
#include <iostream>
#include <cstring>
#include <memory>

using namespace Vaultify::Entries;
using namespace Vaultify;

uint32_t Entry::idCounter = 1; 

std::mutex Entry::mtx;

Entry::Entry() {    
    mtx.lock();
    id = idCounter++;
    mtx.unlock();
    std::cout << "(constructor): Constructor for entry " << id << " called\n";
}

Entry::Entry(const char* title) : Entry() {
    this->title = std::make_unique<char[]>(strlen(title) + 1);
    strcpy(this->title.get(), title);
}

Entry::Entry(const Entry& other) : id(idCounter++), title(std::make_unique<char[]>(strlen(other.title.get()) + 1)) {
    std::cout << "(copy_constructor): Copied contents of entry " << other.id << " to entry " << id << "\n";
    strcpy(this->title.get(), other.title.get());
}

Entry::Entry(Entry&& other) noexcept : id(other.id), title(std::move(other.title)) {
    std::cout << "(move_constructor): Moved contents of entry " << id << "\n";
    other.id = MOVED_ID_VALUE;
}

Entry::~Entry() {
    std::cout << "(destructor): Destructor for entry " << id << " called\n";
}

int Entry::getId() const {
    return id;
}

const char* Entry::getTitle() const {
    return this->title.get();
}

void Entry::setTitle(const char* new_title) {
    this->title = std::make_unique<char[]>(strlen(new_title) + 1);
    strcpy(this->title.get(), new_title);
}

void Entry::setParentDatabase(std::weak_ptr<Database> parentDatabase) {
    this->parentDatabase = parentDatabase;
}

std::shared_ptr<Database> Entry::getParentDatabase() const {
    return this->parentDatabase.lock();
}

Entry& Entry::operator=(const Entry& other) {
            if (this != &other) {
              title = std::make_unique<char[]>(strlen(other.title.get()) + 1);
              strcpy(title.get(), other.title.get());
        }
        return *this;
    }

Entry& Entry::operator=(Entry&& other) noexcept {
    if (this != &other) {
        title = std::move(other.title);
    }
    return *this;
}