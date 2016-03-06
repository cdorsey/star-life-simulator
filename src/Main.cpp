#include <iostream>
#include "Star.h"
#include <queue>
#include <list>
#include <time.h>

using namespace std;

int rollDice();

int main() {
    int diceVal;   //Hold dice roll
    queue<Star *> ism;   //Desk of Interstellar Material
    Star **turnStars;  //Dynamic array to hold stars for current turn
    list<Turn *> turns; //List of turns
    Turn *thisTurn = nullptr;    //Information for current turn
    deque<Star *> pending; //Stars that are waiting to be killed

    srand((unsigned int) time(0));

    // Create ISM
    for (int i = 0; i < 50; i++)
        ism.push(new Star());

    for (int turnNum = 1; turnNum <= 30 && ism.size() > 0; turnNum++) { //Start turn
        diceVal = rollDice();
        turnStars = new Star *[diceVal];
        int turnStars_size = diceVal;

        if (turnNum == 1)
            thisTurn = new Turn();
        else
            thisTurn = new Turn(*thisTurn);

        turns.push_back(thisTurn);

        // Define all stars for this turn
        for (int i = 0; i < turnStars_size; i++) {
            //If no ISM is available, stop making stars
            if (ism.size() <= 0) {
                turnStars_size = i;
                break;
            }

            //Pull ISM out of the pile and make a star
            turnStars[i] = ism.front();
            ism.pop();

            turnStars[i]->setCreated(thisTurn);

            diceVal = rollDice();
            switch (diceVal) {
                case 1:
                    turnStars[i]->setType(Star::TYPE_HIGH_MASS);
                    break;
                case 2:
                case 3:
                    turnStars[i]->setType(Star::TYPE_MED_MASS);
                    break;
                case 4:
                case 5:
                case 6:
                    turnStars[i]->setType(Star::TYPE_LOW_MASS);
                    break;
                default:
                    break;
            }
        }

        // Sort stars into appropriate "Staging area"
        // High mass: Go to top of pending pile to die this turn
        // Mid mass:  Go to bottom of pending pile to die in a future turn
        // Low mass:  Deleted as low mass stars no longer contribute to ISM
        for (int i = 0; i < turnStars_size; i++) {
            if (turnStars[i]->getType() == Star::TYPE_HIGH_MASS) {
                //Place high mass stars at front of pending pile
                //High mass stars will die this turn
                pending.push_front(turnStars[i]);
            }
            else if (turnStars[i]->getType() == Star::TYPE_MED_MASS) {
                //Place mid mass stars at the back of pending pile
                //Medium mass stars will die 3 turns after being created
                pending.push_back(turnStars[i]);
            }
            else if (turnStars[i]->getType() == Star::TYPE_LOW_MASS) {
                //Low mass stars no longer interact with ISM
                delete turnStars[i];
            }
            else {
                throw logic_error("Invalid star type");
            }
        }

        Star *star = (pending.size() > 0 ? pending.front() : nullptr);
        //Kill stars at the end of their lives
        while (pending.size() > 0 &&
               star->getCreatedAsInt() + star->getLifespan() <= thisTurn->getNum()) {
            if (star->getType() == Star::TYPE_HIGH_MASS) {
                thisTurn->incT2();
                ism.push(star);
            }
            else {
                thisTurn->incPN();

                if (rand() % 2 == 0)
                    ism.push(star);
                else
                    delete star;
            }
            pending.pop_front();
            star = (pending.size() > 0 ? pending.front() : nullptr);
        }
    }
    // End Turn

    cout << "Final output: " << *(turns.back()) << endl;
    cin.get();
    return 0;
}


int rollDice() {
    return 1 + (rand() % 6);
}