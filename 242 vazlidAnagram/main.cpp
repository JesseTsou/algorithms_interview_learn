#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

/*
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
 */

class Solution {
public:
    /*
     * 时间复杂度：O(nlogn)
     */
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        bool isanagram = true;
        map<int, int> map1;
        for (int e:s)
        {
            map1[e] ++;
        }

        for (int e:t)
        {
            if(map1[e] > 0){
                map1[e] --;
            }else{
                isanagram = false;
                break;
            }
        }
        return isanagram;
    }
    /*
     * 时间复杂度：O(n)
     */
    bool isAnagram2(string s, string t) {
        if(s.size() != t.size())
            return false;
        bool isanagram = true;
        unordered_map<int, int> map1;
        for (int e:s)
        {
            map1[e] ++;
        }

        for (int e:t)
        {
            if(map1[e] > 0){
                map1[e] --;
            }else{
                isanagram = false;
                break;
            }
        }
        return isanagram;
    }

    /*
     * 时间复杂度：O(n)
     * 使用数组存储字母元素次数
     * 最后作比较
     */
    bool isAnagram3(string s, string t) {
        int ch1[26] = {0};
        int ch2[26] = {0};

        if (s.size() != t.size())
            return false;

        for (int e:s)
            ch1[e - 'a'] ++;

        for (int e:t)
            ch2[e - 'a'] ++;

        for (int i = 'a'; i <= 'z'; i ++)
        {
            if (ch1[i - 'a'] != ch2[i - 'a']){
                return false;
            }
        }
        return true;
    }
};

int print(string str)
{
    cout << str << endl;
}

int main() {
    string str1="anagram";
    string str2="angarma";

    print(str1);
    print(str2);

    Solution s;
    if(s.isAnagram3(str1, str2)) {
        cout << "is anagram" << endl;
    }else{
        cout << "is not anagram" << endl;
    }

    return 0;
}