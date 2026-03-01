//! Unit Tests for MPAGSCipher CaesarCipher Class
#include "gtest/gtest.h"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"
#include "Cipher.hpp"

bool testCipher(const Cipher& cipher, const CipherMode mode,
                const std::string& inputText, const std::string& outputText)
{
    return cipher.applyCipher(inputText, mode) == outputText;
}

TEST(Cipher, AllEncryptDecrypt)
{
    CaesarCipher ckey{10};
    EXPECT_TRUE(
        testCipher(ckey, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));

    EXPECT_TRUE(
        testCipher(ckey, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));

    VigenereCipher vkey{"hello"};
    EXPECT_TRUE(
        testCipher(vkey, CipherMode::Encrypt,
                   "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES",
                   "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ"));

    EXPECT_TRUE(
        testCipher(vkey, CipherMode::Decrypt,
                   "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ",
                   "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES"));

    PlayfairCipher pkey{"hello"};
    EXPECT_TRUE(
        testCipher(pkey, CipherMode::Encrypt,
                   "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING",
                   "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
    EXPECT_TRUE(
        testCipher(pkey, CipherMode::Decrypt,
                   "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA",
                   "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
}

