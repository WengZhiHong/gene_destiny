#include "./helper.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// 找出兩組數字中共有的元素
std::vector<int> findCommonNumbers(const std::vector<int>& set1, const std::vector<int>& set2) {
    std::vector<int> commonNumbers;
    for (int num : set1) {
        if (std::find(set2.begin(), set2.end(), num) != set2.end()) {
            commonNumbers.push_back(num);
        }
    }
    if (commonNumbers.empty())
        commonNumbers.push_back(0);
    return commonNumbers;
}

// 找出兩組數字中都缺少的元素
std::vector<int> findMissingNumbers(const std::vector<int>& set1, const std::vector<int>& set2) {
    std::vector<int> missingNumbers;
    for (int num = 1; num <= 9; ++num) {
        if (std::find(set1.begin(), set1.end(), num) == set1.end() && 
            std::find(set2.begin(), set2.end(), num) == set2.end()) {
            missingNumbers.push_back(num);
        }
    }
    if (missingNumbers.empty())
        missingNumbers.push_back(0);
    return missingNumbers;
}

std::vector<int> findMissingNumbers3(const std::vector<int>& set1,
                                    const std::vector<int>& set2,
                                    const std::vector<int>& set3) {
    std::vector<int> missingNumbers;
    for (int num = 1; num <= 9; ++num) {
        if (std::find(set1.begin(), set1.end(), num) == set1.end() && 
            std::find(set2.begin(), set2.end(), num) == set2.end() && 
            std::find(set3.begin(), set3.end(), num) == set3.end()) {
            missingNumbers.push_back(num);
        }
    }
    if (missingNumbers.empty())
        missingNumbers.push_back(0);
    return missingNumbers;
}


std::unordered_map<int, std::vector<int>> gene_num(int destiny_num, int money_num, int room_num) {
    std::unordered_map<int, std::vector<int>> ordered_table = {
        {1, {1, 4, 6, 8, 2}},
        {2, {2, 1, 3, 5, 7}},
        {3, {3, 4, 6, 9, 2}},
        {4, {4, 1, 5, 8, 3}},
        {5, {5, 4, 9, 2, 7}},
        {6, {6, 1, 4, 3, 8}},
        {7, {7, 2, 3, 5, 9}},
        {8, {8, 2, 1, 6, 4}},
        {9, {9, 1, 3, 5, 7}}  
    };

    std::unordered_map<int, std::vector<int>> gene_num = {
        {1, {}}, {2, {}}, {3, {}}, {4, {}}, {5, {}},
        {6, {}}, {7, {}}, {8, {}}, {9, {}}
    };

    gene_num[7] = ordered_table[digSum(destiny_num)];
    gene_num[9] = ordered_table[digSum(money_num)];
    gene_num[3] = ordered_table[digSum(room_num)];
    
    gene_num[6] = findCommonNumbers(gene_num[9], gene_num[3]);
    gene_num[5] = findMissingNumbers(gene_num[9], gene_num[3]);
    gene_num[2] = findCommonNumbers(gene_num[9], gene_num[7]);
    gene_num[4] = findCommonNumbers(gene_num[7], gene_num[3]);
    gene_num[1] = findCommonNumbers(gene_num[2], gene_num[4]);
    gene_num[8] = findMissingNumbers3(gene_num[7], gene_num[9], gene_num[3]);

    return gene_num; // 返回結果
}

void printVector(const std::vector<int>& vec) {
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}