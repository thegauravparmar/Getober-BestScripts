 int func(vector<int>&A, int B)
 {
    int l=0,h=A.size()-1;
    int x=0;
    int n = A.size();

    //rotated count function
    while(l<=h)
    {
        int mid = l + (h - l) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
 
        if (A[mid] <= A[prev]&& A[mid] <= A[next])
            {
                x= mid;
            break;
            }
        else if (A[mid] <= A[h])
            h = mid - 1;
        else if (A[mid] >= A[l])
            l = mid + 1;
    }

    l=0;h=x-1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(A[mid]==B)
        return mid;
        else if(A[mid]>B)
        h=mid-1;
        else
        l=mid+1;
    }
    l=x;h=A.size()-1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(A[mid]==B)
        return mid;
        else if(A[mid]>B)
        h=mid-1;
        else
        l=mid+1;
    }
    return -1;
 }
