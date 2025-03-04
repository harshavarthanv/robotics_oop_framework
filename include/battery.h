#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the assignment2
 *
 */
namespace RWA2 {
/**
 * @brief Class for the battery
 *
 */
class Battery {
 private:
  // ==================== attributes ====================
  /**
   * @brief modelname of the battery
   * 
   */
  std::string model_;
  /**
   * @brief current charge of the battery
   * 
   */
  int current_charge_;
  /**
   * @brief checks to see if the robot is charging
   * 
   */
  bool is_charging_;


  /**
   * @brief Stop charging the battery
   *
  */
  void stop_charging();

 public:


  // ==================== constructors ====================
  Battery(std::string model, int current_charge, bool is_charging)
      : model_(model),current_charge_{current_charge},is_charging_{is_charging} {}
  //======================accessor=========================
    /**
   * @brief Get the battery level of the robot
   *
   * @return double
   */
  int get_current_level() { return current_charge_; }
  // ==================== methods ====================
  /**
   * @brief Start charging the battery
   *
   */
  void start_charging();
  /**
   * @brief Discharge the battery
   *
   * Each time the robot moves, the battery discharges by 1 percent
   */
  void discharge(double decrement);
  /**
   * @brief Get the battery model object
   * 
   * @return std::string 
   */
  std::string get_battery_model() {return model_;}
};  // class Battery
}  // namespace RWA2
