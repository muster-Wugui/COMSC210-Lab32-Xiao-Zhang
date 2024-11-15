// COMSC-210 | Lab 33 | Xiao Zhang

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>
#include "Car.h"

using namespace std;


int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    array<deque<Car>, 4> lanes;

    for (auto& lane : lanes) {
        int numCars = rand() % 3 + 1;
        for (int i = 0; i < numCars; i++) {
            lane.push_back(Car());
        }
    }

    cout << "Initial queue:\n";
    
    for (int i = 0; i < 4; i++){
        cout<<"Lane "<<i+1<<":"<<endl;
        
        if(lanes[i].empty()){
            cout << "\tEmpty\n";
        }
        else{
           for (auto& car : lanes[i]){
               cout << "\t";
            car.print();
           }
        }

    }

    for (int ti = 1; ti <= 20; ti++){
        cout << "Time: " << ti <<endl;
        for(int i = 0; i < 4; i++){
            int rad = rand() % 100;
            cout<<"Lane "<<i+1<<":"<<endl;

            if(!lanes[i].empty()){
                if(rad < 46){
                    cout << "Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                }
                else if (rad < 85){
                    Car newCar;
                    cout << "Joined: ";
                    newCar.print();
                    lanes[i].push_back(newCar);
                }else{
                    int newlane;
                    do {
                        newlane = rand() % 4; // Pick a new random lane
                    } while (newlane == i);

                    Car switchcar = lanes[i].back();
                    lanes[i].pop_back();
                    lanes[newlane].push_back(switchcar);

                    cout << "Switched: ";
                    switchcar.print();
                    cout << " to Lane " << newlane + 1;
                }
            }
            else{
                if(rand() % 2 == 0){
                    
                }
            }
        }
    }
    
    return 0;
    }

