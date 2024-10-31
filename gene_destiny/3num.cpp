#include <iostream>
#include "./helper.h"

int digSum(int num);
int digSum(int num) //相加至個位數
{
    while ( num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

///////////////////////////////////////////////////////////////////////////

int destiny_num (int father_name_cnt, int mother_name_cnt, int birth_num); // 命數
int destiny_num (int father_name_cnt, int mother_name_cnt, int birth_num){
    
    return father_name_cnt + mother_name_cnt - birth_num +1;
}

/////////////////////////////////////////////////////////////////////
int sky_num4female (int chinese_birth_year); //天卦 (女)
int sky_num4female (int chinese_birth_year){
    return digSum(chinese_birth_year);
}

int fate_num4male (int chinese_birth_year); // 命卦 (男)
int fate_num4male (int chinese_birth_year){
    switch ( digSum(chinese_birth_year)){
        case 1:
            return 7;
        case 2: 
            return 6;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 9;
        case 9:
            return 8;
        default:
            return 10;
    }

}


int money_num (bool gender, int chinese_birth_year, int destiny_num); //財數
int money_num (bool gender, int chinese_birth_year, int destiny_num){
    if(gender == 0){
        int sky_num = sky_num4female(chinese_birth_year);
        return digSum(destiny_num)*10 + sky_num;
    }
    else {
        int fate_num = fate_num4male(chinese_birth_year);
        return digSum(destiny_num)*10 + fate_num;
    }
}


////////////////////////////////////////////////////////////////////

int room_num (int destiny_num, int money_num); //庫數
int room_num (int destiny_num, int money_num){
    return digSum(money_num)*10 + digSum(destiny_num);
}

///////////////////////////////////////////////////////////////////




