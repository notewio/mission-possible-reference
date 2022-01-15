/*
    This is the basic code to send custom data across the VEXnet connection.

    Some things to consider:

      * The RobotC IDE uses this serial connection to tell which connected
          device is the Cortex. If you start sending your own data across the
          connection, the IDE won't be able to recognize the device anymore.
          In fact, only one application can use the port at a time, so you can
          only have your own code running from here on out.

          As such, this should probably be the last thing you implement, after
          the rest of your rover code is done. If you do still need the IDE, you
          have to reset the Cortex: Robot > Download Firmware > Manually Update
          Firmware > RobotC Firmware > Standard File

      * Remember your primitive types: chars store 8 bits of information, but
          ints store 16 bits. If you convert an int to a char like is being done
          here, it's going to max out at a value of 255. If you want to send
          numbers bigger than that, you'll need to split the int into two chars.

      * How does the computer know which byte is which if you're sending more
          than one? Usually in networking this is solved using packets: before
          sending the actual data, send some sequence of bytes that can be
          recognized by the computer that tell it what the next bytes are
          supposed to mean.

      * You're probably gonna want your main loop to run faster than 10 times a
          second, so it might be worth running this serial task in parallel.
*/

task main() {
    while (true) {
        // int SensorValue[in1] is automatically casted to unsigned char
        unsigned char sensor_value = SensorValue[in1];
        sendChar(UART0, sensor_value);
        sleep(100);
    }
}
