class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, 
        vector<int>, 
        greater<int>> minHeap;
    MedianFinder() {
        
    }

    void normalizeHeaps() {
        int n = maxHeap.size();
        int m = minHeap.size();
        while(n - m > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            n = maxHeap.size();
            m = minHeap.size();
        }

        n = maxHeap.size();
        m = minHeap.size();
        while(m - n > 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();

            n = maxHeap.size();
            m = minHeap.size();
        }
    }
    
    void addNum(int num) {
        if(minHeap.empty() ||
        minHeap.top() < num)
            minHeap.push(num);
        else
            maxHeap.push(num);

        normalizeHeaps();
    }
    
    double findMedian() {
        int n = maxHeap.size();
        int m = minHeap.size();

        if(n == m)  
            return (maxHeap.top() + minHeap.top())/(double)2;
        if(n > m)   return maxHeap.top();
        return minHeap.top();
    }
};






