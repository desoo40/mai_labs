package org.mai.dep110.collections.auction;

import org.junit.*;

import java.math.BigDecimal;
import java.util.List;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

public class AuctionImplTest {

    Auction auction;
    String product4thEdition = "Thinking Java 4th edition";
    String product3rdEdition = "Thinking Java 3rd edition";
    BigDecimal defaultPrice = BigDecimal.TEN;

    /*Вызыватется при инициализации класса AuctionImplTest*/
    @BeforeClass
    public static void setupClass(){

    }

    /*Вызыватется перед вызовом каждого метода помеченного аннотацией @Test*/
    @Before
    public void setup(){
        auction = new AuctionImpl();
        auction.placeProduct(product3rdEdition, defaultPrice);
        auction.placeProduct(product4thEdition, defaultPrice);
    }

    /*Вызыватется после вызова каждого метода помеченного аннотацией @Test*/
    @After
    public void clear() {
        auction = null;
    }

    /*Вызывается после вызова всех тестовых методов*/
    @AfterClass
    public static void releaseRecources() {

    }

    @Test(expected = ProductNotFoundException.class)
    public void placeProduct() throws Exception {
        List<String> products = auction.getProducts();

        assertThat(products, hasItems(product3rdEdition, product4thEdition));

        String product5thEdition = "Thinking Java 5th edition";
        assertThat(products, not(hasItem(product5thEdition)));

        assertEquals(auction.getProductPrice(product3rdEdition), defaultPrice);

        BigDecimal notExistingproductPrice = auction.getProductPrice(product5thEdition);
    }

    @Test
    public void addBid() throws Exception {
        assertTrue(true);
    }

    @Test
    public void removeBid() throws Exception {
        assertTrue(true);
    }

    @Test
    public void sellProduct() throws Exception {
        assertTrue(true);
    }

}
