#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
int digSum(int num);//相加至個位數
int destiny_num (int father_name_cnt, int mother_name_cnt, int birth_num); // 命數
int sky_num4female (int chinese_birth_year); //天卦 (女)
int fate_num4male (int chinese_birth_year); // 命卦 (男)
int money_num (bool gender, int chinese_birth_year, int destiny_num); //財數
int room_num (int destiny_num, int money_num); //庫數

std::vector<int> findCommonNumbers(const std::vector<int>& set1, const std::vector<int>& set2);
std::vector<int> findMissingNumbers(const std::vector<int>& set1, const std::vector<int>& set2);
std::vector<int> findMissingNumbers3(const std::vector<int>& set1,
                                    const std::vector<int>& set2,
                                    const std::vector<int>& set3);
std::unordered_map<int, std::vector<int>> gene_num(int destiny_num, int money_num, int room_num);
void printVector(const std::vector<int>& vec);
