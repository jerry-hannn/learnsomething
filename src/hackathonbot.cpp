//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"

HackathonBot::HackathonBot() {};

double HackathonBot::getBalance(){
    return this->balance;
}

bool HackathonBot::isHolding(){
    return this->holding;
}

void HackathonBot::buy(){
    this->holding = true;
}

void HackathonBot::sell(){
    this->holding = false;
    this->prices.clear();
}

void HackathonBot::takeAction(float price){

    //streaks like snapchat
    if (this->prices.size() > 0){
        if (price > this->prices.back()){
            riseStreak++;
            fallStreak = 0;
        }
        else if(price < this->prices.back()){
            riseStreak = 0;
            fallStreak++;
        }
    }

    //new price
    this->prices.push_back(price);

    //buy and don't sell
    if(!(this->holding)){
        if(price < 52.0 || fallStreak>= 5){
            this->buy();
        }
        return;
    }

    //sell 
    if(riseStreak >= 52 || fallStreak >= 47){
        this->sell();
        return;
    }

    float fallrise = price / this->prices.front();
    if (fallrise < 0.62 || fallrise > 1.89){
        this->sell();
        return;
    }

    int len = prices.size();
    if(len > 2){
        float price0 = this->prices[len - 3];
        float price1 = this->prices[len - 2];
        float price2 = this->prices[len - 1];

        float change1 = price1/price0;
        float change2 = price2/price1;
        float change3 = price/price2;

        float totalChange = price/price0;

        if(change1 >= 1.2 && change2 >= 0.85 && change3 >= 1.3 && totalChange >= 1.5){
            this->sell();
            return;
        }
        if(change1 >= 0.85 && change2 >= 1.15 && change3 <=0.75 && totalChange <= 0.55){
            this->sell();
            return;
        }
    }

    if(len > 10){
        float buyPrice = this->prices.front();
        for(int i = 0; i < 11; i++){
            float change = this->prices[i]/buyPrice;
            if(change > 1.05 || change < 0.95){
                return;
            }
        }
        this->sell();
    }
}