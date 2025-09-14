#pragma once
#include <string>
#include <vector>
using namespace std;

namespace string_utils {
    string upperAllString(string str);
    string lowerAllString(string str);
    vector<string> splitString(string str, const string& delimiter);
    string joinString(const vector<string>& vString, const string& delimiter);
    string joinString(string strArr[], short arrSize, const string& delimiter);
    string trimLeft(string str);
    string trimRight(string str);
    string trim(string str);
    string reverseWordsInString(string str);
    string replace(string str, const string& targetWord, const string& replacementWord, bool matchCase);
    string removePunctuationsFromString(string str);
}