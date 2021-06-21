#include<iostream>
#include<assert.h>
#include<math.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ilength = 0;
        int istep = 0;
        if(s.size() < 2) return s.size();
        for(int i = 1; i < s.size(); i++ ){
            for(int j = istep; j < i; j++){
                if(s[i] == s[j]) {
 //                   ilength = ilength > i-istep ? ilength : i-istep;
                    ilength = max(ilength,i-istep);
                    istep = j + 1;
                    break;
                }
                else if((i == s.size()-1) && (j == s.size()-2)){
//                    ilength = ilength > i+1-istep ? ilength : i+1-istep;
                    ilength = max(ilength,i+1-istep);
                }
            }
             
        }
        return ilength;     
    }

};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}