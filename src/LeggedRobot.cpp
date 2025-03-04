/**
 * Project Untitled
 */

#include "LeggedRobot.h"

/**
 * LeggedRobot implementation
 */

/**
 * @param distance
 * @param angle
 * @return void
 */

void RWA2::LeggedRobot::move(double distance, double angle)
{
    double battery_req = distance*leg_strength_ * 100 + leg_strength_;

    if (distance <= max_jump_)
    {

        if (battery_.get_current_level() < battery_req)
        {
            battery_.start_charging();
        }
        for(auto&sensor: sensor_){
        sensor->read_data(5);} // Hypothetical function
        rotate(angle);
        jump(distance);
        kick();
        // print_status();
    }
    
}

/**
 * @return void
 */
void RWA2::LeggedRobot::print_status()
{
    std::cout << "Position of the mobile robot is (" << position_.first << ", " << position_.second << ")" << '\n';
    std::cout << "Orientation of the mobile robot is " << orientation_ << " degrees" << '\n';
    std::cout << "Velocity of the mobile robot is " << speed_ << '\n';

    std::cout << LeggedRobot::model_ << " has " << number_of_legs_ << " legs "<<'\n';
    std::cout<< "It can jump at height : " << height_ << '\n';
    std::cout<<"Its leg strength is: " << leg_strength_ << "\n";
}

/**
 * @param angle
 * @return void
 */
void RWA2::LeggedRobot::rotate(double angle)
{
    std::cout << LeggedRobot::model_ << " rotated " << angle << " degrees." <<'\n';
}

/**
 * @return void
 */
void RWA2::LeggedRobot::kick()
{
    std::cout << LeggedRobot::model_ << " kicks with a strength of " << leg_strength_ <<'\n';
    battery_.discharge(leg_strength_ );
}

/**
 * @param amount
 * @return void
 */
void RWA2::LeggedRobot::jump(double amount)
{
    std::cout << LeggedRobot::model_ << " jumps at a height of " << leg_strength_ * amount << " cm above the ground" <<'\n';
    battery_.discharge(leg_strength_ * 100 * amount);
}