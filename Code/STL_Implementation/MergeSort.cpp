void merge(int arr[], int l, int mid, int h){
    int i = l, j = mid+1;
    vector<int> vec(h-l+1);
    while(i<=mid || j <= h){
        int small = 0;
        if (i>mid) small = arr[j++];
        else if (j>h) small = arr[i++];
        else if (arr[i] < arr[j]) small = arr[i++];
        else small = arr[j++];
        
        vec[((i-l)+(j-(mid+1))) - 1] = small;
    }
    for (int i = l; i <= h; i++){
        arr[i] = vec[i-l];
    }
}
void mergesort(int arr[], int l, int h){
    if (l<h){
        int mid = (l+h)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

/*
mergesort(vec, 0, size-1);
*/
