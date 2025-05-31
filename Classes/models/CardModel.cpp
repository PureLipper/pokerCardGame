#pragma once
#include "CardModel.h"

#include "utils/JsonUtils.h"

CardModel::CardModel(CardFaceType cardFace, CardSuitType cardSuit, const Vec2& pos)
    : _cardFace(cardFace), _cardSuit(cardSuit), _position(pos) {}

CardModel::~CardModel()
{}

int CardModel::getCardFace() const {
	return _cardFace;
}

int CardModel::getCardSuit() const {
	return _cardSuit;
}

Vec2 CardModel::getPosition() const {
	return _position;
}

void CardModel::toJson(rapidjson::Value& out, rapidjson::Document::AllocatorType& allocator) const {
    out.SetObject();
    out.AddMember("CardFace", static_cast<int>(_cardFace), allocator);
    out.AddMember("CardSuit", static_cast<int>(_cardSuit), allocator);

    rapidjson::Value posObj(rapidjson::kObjectType);
    posObj.AddMember("x", _position.x, allocator);
    posObj.AddMember("y", _position.y, allocator);
    out.AddMember("Position", posObj, allocator);
}

CardModel* CardModel::fromJson(rapidjson::Value& value) {
    const int cardFace = value["CardFace"].GetInt();
    const int cardSuit = value["CardSuit"].GetInt();

    const rapidjson::Value& posObj = value["Position"];
    const float x = posObj["x"].GetFloat();
    const float y = posObj["y"].GetFloat();

    Vec2 pos(x, y);
    return new CardModel(static_cast<CardFaceType>(cardFace), static_cast<CardSuitType>(cardSuit), pos);
}

std::string CardModel::getResName() const
{
    std::string color;
    std::string face;

    if (_cardSuit == CST_CLUBS || _cardSuit == CST_SPADES) {
        color = "black";
    }
    else{
        color = "red";
    }

    int t = static_cast<int>(_cardFace);
    if (t >= 1 && t <= 9) {
        face = std::to_string(t+1);
    }
    else {
        switch (t) {
        case 0:
            face = "A";
            break;
        case 10:
            face = "J";
            break;
        case 11:
            face = "Q";
            break;
        case 12:
            face = "K";
            break;
        }
    }

    return color + "_" + face;
}

std::string CardModel::getSuitName() const
{
    std::string suit;
    switch (_cardSuit) {
	    case CST_CLUBS:
	        suit = "club";
	        break;
	    case CST_HEARTS:
	        suit = "heart";
	        break;
	    case CST_DIAMONDS:
	        suit = "diamond";
	        break;
	    case CST_SPADES:
	        suit = "spade";
	        break;
	    default:
	        suit = "";
    }
    return suit;
}
