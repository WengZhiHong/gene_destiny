#include "./helper.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
int main() {

    while (1){
    int father_name_cnt;
    int mother_name_cnt;
    int birth_num;
    bool gender;
    int chinese_birth_year;
    
    std::cout << "父姓筆畫: ";
    std::cin >> father_name_cnt;
    std::cout << "母性筆畫: ";
    std::cin >> mother_name_cnt;
    std::cout << "胎序: ";
    std::cin >> birth_num;
    std::cout << "性別 (女輸入0, 男輸入1): ";
    std::cin >> gender;
    std::cout << "民國出生年(農曆): ";
    std::cin >> chinese_birth_year;

    int user_destiny_num = destiny_num(father_name_cnt, mother_name_cnt, birth_num);
    int user_money_num = money_num(gender, chinese_birth_year, user_destiny_num);
    int user_room_num = room_num(user_destiny_num, user_money_num);

    std::cout << "命數: " << user_destiny_num << std::endl;
    std::cout << "財數: " << user_money_num << std::endl;
    std::cout << "庫數: " << user_room_num << std::endl;

    std::cout << std::endl << "-------------------------" << std::endl;

    auto user_gene_num = gene_num(user_destiny_num, user_money_num, user_room_num);
           

    std::vector<int> outputOrder = {7, 9, 3, 6, 5, 2, 4, 1, 8};

    // 按照 outputOrder 的順序輸出結果
    for (int key : outputOrder) {
        std::cout << key << ": ";
        for (int num : user_gene_num[key]) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    system("pause");
    }
}
