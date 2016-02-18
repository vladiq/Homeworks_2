#include <stdio.h>

struct rational {
    int a;
    int b;
};

void get_Farrey(int n_user, int *last, struct rational f[]);
void show_Farrey(struct rational f[], int last);

int main() {
    struct rational f[1000];
    int user_n;
    int last;
    printf("\nEnter the number for the max dinominator: ");
    scanf("%d", &user_n);
    get_Farrey(user_n, &last, f);
    show_Farrey(f,last);
    return(0);
}

void get_Farrey(int user_n, int *last, struct rational f[]) {
    int n;
    int i;
    int j;
    *last = 1; //индекс последней дроби
    f[0].a = 0; f[0].b = 1;
    f[1].a = 1; f[1].b = 1;
    for(n = 2; n <= user_n; n ++) {
        for (i = 0; i < *last; i ++) {
            if ((f[i].b + f[i+1].b) <= n) {
                for(j = *last; j > i; j --) {
                    f[j+1].a = f[j].a;
                    f[j+1].b = f[j].b;
                }
                f[i+1].a = f[i].a + f[i+2].a;
                f[i+1].b = f[i].b + f[i+2].b;
                *last = *last + 1;
            }
        }
    }
}

void show_Farrey(struct rational f[], int last) {
    int i;
    printf("\n");
    for(i = 0; i <= last; i++) {
        printf("%d/%d ",f[i].a, f[i].b);
    }
    printf("\n");
}