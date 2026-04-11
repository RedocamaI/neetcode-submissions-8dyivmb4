class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, 
        vector<int>, 
        greater<int>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq1.push(num);
    }
    
    double findMedian() {
        int n = pq1.size();
        int x = n%2 ? (n-1)/2 : n/2;

        while(x--) {
            int val = pq1.top();
            pq1.pop();
            pq2.push(val);
        }

        double median = n%2 ? pq1.top() : 
            (pq1.top() + pq2.top())/(double)2;
        
        while(!pq2.empty()) {
            pq1.push(pq2.top());
            pq2.pop();
        }

        return median;
    }
};
