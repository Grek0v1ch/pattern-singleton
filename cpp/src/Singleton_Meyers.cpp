#include "Singelton_Meyers.hpp"

#include <iostream>
#include <fstream>
#include "../external/json.hpp"

using json = nlohmann::json;

Trader& Trader::instance() noexcept {
    static Trader instance;
    return instance;
}

void Trader::add_exchange_rate(const std::string& exchange1, const std::string& exchange2,
                               double rate) noexcept {
    string_pair temp { exchange1, exchange2 };
    if (_table.find(temp) == _table.end()) {
        _table.emplace(temp, rate);
    }
}

void Trader::change_exchange_rate(const std::string& exchange1, const std::string& exchange2,
                                  double rate) noexcept {
    string_pair temp { exchange1, exchange2 };
    if (_table.find(temp) != _table.end()) {
        _table[temp] = rate;
    }
}

double
Trader::exchange_currency(const double amount_currency, const std::string& exchange1,
                                                        const std::string& exchange2) noexcept {
    string_pair temp { exchange1, exchange2 };
    if (_table.find(temp) == _table.end()) {
         return -1.0;
    }
    return amount_currency * _table[temp];
}

void Trader::load_json(const std::string& file_path) {
    std::ifstream fin(file_path);
    if (! fin.is_open()) {
        return;
    }
    json rates;
    fin >> rates;
    _table.clear();
    for (const auto& curr_rate : rates) {
        add_exchange_rate(curr_rate["exchange1"], curr_rate["exchange2"], curr_rate["rate"]);
    }
    rates.clear();
}

void Trader::print_rates() const noexcept {
    for (const auto& curr_rate : _table) {
        std::cout << curr_rate.first.first << " -> " << curr_rate.first.second << " : "
                  << curr_rate.second << '\n';
    }
}

std::size_t Trader::pair_hash::operator()(const Trader::string_pair& v) const noexcept {
    return std::hash<std::string>()(v.first + v.second);
}

bool
Trader::pair_equal::operator()(const Trader::string_pair& v1, const Trader::string_pair& v2) const {
    return v1.first == v2.first && v1.second == v2.second;
}
