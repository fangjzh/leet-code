#include<iostream>
#include<assert.h>
#include<math.h>
using namespace std;

class Solution {
public:
    int hashmap[130];
    int lengthOfLongestSubstring(string s) { //双指针滑动窗口
        int max=0;
        int n = s.size();
        for(int i=0,j=0;j<n;j++){//当前判断是否重复的串为s[i..j]
            hashmap[s[j]]++;  
            while(hashmap[s[j]]>1){
                hashmap[s[i++]]--;  //i指针右移 
                //数组下标赋值++优先级，应当先s[i]赋值后i++
                //如果是s[++i],则先i++
                //这里的顺序 hashmap[s[i]]--  然后i++
            }
            if(j-i+1>max)
                max = j-i+1;
        }
        return max;     
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