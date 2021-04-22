#pragma once

#include <string> 
#include <cstdlib>

using std::string;

static const string CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const size_t CHARSET_LENGTH = 62;

string randString(int length);

string randString(int length, string charset);

int randint(int start, int end);