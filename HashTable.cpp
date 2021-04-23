#include "HashTable.hpp"

#include <limits>

// private functions
int HashTable::hashKey(string key) {
    // hash function is just the length
    // of the string as an integer
    int hash = 0;
    int temp;
    for (int i = 0; i < key.size(); ++i) {
        temp = static_cast<unsigned char>(key.at(i));
        hash += temp;
    }
    return hash;
}

// public functions
HashTable::HashTable(int init_size) {
    table.resize(init_size);
}

HashTable::HashTable() {}

HashTable::~HashTable() {}

void HashTable::add(string key, int value) {
    HashNode temp;
    temp.key = key;
    temp.value = value;
    int hash = hashKey(key);

    int current_size = int(size());

    if (current_size < hash) {
        rows = hash + 1;
        table.resize(rows);
    }

    vector<HashNode>& values = table.at(hash);
    values.push_back(temp);
}

bool HashTable::remove(string key) {
    int hash = hashKey(key);

    if (hash > rows) {
        return std::numeric_limits<int>::min();
    }
    
    vector<HashNode>& values = table.at(hash);

    for (auto it = values.begin(); it != values.end(); ++it) {
        HashNode temp = *it;
        if (temp.key == key) {
            values.erase(it);
            --rows;
            return true;
        }
    }

    return false;
}

// gets value. Returns numeric min if not found
int HashTable::get(string key) {
    int hash = hashKey(key);

    if (hash > rows) {
        return std::numeric_limits<int>::min();
    }

    vector<HashNode>& values = table.at(hash);

    for (auto it = values.begin(); it != values.end(); ++it) {
        HashNode temp = *it;
        if (temp.key == key) {
            return temp.value;
        }
    }

    return std::numeric_limits<int>::min();
}

size_t HashTable::size() {
    return rows;
}

size_t HashTable::size(int hash) {
    vector<HashNode>& values = table.at(hash);
    return values.size();
}

bool HashTable::isEmpty() {
    return table.empty();
}

bool HashTable::isEmpty(int hash) {
    vector<HashNode>& values = table.at(hash);
    return values.empty();
}