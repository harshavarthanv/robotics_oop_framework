/**
 * Project Untitled
 */

#include "mobile_robot.h"

/**
 * MobileRobot implementation
 */

/**
 * @param distance
 * @param angle
 * @return void
 */
void RWA2::MobileRobot::move(double distance, double angle)
{
}

/**
 * @return void
 */
void RWA2::MobileRobot::print_status()
{
    std::cout << "Position of the mobile robot is (" << position_.first << ", " << position_.second << ")" << '\n';
    std::cout << "Orientation of the mobile robot is " << orientation_ << " degrees" << '\n';
    std::cout << "Velocity of the mobile robot is " << speed_ << '\n';
}

/**
 * @param angle
 * @return void
 */
void RWA2::MobileRobot::rotate(double angle)
{
    orientation_ = orientation_ + angle;
    std::cout << "Rotating " << orientation_ << " degrees" << '\n';
}

void RWA2::MobileRobot::add_sensor(
    std::unique_ptr<RWA2::sensor> sensor)
{
    sensor_.push_back(std::move(sensor));
}

void RWA2::MobileRobot::get_sensor_reading(int period){
  for (const auto& sensor : sensor_) {
    sensor->read_data(period);
  }
  // for (const auto& sensor : sensor_) {
  //   read_sensor = sensor->get_sensor_data();
  // }

}