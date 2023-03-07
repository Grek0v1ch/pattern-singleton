object Trader {
    private var table: HashMap<Pair<String, String>, Double> = HashMap()
    init {
        addExchangeRate("RUB", "USD", 0.013289)
        addExchangeRate("USD", "RUB", 75.25)
        addExchangeRate("RUB", "EUR", 0.012484)
        addExchangeRate("EUR", "RUB", 80.1)
        addExchangeRate("RUB", "KZT", 5.92)
    }

    fun addExchangeRate(exchange1: String, exchange2: String, rate: Double) {
        val temp = Pair(exchange1, exchange2)
        if (! table.containsKey(temp)) {
            table[temp] = rate
        }
    }

    fun changeExchangeRate(exchange1: String, exchange2: String, rate: Double) {
        val temp = Pair(exchange1, exchange2)
        if (table.containsKey(temp)) {
            table[temp] = rate
        }
    }

    fun exchangeCurrency(amount_currency: Double, exchange1: String, exchange2: String): Double {
        val temp = Pair(exchange1, exchange2)
        if (! table.containsKey(temp)) {
            return -1.0
        }
        return amount_currency * table[temp]!!
    }

    override fun toString(): String {
        var result: String = String()
        for (rate in table) {
            result += rate.key.first + " -> " + rate.key.second + " : " +
                      rate.value.toString() + "\n"
        }
        return result
    }
}

fun initTrader() {
    println("Курсы валют на момент функции init_trader():")
    print(Trader)
    println("Переведем 10 рублей в доллары: " + Trader.exchangeCurrency(10.0, "RUB", "USD"))
    println("Переведем 10 долларов в рубли: " + Trader.exchangeCurrency(10.0, "USD", "RUB"))
    println("Переведем 5 рублей в тенге: " + Trader.exchangeCurrency(10.0, "RUB", "KZT"))
    println("Если мы попробуем перевести 10 евро в тенге, то у нас не выйдет: " +
            Trader.exchangeCurrency(10.0, "EUR", "KZT"))
    println()
}

fun changeTrader() {
    println("\n");
    println("Добавим этот курс в трейдер: BYN -> RUB : 26.67")
    Trader.addExchangeRate("BYN", "RUB", 26.67);
    println("Изменим курс USD -> RUB : 75.25 на курс USD -> RUB : 1")
    Trader.changeExchangeRate("USD", "RUB", 1.0);
    println("Курсы валют в конце функции change_trader():")
    println(Trader)
}


fun main(args: Array<String>) {
    initTrader()
    changeTrader()
    println("\n\nВ конце main() трейдер содержит такие курсы:")
    println(Trader)
}