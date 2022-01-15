task main() {
    while (true) {

        // Like sensors, you can read joystick values from vexRT[].

        /*
            Ch1 and Ch4 are the analog stick's X directions, and Ch2 and Ch3 are
            the Y directions. They return ints from -128 to 127.
        */
        motor[port1] = vexRT[Ch2];
        // Note: a lot of Kaluta's joysticks have a little analog stick drift.

        /*
            Btn5 and Btn6 are on the back of the joystick, and they each have
            a U and D. They return either 1 or 0 for pressed or not.
        */
        if (vexRT[Btn6U] == 1) {
            motor[port2] = 127;
        }

        /*
            Btn7 and Btn8 are the four-way buttons on the front, and they each
            have U, D, R, and L. They also return 1 or 0.
        */
        if (vexRT[Btn8U] == 1) {
            motor[port3] = 127;
        }

    }
}
