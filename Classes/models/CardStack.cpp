#include "CardStack.h"

CardStack::~CardStack()
{
}

void CardStack::appendCard(CardModel* card) {
	_cardList.push_back(card);
}

void CardStack::clearCard() {
	_cardList.clear();
}

std::vector<CardModel*> CardStack::getCardList() {
	return _cardList;
}

std::string CardStack::toJson() const {
    Document doc;
    doc.SetArray();
    auto& allocator = doc.GetAllocator();

    for (const auto& card : _cardList) {
        rapidjson::Value cardVal;
        card->toJson(cardVal, allocator);
        doc.PushBack(cardVal, allocator);
    }

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);
    return buffer.GetString();
}

CardStack* CardStack::fromJson(const std::string& jsonStr) {
    CardStack* stack = new CardStack();
    Document doc;
    doc.Parse(jsonStr.c_str());

    if (!doc.IsArray()) {
        CCLOG("CardStack::fromJson: Root JSON is not an array.");
        return stack;
    }

    for (auto& item : doc.GetArray()) {
        CardModel* card = CardModel::fromJson(item);
        stack->appendCard(card);
    }

    return stack;
}
