class PriorityQueue {
    constructor() {
        this.arr = [];
    }
    push(a) {
        this.arr.push(a);
        this.heapifyUp();
    }
    pop() {
        if (this.arr.length === 0) return null;
        if (this.arr.length === 1) return this.arr.pop();
        
        let top = this.arr[0];
        this.arr[0] = this.arr.pop();
        this.heapifyDown();
        return top;
    }
    top() {
        return this.arr[0];
    }
    size() {
        return this.arr.length;
    }
    heapifyUp() {
        let index = this.arr.length - 1;
         
        while (index > 0) {
            let parent = Math.floor((index - 1) / 2);
            if (this.arr[parent] <= this.arr[index]) break;
            
            [this.arr[index], this.arr[parent]] =
                [this.arr[parent], this.arr[index]];
            
            index = parent;
        }
    }
    heapifyDown() {
        let index = 0;
        let length = this.arr.length;
        
        while(1) {
            let left_child = index * 2+1;
            let right_child = index * 2 + 2;
            let smallest = index;
            
            if(left_child < length &&
               this.arr[left_child] < this.arr[smallest])
                smallest = left_child;
            if(right_child < length &&
               this.arr[right_child] < this.arr[smallest])
                smallest = right_child;
            
            if(index == smallest) break;
            
            [this.arr[index], this.arr[smallest]] = 
                [this.arr[smallest], this.arr[index]];
            
            index = smallest;
        }
    }
}

function solution(scoville, K) {
    let pq = new PriorityQueue();
    
    for(let i=0; i<scoville.length; i++){
        pq.push(scoville[i]);
    }
   console.log(pq.top());
    let count = 0;
    
    while(pq.top() < K){
        if(pq.size() == 1){
            count = -1;
            break;
        }
        
        count++;
        
        let first = pq.pop();
        let second = pq.pop();
        
        let new_scoville = first + second * 2;
        pq.push(new_scoville);
    }
    
    return count;
}