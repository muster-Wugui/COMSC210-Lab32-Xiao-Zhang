// COMSC-210 | Lab 32 | Xiao Zhang
//  main.cpp
//  COMSC210-Lab32
//
//  Created by Xiao Zhang on 11/14/24.
//

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;


int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    deque<Car> tollBoothLane;  // Deque to hold the line of cars at the toll booth
    
    int time = 0;

    // Create the initial queue with cars
    for (int i = 0; i < 2; i++) {
        Car car;
        tollBoothLane.push_back(car);
    }

    cout << "Initial queue:\n";
    
    for (auto &car : tollBoothLane) {
        car.print();
    }
    cout << endl;

    

    // Run the loop until the whole queue is empty
    while (!tollBoothLane.empty()) {
        time++;
        int action = rand() % 100;
        
        cout << "Time: " << time << " Operation: ";

        if (action < 55) {  // 55% chance to let the first car pay and leave
            cout << "Car paid: ";
            tollBoothLane.front().print();
            tollBoothLane.pop_front();  // Remove the car
        }
        else {  // 45% chance a new car joins the line
            Car newCar;
            cout << "Joined lane: ";
            newCar.print();
            tollBoothLane.push_back(newCar);  // Add the car to the back
        }

        // Display the current queue
        cout << "Queue:\n";
        if (tollBoothLane.empty()) {
            cout << "\tEmpty\n";
        }
        else {
            for (auto &car : tollBoothLane) {
                cout << "\t";
                car.print();
            }
        }
        cout << endl;

    }

    return 0;
}

