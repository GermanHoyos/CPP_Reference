#include "p_r_s.h"

void prn_final_status(int win_cnt, int lose_cnt)
{
    if (win_cnt > lose_cnt)
        printf("CONGRATS U WON\n\n");
    else if (win_cnt == lose_cnt)
        printf("draw\n\n");
    else
        printf("lost\n\n");
}

void prn_game_status(int win_cnt, int lose_cnt, int tie_cnt)
{
    printf( "\n%s\n%s%4d\n%s%4d\n%s%4d\n%s%4d\n\n",
            "game status:",
            " win: ", win_cnt,
            " lose: ", lose_cnt,
            " Tie: ", tie_cnt,
            " total:", win_cnt + lose_cnt + tie_cnt);
}

void prn_help(void)
{
    printf("p:paper r:rock s:siccors g:print game stats h:help i:reprint this q: quit");
}

void prn_instructions(void)
{
    printf("instructions - ");
}
