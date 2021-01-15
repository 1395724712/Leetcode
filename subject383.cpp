/**
 * Copyright@wh
 * Author:wh
 * Date:20210112
 * Description：从一个字符串中找另一个字符串中的元素，且同一个字符不能出现两次
 * Resolution:方法是数组，但我想用map
*/

#include<string>
#include<map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> tab;
        for(const auto elem : magazine){
            tab[elem]++;
        }
        //然后到ransomNote中进行对比
        for(const auto elem : ransomNote){
            if(tab[elem]==0){
                return false;
            }
            tab[elem]--;
        }
        return true;

    }
};