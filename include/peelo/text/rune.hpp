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
#ifndef PEELO_TEXT_RUNE_HPP_GUARD
#define PEELO_TEXT_RUNE_HPP_GUARD

namespace peelo
{
    /**
     * The Rune class represents single 32-bit Unicode character.
     */
    class rune
    {
    public:
        typedef unsigned int value_type;

        /** Minimum value for rune (zero). */
        static const rune min;
        /** Maximum value for rune. */
        static const rune max;

        /**
         * Empty constructor. Value of the rune is set to zero.
         */
        rune();

        /**
         * Copy constructor.
         */
        rune(const rune& that);

        explicit rune(value_type code);

        inline value_type code() const
        {
            return m_code;
        }

        rune& assign(const rune& that);
        rune& assign(value_type code);

        inline rune& operator=(const rune& that)
        {
            return assign(that);
        }

        inline rune& operator=(value_type code)
        {
            return assign(code);
        }

        bool equals(const rune& that) const;
        bool equals(value_type code) const;

        bool equals_icase(const rune& that) const;
        bool equals_icase(value_type code) const;

        inline bool operator==(const rune& that) const
        {
            return equals(that);
        }

        inline bool operator!=(const rune& that) const
        {
            return !equals(that);
        }

        inline bool operator==(value_type code) const
        {
            return equals(code);
        }

        inline bool operator!=(value_type code) const
        {
            return !equals(code);
        }

        int compare(const rune& that) const;
        int compare(value_type code) const;

        int compare_icase(const rune& that) const;
        int compare_icase(value_type code) const;

        inline bool operator<(const rune& that) const
        {
            return compare(that) < 0;
        }

        inline bool operator>(const rune& that) const
        {
            return compare(that) > 0;
        }

        inline bool operator<=(const rune& that) const
        {
            return compare(that) <= 0;
        }

        inline bool operator>=(const rune& that) const
        {
            return compare(that) >= 0;
        }

        inline bool operator<(value_type code) const
        {
            return compare(code) < 0;
        }

        inline bool operator>(value_type code) const
        {
            return compare(code) > 0;
        }

        inline bool operator<=(value_type code) const
        {
            return compare(code) <= 0;
        }

        inline bool operator>=(value_type code) const
        {
            return compare(code) >= 0;
        }

        /**
         * Returns lower case equivalent if character is upper case.
         */
        rune to_lower() const;

        /**
         * Returns upper case equivalent if character is lower case.
         */
        rune to_upper() const;

        /**
         * Returns <code>true</code> if rune is alphanumeric character.
         */
        bool is_alnum() const;

        /**
         * Returns <code>true</code> if rune is alphabetic character.
         */
        bool is_alpha() const;

        bool is_ascii() const;

        bool is_blank() const;

        /**
         * Returns <code>true</code> if rune is control sequence.
         */
        bool is_cntrl() const;

        /**
         * Returns <code>true</code> if rune is ASCII decimal digit character.
         */
        bool is_digit() const;

        /**
         * Returns <code>true</code> if rune is any printing character, except
         * space and other locale specific space like character.
         */
        bool is_graph() const;

        /**
         * Returns <code>true</code> if rune is lower case letter.
         */
        bool is_lower() const;

        /**
         * Returns <code>true</code> if rune is any number character in any
         * locale.
         */
        bool is_number() const;

        /**
         * Returns <code>true</code> if rune is any printable character,
         * including space.
         */
        bool is_print() const;

        /**
         * Returns <code>true</code> if rune is any punctuation character,
         * except space or alphanumeric character.
         */
        bool is_punct() const;

        /**
         * Returns <code>true</code> if rune is whitespace character.
         */
        bool is_space() const;

        /**
         * Returns <code>true</code> if rune is upper case letter.
         */
        bool is_upper() const;

        bool is_word() const;

        /**
         * Returns <code>true</code> if rune is hexadecimal character.
         */
        bool is_xdigit() const;

    private:
        value_type m_code;
    };
}

#endif /* !PEELO_TEXT_RUNE_HPP_GUARD */