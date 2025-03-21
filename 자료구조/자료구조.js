class Stack {
    constructor(){
        this.arr = [];
    }
    push(a){
        this.arr.push(a);
    }
    pop(){
        this.arr.pop();
    }
    top(){
        return this.arr[this.arr.length-1];
    }
    empty(){
        return this.arr.length === 0;
    }
}

class Queue {
    constructor(){
        this.arr = [];
    }
    push(a){
        this.arr.push(a);
    }
    pop(){
        this.arr.shift();
    }
    top(){
        return this.arr[0];
    }
    empty(){
        return this.arr.length === 0;
    }
}

class Dequeue {
    constructor(){
        this.arr = [];
    }
    push_front(a){
        this.arr.unshift(a);
    }
    push_back(a){
        this.arr.push(a);
    }
    pop_front(){
        this.arr.pop();
    }
    pop_back(){
        this.arr.shift();
    }
    front(){
        return this.arr[0];
    }
    back(){
        return this.arr[this.arr.length-1];
    }
    empty(){
        return this.arr.length === 0;
    }
}

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
            let left_child = index * 2 + 1;
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


// map

let map = new Map();

map.set("apple", 100);
map.set("banana", 200);
console.log(map.get("apple")); // 100
console.log(map.has("banana")); // true

map.delete("banana");
console.log(map.has("banana")); // false

console.log([...map.keys()]); // ["apple"]
console.log([...map.values()]); // [100]

// set

let mySet = new Set();

mySet.add(10);
mySet.add(20);
mySet.add(10); // 중복 저장 X

console.log(mySet.has(10)); // true
console.log(mySet.has(30)); // false

mySet.delete(10);
console.log(mySet.has(10)); // false

console.log([...mySet]); // [20]
