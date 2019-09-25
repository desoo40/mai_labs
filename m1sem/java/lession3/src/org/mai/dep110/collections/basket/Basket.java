package org.mai.dep110.collections.basket;

import java.util.List;

/* Корзина в интернет-магазине */
public interface Basket {

    /* добавить продукт в корзину с заданным количеством */
    void addProduct(String product, int quantity);

    /* удалить продукт из корзины */
    void removeProduct(String product);

    /* изменить количество продукта */
    void updateProductQuantity(String product, int quantity);

    /* получить список продуктов */
    List<String> getProducts();
}
