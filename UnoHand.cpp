#include "UnoHand.h"
#include <iostream>

UnoHand::UnoHand()
{
    this->first = NULL;
}

void UnoHand::insertOne(int value, const std::string &color)
{
    UnoCard * curr = new UnoCard;

    curr->set_value(value);
    curr->set_color(color);

    curr->set_nextCard(NULL);

    if (this->first == NULL)
    {
        this->first = curr;
    }

    else
    {
        UnoCard * srch = this->first;

        while(srch->get_nextCard() != NULL)
        {
            srch = srch->get_nextCard();
        }

        srch->set_nextCard(curr);
    }
}

bool UnoHand::removeOne(int value, const std::string & color)
{
    UnoCard * prev;
    UnoCard * curr = this->first;

    if (curr == NULL)
    {
        return false;
    }

    if (curr->get_value() == value && curr->get_color() == color)
    {
        this->first = curr->get_nextCard();
        delete curr;

        return true;
    }

    else
    {
        while (curr->get_nextCard() != NULL)
        {
            if (curr->get_nextCard()->get_value() == value && curr->get_nextCard()->get_color() == color)
            {
                prev = curr;

                curr = curr->get_nextCard();

                prev->set_nextCard(curr->get_nextCard());
                delete curr;

                return true;
            }
        }
    }

    return false;
}

bool UnoHand::find(int value, const std::string & color)
{
    UnoCard * curr = this->first;

    if (this->first == NULL)
    {
        return false;
    }

    if (this->first->get_value() == value || this->first->get_color() == color)
    {
        return true;
    }

    else
    {
        while (curr->get_nextCard() != NULL)
        {
            if (curr->get_nextCard()->get_value() == value || curr->get_nextCard()->get_color() == color)
            {
                return true;
            }
        }
    }
    return false;
}

bool UnoHand::isEmpty()
{
    if (this->first == NULL)
    {
        return true;
    }

    return false;
}

void UnoHand::print()
{
    UnoCard * curr = this->first;

    while(curr != NULL)
    {
        std::cout << curr->get_color() << curr->get_value() << " ";

        curr = curr->get_nextCard();
    }
}
