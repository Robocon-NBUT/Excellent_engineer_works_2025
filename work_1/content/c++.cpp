#include <iostream>
#include <fstream>
#include <random>
#include <cstdint>
#include <vector>
#include <string>
#include <sstream>

int main() {
    // 生成随机数引擎
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, UINT32_MAX);

    // 生成5个随机数
    std::vector<uint32_t> random_numbers;
    for (int i = 0; i < 5; ++i) {
        random_numbers.push_back(dis(gen));
    }

    // 将随机数写入input.txt并打印到终端
    std::ofstream out_file("input.txt");
    std::stringstream ss;
    for (size_t i = 0; i < random_numbers.size(); ++i) {
        ss << random_numbers[i];
        if (i != random_numbers.size() - 1) {
            ss << ' ';
        }
    }
    std::string line = ss.str();
    std::cout << line << std::endl;
    out_file << line << std::endl;
    out_file.close();

    // 从input.txt读取数据
    std::ifstream in_file("input.txt");
    std::string input_line;
    std::getline(in_file, input_line);
    in_file.close();

    // 解析数据并计算均值
    std::istringstream iss(input_line);
    std::vector<uint32_t> data;
    uint32_t num;
    while (iss >> num) {
        data.push_back(num);
    }

    double sum = 0.0;
    for (uint32_t n : data) {
        sum += static_cast<double>(n);
    }
    float mean_value = static_cast<float>(sum / data.size());
    std::ofstream out_mean_file("output.txt");
    std::cout << mean_value << std::endl;
    out_mean_file << mean_value << std::endl;
    out_mean_file.close();
    return 0;
}    