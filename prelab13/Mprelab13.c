#include <stdio.h>
#include "basicplayer.h"


void printPlayerStatistics(BasicPlayer *player);
int main(void)
{
    BasicPlayer player;
    int walks;

    while (GetNextPlayer(&player))
    {
        printf("ID=%i, Name=%s\n\t", player.id, player.name);
        printPlayerStatistics(&player);
        
    }
}
void printPlayerStatistics(BasicPlayer *player) {
    int temp;
    printf("AB=%i Walks=%i ",(-1 != (temp = GetStat(player->id, ATBATS)) ? temp : -1), (-1 != (temp = GetStat(player->id, WALKS)) ? temp : -1));
    printf("Singles=%i Doubles=%i ",(-1 != (temp = GetStat(player->id, SINGLES)) ? temp : -1), (-1 != (temp = GetStat(player->id, DOUBLES)) ? temp : -1));
    printf("Triples=%i HomeRuns=%i\n",(-1 != (temp = GetStat(player->id, TRIPLES)) ? temp : -1), (-1 != (temp = GetStat(player->id, HOMERUNS)) ? temp : -1));
}
