/*
 * Copyright (c) 2014, peelo.net
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PEELO_FUNCTIONAL_HASH_HPP_GUARD
#define PEELO_FUNCTIONAL_HASH_HPP_GUARD

#include <peelo/text/string.hpp>

namespace peelo
{
    template< class Key >
    struct hash
    {
        typedef Key argument_type;
        typedef std::size_t result_type;

        result_type operator()(const argument_type& key) const
        {
            return reinterpret_cast<result_type>(key);
        }
    };

    template<>
    struct hash<bool>
    {
        result_type operator()(bool key) const
        {
            return key ? 1 : 0;
        }
    };

    template<>
    struct hash<string>
    {
        result_type operator()(const string& key) const
        {
            result_type result = 5381;

            for (string::size_type i = 0; i < key.length(); ++i)
            {
                result = ((result << 5) + result) + key[i];
            }

            return result;
        }
    };
}

#endif /* !PEELO_FUNCTIONAL_HASH_HPP_GUARD */