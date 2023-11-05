// Name: Rosa Rivera Soto
// Date: 11/5/2023
#include "Hand.hpp"
#include <algorithm>

Hand::Hand(){
    cards_;
}
Hand::~Hand(){
    cards_.clear();
}
Hand::Hand(const Hand& other){
    cards_ = other.cards_;
}
Hand& Hand::operator=(const Hand& other){
    if(this != &other){
        cards_ = other.cards_;
    }
    return *this;
}
Hand::Hand(Hand&& other){
    cards_ = std::move(other.cards_);
}
Hand& Hand::operator=(Hand&& other){
    std::swap(cards_, other.cards_);
    return *this;
}
const std::deque<PointCard>& Hand::getCards() const{
    return cards_;
}
void Hand::addCard(PointCard&& card){
    cards_.push_back(std::move(card));
}
bool Hand::isEmpty() const{
    return cards_.empty();
}
void Hand::Reverse(){
    std::reverse(cards_.begin(), cards_.end());
}
int Hand::PlayCard(){
    int points = 0;
    if(cards_.empty()){
        throw std::runtime_error("Hand is empty");
    }
    else{
        if(cards_.front().isPlayable()){
            points = std::stoi(cards_.front().getInstruction().substr(5,1));
            cards_.pop_front();
            return points;
        }
        else{
            cards_.pop_front();
            return points;
        }
    }
        
}