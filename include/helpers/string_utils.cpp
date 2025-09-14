#include "string_utils.h"
#include <cctype>
using namespace std;

namespace string_utils {

    string upperAllString(string str) {
        for (char &c : str) 
            c = toupper(c);
        return str;
    }

    string lowerAllString(string str) {
        for (char &c : str) 
            c = tolower(c);
        return str;
    }

    vector<string> splitString(string str, const string& delimiter) {
        vector<string> vString;
        size_t pos;
        string word;
        while ((pos = str.find(delimiter)) != string::npos) {
            word = str.substr(0, pos);
            if (!word.empty()) 
                vString.push_back(word);
            str.erase(0, pos + delimiter.length());
        }
        if (!str.empty()) 
            vString.push_back(str);
        return vString;
    }

    string joinString(const vector<string>& vString, const string& delimiter) {
        string str = "";
        for (const string& w : vString) 
            str += w + delimiter;
        if (!str.empty()) 
            str = str.substr(0, str.size() - delimiter.size());
        return str;
    }

    string joinString(string strArr[], short arrSize, const string& delimiter) {
        string str = "";
        for (int i = 0; i < arrSize; i++) 
            str += strArr[i] + delimiter;
        if (!str.empty()) 
            str = str.substr(0, str.size() - delimiter.size());
        return str;
    }

    string trimLeft(string str) {
        while (!str.empty() && str[0] == ' ') 
            str.erase(0, 1);
        return str;
    }

    string trimRight(string str) {
        while (!str.empty() && str[str.size() - 1] == ' ') 
            str.erase(str.size() - 1, 1);
        return str;
    }

    string trim(string str) {
        return trimLeft(trimRight(str));
    }

    string reverseWordsInString(string str) {
        vector<string> words = splitString(str, " ");
        string result = "";
        for (auto it = words.rbegin(); it != words.rend(); ++it) 
            result += *it + " ";
        if (!result.empty()) 
            result.pop_back();
        return result;
    }

    string replace(string str, const string& targetWord, const string& replacementWord, bool matchCase) {
        vector<string> words = splitString(str, " ");
        for (string& w : words) {
            if (matchCase ? (w == targetWord) : (lowerAllString(w) == lowerAllString(targetWord))) {
                w = replacementWord;
            }
        }
        return joinString(words, " ");
    }

    string removePunctuationsFromString(string str) {
        string result = "";
        for (char c : str) 
            if (!ispunct(c)) 
                result += c;
        return result;
    }

}