#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp;
        int y = 0;
        int imax = 2147483647, imin = -2147483648;
        if( x > 1e09 - 1 || x < -1e09 + 1){
            for(int i =0;i < 9; i++ ){
                temp = x % 10;
                x = x / 10;
                y = y * 10 + temp;
            }
            if(y > imax/10 || y < imin/10){
                return 0;
            }else if(y == imax/10 || y == imin/10){
                if(x > 7 || x < -8){
                    return 0;
                    } else {
                        return y*10+x;
                    }
            }else{
                return y*10+x;
            }

            return 0;
        }

        while(x !=0 ){
            temp = x % 10;
            x = x / 10;
            y = y * 10 + temp;
        }
        return y;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}