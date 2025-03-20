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
    push(a){
        this.arr.push(a);
        this.arr.sort((a,b) => a-b);
    }
    pop(){
        this.arr.shift();
    }
    front(){
        return this.arr[0];
    }
    empty(){
        return this.arr.length === 0; 
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
