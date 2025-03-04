#pragma once
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "mobile_robot.h"
/**
 * @brief namespace for assigment2
 * 
 */
namespace RWA2
{

    class wheeled_robot : public MobileRobot
    {
    private:
        /**
         * @brief number wheels for the robot
         * 
         */
        int number_of_wheels_;// give this value in constructor
        /**
         * @brief wheel diameter
         * 
         */
        double wheel_diameter_;
        /**
         * @brief required speed of the robot
         * 
         */
        double desired_speed_;
        /**
         * @brief method to accelerate the robot
         * 
         * @param amount 
         */
        void accelerate(double amount);
        /**
         * @brief method to deccelerate the robot
         * 
         * @param amount 
         */
        void deccelerate(double amount);
        /**
         * @brief method to brake the robot
         * 
         */
        void brake();

    public:
        wheeled_robot(std::string robo_model, double x, double y, double orientation, std::string battery_model, double current_charge, double wheel_diameter, double desired_speed, int number_of_wheels= 2) :
        MobileRobot(robo_model, x, y, orientation, battery_model, current_charge),
        /**
         * @brief number of wheels for the robot
         * 
         */
        number_of_wheels_{number_of_wheels}, 
        /**
         * @brief wheel diameter
         * 
         */
        wheel_diameter_{wheel_diameter},
        /**
         * @brief desired speed of the robot
         * 
         */
        desired_speed_ { desired_speed }
        {}
        /**
         * @brief method to move the robot to a desired location
         * 
         * @param distance 
         * @param angle 
         */
        virtual void move(double distance, double angle) override;
        /**
         * @brief printing the current status of the robot 
         * 
         */
        virtual void print_status() override;

    protected:
    /**
     * @brief rotating the robot to the desired angle
     * 
     * @param angle 
     */
        virtual void rotate(double angle) override;
    };
}