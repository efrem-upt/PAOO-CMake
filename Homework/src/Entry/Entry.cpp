#include "Entry.h"

using namespace Vaultify::Entries;

uint32_t Entry::idCounter = 1; 

Entry::Entry() 
    : id(idCounter++)
{
    
    std::cout << "(constructor): Constructor for entry " << id << " called\n";
}

Entry::Entry(const char* title) 
    : Entry()
{
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

Entry::Entry(const Entry& other) 
    : id(idCounter++), title(new char[strlen(other.title) + 1])
{
    std::cout << "(copy_constructor): Copied contents of entry " << other.id << " to entry " << id << "\n";
    strcpy(this->title, other.title);
}

Entry::Entry(Entry&& other) noexcept 
    : id(other.id), title(other.title)
{
    std::cout << "(move_constructor): Moved contents of entry " << id << "\n";
    other.title = nullptr;
    other.id = MOVED_ID_VALUE;
}

Entry::~Entry() {
    if (id == MOVED_ID_VALUE)
        std::cout << "(destructor): Destructor for already moved entry " << id << " called\n";
    else {
        std::cout << "(destructor): Destructor for entry " << id << " called\n";
    }
}

int Entry::getId() const {
    return id;
}

const char* Entry::getTitle() const {
    return this->title;
}

void Entry::setTitle(const char* new_title) {
    delete[] this->title;
    this->title = new char[strlen(new_title) + 1];
    strcpy(this->title, new_title);
}