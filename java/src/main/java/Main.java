class Main {
	static void initTrader() {
		Trader trader = Trader.getInstance();
		System.out.println("Курсы валют на момент функции init_trader():");
		System.out.print(trader);
		System.out.println("Переведем 10 рублей в доллары: " +
				           trader.exchangeCurrency(10.0, "RUB", "USD"));
		System.out.println("Переведем 10 долларов в рубли: " +
				           trader.exchangeCurrency(10.0, "USD", "RUB"));
		System.out.println("Переведем 5 рублей в тенге: " +
				           trader.exchangeCurrency(10.0, "RUB", "KZT"));
		System.out.println("Если мы попробуем перевести 10 евро в тенге, то у нас не выйдет: " +
				trader.exchangeCurrency(10.0, "EUR", "KZT"));
		System.out.println();
	}

	static void changeTrader() {
		Trader trader = Trader.getInstance();
		System.out.println("\n");
		System.out.println("Добавим этот курс в трейдер: BYN -> RUB : 26.67");
		trader.addExchangeRate("BYN", "RUB", 26.67);
		System.out.println("Изменим курс USD -> RUB : 75.25 на курс USD -> RUB : 1");
		trader.changeExchangeRate("USD", "RUB", 1.0);
		System.out.println("Курсы валют в конце функции change_trader():");
		System.out.println(trader);
	}

	public static void main(String[] args) {
		Trader a = Trader.getInstance();
		initTrader();
		changeTrader();
		System.out.println("\n\nВ конце main() трейдер содержит такие курсы:");
    	System.out.println(a);
	}
}
