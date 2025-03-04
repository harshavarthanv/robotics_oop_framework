#include "battery.h"
#include<iostream>
#include <chrono>
#include <thread>

void RWA2::Battery::start_charging() {
   if(!is_charging_){
    is_charging_ = true;
    int remaining_charge = 100 - current_charge_;
    double charge_time = 0.0;
    if (model_ == "Li-ion")
    {
      charge_time = remaining_charge *0.07;
    }
    else if(model_ == "LiFeP04"){
        charge_time = remaining_charge *0.035;
    }
    std::cout << "Sensor " << model_ << " is charging." << '\n';
    std::chrono::seconds duration (static_cast<int>(charge_time));
    std::this_thread::sleep_for(duration);
    stop_charging();
    //   current_charge_ = capacity_;
   }
}

void RWA2::Battery::stop_charging() {
  is_charging_ = false;
  std::cout << "Sensor " << model_ << " is fully charged." << std::endl;
}

void RWA2::Battery::discharge(double decrement) {
    current_charge_ -= static_cast<int>(decrement);
    if (current_charge_ < 0) {
        current_charge_ = 0;
    }
}
  