//#This method returns only true or false
bool binarySearch(int arr[], int size, int num){
    int m,
    l = 0,
    r = size-1;
    while (l <= r){
        m = (l+r)/2;
        if (num == arr[m])
            return true;
        else if (num < arr[m])
            r = m-1;
        else
            l = m+1;
    }
    return false;
}
/*
binarySearch(arr, size, abs(money-arr[i]))
*/
