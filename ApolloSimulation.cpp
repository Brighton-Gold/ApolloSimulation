/*************************************************************
 * 1. Name:
 *     Brighton Gold, Austin Jesperson
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 * 4. What was the hardest part? Be as specific as possible.
 *      Brighton - Honestly I had no idea how all these functions fit together. For example, I didn't know when to use the total component, why I needed it, ecetera.
 *      Austin - The hardest part was working through the order to call each function. We ran into some issues with Visual Studio and its interaction with GitHub as well.
 * 5. How long did it take for you to complete the assignment?
 *     like 3 hours
 **************************************************************/

#include <iostream>  // for CIN and COUT
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/

double ComputeDistance(double originalPosition, double velocity, double acceleration, double time)
{
    double position = originalPosition + (velocity * time) + (.5 * acceleration) * pow(time, 2);
    
    return position;
}
 /**************************************************
  * COMPUTE ACCELERATION
  * Find the acceleration given a thrust and mass.
  * This will be done using Newton's second law of motion:
  *     f = m * a
  * INPUT
  *     f : force, in Newtons (kg * m / s^2)
  *     m : mass, in kilograms
  * OUTPUT
  *     a : acceleration, in meters/second^2
  ***************************************************/

double ComputeAccelertaion(double force, double mass)
{
    double acceleration = (force / mass);

    return acceleration;

}

  /***********************************************
   * COMPUTE VELOCITY
   * Starting with a given velocity, find the new
   * velocity once acceleration is applied. This is
   * called the Kinematics equation. The
   * equation is:
   *     v = v + a t
   * INPUT
   *     v : velocity, in meters/second
   *     a : acceleration, in meters/second^2
   *     t : time, in seconds
   * OUTPUT
   *     v : new velocity, in meters/second
   ***********************************************/
double computeVelocity(double velocity, double acceleration, double time)
{
    double newVelocity = velocity + (time * acceleration);
    return newVelocity;
}

   /***********************************************
    * COMPUTE VERTICAL COMPONENT
    * Find the vertical component of a velocity or acceleration.
    * The equation is:
    *     cos(a) = y / total
    * This can be expressed graphically:
    *      x
    *    +-----
    *    |   /
    *  y |  / total
    *    |a/
    *    |/
    * INPUT
    *     a : angle, in radians
    *     total : total velocity or acceleration
    * OUTPUT
    *     y : the vertical component of the total
    ***********************************************/
double verticalAngle(double angle, double total)
{
    double verticalComponent = cos(angle) * total;
    return verticalComponent;
}
    /***********************************************
     * COMPUTE HORIZONTAL COMPONENT
     * Find the horizontal component of a velocity or acceleration.
     * The equation is:
     *     sin(a) = x / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     x : the vertical component of the total
     ***********************************************/
double horzontalAngle(double angle, double total)
{
    double verticalComponent = sin(angle) * total;
    return verticalComponent;
}
     /************************************************
      * COMPUTE TOTAL COMPONENT
      * Given the horizontal and vertical components of
      * something (velocity or acceleration), determine
      * the total component. To do this, use the Pythagorean Theorem:
      *    x^2 + y^2 = t^2
      * where:
      *      x
      *    +-----
      *    |   /
      *  y |  / total
      *    | /
      *    |/
      * INPUT
      *    x : horizontal component
      *    y : vertical component
      * OUTPUT
      *    total : total component
      ***********************************************/
double totalComponent(double horizontal, double vertical)
{
    double total = pow(horizontal, 2) + pow(vertical, 2);
    return sqrt(total);

}
      /*************************************************
       * RADIANS FROM DEGEES
       * Convert degrees to radians:
       *     radians / 2pi = degrees / 360
       * INPUT
       *     d : degrees from 0 to 360
       * OUTPUT
       *     r : radians from 0 to 2pi
       **************************************************/
       // your function goes here
double DegreestoRadians(double degree)
{
    //need to create something if degrees are more than 360 to loop around and if less than zero vice versa
    double radians = (degree / 360) * 2 * (3.14159265358979323846);
    return radians;

}
       /**************************************************
        * PROMPT
        * A generic function to prompt the user for a double
        * INPUT
        *      message : the message to display to the user
        * OUTPUT
        *      response : the user's response
        ***************************************************/
double prompt(string line)
{
    cout << line;
    double input;
    cin >> input;
    return input;

}
/****************************************************************
         * MAIN
         * Prompt for input, compute new position, and display output
         ****************************************************************/

int main()
{
    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    double x = prompt("What is your position (m)? ");
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double t = prompt("What is the time interval (s)? ");
    double aRadians;            // Angle in radians
    double accelerationThrust;  // Acceleration due to thrust 
    double ddxThrust;           // Horizontal acceleration due to thrust
    double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double v;                   // Total velocity

    // Go through the simulator five times
      // your code goes here
    for (int c = 1; c <= 5; c++)
    {
        aRadians = DegreestoRadians(aDegrees);
        accelerationThrust = ComputeAccelertaion(THRUST, WEIGHT);
        ddxThrust = horzontalAngle(aRadians, accelerationThrust);
        ddyThrust = verticalAngle(aRadians, accelerationThrust);
        ddx = ddxThrust;
        ddy = ddyThrust + GRAVITY;
        dx = computeVelocity(dx, ddx, t);
        dy = computeVelocity(dy, ddy, t);
        x = ComputeDistance(x, dx, ddx, t);
        y = ComputeDistance(y, dy, ddy, t);
        v = totalComponent(dx, dy);


        // Output
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        cout << "\tNew position:   (" << x << ", " << y << ")m\n";
        cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
        cout << "\tTotal velocity:  " << v << "m/s\n\n";

    }
    return 0;
}