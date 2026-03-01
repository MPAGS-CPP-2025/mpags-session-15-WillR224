#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
#include "CipherMode.hpp"

class Cipher {
  public:   
    Cipher() = default;
    Cipher(const Cipher&) = default;
    Cipher(Cipher&&) = default;
    Cipher& operator=(const Cipher&) = default;
    Cipher& operator=(Cipher&&) = default;
    virtual ~Cipher() = default;
    virtual std::string applyCipher(const std::string& input, const CipherMode mode) const = 0;
};
#endif