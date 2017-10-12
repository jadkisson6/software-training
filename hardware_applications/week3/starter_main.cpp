#include <iostream>
#include <STSL/RJRobot.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    RJRobot robot;
    vector<int> measurements;
    auto black_threshold = 10;
    auto grey_threshold = 40;

    while(measurements.empty() || measurements.back() > black_threshold) {
        // Measure square color
        measurements.push_back(robot.LightValue());

        // Move to next square
        robot.SetMotor(MotorPort::A, 200);
        robot.SetMotor(MotorPort::B, 200);
        robot.Wait(250ms);
    }


    return 0;
}