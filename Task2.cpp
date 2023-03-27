#include <iostream>
#include <unistd.h>
#include <csignal>

int sigusr2_count = 0;
void int_handler(int sig) {
    std::cout << "SIGUSR2 count: " << sigusr2_count << std::endl;
    exit(0);
}

void sigusr2_handler(int sig) {
    sigusr2_count++;
}

int main() {
    signal(SIGINT, int_handler);
    signal(SIGUSR2, sigusr2_handler);
    signal(SIGUSR1, SIG_IGN);
    while (true) {
        std::cout << "I am still alive" << std::endl;
        sleep(5);
    }
    return 0;
}
