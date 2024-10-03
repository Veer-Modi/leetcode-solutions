int removeDuplicates(int* nums, int numsSize) {
    int count=1;
    int i,j=0;
    for(i=1;i<numsSize;i++){
    if(nums[i]!=nums[j]){
        j++;
        count++;
    nums[j]=nums[i];
    }
    }
    return count;
}