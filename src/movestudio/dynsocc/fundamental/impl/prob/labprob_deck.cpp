#include <stdio.h>

class ISet
{
public: 
    int Count() { return 0;  }
};

class CardDeck : public ISet
{
};
/*
class Probability 
{
    public:
        double prob(void* event)
        {
            void** f= GetEveryFactor(event);
            int n_f = lengt(f);

            void** pspaces;
            double total_measurement = 0.0;

            for (int i=0;i<n_f;++i)
            {
                void* pspace = GetSpace(f);
            }
            void** pspaces;
            void* pspace;
        }
};

class SelfDescription
{
    public:
        int LargerThan() {} 
        int LessThan() {}
        int InRange() {}
};

class Event
{
    ISet* pSpace; 
    std::string Contidion(
        LargerThan();
        LargerThan();
    );
};
*/

/*
int main(int argc, char const *argv[])
{
    Probability prb;
    CardDeck c1;
    CardDeck c2; 

    CardSet c3 = (c1.pick(4K)) + (c2.pick(4A));
    Card ac1 = c3.pick();
    prb.prob(ac1.color=heart); 

    ComesFrom(ac1)=c3;
    Space();
    // Problem
    // 1. Biểu diễn Event 
    // 

    return 0;
}
*/