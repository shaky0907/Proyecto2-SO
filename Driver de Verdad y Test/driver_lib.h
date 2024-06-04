#ifndef MYLIB_H
#define MYLIB_H

int open_serial_port(const char* device_file);
int send_word(int fd, const char* word);
void close_serial_port(int fd);

#endif