void nextPermutation(vector<int>& nums) {
    //Find first decreasing element -> a[i-1]
    //Finding just larger than a[i-1] -> a[j]
    //swap(a[i-1],a[j])
    //reverse(i,n)
    int firstDecreasingElement = -1;
    for (int i = nums.size()-1; i>0; i--){
        if (nums[i]>nums[i-1]){
            firstDecreasingElement = i-1;
            break;
        }
    }
    if (firstDecreasingElement==-1){
        sort(nums.begin(),nums.end());
        return;
    }
    int lastLarger = firstDecreasingElement+1;
    for (int i = firstDecreasingElement+1; i < nums.size(); i++){
        if (nums[i]<=nums[firstDecreasingElement]) break;
        lastLarger = i;
    }
    swap(nums[firstDecreasingElement],nums[lastLarger]);
    reverse(nums.begin()+firstDecreasingElement+1, nums.end());
}
