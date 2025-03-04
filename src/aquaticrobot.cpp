#include"mobile_robot.h"
#include"aquaticrobot.h"

using namespace RWA2;

void AquaticRobot::dive(double depth) {
    if (!is_diving_) {
        double speed = (has_fins_) ? 2.0 : 1.0; // Speed calculation based on fins
        is_diving_ = true;
        // Calculate time needed to reach the depth based on speed
        double time = depth / speed;

        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(time)));

        depth_ = depth;
    }
}

void AquaticRobot::surface() {
    if (is_diving_) {
        double speed = (has_fins_) ? 4.0 : 2.0; // Speed calculation based on fins
        // Calculate time needed to reach the surface based on speed
        double time = depth_ / speed;

        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(time)));
        std::cout << model_<< " reached a depth of "<< depth_ <<" meters and then surfaced." << std::endl;

        depth_ = 0.0;
        is_diving_ = false;

        // Recharge the battery
        // battery_.chargeFully(); // Assuming a function to charge the battery fully
    }
}

void AquaticRobot::move(double distance, double angle) {
    // Check if the battery charge is enough to dive and surface
    double dive_distance = distance / 2; // Distance to dive (half of the total distance)

    // Calculate battery consumption for diving and surfacing (1% per meter)
    double battery_consumption = distance*2; // Dive + Surface + Movement

    // Check if the battery charge is sufficient
    if (battery_.get_current_level() < battery_consumption) {

        // Insufficient charge, recharge the battery
        battery_.start_charging(); // Recharge the battery
        // Sufficient charge, proceed with the actions
    }
        for(auto&sensor: sensor_){
        sensor->read_data(5);} // Hypothetical function
        rotate(angle);
        dive(dive_distance);
        surface();

        // std::cout << model_ << " reached a depth of " << distance << " meters and then surfaced." << std::endl;
        // print_status();
    
}

void AquaticRobot::rotate(double angle) {
    // MobileRobot::rotate(angle);
    std::cout << "AquaticRobot::" << model_ << " rotated " << angle << " degrees." << std::endl;
}

void AquaticRobot::print_status() {
    MobileRobot::print_status();
    std::cout << "Depth reached: " << depth_ << " meters" << std::endl;
    std::cout << "Is Diving: " << std::boolalpha << is_diving_ << "Has fins:"<< std::boolalpha<< has_fins_<< std::endl;
}
