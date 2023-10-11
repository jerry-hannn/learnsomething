#include "pricingutil.h"

PricingUtil::PricingUtil(){}

float PricingUtil::calcVal(float prevPrice, float interest, float oleoConstant){
    float tv = (prevPrice * (0.9 + interest)) * oleoConstant;
    this->val = tv;
    return tv;
}

float PricingUtil::getVal(){
    return this->val;
}
