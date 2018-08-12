#include <iostream>
#include <string>
using namespace std;
/*
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 */
int print(string str)
{
    cout << str << endl;
    return 0;
}

class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 从数组两边向中间遍历，作判断是否为元音，并作交换
     */
    bool isVowels(char ch) {
        bool ret = false;
        switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            ret = true;
            break;
        default:
            break;
        }
        return ret;
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            if (!isVowels(s[l])){
                l++;
            }
            else if (!isVowels(s[r])){
                r--;
            }else {
                swap(s[l++],s[r--]);
            }
        }
        return s;
    }
};

int main() {
    //string str = "A man, a plan, a canal: Panama";
    //string str = "hello";;
    string str = "leetcode";
    //string str = " ";
    print(str);
    Solution s;
    string str2 = s.reverseVowels(str);
    print(str2);
    return 0;
}