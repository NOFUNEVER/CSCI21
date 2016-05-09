/*
 * Name        : lab_2.cpp
 * Author      : Jason K Lamphere
 * Description : Using Arithmetic to finish the functions MakeChange() and
 *               LaunchHumanCannonball()
 * Sources     :
 */

// Please note the header above. You need to include the name of the file, the
// author, a description of the program and any sources used
#include "lab_2.h"


/*
 * Given an initial integer value (representing change to be given, such as in a
 * financial transaction), break the value down into the number of quarters,
 * dimes, nickels, and pennies that would be given as change.
 * @param int initial_value - The amount of change to be broken down in pennies.
 * @param int quarters  - The number of quarters that come out of initial_value
 * @param int dimes - The number of dimes that come out of initial_value,
 *                    after quarters have been taken out
 * @param int nickels - The number of nickels that come out of initial_value,
 *                      after quarters and dimes have been taken out
 * @param int pennies - The number of pennies that come out of initial_value,
 *                      after quarters, dimes, and nickels have been taken out
 */

// Program Execution Starts Here
int main() {
  int q = -1, n = -1, d = -1, p = -1;
  MakeChange(0, q, d, n, p);
  LaunchHumanCannonball(25.0, 45.0);
  return 0;
}

/*
 * Given an initial integer value (representing change to be given, such as in a
 * financial transaction), break the value down into the number of quarters,
 * dimes, nickels, and pennies that would be given as change.
 * @param int initial_value - The amount of change to be broken down
 * @param int quarters  - The number of quarters that come out of initial_value
 * @param int dimes - The number of dimes that come out of initial_value,
 *                    after quarters have been taken out
 * @param int nickels - The number of nickels that come out of initial_value,
 *                      after quarters and dimes have been taken out
 * @param int pennies - The number of pennies that come out of initial_value,
 *                      after quarters, dimes, and nickels have been taken out
 */
void MakeChange(int initial_value, int &quarters, int &dimes, int &nickels,
                int &pennies) {
  quarters = initial_value / 25;
  initial_value %= 25;
  dimes = initial_value / 10;
  initial_value %= 10;
  nickels = initial_value / 5;
  initial_value %= 5;
  pennies = initial_value / 1;
}




/*
 * Computes the horizontal distance traveled by a human cannonball given an
 * initial velocity and launch angle. Simplified -- does not account for many
 * factors that affect projectile motion.
 * @param double initial_velocity - Represents the initial velocity of the
 *                                  human cannonball in meters/second
 * @param double launch_angle -  Represents the launch angle of the human
 *                               cannonball in degrees
 * @return double  - Represents the horizontal distance the human cannonballgit config --global push.default simple
 *                   will travel
 */
double LaunchHumanCannonball(double initial_velocity, double launch_angle) {
  // (1) Convert launch_angle from degrees to radians
  //     [radangle = degangle * (kPI/180)]
  // CODE HERE
  double radangle = launch_angle * (kPI / 180);
  // (2) Compute final horizontal/x velocity
  //     [xveloc = initialVelocity * cos(radangle)]
  // CODE HERE
  double xveloc = initial_velocity * cos(radangle);
  // (3) Compute final vertical/y velocity
  //     [yveloc = initialVecity * sin(radangle) * -1]
  // CODE HERE
  double yveloc = initial_velocity * sin(radangle) * -1;
  // (4) Compute time of flight [flighttime = (yveloc) * 2 / -9.8]
  // CODE HERE
  double flight_time = yveloc * 2 / -9.8;
  // (5) Compute horizontal/x distance traveled
  //     [xdistance = xveloc * flighttime]
  // CODE HERE
  double horizontal = xveloc * flight_time;
  return horizontal;
}