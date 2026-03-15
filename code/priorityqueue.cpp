#include "PriorityQueue.h"

void PriorityQueue::swap_nodes(int i, int j) const {
    GridNode tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

bool PriorityQueue::has_parent(int idx) {
    return idx > 0;
}

int PriorityQueue::get_parent_index(int idx) {
    return (idx - 1) >> 1;
}

void PriorityQueue::compare_and_swap_with_parent(int& idx) const {
    int parent = get_parent_index(idx);
    if (heap[parent].cost > heap[idx].cost) {
        swap_nodes(parent, idx);
        idx = parent;
    
} else {
        idx = -1;
    
}
}

void PriorityQueue::heapify_up(int idx) const {
    while (has_parent(idx)) {
        compare_and_swap_with_parent(idx);
        if (idx == -1) break;
    
}
}

int PriorityQueue::get_left_child_index(int idx) {
    return (idx << 1) + 1;
}

int PriorityQueue::get_right_child_index(int idx) {
    return (idx << 1) + 2;
}

int PriorityQueue::get_smallest_child_index(int idx) const {
    int left = get_left_child_index(idx);
    int right = get_right_child_index(idx);
    int smallest = idx;

    if (left < size && heap[left].cost < heap[smallest].cost) smallest = left;
    if (right < size && heap[right].cost < heap[smallest].cost) smallest = right;

    return smallest;
}

void PriorityQueue::compare_and_swap_with_smallest_child(int& idx) const {
    int smallest = get_smallest_child_index(idx);
    if (smallest == idx) {
        idx = -1;
    
} else {
        swap_nodes(idx, smallest);
        idx = smallest;
    
}
}

void PriorityQueue::heapify_down(int idx) const {
    while (idx != -1) {
        compare_and_swap_with_smallest_child(idx);
    
}
}

void PriorityQueue::allocate_heap(int cap) {
    heap = new GridNode[cap];
}

void PriorityQueue::copy_heap(const GridNode* source, int count) const {
    for (int i = 0; i < count; ++i) {
        heap[i] = source[i];
    
}
}

void PriorityQueue::copy_from_other(const PriorityQueue& other) {
    size = other.size;
    capacity = other.capacity;
    allocate_heap(capacity);
    copy_heap(other.heap, size);
}

PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    size = 0;
    allocate_heap(cap);
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

PriorityQueue::PriorityQueue(const PriorityQueue& other) {
    copy_from_other(other);
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
    if (this != &other) {
        delete[] heap;
        copy_from_other(other);
    
}
    return *this;
}

void PriorityQueue::push(const GridNode& node) {
    heap[size] = node;
    heapify_up(size++);
}

GridNode PriorityQueue::pop() {
    GridNode top = heap[0];
    heap[0] = heap[--size];
    heapify_down(0);
    return top;
}

bool PriorityQueue::empty() const {
    return size == 0;
}
