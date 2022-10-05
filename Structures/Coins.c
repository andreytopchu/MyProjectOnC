#include <stdio.h>
#include "../Interfaces/Coins.h"

int Change (const int coins[], int money, int min_coins[], int coins_used[]) {
    for (int cents = 0; cents < money + 1; ++cents) {
        int coin_count = cents;
        int new_coin = 1;

        int array_size = 0;

        for (int j = 0; j < 5; ++j) {
            if(coins[j] <= cents)
                array_size++;
        }

        int allowed_coins[array_size];

        for (int j = 0; j < 5; ++j) {
            if(coins[j] <= cents) allowed_coins[j] = coins[j];
        }

        for (int j = 0; j < array_size; ++j) {
            if(min_coins[cents - allowed_coins[j]] + 1 < coin_count){
                coin_count = min_coins[cents - allowed_coins[j]] + 1;
                new_coin = allowed_coins[j];
            }
        }
        min_coins[cents] = coin_count;
        coins_used[cents] = new_coin;
    }
    return min_coins[money];
}

void PrintCoins(const int coins_used[], int money) {
    int coin = money;
    while (coin > 0) {
        int this_coin = coins_used[coin];
        printf("%d ", this_coin);
        coin = coin - this_coin;
    }
}

void ChangeCoins (int amount) {
    int coinsType[5] = {1, 2, 5, 7, 10};
    int coinsUsed[amount + 1];
    int coinCount[amount + 1];

    printf("Making change for %d requires %d coins.", amount, Change(coinsType, amount, coinCount, coinsUsed));
    printf("\nThey are: ");
    PrintCoins(coinsUsed, amount);
}