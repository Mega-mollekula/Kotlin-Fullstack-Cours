//
// Created by Соловьев(А) on 08.09.2024.
//
#include "terminal.h"
#include <iostream>

float randomChange(){
    return (rand() % 11 - 5) / 100.0;
}

void exchange(Balance& user, Balance& terminal, float amount, float& exchangeRate, int pair){

    //RUB -> USD
    if (pair == 1) {
        if (user.RUB < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.USD - amount * exchangeRate > 0.0) {
            user.RUB -= amount;
            user.USD += amount * exchangeRate;
            terminal.RUB += amount;
            terminal.USD -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough USD in terminal!");
        }
    }

    //USD -> RUB
    if (pair == 2) {
        if (user.USD < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.RUB - amount * exchangeRate > 0.0) {
            user.USD -= amount;
            user.RUB += amount * exchangeRate;
            terminal.USD += amount;
            terminal.RUB -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough RUB in terminal!");
        }
    }

    //RUB -> EUR
    if (pair == 3) {
        if (user.RUB < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.EUR - amount * exchangeRate > 0.0) {
            user.RUB -= amount;
            user.EUR += amount * exchangeRate;
            terminal.RUB += amount;
            terminal.EUR -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough EUR in terminal!");
        }
    }

    //EUR -> RUB
    if (pair == 4) {
        if (user.EUR < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.RUB - amount * exchangeRate > 0.0) {
            user.EUR -= amount;
            user.RUB += amount * exchangeRate;
            terminal.EUR += amount;
            terminal.RUB -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough RUB in terminal!");
        }
    }

    //USD -> EUR
    if (pair == 5) {
        if (user.USD < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.EUR - amount * exchangeRate > 0.0) {
            user.USD -= amount;
            user.EUR += amount * exchangeRate;
            terminal.USD += amount;
            terminal.EUR -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough EUR in terminal!");
        }
    }

    //EUR -> USD
    if (pair == 6) {
        if (user.EUR < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.USD - amount * exchangeRate > 0.0) {
            user.EUR -= amount;
            user.USD += amount * exchangeRate;
            terminal.EUR += amount;
            terminal.USD -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough USD in terminal!");
        }
    }

    //USD -> USDT
    if (pair == 7) {
        if (user.USD < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.USDT - amount * exchangeRate > 0.0) {
            user.USD -= amount;
            user.USDT += amount * exchangeRate;
            terminal.USD += amount;
            terminal.USDT -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough USDT in terminal!");
        }
    }

    //USDT -> USD
    if (pair == 8) {
        if (user.USDT < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.USD - amount * exchangeRate > 0.0) {
            user.USDT -= amount;
            user.USD += amount * exchangeRate;
            terminal.USDT += amount;
            terminal.USD -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough USD in terminal!");
        }
    }

    //USD -> BTC
    if (pair == 9) {
        if (user.USD < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.BTC - amount * exchangeRate > 0.0) {
            user.USD -= amount;
            user.BTC += amount * exchangeRate;
            terminal.USD += amount;
            terminal.BTC -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough BTC in terminal!");
        }
    }

    //BTC -> USD
    if (pair == 10) {
        if (user.BTC < amount) {
            throw std::invalid_argument("You dont have enough cash of this type!");
        }
        if (terminal.USD - amount * exchangeRate > 0.0) {
            user.BTC -= amount;
            user.USD += amount * exchangeRate;
            terminal.BTC += amount;
            terminal.USD -= amount * exchangeRate;
        }
        else {
            throw std::invalid_argument("Not enough USD!");
        }
    }

    float percentChange = randomChange();
    exchangeRate *= (1 + percentChange);
}

void printMenu() {
    printf("\n--------------- Menu ----------------\n");
    printf("0. Show your cash\n");
    printf("1. RUB -> USD\n");
    printf("2. USD -> RUB\n");
    printf("3. RUB -> EUR\n");
    printf("4. EUR -> RUB\n");
    printf("5. USD -> EUR\n");
    printf("6. EUR -> USD\n");
    printf("7. USD -> USDT\n");
    printf("8. USDT -> USD\n");
    printf("9. USD -> BTC\n");
    printf("10. BTC -> USD\n");
    printf("11. Show terminal cash\n");
    printf("12. Show current course\n");
    printf("Enter STOP to exit\n");
    printf("Choose action:");
}