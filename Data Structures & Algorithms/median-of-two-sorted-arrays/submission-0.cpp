class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> med;
        int i = 0, j = 0;
        int n = a.size();
        int m = b.size();

        while(i < n && j < m){
            if(a[i] < b[j]){
                med.push_back(a[i]);
                i++;
            }else{
                med.push_back(b[j]);
                j++;
            }
        }

        while(i < n){
            med.push_back(a[i]);
            i++;
        }

        while(j < m){
            med.push_back(b[j]);
            j++;
        }

        if(med.size()%2)    return med[med.size()/2];
        
        return (med[med.size()/2] + med[med.size()/2 - 1]) / (double)2;
    }
};
