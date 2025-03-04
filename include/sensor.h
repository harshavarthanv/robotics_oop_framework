    #pragma once

    #include <iostream>
    #include <memory>
    #include <thread>
    #include <utility>
    #include <vector>

    /**
     * @brief Namespace for the maze navigation project
     *
     */
    namespace RWA2 {
    /**
     * @brief Class for the sensor
     *
     */
    class sensor {
    private:
    // ==================== attributes ====================
    /**
     * @brief sensor model
     * 
     */
    std::string model_;
    /**
     * @brief array of 50 data
     * 
     */
    std::array<double,50> data_;

    public:
    // ==================== constructors ====================

    sensor(std::string model) : model_(model){}

    // ==================== methods ====================
    /**
     * @brief Get the sensor data object
     * 
     * @return std::array<double, 50> 
     */
    std::array<double, 50> get_sensor_data();
    /**
     * @brief 
     * 
     * @param duration 
     */
    void read_data(unsigned int duration);
    /**
     * @brief Start reading the sensor data
     *
     * @param period Period of the reading (in s)
     */
    };  // class Sensor
    }  // namespace RWA2
