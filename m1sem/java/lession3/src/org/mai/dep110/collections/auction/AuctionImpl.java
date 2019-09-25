package org.mai.dep110.collections.auction;

import java.math.BigDecimal;
import java.util.List;


public class AuctionImpl implements Auction {
    @Override
    public void placeProduct(String product, BigDecimal initialPrice) {

    }

    @Override
    public void addBid(String user, String product, BigDecimal price) {

    }

    @Override
    public void removeBid(String user, String product) {

    }

    @Override
    public boolean sellProduct(String product) {
        return false;
    }

    @Override
    public List<String> getProducts() {
        return null;
    }

    @Override
    public BigDecimal getProductPrice(String product) {
        return null;
    }
}
