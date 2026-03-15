#ifndef STRUCTS_H
#define STRUCTS_H

struct Elevator {
    int StartX, StartY, EndX, EndY;
    int duration, interval;
};

struct List {
    Elevator* elevator;
    List* next;
};

struct GridNode {
    int posX, posY, cost;
};

#endif
