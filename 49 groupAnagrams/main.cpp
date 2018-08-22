#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 */
class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 重点是明确map需要查找什么
     * 将每个字符串排序后，以 排序后的字符串 为键，以 原始字符串的容器 为值
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map1;
        for(auto e:strs){
            string tmp = e;
            //排序，则异位词排序后会成为相同的词，以该词为键，各个异位词的容器为值
            sort(tmp.begin(),tmp.end());
            map1[tmp].push_back(e);
        }

        for (auto e:map1){
            res.push_back(e.second);
        }
        return res;
    }
};

int print(vector<vector<string>> vec)
{
    for (auto e1:vec){
        for (auto e2:e1){
            cout << e2 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ret = s.groupAnagrams(str);
    print(ret);
    return 0;
}