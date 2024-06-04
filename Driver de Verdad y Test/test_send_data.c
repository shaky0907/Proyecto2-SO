#include "driver_lib.h"
#include <stdio.h>
#include <unistd.h>


int main() {
    int fd = open_serial_port("/dev/ttyACM0");

    int bytes_written = send_word(fd, "Hello, Arduino!\n");

    close_serial_port(fd);

    /*
    while (1) {
        sleep(2);
        char buf[100];
        int n = read(fd, buf, sizeof(buf));
        if (n > 0) {
            buf[n] = 0; // Null terminate the string
            printf("Received: %s\n", buf);
        }
    }
    */


    return 0;
}