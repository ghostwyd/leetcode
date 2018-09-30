#include <stdlib.h>
#include <stdio.h>

int reverse(int x) {
    const int max_int = 2147483647;
    const int min_int = -2147483648;
    int result = 0;
    int tmp = x;
    int remain = 0;
    while (tmp != 0) {

       remain = tmp % 10;
       tmp = tmp /10;
       if (result > 0 && (result > max_int / 10 || (result == max_int / 10 && remain > 7))) {
           return 0;
       }

       if (result < 0 && (result < min_int / 10 || (result == min_int / 10 && remain < -8))) {
           return 0;
       }
       result = result * 10 + remain;
    }

    return result;
}


int main(void)
{
    int origin_num = -24323;
    int reverse_num = reverse(-24323);
    printf("origin:%d, reverse:%d\n", origin_num, reverse_num);
    return EXIT_SUCCESS;
}
