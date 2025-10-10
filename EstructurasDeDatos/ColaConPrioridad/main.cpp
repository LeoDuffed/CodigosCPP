#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main(){
    PriorityQueue<string> priorityQueue;
    priorityQueue.enque("Leo", 1);
    priorityQueue.enque("Edu", 2);
    priorityQueue.enque("Danna", 0);
    priorityQueue.print();
    priorityQueue.dequeue();
    priorityQueue.print();
    return 0;
}