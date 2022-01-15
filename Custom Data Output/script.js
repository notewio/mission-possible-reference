if ("serial" in navigator) {

    // Prompt user to select a serial port, and wait for it to open.
    const port = await navigator.serial.requestPort();
    await port.open({baudRate: 115200});

    /*
        Write one character to the Cortex to enable download mode. This signals
            to the Cortex that it can start sending data to the computer.
        Note that there isn't an await in front of writer.write(). We have to
            block the thread and wait for the character to go through first
            before any data can be read.
    */
    const writer = port.writable.getWriter();
    const data = new Uint8Array([32]);
    writer.write(data);

    // Listen to data coming from the serial device.
    while (port.readable) {
        const reader = port.readable.getReader();
        try {
            while (true) {
                const {value, done} = await reader.read();
                if (done) {
                    reader.releaseLock();
                    break;
                }
                if (value) {
                    // Value is a Uint8Array. Do with it what you will
                }
            }
        } catch (error) { // A non-fatal error occurred.
            // Close the current reader so it can reopen in the next iteration.
            reader.releaseLock();
        }
    }

    // Close the writer too.
    writer.releaseLock();
}
