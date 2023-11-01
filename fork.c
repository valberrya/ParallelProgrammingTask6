#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

const int imageSize = 1900; //размер изображения в байтах
const int coefficient = 1;
const int maxThreads = 8;
const int threadStep = imageSize / maxThreads;

void change_bytes(int start, int end, unsigned char buffer[1900]) {
    for (int i = start; i > end; i -= threadStep) {
        buffer[i] += (i * coefficient) & 255;
        printf("%d ", (int)buffer[i]);
    }
}

int main()
{
    pid_t pid_array[maxThreads];
    int status = 0;
    int i;
    FILE* original_file;
    FILE* new_file;
    unsigned char f[1900];

    original_file = fopen("/home/godseven/corrupted_binary.jpg", "rb");
    new_file = fopen("/home/godseven/changed_binary_fork.jpg", "wb");
    fread(f, sizeof(f), 1, original_file);

    for (i = 1; i < maxThreads + 1; i++) {
        if (pid_array[i] = fork()) {
            break;
        }
    }
    if (i == maxThreads + 1) {
        for (int pid = 0; pid < maxThreads + 1; s++) {
            waitpid(pid_array[pid], &status, 0);
        }
        fwrite(f, sizeof(f), 1, new_file);
    } else {
        double start = imageSize - i;
        double end = 0;
        change_bytes(start, end, f);
    }
    exit(0);
    return 0;
}
