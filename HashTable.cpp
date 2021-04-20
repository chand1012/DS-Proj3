#include "HashTable.hpp"

#include <limits>

// private functions
int HashTable::hashKey(string key) {
    // hash function is just the length
    // of the string as an integer
    return int(key.size());
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
        table.resize(hash * 2);
    }

    vector<HashNode>& values = table.at(hash);
    values.push_back(temp);
}

bool HashTable::remove(string key) {
    int hash = hashKey(key);
    vector<HashNode>& values = table.at(hash);

    for (auto it = values.begin(); it != values.end(); ++it) {
        HashNode temp = *it;
        if (temp.key == key) {
            values.erase(it);
            return true;
        }
    }

    return false;
}

// gets value. Returns numeric min if not found
int HashTable::get(string key) {
    int hash = hashKey(key);
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
    return table.size();
}

size_t HashTable::size(string key) {
    int position = hashKey(key);
    vector<HashNode>& values = table.at(position);
    return values.size();
}

bool HashTable::isEmpty() {
    return table.empty();
}

bool HashTable::isEmpty(string key) {
    int position = hashKey(key);
    vector<HashNode>& values = table.at(position);
    return values.empty();
}