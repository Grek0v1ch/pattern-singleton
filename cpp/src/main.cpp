#include <iostream>

#include "Singelton_Meyers.hpp"

void init_trader() {
    Trader& trader = Trader::instance();
    trader.load_json("res/rates.json");
    std::cout << "Курсы валют на момент функции init_trader():\n";
    trader.print_rates();
    
    std::cout << "Переведем 10 рублей в доллары: "
              << trader.exchange_currency(10, "RUB", "USD") << std::endl;
    std::cout << "Переведем 10 долларов в рубли: "
              << trader.exchange_currency(10, "USD", "RUB") << std::endl;
    std::cout << "Переведем 5 рублей в тенге: "
              << trader.exchange_currency(10, "RUB", "KZT") << std::endl;
    std::cout << "Если мы попробуем перевести 10 евро в тенге, то у нас не выйдет: "
              << trader.exchange_currency(10, "EUR", "KZT");
    std::cout << std::endl;
}

void change_trader() {
    Trader& trader = Trader::instance();

    std::cout << "\n\n";
    std::cout << "Добавим этот курс в трейдер: BYN -> RUB : 26.67\n";
    trader.add_exchange_rate("BYN", "RUB", 26.67);
    std::cout << "Изменим курс USD -> RUB : 75.25 на курс USD -> RUB : 1\n";
    trader.change_exchange_rate("USD", "RUB", 1);
    std::cout << "Курсы валют в конце функции change_trader():\n";
    trader.print_rates();
}

int main() {
    Trader& trader = Trader::instance();
    init_trader();
    change_trader();
    std::cout << "\n\nВ конце main() трейдер содержит такие курсы: \n";
    trader.print_rates();
    return 0;
}
