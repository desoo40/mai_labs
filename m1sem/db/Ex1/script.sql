create table CITY
(
    CITY_ID   NUMBER not null
        constraint XPKCITY
            primary key,
    REGION    VARCHAR2(100),
    COUNTRY   VARCHAR2(100),
    CITY_NAME VARCHAR2(250)
)
/

create table OFFICE
(
    OFFICE_ID   NUMBER not null
        constraint XPKOFFICE
            primary key,
    CITY_ID     NUMBER not null
        constraint R_5
            references CITY,
    OFFICE_NAME VARCHAR2(200)
)
/

create table MANAGER
(
    MANAGER_ID         NUMBER not null
        constraint XPKMANAGER
            primary key,
    MANAGER_FIRST_NAME VARCHAR2(250),
    OFFICE_ID          NUMBER not null
        constraint R_4
            references OFFICE,
    MANAGER_LAST_NAME  VARCHAR2(250)
)
/

create table PRODUCT
(
    PRODUCT_ID   NUMBER not null
        constraint XPKPRODUCT
            primary key,
    PRODUCT_NAME VARCHAR2(200)
)
/

create table SALES_ORDER
(
    SALES_ORDER_ID NUMBER not null
        constraint XPKSALES_ORDER
            primary key,
    ORDER_DATE     DATE,
    MANAGER_ID     NUMBER
        constraint R_1
            references MANAGER
)
/

create table SALES_ORDER_LINE
(
    ORDER_LINE_ID  NUMBER not null
        constraint XPKSALES_ORDER_LINE
            primary key,
    SALES_ORDER_ID NUMBER not null
        constraint R_2
            references SALES_ORDER,
    PRODUCT_ID     NUMBER not null
        constraint R_3
            references PRODUCT,
    PRODUCT_QTY    NUMBER(32, 2),
    PRODUCT_PRICE  NUMBER(32, 2)
)
/

create table COMPANY
(
    ID             NUMBER,
    NAME           VARCHAR2(1000),
    SECTOR         VARCHAR2(200),
    SUBSECTOR      VARCHAR2(200),
    COUNTRY_OF_INC VARCHAR2(100),
    REGION         VARCHAR2(100),
    ORD_SHARES     VARCHAR2(3),
    WARRANTS       VARCHAR2(3),
    MARKET_CAPITAL NUMBER(15, 10),
    MAIN_MARKET    VARCHAR2(100)
)
/

create table SALES_ORDER_LINE_EMPTY
(
    ORDER_LINE_ID  NUMBER not null,
    SALES_ORDER_ID NUMBER not null,
    PRODUCT_ID     NUMBER not null,
    PRODUCT_QTY    NUMBER(32, 2),
    PRODUCT_PRICE  NUMBER(32, 2)
)
/

create table T1
(
    T1_ID NUMBER
)
/

create table T2
(
    T2_ID NUMBER
)
/

create table STUDENT_ACCOUNT
(
    STUD_ID      NUMBER,
    STUD_ACCOUNT VARCHAR2(100)
)
/

create table STUDENT_NEW
(
    STUD_ID   NUMBER,
    STUD_NAME VARCHAR2(100)
)
/


