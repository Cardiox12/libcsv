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
            csv(const char *filename) : m_filename{ filename }, m_sep{ SEP::comma } {};
            csv(std::string &filename) : m_filename{ filename }, m_sep{ SEP::comma } {};
            csv(std::string &filename, SEP sep) : m_filename{ filename }, m_sep{ SEP::comma } {};

            void            write_rows(const vec_string_vec &rows) const;
            void            write_row(const std::vector<std::string> &row) const;
            vec_string_vec  read() const;

            template<typename T>
            void            write_col(T &val) const;
    };

    void csv::write_rows(const vec_string_vec &rows) const {
        for ( const auto &row : rows ){
            write_row( row );
        }
    }

    void csv::write_row(const std::vector<std::string> &row) const {
        std::ofstream file{ m_filename, std::ios_base::app };

        for ( const auto &item : row ){
            file << item;

            if ( &item != &row.back() ){
                file << static_cast<char>( m_sep );
            }
        }
        file << std::endl;
        file.close();
    }

    template<typename T>
    void csv::write_col(T &val) const {
        std::ofstream file{ m_filename, std::ios_base::app };

        file << val;
        file.close();
    }

    vec_string_vec csv::read() const {
        vec_string_vec result;
        std::ifstream file{ m_filename };
        std::string line;

        while ( ( std::getline( file, line ) ) ){
            std::cout << line << std::endl;
        }
        return (result);
    }
};

#endif // CSV_H
