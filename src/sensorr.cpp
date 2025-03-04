#include <sensor.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <random>

namespace RWA2{
//==============================================================================
void sensor::read_data(unsigned int duration) {
    
    std::cout << "Sensor " << model_ << " gathering data for " << duration << "seconds" << '\n';

    std::this_thread::sleep_for(std::chrono::seconds(duration));
    //generate random double between 1 and 100
      // Random device engine, usually based on
                            // /dev/urandom on UNIX-like OSes
    for(int i=0;i<=49;i++){
        std::random_device rd;
        std::mt19937 gen(rd());  // Initializes with the random device
        std::uniform_real_distribution<> dis(1.0, 30.0);
        data_[i] = dis(gen);
    }
    
}
std::array<double, 50> RWA2::sensor::get_sensor_data() {
    return data_;
}
}