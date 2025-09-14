#include "char_utils.h"
#include <cctype>
using namespace std;

namespace char_utils {
    char invertLetterCase(char c){
        return isupper(c) ? tolower(c) : toupper(c);
    }
}