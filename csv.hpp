//
// Created by Cardi on 3/10/2021.
//

#ifndef CSV_H
#define CSV_H

#include <fstream>
#include <string>
#include <vector>

namespace csv {
    using vec_string_vec = std::vector<std::vector<std::string>>;

    enum class SEP : char {
        comma = ',',
        semicol = ';'
    };

    class csv {
            std::string m_filename;
            SEP         m_sep;
        public:
            csv() : m_sep{ SEP::comma } {};
            csv(std::string &filename) : m_filename{ filename }, m_sep{ SEP::comma } {};
            csv(std::string &filename, SEP sep) : m_filename{ filename }, m_sep{ SEP::comma } {};

            void    write_rows(vec_string_vec &rows);
            void    write_row(std::vector<std::string> &row);
    };
};

#endif // CSV_H
