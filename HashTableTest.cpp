#include <cassert>
#include <iostream>
#include <limits>

#include "HashTable.hpp"
#include "helpers.hpp"

using namespace std;

int main() {
    { // test init
        HashTable table;
        assert(table.isEmpty());
        assert(table.size() == 0);
    }

    { // test functionality
        HashTable table;
        table.add("test", 0);
        table.add("test1", 1);
        table.add("test2", 2);
        table.add("test3_", 3);

        // test if elements were added 
        // correctly
        assert(!table.isEmpty());
        assert(table.size() == 4);

        // test getting
        assert(table.get("test") == 0);
        assert(table.get("test1") == 1);
        assert(table.get("test2") == 2);
        assert(table.get("test3_") == 3);

        // test lengths
        for (int i = 0; i < 4; ++i) {
            assert(table.size(i) == 0);
        }
        assert(table.size(4) == 1);
        assert(table.size(5) == 2);
        assert(table.size(6) == 1);

        // test removal
        bool removed = table.remove("test");
        assert(removed);
        assert(table.get("test") == std::numeric_limits<int>::min());
        
        // test that the hash of 4 is empty
        assert(table.isEmpty(4));
    }

    
    return 0;
}