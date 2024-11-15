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
    
    int time = 0;

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
           for (const auto& car : lanes[i]){
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
            
        }
    }

    }

    return 0;
}

