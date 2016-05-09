/*
 * Name        : lab_9.cpp
 * Author      : Jason K Lamphere
 * Description : Building a Spaceship Class
 */
#include "lab_9.h"

// CODE HERE -- CLASS FUNCTION DEFINITIONS
void Spaceship::set_name(string name) {
  name_ = name;
}
//sets private top speed variable -jkl
void Spaceship::set_top_speed(double top_speed) {
  top_speed_ = top_speed;
}
//sets private fuel source -jkl
void Spaceship::set_fuel_source(string fuel_source) {
  fuel_source_ = fuel_source;
}
// sets the private crew capacity variable-jkl
void Spaceship::set_crew_capacity(int crew_capacity) {
  crew_capacity_ = crew_capacity;
}
//returns name-jkl
string Spaceship::name() const {
  return name_;
}
//returns max speed-jkl
double Spaceship::top_speed() const {
  return top_speed_;
}
// returns fuel source-jkl
string Spaceship::fuel_source() const {
  return fuel_source_;
}
//returns crew capacity -jkl
int Spaceship::crew_capacity() const {
  return crew_capacity_;
}
//generates a string to store using the class variables -jkl
string Spaceship::ToString() const  {
  string Space_Ship;
  stringstream ss;
  ss.setf(std::ios::fixed|std::ios::showpoint);//cleans up numbers -jkl
  ss.precision(2);
  ss << name_ << "\nTop Speed:     Warp " << top_speed_
     << "\nFuel Source:   " << fuel_source_
     << "\nCrew Capacity: " << crew_capacity_;
  Space_Ship = ss.str();
    return Space_Ship;
}
