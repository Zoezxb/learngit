/*
	剑指offer41 
	数据流中的中位数
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,greater<int>>a;// 小顶堆
    priority_queue<int,vector<int>,less<int>>b; //大顶堆
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(a.size()!=b.size())
        {
            a.push(num);
            auto t = a.top();
            a.pop();
            b.push(t);
        }
        else
        {
            b.push(num);
            auto t = b.top();
            b.pop();
            a.push(t);
        }
    }
    
    double findMedian() {
        if(a.size()!=b.size())
        {
            return a.top();
        }
        else
        {
            cout<<a.top()<<" "<<b.top()<<endl;
            return (a.top()+b.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */