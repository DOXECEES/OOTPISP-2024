#include "Errors.h"

bool BaseError::operator==([[maybe_unused]]  const BaseError&  other) const {
    return false;
}


InvalidPointer::InvalidPointer(unsigned char* badAddr) : m_badAddr(badAddr) {}

void InvalidPointer::Print() const {
    std::cout << "Invalid pointer error occurred! Bad address: " << static_cast<void*>(m_badAddr) << std::endl;
}



void ListError::Print() const {
    std::cout << "List error occurred!" << std::endl;
}


InvalidIndex::InvalidIndex(int index) : m_index(index) {}

void InvalidIndex::Print() const {
    std::cout << "Invalid index: " << m_index << "!" << std::endl;
}

const char* InvalidIndex::what() const noexcept {
    return "Invalid index specified.";
}



void ListOverflow::Print() const {
    std::cout << "List overflow error occurred!" << std::endl;
}


