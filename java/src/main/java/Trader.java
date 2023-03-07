import java.util.AbstractMap;
import java.util.HashMap;
import java.util.Map;

class Trader {
    private static Trader instance = null;
    private HashMap<Map.Entry<String, String>, Double> table;

    private Trader() {
        table = new HashMap<>();
        addExchangeRate("RUB", "USD", 0.013289);
        addExchangeRate("USD", "RUB", 75.25);
        addExchangeRate("RUB", "EUR", 0.012484);
        addExchangeRate("EUR", "RUB", 80.1);
        addExchangeRate("RUB", "KZT", 5.92);
    }

    public static Trader getInstance() {
        if (null == instance) {
            instance = new Trader();
        }
        return instance;
    }

    public void addExchangeRate(final String exchange1, final String exchange2, double rate) {
        Map.Entry<String, String> temp = new AbstractMap.SimpleEntry<>(exchange1, exchange2);
        if (! table.containsKey(temp)) {
            table.put(temp, rate);
        }
    }

    public void changeExchangeRate(final String exchange1, final String exchange2, double rate) {
        Map.Entry<String, String> temp = new AbstractMap.SimpleEntry<>(exchange1, exchange2);
        if (table.containsKey(temp)) {
            table.put(temp, rate);
        }
    }

    public double exchangeCurrency(double amount_currency,
                                   final String exchange1,
                                   final String exchange2) {
        Map.Entry<String, String> temp = new AbstractMap.SimpleEntry<>(exchange1, exchange2);
        if (! table.containsKey(temp)) {
            return -1.0;
        }
        return amount_currency * table.get(temp);
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (var rate : table.entrySet()) {
            result.append(rate.getKey().getKey())
                    .append(" -> ")
                    .append(rate.getKey().getValue())
                    .append(" : ")
                    .append(rate.getValue())
                    .append("\n");
        }
        return result.toString();
    }
}
