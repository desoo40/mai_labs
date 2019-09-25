package org.mai.dep1010.cer;

import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.math.BigDecimal;
import java.util.Currency;

public class Money {
    private Currency currency;
    private BigDecimal amount;

    public Money(Currency currency, BigDecimal amount) {
        this.currency = currency;
        this.amount = amount.setScale(this.currency.getDefaultFractionDigits());
    }

    public Currency getCurrency() {
        return currency;
    }

    public BigDecimal getAmount() {
        return amount;
    }

    public Money add(Money m) {
        throw new NotImplementedException();
    }

    public Money subtract(Money m) {
        throw new NotImplementedException();
    }

    public Money multiply(BigDecimal ratio) {
        throw new NotImplementedException();
    }

    public Money devide(BigDecimal ratio) {
        throw new NotImplementedException();
    }
}
