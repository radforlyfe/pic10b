#include "String.h"

namespace basic { // open up the namespace
    
    // Default Constructor, size is initially 1 (null char), ptr points null, also track constructor type and id
    string::string() : sz(1), ptr(nullptr), type("default"), id(count++) {
        ptr = new char[1]{ '\0' };
    }
    
    // Constructur accepts a string literal as an input, will copy data from a string literal
    string::string(const char* char_ptr) : sz(0), ptr(nullptr), type("const char*"), id(count++) { // set size to 0 initially
        while (char_ptr[sz++] != '\0')     // increment count until at null character
        { /* EMPTY STATEMENT */    }       // sz is now the size of the char[], including the null char
        ptr = new char[sz];                // allocate appropriate size of array
        for (size_t i = 0; i < sz; ++i) {  // and copy char from string literal to basic::string
            ptr[i] = char_ptr[i];
        }
    }
    
    // Copy Constructor
    string::string(const string& other) : sz(other.sz), ptr(nullptr), type("copy"), id(count++) {
        ptr = new char[other.sz];                // allocate new array of size other
        for (size_t i = 0; i < other.sz; ++i) {  // copy over every char, even the null, from other
            ptr[i] = other.ptr[i];
        }
    }
}

// we could also just add a bunch of ::'s and define things like you see here
// note how these definitions appear outside of the namespace braces!

// Move Constructor
basic::string::string(string&& other) : string() { // invoke the default constructor
    std::swap(ptr, other.ptr);                     // then swap their pointers and sizes
    std::swap(sz, other.sz);
    type = "move"; // update the type tracking parameter since it would otherwise be "default"
}

// Copy Assignment
basic::string& basic::string::operator=(const string& other) {
    if(this == &other){                  // self-assignment
        return *this;
    }
    char *old(ptr);                      // old location
    ptr = new char[other.sz];            // allocate new array of size other
    for(size_t i=0; i < other.sz; ++i){  // copy each char from other
        ptr[i] = other.ptr[i];
    }
    sz = other.sz;
    delete [] old;                       // free up old memory
    return *this;
}

// Move Assignment
basic::string& basic::string::operator=(string&& other) {
    std::swap(ptr,other.ptr);            // swap values and return
    std::swap(sz, other.sz);
    return *this;
}

// Destructor
basic::string::~string() {               // when the object is destroyed, we print its information for illustration
    std::cout << "Deleting string " << id << " - ";
    if (ptr != nullptr) {                // print the information if it is safe to do so
        std::cout << ptr;
    }
    std::cout << '\n';
    delete[] ptr;                        // free the memory
    ptr = nullptr;                       // good coding practice
}

// Concatenate
void basic::string::concat(const string& rhs) {
    size_t newsize = sz + rhs.sz - 1;      // don't need two null chars
    char* old_location(ptr);               // temporarily store location of these elements with old_location
    ptr = new char[newsize];               // reset ptr to manage space big enough for all elements
    for (size_t i = 0; i < sz - 1; ++i) {  // loop over, but not include the null: hence i < sz-1
        ptr[i] = old_location[i];
    }
    for (size_t i = 0; i < rhs.sz; ++i) {  // get all data from string appending from
        ptr[i + sz - 1] = rhs.ptr[i];
    }
    sz = newsize;                          // update the size
    delete[] old_location;                 // free up the old spot in memory
    old_location = nullptr;                // good coding practice
}

// Print
void basic::string::print() const {        // displays the id, the string contents, and how it was created
    std::cout << id << ": ";
    std::cout << ptr;
    std::cout << " - created via " << type << '\n';
}

// At
char& basic::string::at(size_t i) {
    return ptr[i];
}

// At overloaded on const
char basic::string::at(size_t i) const {
    return ptr[i];
}

// need to define the static member of string
short basic::string::count = 0;
