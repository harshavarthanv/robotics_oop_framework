#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <thread>
#include <chrono>

#include <sensor.h>  // Include Sensor header file
#include <battery.h> // Include Battery header file
#include <mobile_robot.h> // Include MobileRobot header file
/**
 * @brief namespace for the assignment2
 * 
 */
namespace RWA2 {
    class AerialRobot : public MobileRobot {
    private:
        // ==================== attributes ====================
        /**
         * @brief checks if the robot has wings
         * 
         */
        bool has_wings_;
        /**
         * @brief initializing altitude to 0.0
         * 
         */
        double altitude_ = 0.0;
        /**
         * @brief checks if the robot is flying
         * 
         */
        bool is_flying_ = false;

        // ==================== methods ====================
        /**
         * @brief takeoff methord to make the robot takeoff
         * 
         * @param altitude 
         */
        void take_off(double altitude);
        /**
         * @brief land methord to land the robot
         * 
         */
        void land();

    public:
        // ==================== constructors ====================
        AerialRobot(std::string robo_model,double x, double y, double orientation, std::string battery_model, int current_charge, bool has_wings, double altitude, bool is_flying)
            : MobileRobot(robo_model, x,y,orientation,battery_model, current_charge), has_wings_{has_wings}, altitude_{altitude},is_flying_{is_flying} {}

        // ==================== accessors ====================
        double get_altitude() const { return altitude_; }

        // ==================== methods ====================
        /**
         * @brief moves the robot to the desired location
         * 
         * @param distance 
         * @param angle 
         */
        virtual void move(double distance, double angle) override;
        /**
         * @brief prints the general status of the robots
         * 
         */
        virtual void print_status() override;
        virtual void rotate(double angle) override;
    };  
}  // namespace RWA2
