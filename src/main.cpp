#include <iostream>
#include <memory>
#include <vector>

#include "mobile_robot.h"
#include "AerialRobot.h"
#include "LeggedRobot.h"
#include "wheeled_robot.h"
#include "aquaticrobot.h"

void get_status(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots)
{
    for (const auto &robot : robots)
        robot->print_status();
}
void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots)
{
    for (const auto &robot : robots)
    {
        // robot->add_sensor(std::make_unique<RWA2::Sensor>("2D lidar"));
        robot->move(5.0, 5.0);  
    }
}
void add_sensor(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots)
{   
    for (const auto &robot : robots)
    {

        if ((std::rand()) % 2)
        {
            robot->add_sensor(std::make_unique<RWA2::sensor>("2D lidar"));
        }
        else
        {
            robot->add_sensor(std::make_unique<RWA2::sensor>("3D lidar"));
        }
    }
}
int main()
{
    std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;

    std::unique_ptr<RWA2::MobileRobot> crazyflie =
        std::make_unique<RWA2::AerialRobot>("CrazyFlie", 0.0, 0.0, 0.0, "Li-ion", 70, false, 0, false);
    std::unique_ptr<RWA2::MobileRobot> erle_plane =
        std::make_unique<RWA2::AerialRobot>("Erle-Plane", 0.0, 0.0, 0.0, "LiFePO4", 10, true, 0, false);

    std::unique_ptr<RWA2::MobileRobot> spot =
        std::make_unique<RWA2::LeggedRobot>("Spot", 0.0, 0.0, 0.0, "LiFePO4", 90, 0.2, 5, 2);

    std::unique_ptr<RWA2::MobileRobot> turtlebot =
        std::make_unique<RWA2::wheeled_robot>("Turtlebot", 3.0, 0.0, 0.0, "Li-ion", 20, 2, 0.1, 2);

    std::unique_ptr<RWA2::MobileRobot> sofi =
        std::make_unique<RWA2::AquaticRobot>("Sofi", 1.0, 10.0, 20.0, "LiFePO4", 90, true, 10, false);

    // mobile_robots.push_back(std::move(crazyflie));
    mobile_robots.push_back(std::move(erle_plane));
    // mobile_robots.push_back(std::move(spot));

    // mobile_robots.push_back(std::move(turtlebot));
    // mobile_robots.push_back(std::move(sofi));

    add_sensor(mobile_robots);
    move_robot(mobile_robots);
    get_status(mobile_robots);
}