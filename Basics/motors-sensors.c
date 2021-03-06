#pragma config(Sensor, in1,    light,          sensorReflection)
#pragma config(Motor,  port1,           motor_name,           tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
    To get a motor or sensor working, you have to first configure it in the
    "Motor and Sensor Setup" menu at the top of the IDE. Should be fairly
    self-explanatory, and if done correctly you'll see lines like these show up
    at the top of your file.
*/

task main() {

    // Set values in motor[] to give voltage to a motor.
    motor[motor_name] = 127;
    // Of course, it won't do anything unless you give it time to actually turn:
    sleep(1000);
    // Values go from -128 to 127 (signed int).
    motor[motor_name] = -128;
    sleep(1000);
    // To turn a motor off, reset to 0.
    motor[motor_name] = 0;

    // Reading a sensor value is similar: get it from SensorValue[].
    int brightness = SensorValue[light];
    writeDebugStreamLine("%d", brightness);

}
