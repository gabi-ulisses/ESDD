#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10001

int main() {
    int rack[MAX_SIZE] = {0}; 
    int n, x, y, num;
    int inicio, fim, acl;

    while (scanf("%d", &n) != EOF) {
        memset(rack, 0, sizeof(rack)); 

        for (int j = 0; j < n; j++) {
            scanf("%d %d", &inicio, &fim);
            for (int i = inicio; i <= fim; i++) {
                rack[i]++;
            }
        }

        acl = 0;
        scanf("%d", &num);

        if (rack[num]) {
            for (int i = 1; i < num; i++) {
                acl += rack[i];
            }

            printf("%d found from %d to %d\n", num, acl, (acl + rack[num] - 1));
        } else {
            printf("%d not found\n", num);
        }
    }

    return 0;
}