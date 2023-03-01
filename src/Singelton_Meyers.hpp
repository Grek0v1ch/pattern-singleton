#pragma once

#include <unordered_map>
#include <string>

class Trader {
public:
    Trader(const Trader&) = delete;
    Trader& operator=(const Trader&) = delete;

    static Trader& get_instance() noexcept;

    void add_exchange_rate(const std::string&, const std::string&, double) noexcept;
    void change_exchange_rate(const std::string&, const std::string&, double) noexcept;
    /**
     * @return - неотрицательное значение. Если возвращенное значение меньше нуля, значит обмен
     * неудачный.
     * */
    double exchange_currency(double, const std::string&, const std::string&) noexcept;

    void load_json(const std::string& absolutely_path);

    void print_rates() const noexcept;
private:
    using string_pair = std::pair<std::string, std::string>;

    struct pair_hash {
        std::size_t operator () (string_pair const&) const noexcept;
    };

    struct pair_equal {
        bool operator()(const string_pair&, const string_pair&) const;
    };

    /**
     * Обмен происходит из валюты string_pair.first в валюту string_pair.second по заданному
     * курсу. Курс задается как стоимость одной единицы валюты string_pair.first в единицах
     * валюты string_pair.second.
     * */
    std::unordered_map<string_pair, double, pair_hash, pair_equal> _table;

    Trader() = default;
};