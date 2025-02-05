//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2024, Thierry Lelegard
// BSD-2-Clause license, see LICENSE.txt file or https://tsduck.io/license
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Triple-DES (EDE) block cipher
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsBlockCipher.h"

namespace ts {
    //!
    //! Triple-DES block cipher.
    //! @ingroup crypto
    //!
    class TSDUCKDLL TDES: public BlockCipher
    {
        TS_NOCOPY(TDES);
    public:
        TDES() = default;                        //!< Constructor.
        static constexpr size_t BLOCK_SIZE = 8;  //!< TDES block size in bytes.
        static constexpr size_t KEY_SIZE = 24;   //!< TDES key size in bytes.
        static constexpr size_t ROUNDS = 16;     //!< TDES number of rounds.

        // Implementation of BlockCipher interface:
        virtual UString name() const override;
        virtual size_t blockSize() const override;
        virtual size_t minKeySize() const override;
        virtual size_t maxKeySize() const override;
        virtual bool isValidKeySize (size_t size) const override;
        virtual size_t minRounds() const override;
        virtual size_t maxRounds() const override;
        virtual size_t defaultRounds() const override;

    protected:
        // Implementation of BlockCipher interface:
        virtual bool setKeyImpl(const void* key, size_t key_length, size_t rounds) override;
        virtual bool encryptImpl(const void* plain, size_t plain_length, void* cipher, size_t cipher_maxsize, size_t* cipher_length) override;
        virtual bool decryptImpl(const void* cipher, size_t cipher_length, void* plain, size_t plain_maxsize, size_t* plain_length) override;

    private:
        uint32_t _ek[3][32] {};  // Encryption keys
        uint32_t _dk[3][32] {};  // Decryption keys
    };
}
