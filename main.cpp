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
    writer.read();
    return 0;
}
