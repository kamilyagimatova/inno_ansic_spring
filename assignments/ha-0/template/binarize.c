//
// Created by cubazis on 23.05.18.
//

#include "binarize.h"

void binarize_u(unsigned long long x){
	if (x < 0) {
	    x = -x;
	}
	int answer[32];
	int i = 0;
	while (x != 0) {
        answer[i] = x % 2;
        x = x / 2;
        i++;
	}
	while (i < 32) {
	    answer[i] = 0;
	    i++;
	}
	for (int i = 31; i >= 0; i--) {
	    printf("%d", answer[i]);
        if (i % 8 == 0) {
            printf("%c", ' ');
        }
	}
	printf("%c", '\n');
}

void binarize_s(signed long long y){
	if (y >= 0) {
	    binarize_u(y);
	} else {
        int answer[32];
        int i = 0;
        while (y != 0) {
            answer[i] = (y % 2 + 1) % 2;  // invert digit
            y = y / 2;
            i++;
        }
        while (i < 32) {
            answer[i] = 1;  // 1 is inverting 0
            i++;
        }
        i = 0;
        while (i < 32) {
            if (answer[i] == 0) {
                answer[i] = 1;
                break;
            } else {
                answer[i] = 0;
            }
            i++;
        }
        for (int i = 31; i >= 0; i--) {
            printf("%d", answer[i]);
            if (i % 8 == 0) {
                printf("%c", ' ');
            }
        }
        printf("%c", '\n');
	}
}