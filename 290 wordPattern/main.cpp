#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using  namespace std;

/*
 * 给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。
 */

class Solution {
public:

    vector<string> getvec(string str, string tar)
    {
        vector<string> vec;
        string::size_type pos1, pos2;
        pos1 = str.find(tar);
        pos2 = 0;
        while(pos1 != string::npos){
            vec.push_back(str.substr(pos2, pos1-pos2));
            pos2 = pos1 + tar.size();
            pos1=str.find(tar,pos2);
        }
        if (pos2 != str.size()){
            vec.push_back(str.substr(pos2));
        }
        return vec;
    }

    bool wordPattern(string pattern, string str) {
        unordered_map<int,string> map1;
        unordered_map<string,int> map2;
        vector<string> vec = getvec(str, " ");

        if (pattern.size() != vec.size()){
            return false;
        }

        for(int i = 0; i < pattern.size(); i ++)
        {
            if(map1.find(pattern[i]) != map1.end()){
                if(map1[pattern[i]] != vec[i]){
                    return false;
                }
            }
            else{
                map1.insert(unordered_map<int,string>::value_type((int)pattern[i],vec[i]));
            }

            if(map2.find(vec[i]) != map2.end()){
                if(map2[vec[i]] != pattern[i]){
                    return false;
                }
            }
            else{
                map2.insert(unordered_map<string,int>::value_type(vec[i],(int)pattern[i]));
            }
        }

        return true;
    }
};

int main() {
    string str1 = "abba";
    string str2 = "dog dog dog dog";

    Solution s;
    if (s.wordPattern(str1, str2)){
        cout << "is match" << endl;
    }else{
        cout << "is not match" << endl;
    }


    return 0;
}