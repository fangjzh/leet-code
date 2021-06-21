#include<vector>
#include<iostream>
#include <algorithm>
#include <sstream> 
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int isize,isize1,isize2,num1=0,num2=0;
        double a1=0,a2=0,result;
        isize1 = nums1.size();
        isize2 = nums2.size();
        isize =isize1 + isize2;
        
        
        for(int i=0;i<isize/2+1;i++)
            {
                if(num1<isize1 && num2<isize2){
                    if(nums1[num1]<nums2[num2])
                    {
                        a1=a2;a2=nums1[num1];
                        num1++;
                    }else
                    {
                        a1=a2;a2=nums2[num2];
                        num2++;
                    }
                }else if(num1<isize1)
                {
                    a1=a2;a2=nums1[num1];
                    num1++; 
                }else if(num2<isize2)
                {
                    a1=a2;a2=nums2[num2];
                    num2++;
                }
            }
        
        if(isize%2==0){
            result = (a1+a2)/2;
            }
        else{
            result = a2;
            }
        
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
