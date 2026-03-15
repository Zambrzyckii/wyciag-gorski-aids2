#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <cstdio>
#include <climits>
#include "PriorityQueue.h"
void ReadInputData(int& Width, int& Height, int& StartX, int& StartY, int& GoalX, int& GoalY, int& elevatorCount, Elevator*& elevators) {
    scanf("%d %d", &Width, &Height);
    scanf("%d %d", &StartX, &StartY);
    scanf("%d %d", &GoalX, &GoalY);
    scanf("%d", &elevatorCount);

    elevators = new Elevator[elevatorCount];
    for (int i = 0; i < elevatorCount; i++) {
        scanf("%d %d %d %d %d %d",
              &elevators[i].StartX, &elevators[i].StartY,
              &elevators[i].EndX, &elevators[i].EndY,
              &elevators[i].duration, &elevators[i].interval);
    
}
}

void InitializeMaps(int Width, int Height, int**& Map, int**& DistanceMap, List***& elevatorMap) {
    Map = new int*[Height];
    DistanceMap = new int*[Height];
    elevatorMap = new List**[Height];
    for (int i = 0; i < Height; ++i) {
        Map[i] = new int[Width];
        DistanceMap[i] = new int[Width];
        elevatorMap[i] = new List*[Width];
        for (int j = 0; j < Width; j++) {
            scanf("%d", &Map[i][j]);
            DistanceMap[i][j] = INT_MAX;
            elevatorMap[i][j] = nullptr;
        
}
    
}
}

void PopulateElevators(int elevatorCount, Elevator* elevators, List*** elevatorMap) {
    for (int i = 0; i < elevatorCount; i++) {
        List* list = new List;
        list->elevator = &elevators[i];
        list->next = elevatorMap[elevators[i].StartY][elevators[i].StartX];
        elevatorMap[elevators[i].StartY][elevators[i].StartX] = list;
    
}
}

void RunDijkstra(int Width, int Height, int StartX, int StartY, int GoalX, int GoalY,
                 int** Map, int** DistanceMap, List*** elevatorMap) {

    constexpr int dirX[] = {0, 1, 0, -1
};
    constexpr int dirY[] = {1, 0, -1, 0
};

    DistanceMap[StartY][StartX] = 0;
    PriorityQueue Queue(Width * Height);
    Queue.push({StartX, StartY, 0
});

    while (!Queue.empty()) {
        GridNode current = Queue.pop();
        int x = current.posX, y = current.posY, cost = current.cost;

        if (x == GoalX && y == GoalY) {
            printf("%d\n", cost);
            return;
        
}

        if (cost > DistanceMap[y][x]) continue;

        for (int d = 0; d < 4; d++) {
            int nx = x + dirX[d];
            int ny = y + dirY[d];
            if (nx < 0 || ny < 0 || nx >= Width || ny >= Height) continue;

            int moveCost = Map[ny][nx] > Map[y][x] ? (Map[ny][nx] - Map[y][x] + 1) : 1;
            int newCost = cost + moveCost;

            if (newCost < DistanceMap[ny][nx]) {
                DistanceMap[ny][nx] = newCost;
                Queue.push({nx, ny, newCost
});
            
}
        
}

        List* currElevator = elevatorMap[y][x];
        while (currElevator) {
            Elevator* e = currElevator->elevator;
            int waitTime = (e->interval - (cost % e->interval)) % e->interval;
            int arrivalTime = cost + waitTime + e->duration;
            if (arrivalTime < DistanceMap[e->EndY][e->EndX]) {
                DistanceMap[e->EndY][e->EndX] = arrivalTime;
                Queue.push({e->EndX, e->EndY, arrivalTime
});
            
}
            currElevator = currElevator->next;
        
}
    
}
}

void CleanUpMemory(int Width, int Height, int** Map, int** DistanceMap, List*** elevatorMap, Elevator* elevators) {
    for (int i = 0; i < Height; ++i) {
        delete[] Map[i];
        delete[] DistanceMap[i];
        for (int j = 0; j < Width; ++j) {
            List* node = elevatorMap[i][j];
            while (node) {
                List* temp = node;
                node = node->next;
                delete temp;
            
}
        
}
        delete[] elevatorMap[i];
    
}
    delete[] Map;
    delete[] DistanceMap;
    delete[] elevatorMap;
    delete[] elevators;
}

void RunPathfinding() {
    int Width, Height;
    int StartX, StartY, GoalX, GoalY;
    int elevatorCount;
    Elevator* elevators;
    int** Map;
    int** DistanceMap;
    List*** elevatorMap;
    ReadInputData(Width, Height, StartX, StartY, GoalX, GoalY, elevatorCount, elevators);
    InitializeMaps(Width, Height, Map, DistanceMap, elevatorMap);
    PopulateElevators(elevatorCount, elevators, elevatorMap);
    RunDijkstra(Width, Height, StartX, StartY, GoalX, GoalY, Map, DistanceMap, elevatorMap);
    CleanUpMemory(Width, Height, Map, DistanceMap, elevatorMap, elevators);
}
#endif // FUNCTIONS_H
