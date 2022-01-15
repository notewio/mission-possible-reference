/*
    The easiest way to see data from the Cortex on the computer is to use the
    Debug Stream. It's RobotC's equivalent of the standard out.
*/

task main() {
    writeDebugStreamLine("Hello, World!");
    writeDebugStreamLine("Here's some numbers: %d %.2f", 47, 2.121212);
    writeDebugStreamLine("And here's a string: %s", "hello world again");
}
