package org.mai.dep110.collections.auction;

import org.junit.*;
import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

import static org.hamcrest.CoreMatchers.*;


public class ExampleJUnitTest {

    @BeforeClass
    public static void setupClass(){

    }

    /*Вызыватется перед вызовом каждого метода помеченного аннотацией @Test*/
    @Before
    public void setup(){

    }

    /*Вызыватется после вызова каждого метода помеченного аннотацией @Test*/
    @After
    public void clear() {

    }

    /*Вызывается после вызова всех тестовых методов*/
    @AfterClass
    public static void releaseRecources() {

    }

    @Test
    public void simpleTest() {

        //JUnit asserts
        assertTrue(1 == 1);

        assertFalse("test" == new String("test"));

        assertTrue("test".equals(new String("test")));

        assertEquals(new Integer(1), Integer.valueOf(1));

        assertNotNull(new Object());

        Object test = null;
        assertNull(test);

        assertArrayEquals(new int[] {1,2,3}, new int[] {1,2,3});

    }

    @Test(expected = NotImplementedException.class)
    public void exceptionTest() {
        throw new NotImplementedException();
    }

    @Test
    public void collectionTest() {
        List<Integer> ints = new ArrayList<>();
        ints.add(1);
        ints.add(2);
        ints.add(3);
        ints.add(4);

        assertTrue(ints.size() == 4);
        assertTrue(ints.contains(1));

        assertThat(ints, hasItem(1));
        assertThat(ints, not(hasItem(10)));

        assertThat(ints, hasItems(1,2,3));

        assertThat(ints, not(hasItems(5)));

    }


}
