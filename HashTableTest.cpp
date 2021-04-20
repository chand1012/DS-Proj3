
#include <cassert>

#include "HashTable.hpp"
#include "helpers.hpp"

int main() {
    {
        HashTable table;
        assert(table.isEmpty());
        assert(table.size() == 0);
    }
    return 0;
}