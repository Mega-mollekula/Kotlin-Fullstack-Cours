//
// Created by Соловьев(А) on 08.09.2024.
//

#ifndef UNTITLED_TERMINAL_H
#define UNTITLED_TERMINAL_H

struct Balance {
    float RUB;
    float USD;
    float EUR;
    float USDT;
    float BTC;
};

float randomChange();

void exchange(Balance& user, Balance& terminal, float amount, float& exchangeRate, int pair);

void printMenu();

#endif //UNTITLED_TERMINAL_H
