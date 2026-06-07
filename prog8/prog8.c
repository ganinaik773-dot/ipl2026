#include <stdio.h>

void moveDisk(int disk, char from, char to) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    int totalMoves = (1 << n) - 1;

    char peg[3] = {'A', 'B', 'C'};

    
    int pos[32];
    for (int i = 1; i <= n; i++)
        pos[i] = 0; // all start on A

    for (int move = 1; move <= totalMoves; move++) {

        if (move % 2 == 1) {
          
            int from = pos[1];
            int to;

            if (n % 2 == 1)
                to = (from + 1) % 3; 
            else
                to = (from + 2) % 3;  

            moveDisk(1, peg[from], peg[to]);
            pos[1] = to;
        } else {
           
            int d = 2;

            while (d <= n) {
                int from = pos[d];

                for (int to = 0; to < 3; to++) {
                    if (to == from) continue;

                    int legal = 1;

                   
                    for (int k = 1; k < d; k++)
                        if (pos[k] == from)
                            legal = 0;

                   
                    for (int k = 1; k < d; k++)
                        if (pos[k] == to)
                            legal = 0;

                    if (legal) {
                        moveDisk(d, peg[from], peg[to]);
                        pos[d] = to;
                        d = n + 1; /
                        break;
                    }
                }
                d++;
            }
        }
    }

    return 0;
}