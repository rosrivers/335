#include "Hand.hpp"
#include <algorithm>
Hand::Hand() {
}
Hand::~Hand() {
}
Hand::Hand(const Hand& other) {
    cards_ = other.cards_;
}
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}
Hand::Hand(Hand&& other) {
    cards_ = std::move(other.cards_);
}
Hand& Hand::operator=(Hand&& other) {
    if (this != &other) {
        cards_ = std::move(other.cards_);
    }
    return *this;
}
const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}
void Hand::addCard(PointCard&& card) {
    cards_.push_back(std::move(card));
}
bool Hand::isEmpty() const {
    return cards_.empty();
}
void Hand::Reverse() {
    std::reverse(cards_.begin(), cards_.end());
}
int Hand::PlayCard() {
    if (isEmpty()) {
        throw std::out_of_range("The hand is empty.");
    }
    PointCard frontCard = std::move(cards_.front());
    cards_.pop_front();
    
    if (!frontCard.isPlayable()) {
        return 0;
    }
    return 1 + rand() % 99;
}