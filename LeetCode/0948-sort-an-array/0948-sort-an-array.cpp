class Solution {
private:
    int partition(vector<int>& temp, int lo, int hi) {
        int i = lo-1, j = hi+1;
        int pivot = temp[lo];
        while(true) {
            do {i = i+1;} while(temp[i] < pivot);
            do {j = j-1;} while(temp[j] > pivot);
            if(i >= j) return j;
            swap(temp[i], temp[j]);
        }
        return -1;
    }
    void quicksort(vector<int>& temp, int lo, int hi) {
        if(lo >= hi or lo < 0) return;

        int pivot = temp[lo];

        // hoare partition scheme

        int p = partition(temp, lo, hi);
        
        quicksort(temp, lo, p);
        quicksort(temp, p+1, hi);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp = nums;
        quicksort(temp, 0, nums.size()-1);
        return temp;
    }
};