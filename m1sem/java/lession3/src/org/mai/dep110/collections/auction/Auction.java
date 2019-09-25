package org.mai.dep110.collections.auction;

import java.math.BigDecimal;
import java.util.List;

/* Аукцион */
public interface Auction {

    /* Выставить продукт на аукцион с начальной ценой */
    void placeProduct(String product, BigDecimal initialPrice);

    /* Покупатель user добавляет заявку на продукт со своей ценой */
    void addBid(String user, String product, BigDecimal price);

    /* Покупательно может удалить заявку */
    void removeBid(String user, String product);

    /* Продать продукт по самой выгодной предложенной цене */
    boolean sellProduct(String product);

    /* Получить список выставленных товаров на аукцион */
    List<String> getProducts();

    /* Получить цену выставленного товара на аукцион */
    BigDecimal getProductPrice(String product);
}
