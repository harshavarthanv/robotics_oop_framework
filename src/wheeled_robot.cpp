#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "wheeled_robot.h"

void RWA2::wheeled_robot::accelerate(double amount)
{
    while (speed_ < desired_speed_)
    {
        speed_ += amount;
        std::chrono::seconds duration(static_cast<int>(0.5));
        std::this_thread::sleep_for(duration);
    }
    std::cout << wheeled_robot::model_ << " has reached the desired speed of " << desired_speed_ << " m/s." << std::endl;
}
void RWA2::wheeled_robot::move(double distance, double angle)
{
    if (distance <= 100.0)
    {
        if (battery_.get_current_level() < distance)
        {
            // charge the battery
            battery_.start_charging();
        }
        for(auto&sensor: sensor_){
        sensor->read_data(5);} // Hypothetical function
        rotate(angle);
        accelerate(2.0);
        std::chrono::seconds duration(static_cast<int>(distance - 2.0));
        std::this_thread::sleep_for(duration);
        deccelerate(2.0);
        brake();
        std::cout << wheeled_robot::model_ << " drove " << distance << " m." << std::endl;
    }
    return;
}
void RWA2::wheeled_robot::deccelerate(double amount)
{
    while (speed_ >= 0.0)
    {
        speed_ -= amount;
        std::chrono::seconds duration(static_cast<int>(0.5));
        std::this_thread::sleep_for(duration);
    }
}
void RWA2::wheeled_robot::rotate(double angle)
{
    std::cout << "WheelRobot::"<< model_<<" rotated" << angle<<" deg" << " \n";
}
void RWA2::wheeled_robot::brake()
{
    speed_ = 0.0;
}
void RWA2::wheeled_robot::print_status()
{
    std::cout << "Position of the wheeled robot are (" << position_.first << ", "
              << position_.second << ")" << '\n';
    std::cout << "Orientation of the wheeled robot is " << orientation_
              << " degrees" << '\n';
    std::cout << "Speed of the wheeled robot is " << speed_ << '\n';
    std::cout << "Battery " << battery_.get_battery_model() << " has charge " << battery_.get_current_level() << '\n';
    std::cout<< " The sensor used is" ; //addd here start
    std::cout << wheeled_robot::model_ << "Has : " << number_of_wheels_
              << " wheels ";
    std::cout<<"Diameter of the wheel: "<< wheel_diameter_ <<"m";
    std::cout<< " Desired speed : " << desired_speed_ << std::endl;
    return;
}
