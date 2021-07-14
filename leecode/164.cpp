#include <iostream>
#include <vector>
using namespace std;

void myswap(int &a ,int &b){
    int temp = a;
    a=b;
    b=temp;
}

void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边

}
int maximumGap(vector<int>& nums) {
	
    // for(int i =0; i<nums.size();i++){
        
    //     if(nums[i]>nums[nums.size()-1]){
    //         myswap(nums[i],nums[nums.size()-1]);
    //     }
    //  }
    quickSort(0,nums.size()-1,nums);

    int maxerror=0;
    for(int k=0;k<nums.size()-1;k++){
        maxerror=(maxerror>nums[k+1]-nums[k]) ? maxerror:nums[k+1]-nums[k];
    }
    return maxerror;
}

int main(int argc, char const *argv[])
{
    int b[4]={100,3,2,1};
    vector<int> a(b,b+4);
    cout<<maximumGap(a)<<endl;
	//cout<<a.begin()<<endl;
    return 0;
}
