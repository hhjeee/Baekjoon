class Queue{
    constructor(){
        this.arr = [];
    }
    push(a) {
        this.arr.push(a);
    }
    pop() {
        this.arr.shift();
    }
    front() {
        return this.arr[0];
    }
    empty() {
        return this.arr.length === 0;
    }
}

function solution(n, computers) {
    var answer = 0;
    let visited = new Array(n).fill(false);
    
    for(let i=0; i<n; i++){
        if(visited[i]) continue;
        
        answer++;
        
        let q = new Queue();
        q.push(i);
        visited[i] = true;
        
        while(!q.empty()){
            let cur = q.front();
            q.pop();
            
            for(let j=0; j<n; j++){
                if(computers[cur][j] == 1 && !visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }          
        }
    }
    
    return answer;
}