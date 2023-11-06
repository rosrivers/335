// Name: Rosa Rivera Soto
// Date: 11/5/2023
#include "Card.hpp"
Card::~Card()
{
    delete[] bitmap_;
    bitmap_ = nullptr;
}
Card::Card(const Card& rhs)
{
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
    bitmap_ = new int[80];
    for (int i = 0; i < 80; i++) {
        bitmap_[i] = rhs.bitmap_[i];
    }
}
Card& Card::operator=(const Card& rhs){
        if(this != &rhs){
            cardType_ = rhs.cardType_;
            instruction_ = rhs.instruction_;
            drawn_ = rhs.drawn_;
            delete[] bitmap_;
            bitmap_ = nullptr;
            bitmap_ = new int[80];
            for (int i = 0; i < 80; i++) {
                bitmap_[i] = rhs.bitmap_[i];
            }
        }
        return *this;
}
Card::Card(Card&& rhs){
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
    bitmap_ = rhs.bitmap_;
    rhs.instruction_ = "";
    rhs.drawn_ = false;
    rhs.bitmap_ = nullptr;
}
Card& Card::operator=(Card&& rhs){
    if(this != &rhs){
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        bitmap_ = rhs.bitmap_;
        drawn_ = rhs.drawn_;
        rhs.instruction_ = "";
        rhs.bitmap_ = nullptr;
        rhs.drawn_ = false;
    }
    return *this;
}
Card::Card(){
    instruction_ = "";
    drawn_ = false;
    bitmap_ = new int[80];
}
std::string Card::getType() const{
    if(cardType_ == POINT_CARD){
        return "POINT_CARD";
    }
    else if (cardType_ == ACTION_CARD)
    {
        return "ACTION_CARD";
    }   
}
void Card::setType(const CardType& type){
    cardType_ = type;
}
const std::string& Card::getInstruction() const{
    return instruction_;
}
void Card::setInstruction(const std::string& instruction){
    instruction_ = instruction;
}
const int* Card::getImageData() const{
    return bitmap_;
}
void Card::setImageData(int* data){
    bitmap_ = data;
}
bool Card::getDrawn() const{
    return drawn_;
}
void Card::setDrawn(const bool& drawn){
    drawn_ = drawn;
}
