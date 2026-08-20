#ifndef DYNSOCC_INTERFACE_BASIC_TOURNAMENT_H_
#define DYNSOCC_INTERFACE_BASIC_TOURNAMENT_H_

enum TournamentType {
    NATIONTEAM_TOURNAMENT_32,
    CLUBTEAM_TOURNAMENT_32,
    NATIONTEAM_TOURNAMENT_24,
    NATIONTEAM_TOURNAMENT_16,
    LEAGUE_2ROUND,
    LEAGUE_1ROUND
};

struct ITournament 
{
    TournamentType type;
    int teamCount;
};

class TournamentFixture 
{
public:
    virtual ~TournamentFixture() {}
};  

#endif 