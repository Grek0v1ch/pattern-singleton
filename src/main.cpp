#include <iostream>

#include "Singelton_Meyers.hpp"

void init_trader() {
    Trader::get_instance().load_json("res/rates.json");
    std::cout << "Курсы валют на момент функции init_trader():\n";
    Trader::get_instance().print_rates();

    std::cout << "Переведем 10 рублей в доллары: "
              << Trader::get_instance().exchange_currency(10, "RUB", "USD") << std::endl;
    std::cout << "Переведем 10 долларов в рубли: "
              << Trader::get_instance().exchange_currency(10, "USD", "RUB") << std::endl;
    std::cout << "Переведем 5 рублей в тенге: "
              << Trader::get_instance().exchange_currency(10, "RUB", "KZT") << std::endl;
    std::cout << "Если мы попробуем перевести 10 евро в тенге, то у нас не выйдет: "
              << Trader::get_instance().exchange_currency(10, "EUR", "KZT");
    std::cout << std::endl;
}

void change_trader() {
    std::cout << "\n\n";
    std::cout << "Добавим этот курс в трейдер: BYN -> RUB : 26.67\n";
    Trader::get_instance().add_exchange_rate("BYN", "RUB", 26.67);
    std::cout << "Изменим курс USD -> RUB : 75.25 на курс USD -> RUB : 1\n";
    Trader::get_instance().change_exchange_rate("USD", "RUB", 1);
    std::cout << "Курсы валют в конце функции change_trader():\n";
    Trader::get_instance().print_rates();
}

int main() {
    init_trader();
    change_trader();
    std::cout << "\n\nВ конце main() трейдер содержит такие курсы: \n";
    Trader::get_instance().print_rates();
    return 0;
}
