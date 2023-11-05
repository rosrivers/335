#include "hand.hpp"
Hand::Hand() {}
Hand::~Hand() {}
Hand::Hand(const Hand& other) : cards_(other.cards_) {}
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}
Hand::Hand(Hand&& other) : cards_(std::move(other.cards_)) {}
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
    if (!isEmpty()) {
        PointCard frontCard = cards_.front();
        if (frontCard.isPlayable()) {
            int points = 0;
            const std::string& instruction = frontCard.getInstruction();
            for (char digit : instruction) {
                if (std::isdigit(digit)) {
                    points = points * 10 + (digit - '0');
                } else {}
            }
            cards_.pop_front();
            return points;
        } else {
            cards_.pop_front();
            return 0;
        }
    }
    return 0; // You can return a default value or handle it as needed
}
