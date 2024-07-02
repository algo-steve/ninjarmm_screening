#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<functional>
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


    return 0;
}