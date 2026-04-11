class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, 
        vector<int>, 
        greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
    }
    
    double findMedian() {
        int n = maxHeap.size();
        int x = n%2 ? (n-1)/2 : n/2;

        while(x--) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }

        double median = n%2 ? maxHeap.top() : 
            (maxHeap.top() + minHeap.top())/(double)2;
        
        while(!minHeap.empty()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        return median;
    }
};
