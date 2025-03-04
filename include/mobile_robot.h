#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "battery.h"
#include "sensor.h"

/**
 * @brief Namespace for the RWA2 project
 *
 */
namespace RWA2 {
/**
 * @brief Class for the mobile robot
 *
 */
class MobileRobot {
 protected:
  // ==================== attributes ====================
  //<! position of the robot
  /**
   * @brief position of the robot
   * 
   */
  std::pair<double, double> position_;
  //<! orientation of the robot (in rad)
  /**
   * @brief orientation of the robot
   * 
   */
  double orientation_;
  //<! speed of the robot
  /**
   * @brief speed of the robot
   * 
   */
  double speed_{0};
  //<! battery of the robot
  /**
   * @brief battery staus of the robot
   * 
   */
  RWA2::Battery battery_;
  //<! list of sensors for the robot
  /**
   * @brief gives the sensor values
   * 
   */
  std::vector<std::unique_ptr<RWA2::sensor>> sensor_;
  //<! Model of the sensor
  /**
   * @brief maodel of the robot
   * 
   */
  std::string model_;
  /**
   * @brief rotation of the robot
   * 
   * @param angle 
   */
  virtual void rotate(double angle);



 public:

  MobileRobot(std::string robo_model, double x, double y, double orientation,
    std::string battery_model, int current_charge):
    model_{robo_model},position_{x,y}, orientation_{orientation}, battery_{battery_model, current_charge,false}{
    }


  // ==================== methods ====================
  /**
   * @brief print the robot status
   *
   * 
   */
   virtual void print_status();
  /**
   * @brief sensor added
   * 
   * @param sensor 
   */
   void add_sensor(std::unique_ptr<RWA2::sensor> sensor);
  /**
   * @brief move the robot
   *
   */
   virtual void move(double distance, double angle);
   /**
    * @brief Get the sensor reading object
    * 
    * @param period 
    */
   void get_sensor_reading(int period); 

   private:
   /**
    * @brief array of 50 data.
    * 
    */
    std::array<double,50>read_sensor;
    };  // class MobileRobot
}  // namespace MazeNavigation
