-- 1. Data definition language (DDL)
Create table PERSON(
    PERSON_ID INTEGER,
    PERSON_NAME VARCHAR2(200),
    BIRTH_DATE DATE
);

alter table PERSON add primary key PERSON_PK(PERSON_ID);

alter table PERSON MODIFY column PERSON_NAME VARCHAR2(300); -- если не влезает в 200, уменьшить можно только в случае отсутствия данных в таблице

-- INTEGER
-- NUMBER (38, 2) - фиксированнаая точка
-- FLOAT - плавающая точка
-- CHAR(10) - если меньше - добивается пробелами до 10 символов (фиксированная ширина) - 'RU', 'US'
-- VARCHAR2(200 CHAR) - указывается макс длина в ORACLE max - 4000
-- CLOB - Character large object почти неогранниченные размер текста
-- BLOB - Byte large object
-- DATE 
-- TIMESTAMP


-- 2. Data manipulation language

-- 1. INSERT
INSERT INTO PERSON(
    PERSON_ID,
    PERSON_NAME,
    BIRTH_DATE) values (2, 'John Smith', TO_DATE('19.01.1995', 'DD.MM.YYYY'));

-- Можно и так, но это небезопасно
INSERT INTO PERSON values (2, 'John Smith', SYSDATE);

-- 2. DELETE

DELETE FROM PERSON; -- удаление всех строчек из таблицы
DELETE FROM PERSON where PERSON_ID = 2;
TRUNCATE TABLE PERSON; -- очищает для перезаписи

-- 3. UPDATE
UPDATE PERSON set PERSON_NAME = 'Steve Brown',
                  BIRTH_DATE = TO_DATE('20.02.1995', 'DD.MM.1995')
where PERSON_ID = 3;

commit;
rollback;

-- 4. SELECT
select * from PERSON;

SELECT PERSON_NAME, PERSON_ID from PERSON
WHERE PERSON_ID > 1 AND PERSON_NAME = 'Steve Brown' AND PERSON_NAME like '%Brown';

SELECT PERSON_NAME, PERSON_ID from PERSON_ID
ORDER BY PERSON_NAME, PERSON_ID DESC;

select count(distinct PERSON_NAME) from PERSON;

select avg(PRODUcT_QTY) from sales_order_line;
select sum(PRODUcT_QTY) from sales_order_line;
select PRODUCT_ID, avg(PRODUCT_QTY),sum(PRODUcT_QTY) from sales_order_line
GROUP BY PRODUCT_ID

select PRODUCT_ID, avg(PRODUCT_QTY),sum(PRODUcT_QTY) from sales_order_line

WHERE PRODUcT_QTY > 5
GROUP BY PRODUCT_ID
having avg(PRODUCT_QTY) > 25 -- после группировки 
order by PRODUCT_ID