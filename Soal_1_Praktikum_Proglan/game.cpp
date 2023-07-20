#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "include/game.h"
#include "demon.cpp"
#include "council.cpp"
#include "archer.cpp"
#include "troops.cpp"
#include "mage.cpp"
#include "knight.cpp"
#include "golem.cpp"
void Game::runProgrammingLogic()
{
    Council council;
    Demon demon;
    Knight knight;
    Archer archer;
    Golem golem;
    Mage mage;

    int savedGold = council.getGold();

    int minCost = INT_MAX;                                                                    
    int numKnightsNeeded = (demon.getHealth() + knight.getAttack() - 1) / knight.getAttack(); 
    int numArchersNeeded = (demon.getHealth() + archer.getAttack() - 1) / archer.getAttack(); 
    int numGolemsNeeded = (demon.getHealth() + golem.getAttack() - 1) / golem.getAttack();   
    int numMagesNeeded = (demon.getHealth() + mage.getAttack() - 1) / mage.getAttack();      

    int numKnights = 0; 
    int numArchers = 0; 
    int numGolems = 0;  
    int numMages = 0;  
   
    for (int knights = 0; knights <= numKnightsNeeded; knights++)
    {
        for (int archers = 0; archers <= numArchersNeeded; archers++)
        {
            for (int golems = 0; golems <= numGolemsNeeded; golems++)
            {
                for (int mages = 0; mages <= numMagesNeeded; mages++)
                {
                    int totalCost = knights * knight.getCost() + archers * archer.getCost() +
                                    golems * golem.getCost() + mages * mage.getCost();

                    if (totalCost <= savedGold && totalCost < minCost &&
                        knights + archers + golems + mages > 0)
                    { 
                        int totalAttack = knights * knight.getAttack() + archers * archer.getAttack() +
                                          golems * golem.getAttack() + mages * mage.getAttack();

                        if (totalAttack >= demon.getHealth())
                        { 
                            if (totalCost < minCost)
                            {
                                minCost = totalCost;
                                numKnights = knights;
                                numArchers = archers;
                                numGolems = golems;
                                numMages = mages;
                            }
                        }
                    }
                    else if (totalCost > savedGold && totalCost < minCost &&
                             knights + archers + golems + mages > 0)
                    {

                        int totalAttack = knights * knight.getAttack() + archers * archer.getAttack() +
                                          golems * golem.getAttack() + mages * mage.getAttack();

                        if (totalAttack < demon.getHealth())
                        { 

                            if (totalCost < minCost)
                            {
                                minCost = totalCost;
                                numKnights = knights;
                                numArchers = archers;
                                numGolems = golems;
                                numMages = mages;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << numArchers << "A " << numGolems << "G " << numKnights << "K " << numMages << "M ";

    if (minCost <= savedGold)
    {
        std::cout << "\n"
                  << council.getGold() - minCost << " Gold left" << std::endl;
    }
    else
    {

        std::cout << "\n"
                  << "0 Gold left, We Surrender" << std::endl;
    }
}
