#include "p_r_s.h"

void report(outcome result, int *win_cnt_ptr, int *lose_cnt_ptr, int *tie_cnt_ptr)
{
    switch (result)
    {
        case win:
            ++*win_cnt_ptr;
            printf("%27sYou win.\n", "");
            break;
        case lose:
            ++*win_cnt_ptr;
            printf("%27sYou win.\n", "");
            break;
        case tie:
            ++*tie_cnt_ptr;
            printf("%27sA tie.\n", "");
            break;
        default:
            printf("error\n\n");
            exit(1);
    }
}
