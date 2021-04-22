#include "helpers.hpp"

string randString(int length) {
    string temp;
    for (int i = 0; i < length; ++i) {
        int charpos = rand() % CHARSET_LENGTH;
        temp += CHARSET.substr(charpos, 1);
    }

    return temp;
}

string randString(int length, string charset) {
    string temp;
    for (int i = 0; i < length; ++i) {
        int charpos = rand() % charset.size();
        temp += charset.substr(charpos, 1);
    }

    return temp;
}

int randint(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}