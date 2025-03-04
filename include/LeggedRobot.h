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
 * @brief namespace for the assignment2 submission
 * 
 */
namespace RWA2 {
    class LeggedRobot : public MobileRobot {
    private:
        // ==================== attributes ====================
        /**
         * @brief height of the legs
         * 
         */
        double height_;
        /**
         * @brief leg strength
         * 
         */
        int leg_strength_;
        /**
         * @brief number of legs
         * 
         */
        int number_of_legs_ = 2;
        double max_jump_ = 10;

    public:
        // ==================== constructors ====================
        LeggedRobot(std::string robo_model,  double x, double y, double orientation,  std::string battery,int leg_strength,int current_charge ,double height, int number_of_legs = 2)
            : MobileRobot(robo_model,x,y,orientation, battery,current_charge), height_{height}, leg_strength_{leg_strength}, number_of_legs_{number_of_legs} {}

        // ==================== accessors ====================
        double get_height() const { return height_; }
        int get_leg_strength() const { return leg_strength_; }
        int get_number_of_legs() const { return number_of_legs_; }

        // ==================== methods ====================
        /**
         * @brief calculate the kick strength
         * 
         */
        void kick();
        /**
         * @brief calculate the jump distance
         * 
         * @param amount 
         */
        void jump(double amount);
        /**
         * @brief moves the robot to the desired location
         * 
         * @param distance 
         * @param angle 
         */
        virtual void move(double distance, double angle) override;
        /**
         * @brief rotates the robot to the desired angle
         * 
         * @param angle 
         */
        virtual void rotate(double angle) override;
        /**
         * @brief prints the current general status of the robot
         * 
         */
        virtual void print_status() override;
    };  // class LeggedRobot
}  // namespace RWA2
