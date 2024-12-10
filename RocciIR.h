/** 
 *    RocciIR.h : IR Sensor Library for LEGO NXT (NXC)
 *
 *    Put this file in your project directory and use it with #include "RocciIR.h".
 * 
 *    Author: Jonas Biener (<jonas.biener@rocci.net>) for the Robotics Competence Center Illertal e. V. (<https://rocci.net>) 
 *    Version: 1.0 [12-2024] First stable release
*/


/* 
 *    Returns the value of the IR-Seeker.
 *
 *    byte port  :   The IR Seeker's port (IN_2)
 *    byte index :   1-7 Get the value of the unique sensors
 *                   0   Get the id of the unique sensor with the highest value
 *
 *    Returns -1 in case of errors.
*/

int SensorIR(byte port,  byte index)
{
  int result = -1;                  // default: error value
  byte outbuf[];                    // here we will get data
  byte cmdbuf[];                    // register number holder
  byte adr = 0x10;
  byte cnt = 1;
  byte reg = 0x49+index;

  while (I2CCheckStatus(port)==STAT_COMM_PENDING);

  ArrayBuild(cmdbuf, adr, reg);
  if(I2CBytes(port, cmdbuf, cnt, outbuf))
  {
    result = outbuf[0];             // read value

    if(cnt==2)
      result = result + outbuf[1]*256;
  }
  return result;                    // returns -1 if I2CBytes failed
}
