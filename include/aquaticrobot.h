#pragma once

#include "mobile_robot.h"
/**
 * @brief namespace for the assignment2
 * 
 */
namespace RWA2 {

    class AquaticRobot : public MobileRobot {
    private:
        /**
         * @brief checks if the robot has wings
         * 
         */
        bool has_fins_;
        /**
         * @brief depth of the robot
         * 
         */
        double depth_{0.0};
         /**
         * @brief checks if the robot is diving
         * 
         */
        bool is_diving_{false};
        /**
         * @brief used to make the robot dive to the desired depth
         * 
         * @param depth 
         */
        void dive(double depth);
        /**
         * @brief gets the surface values 
         * 
         */
        void surface();

    public:
        AquaticRobot(std::string robo_model, double x, double y, double orientation, 
        std::string battery_model, int current_charge, bool hasFins, double depth, bool is_diving)
        : MobileRobot(robo_model,x,y, orientation, battery_model, current_charge), has_fins_{hasFins} , depth_{depth}, is_diving_{is_diving} {}
        /**
         * @brief moves the robot to the desired location
         * 
         * @param distance 
         * @param angle 
         */
        virtual void move(double distance, double angle) override;
        /**
         * @brief prints the general status of the robot
         * 
         */
        virtual void print_status() override;
    protected:
        /**
         * @param angle
         */
        virtual void rotate(double angle) override;
    };

} 