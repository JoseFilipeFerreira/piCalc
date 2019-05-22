#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

double pointDist(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int insideN(int n){
    double x, y;
    int inside = 0;
    for(int i = 0; i < n; i++){
        x = ((double) rand() / (RAND_MAX)); 
        y = ((double) rand() / (RAND_MAX));
        if (pointDist(x, y, 0.5, 0.5) <= 0.5)
            inside++;
    }
    return inside;
}

int main(int argc, char**argv){
    int total = atoi(argv[1]) * atoi(argv[2]);
    int pipefd[2];
    pipe(pipefd);
    for(int i = 0; i < atoi(argv[1]); i++){
        if(!fork()){
            srand(time(0) + clock());
            int inside = insideN(atoi(argv[2]));
            write(pipefd[1], &inside, sizeof(int));
            return 0;
        }
    }
    int iT = 0;
    for(int i = 0; i < atoi(argv[1]); i++){
        int r;
        read(pipefd[0], &r, sizeof(int));
        iT += r;
    }
    printf("%f\n", 4*((double) iT / (double) total));

    close(pipefd[1]);
}
