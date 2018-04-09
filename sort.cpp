#include<iostream>
#include "swap.h"

int sort(int t[], const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (t[j] > t[j - 1]) {
				swap(&t[j], &t[j - 1]);
			}
		}
	 }
	return t[(int)(size / 2)];
}