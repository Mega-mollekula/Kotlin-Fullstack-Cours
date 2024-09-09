#include <iostream>
#include "terminal.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    //data on 08.09.24
    float RUB_USD_rate = 0.011;
    float USD_RUB_rate = 89.82;
    float RUB_EUR_rate = 0.01;
    float EUR_RUB_rate = 99.72;
    float USD_EUR_rate = 0.9;
    float EUR_USD_rate = 1.11;
    float USD_USDT_rate = 1.0;
    float USDT_USD_rate = 1.0;
    float USD_BTC_rate = 0.000019;
    float BTC_USD_rate = 53841.0;

    Balance user = {1000000, 0, 0, 0, 0};
    Balance terminal = {10000, 1000, 1000, 1000, 1.5};

    while (true) {
        string input;
        printMenu();
        cin >> input;
        if (input == "STOP") {
            break;
        }
        int action = std::stoi(input);
        switch (action) {
            case 0: {
                cout << "Your cash:\n";
                printf("RUB: %.2f; USD: %.2f; EUR: %.2f; USDT: %.2f; BTC: %.5f;\n",
                       user.RUB, user.USD, user.EUR, user.USDT, user.BTC);
                break;
            }
            case 1: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, RUB_USD_rate, 1);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, USD_RUB_rate, 2);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, RUB_EUR_rate, 3);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, EUR_RUB_rate, 4);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, USD_EUR_rate, 5);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 6: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, EUR_USD_rate, 6);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 7: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, USD_USDT_rate, 7);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 8: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, USDT_USD_rate, 8);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 9: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, USD_BTC_rate, 9);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 10: {
                cout << "Enter value: ";
                float value;
                cin >> value;
                try {
                    exchange(user, terminal, value, BTC_USD_rate, 10);
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 11: {
                cout << "Cash in terminal: ";
                printf("RUB: %.2f; USD: %.2f; EUR: %.2f; USDT: %.2f; BTC: %.5f;\n",
                       terminal.RUB, terminal.USD, terminal.EUR, terminal.USDT,terminal.BTC);
                break;
            }
            case 12: {
                cout << "Show current course:\n";
                printf(" 1 RUB -> %.4f USD\n 1 USD-> %.4f RUB\n 1 RUB-> %.4f EUR\n 1 EUR-> %.4f RUB\n"
                       " 1 USD -> %.4f EUR\n 1 EUR -> %.4f USD\n 1 USD -> %.4f USDT\n 1 USDT -> %.4f USD\n"
                       " 1 USD -> %.4f BTC\n 1 BTC -> %.4f USD\n",
                      RUB_USD_rate, USD_RUB_rate, RUB_EUR_rate, EUR_RUB_rate, USD_EUR_rate, EUR_USD_rate,
                      USD_USDT_rate, USDT_USD_rate,USD_BTC_rate, BTC_USD_rate);
                break;
            }
            default:
                printf("Unknown command.\n");
                break;
        }
    }
}