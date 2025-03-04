#include <AerialRobot.h>

namespace RWA2 {
    void AerialRobot::take_off(double altitude) {
        if (!is_flying_) {
            is_flying_ = true;
            altitude_ = altitude;
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(altitude / (has_wings_ ? 3 : 1.5))));
        }
    }

    void AerialRobot::land() {
        if (is_flying_) {
            is_flying_ = false;
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(altitude_ / (has_wings_ ? 4 : 2))));
            altitude_ = 0.0;
        }
    }

    void AerialRobot::move(double distance, double angle) {
         if (distance <= 50)
    {

        if (battery_.get_current_level() < distance * 2)
        {
            battery_.start_charging();
        }
        
        get_sensor_reading(5);

        take_off(distance);
        rotate(angle);
        land();
        std::cout << "AerialRobot::"<< model_ << " reached an altitude of " << distance << "meters and then landed."
                  << '\n';
        // std::cout << " Current Battery Charge : " << battery_.get_current_level();
    }
    // else
    // {
    //     std::cout <<" AerialRobot::" << model_ << "cannot fly the given distance due to insufficient battery capacity"<<'\n';
    // }
    }

    void AerialRobot::rotate(double angle) {
    // MobileRobot::rotate(angle);
    std::cout << "AerialRobot::" << model_ << " rotated " << angle << " degrees." << std::endl;
}

    void AerialRobot::print_status() {
        MobileRobot::print_status();
        std::cout << "Has wings: " << (has_wings_ ? "Yes" : "No") << "\n";
        std::cout << "Altitude: " << altitude_ << "\n";
        std::cout << "Is flying: " << (is_flying_ ? "Yes" : "No") << "\n";
    }
} // namespace RWA2
