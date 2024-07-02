#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<functional>
#include<fstream>
#include<sstream>
#include<numeric>
#include<filesystem>
#include "job.h"
#include "programmer.h"
#include "pilot.h"

namespace fs = std::filesystem;
using vec2dstrings = std::vector<std::vector<std::string>>;

template <typename T>
bool IsInBounds(T value, T lower, T upper) {
    return value >= lower && value <= upper;
}

int ContainsTheString(const std::function<bool(const std::string&)>& test, const std::vector<std::string>& collection) {
    return std::count_if(collection.begin(), collection.end(), test);
}

void writeExampleCSV(const std::string& filename) 
{
    std::ofstream file(filename);
    file << "id,type,name\n";
    file << "0,bird,blue\n";
    file << "1,cat,felix\n";
    file << "2,dog,toto\n";
    file.close();
}

vec2dstrings readCSV(const std::string& filename) 
{
    std::ifstream file(filename);
    vec2dstrings data;
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

vec2dstrings transpose(const vec2dstrings& data) 
{
    if (data.empty()) return {};
    vec2dstrings transposed(data[0].size(), std::vector<std::string>(data.size()));
    for (auto i = 0; i < data.size(); ++i) {
        for (auto j = 0; j < data[i].size(); ++j) {
            transposed[j][i] = data[i][j];
        }
    }
    return transposed;
}

void writeCSV(const std::string& filename, const vec2dstrings& data) 
{
    std::ofstream file(filename);
    for (const auto& row : data) 
    {
        file << accumulate(next(row.begin()), row.end(), row[0], 
                           [](std::string a, const std::string& b) { return a + ',' + b; }) << '\n';
    }
    file.close();
}

void do_csv_requirement()
{
    std::string inputFile = "example.csv";
    std::string outputFile = "transposed_example.csv";

    writeExampleCSV(inputFile);
    auto data = readCSV(inputFile);
    auto transposedData = transpose(data);
    writeCSV(outputFile, transposedData);

    std::cout << "CSV transposed successfully.\n";
}

void cleanup_before_run()
{
    fs::path currentPath = fs::current_path();
    for (const auto& entry : fs::directory_iterator(currentPath)) 
    {
        if (entry.is_regular_file() && entry.path().extension() == ".csv") 
        {
            fs::remove(entry.path());
        }
    }
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

    //requirement j
    cleanup_before_run();
    do_csv_requirement();
    return 0;
}