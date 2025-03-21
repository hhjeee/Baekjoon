const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, s] = input[0].split(' ').map(Number);

let arr = input[1].split(' ').map(Number);

let left = 0;
let right = 0;

let sum = 0;
let shortest = 100001;

while(left <= right && right <= n){
    if(sum < s){
        sum += arr[right];
        right++;
    } else {
        if(shortest > right - left) shortest = right - left;
        sum -= arr[left];
        left++;
    }
}

console.log(shortest === 100001 ? 0 : shortest);