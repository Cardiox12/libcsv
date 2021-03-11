#include <iostream>
#include "csv.hpp"

int main() {
    csv::csv writer{ "./data.csv" };
    csv::vec_string_vec rows = {
            { "h1", "h2", "h3" },
            { "lorem", "ipsum", "lorem" },
            { "ipsum", "lorem", "ipsum" }
    };

    writer.write_rows( rows );
    csv::vec_string_vec matrix = writer.read();

    for ( const auto &row : matrix ){
        for ( const auto &col : row ){
            std::cout << col << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}
