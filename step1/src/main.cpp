#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<functional>
#include<fstream>
#include<sstream>
#include "job.h"
#include "programmer.h"
#include "pilot.h"

template <typename T>
bool IsInBounds(T value, T lower, T upper) {
    return value >= lower && value <= upper;
}

int ContainsTheString(const std::function<bool(const std::string&)>& test, const std::vector<std::string>& collection) {
    return std::count_if(collection.begin(), collection.end(), test);
}

void writeExampleCSV(const std::string& filename) {
    std::ofstream file(filename);
    file << "id,type,name\n";
    file << "0,bird,blue\n";
    file << "1,cat,felix\n";
    file << "2,dog,toto\n";
    file.close();
}

std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> data;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream s(line);
        std::string field;
        data.emplace_back();
        while (getline(s, field, ',')) {
            data.back().push_back(field);
        }
    }
    return data;
}

int main()
{
    //requirements e and f
    std::vector<std::unique_ptr<Job>> jobs;
    jobs.push_back(std::make_unique<Programmer>());
    jobs.push_back(std::make_unique<Pilot>());

    //requirement g
    for (const auto& job : jobs) {
        job->Work();
        job->TakeBreak();
        job->Train();
        job->GetSalary();
    }

    //requirement h
    uint32_t httpResponseCode = 503;
    std::cout << "IsInBounds<uint32_t>(" << httpResponseCode << ", 500, 599): "
              << (IsInBounds<uint32_t>(httpResponseCode, 500, 599) ? "true" : "false") << std::endl;


     //requirement i + (i/ii)
    auto theStrings = std::vector<std::string>{"one", "two", "test"};
    auto count = ContainsTheString([](const std::string& tested) { return tested == "test"; }, theStrings);
    std::cout << "Number of 'test' strings: " << count << std::endl;
    return 0;
}