#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid = fork();
    
    if(child_pid == -1) {
        std::cout << "Failed to fork!\n";
    }
    else if(child_pid == 0) {
        std::cout << "Before kill\n";
        sleep(5);
        kill(getppid(), SIGKILL);
        std::cout << "After kill\n";
    }
    else {
        wait(NULL);
    }
    return 0;
}
