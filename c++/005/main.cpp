#include <iostream>
#include <assert.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ress;
        int n = s.size();
        int a = 0, b = 0, c = 0, d = 0;
        if (n < 3)
        {
            if (n == 1)
            {
                ress = s;
                return ress;
            }
            if (n == 2)
            {
                if (s[1] == s[0])
                {
                    ress = s;
                    return ress;
                }
                else
                {
                    ress = s[0];
                    return ress;
                }
            }
        }
        if (n > 1)
        {
            if (s[1] == s[0])
            {
                a = 1;
                b = 1;
            }
        }
        for (int i = 2; i < n; i++)
        {
            int j = 0;
            if (s[i] == s[i - 1])
            {
                for (j = 0; i + j + 1 < n && i - j - 2 >= 0; j++)
                {
                    if (s[i + j + 1] != s[i - j - 2])
                    {
                        break;
                    }
                }
                if (j + 1 > b)
                {
                    a = i;
                    b = j + 1;
                }
            }
            if (s[i] == s[i - 2])
            {
                for (j = 0; i + j + 1 < n && i - j - 3 >= 0; j++)
                {
                    if (s[i + j + 1] != s[i - j - 3])
                    {
                        break;
                    }
                }
                if (j + 1 > d)
                {
                    c = i;
                    d = j + 1;
                }
            }
        }
        if (a + b + c + d == 0)
        {
            ress = s[0];
            return ress;
        }
        if (2 * d + 1 > 2 * b)
        {
            ress = s.substr(c - d - 1, 2 * d + 1);
        }
        else
        {
            ress = s.substr(a - b, 2 * b);
        }
        return ress;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}