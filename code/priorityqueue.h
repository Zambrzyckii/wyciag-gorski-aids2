#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Structs.h"
class PriorityQueue {
private:
    GridNode* heap{
};
    int size{
};
    int capacity{
};

    void swap_nodes(int i, int j) const;

    static auto has_parent(int idx) -> bool;

    static int get_parent_index(int idx);
    void compare_and_swap_with_parent(int& idx) const;

    static int get_left_child_index(int idx);

    static int get_right_child_index(int idx);
    [[nodiscard]] int get_smallest_child_index(int idx) const;
    void compare_and_swap_with_smallest_child(int& idx) const;

    void heapify_up(int idx) const;
    void heapify_down(int idx) const;

    void allocate_heap(int cap);
    void copy_heap(const GridNode* source, int count) const;
    void copy_from_other(const PriorityQueue& other);

public:
    explicit PriorityQueue(int cap);
    ~PriorityQueue();
    PriorityQueue(const PriorityQueue& other);
    PriorityQueue& operator=(const PriorityQueue& other);

    void push(const GridNode& node);
    GridNode pop();
    [[nodiscard]] bool empty() const;
};

#endif // PRIORITYQUEUE_H

