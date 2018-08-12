#include <iostream>
#include <string>
using namespace std;
int print(string str)
{
    cout << str << endl;
    return 0;
}
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l <= r)
        {
            if ()
        }

    }
};

int main() {
    string str = "A man, a plan, a canal: Panama";
    print(str);
    Solution s;
    if (s.isPalindrome(str)){
        cout << "is palindrome" << endl;
    }
    else {
        cout << "is not palindrome" << endl;
    }
    return 0;
}