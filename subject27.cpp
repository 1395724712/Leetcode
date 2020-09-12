#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    //思路：双指针，前指针指向当前元素，后结点寻找与val不同的元素
    int curr_pos = 0;
    int lat_pos = nums.size()-1;
    //记录不重复元素的数量
    int count = 0;
    //特殊情况1：如果只有一个元素
    if(nums.size()==1)
    {
       if(nums[0]==val)
        {
            return 0;
        }
        else
        {
            return 1;
        }   
    }
    //特殊情况2：没有元素
    if(nums.size()==0)
    {
        return  0;
    }
    while(lat_pos>=curr_pos)
    {
        // count++;
        if(nums[curr_pos]==val)
        {
            if(nums[lat_pos]!=val)
            {
                swap(nums[curr_pos],nums[lat_pos]);
            }
            lat_pos--;
        }
        if (nums[curr_pos]!=val)
        {
            /* code */
            curr_pos++;

            count++;
        }
        
    }

    if(nums[curr_pos]!=val&&curr_pos!=nums.size())
    {
        count++;
    }

    return count;        
}

int main()
{
    vector<int> nums = {3,3};

    // cout<<nums.size()<<endl;

    int val=5;

    int  count = removeElement(nums,val);

    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        cout<<nums[i]<<endl;
    }
    
    cout<<count<<endl;

    system("pause");
    return 0;    
}