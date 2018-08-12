#include <iostream>
#include <string>
using namespace std;
/*
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
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
     * 从两边开始向中间扫描，跳过不满足条件的字符
     * 若对应有不相等的，则为false
     * 但是判断实在是太复杂了
     */
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while (!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9')) && l <= s.size() - 1)
                l++;
            while (!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9')) && r >= 0)
                r--;
            if(s[r] >= 'A' && s[r] <= 'Z' )
                s[r] += 32;
            if(s[l] >= 'A' && s[l] <= 'Z'  )
                s[l] += 32;
            if (s[l] != s[r]){
                return false;
            }else{
                l++;
                r--;
            }
        }
        return true;
    }
    /*
     *使用isalnum判断是否为字母与数字
     */
    bool isPalindrome2(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while (!(isalnum(s[l])) && l <= s.size() - 1)
                l++;
            while (!(isalnum(s[r])) && r >= 0)
                r--;
            if(s[r] >= 'A' && s[r] <= 'Z' )
                s[r] += 32;
            if(s[l] >= 'A' && s[l] <= 'Z'  )
                s[l] += 32;
            if (s[l] != s[r]){
                return false;
            }else{
                l++;
                r--;
            }
        }
        return true;
    }
};

int main() {
    //string str = "A man, a plan, a canal: Panama";
    //string str = "race a car";;
    //string str = " ";
    string str = ",.";
    print(str);
    Solution s;
    if (s.isPalindrome2(str)){
        cout << "is palindrome" << endl;
    }
    else {
        cout << "is not palindrome" << endl;
    }
    return 0;
}