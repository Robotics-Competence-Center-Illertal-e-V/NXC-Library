/** 
 *    RocciCompass.h : Compass Sensor Library for LEGO NXT (NXC)
 *
 *    Put this file in your project directory and use it with #include "RocciCompass.h".
 * 
 *    Author: Jonas Biener (<jonas.biener@rocci.net>) for the Robotics Competence Center Illertal e. V. (<https://rocci.net>) 
 *    Version: 1.0 [12-2024] First stable release
*/

#ifndef ROCCI_COMPASS
#define ROCCI_COMPASS

/* 
 *    Returns the calculated direction of the compass.
 *    180 is in front for better comparison.
 *
 *    int sensor_value :   The current value of the sensor
 *    int offset       :   The saved offset value that is zero
*/

int CompassDirection(int sensor_value, int offset)
{
  return (sensor_value - offset + 180 + 360) % 360;
}

#endif