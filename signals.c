#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sigfn1(int signo)
{
    printf("Parent: Work is over, child - you can proceed\n");
}

void sigfn2(int signo)
{
    printf("Child: Work is over, parent - you can proceed\n");
}

int main()
{
    signal(SIGUSR1, sigfn1);
    signal(SIGUSR2, sigfn2);

    int temp;
    key_t key = ftok("consumer1.c", 165);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    int shmid = shmget(key, 10 * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    printf("Shared memory id=%d\n", shmid);

    int *ptr = (int *)shmat(shmid, NULL, 0);
    if (ptr == (int *)(-1)) {
        perror("shmat");
        return 1;
    }

    int pid = fork();
    if (pid == 0) {
        printf("Child: Child is going to wait for data\n");
        pause();
        printf("Child: Got signal from parent\n");

        // Sorting the data
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (*(ptr + i) > *(ptr + j)) {
                    temp = *(ptr + i);
                    *(ptr + i) = *(ptr + j);
                    *(ptr + j) = temp;
                }
            }
        }

        printf("Child: Sorted data\n");
        for (int i = 0; i < 10; i++)
            printf("Child: %d\n", *(ptr + i));

        printf("Child: Signalling parent\n");
        kill(getppid(), SIGUSR2);

        printf("Child: Terminating\n");
    } else {
        printf("Parent: Writing data\n");
        printf("Parent: Enter 10 data:\n");

        for (int i = 0; i < 10; i++)
            scanf("%d", ptr + i);

        printf("Parent: Data written in memory:\n");
        for (int i = 0; i < 10; i++)
            printf("Parent: %d\n", *(ptr + i));

        printf("Parent: Signalling child\n");
        kill(pid, SIGUSR1);

        printf("Parent: Waiting for child signal\n");
        pause();

        printf("Parent: Got signal from child\n");

        printf("Parent: Sorted data\n");
        for (int i = 0; i < 10; i++)
            printf("Parent: %d\n", *(ptr + i));

        shmdt(ptr);
    }

    return 0;
}
