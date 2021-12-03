#include <stdio.h>
#include "basicplayer.h"
#define SIZE 22

typedef struct
{
    int AtBats;
    int Walks;
    int Singles;
    int Doubles;
    int Triples;
    int Homeruns;
} PlayerStats;


void ReadInPlayerStats(PlayerStats *pStats, BasicPlayer *player, int *count)
{
    int i = 0;
    while(GetNextPlayer(player))
    {
        if((-1)!=(GetStat(player->id,WALKS)))
        {
            pStats[i].AtBats = GetStat(player->id, ATBATS);
            pStats[i].Walks = GetStat(player->id, WALKS);
            pStats[i].Singles = GetStat(player->id, SINGLES);
            pStats[i].Doubles = GetStat(player->id, DOUBLES);
            pStats[i].Triples = GetStat(player->id, TRIPLES);
            pStats[i].Homeruns = GetStat(player->id, HOMERUNS);
        
            i++;
        }
    }
    
    *count = i;
}



void PrintPlayerStats(PlayerStats *pStats, BasicPlayer *player)
{
    // count is irrelevant because this doesn't update with player name
    for (int i = 0; GetNextPlayer(player); i++) {
        printf("ID=%d, Name=%s\n", player->id, player->name);
        printf("     AB=%d Walks=%d Singles=%d Doubles=%d Triples=%d Homeruns=%d\n", pStats[i].AtBats, pStats[i].Walks, pStats[i].Singles, pStats[i].Doubles, pStats[i].Triples, pStats[i].Homeruns);
    }
}


int main(void)
{
    // MODIFIED BY MATT MARLOW
    BasicPlayer player;
    int walks;
    PlayerStats pStats[SIZE];
    int count;

    while (GetNextPlayer(&player))
    {
        if((-1)!=(walks=GetStat(player.id,WALKS)))
        {
            printf("%s had %d walks.\n", player.name, walks);
        }
    }
    ResetToFirstPlayer();
    printf("\n\n");
    ReadInPlayerStats(pStats, &player, &count);
    ResetToFirstPlayer(); 
    PrintPlayerStats(pStats, &player);
}