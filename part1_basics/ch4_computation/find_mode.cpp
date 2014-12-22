/* Takes a series of integers as input and finds the mode*/
#include "../std_lib_facilities.h"

int main() 
{
    cout << "Enter a set of integers. Enter any non-numeric value"
        << " (i.e. '|') to end input\n";
    
    /*Create vector*/
    vector<int>nums;
    for(int num; cin>>num; )
        nums.push_back(num);

    /*Find mode*/
    sort(nums);
    int mode = nums[0];
    int count = 1;
    int max_count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            count = 1;
        }
        else {
            count++;
            if (count > max_count) {
                mode = nums[i];
                max_count = count;
            }
        }
    }//End for

    cout << "The mode is " << mode << "\n";

    return 0;
}
