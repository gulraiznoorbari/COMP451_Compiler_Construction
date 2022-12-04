/*****in1.c****
 *
 *
 */
#include <stdio.h>
// defining macros

#define ON 1
#define OFF 0

int main()
{

/*declaring variables*/
    int j = 2;
    int motor, sensorValue = 0;
    if (motor == ON ) // what to do when motor is running
    {
        sensorValue++;
    }
    else if (motor == OFF ) /* what to do when motor is not running */
    {
        sensorValue--;
    }

    printf("SensorValue = %d", sensorValue);
    return 0;
}