#include <iostream>
#include <vector>
using namespace std;

int maximumGap(vector<int>& nums) {
    int i, j, temp;
	for (j = 0; j < nums.size() - 1; j++)
	{
		for (i = 0; i < nums.size() - 1 - j; i++)
		if (nums[i] > nums[i + 1])
		{
			temp = nums[i];
			nums[i] = nums[i + 1];
			nums[i + 1] = temp;
		}
	}

    int maxerror=0;
    for(int k=0;k<nums.size()-1;k++){
        maxerror=(maxerror>nums[k+1]-nums[k]) ? maxerror:nums[k+1]-nums[k];
    }
    return maxerror;
}

int main(int argc, char const *argv[])
{
    int b[7]={1,6,3,23,5,6,0};
    vector<int> a(b,b+7);
    cout<<maximumGap(a)<<endl;
    return 0;
}
