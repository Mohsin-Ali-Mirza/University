-- Generated by Oracle SQL Developer Data Modeler 4.1.1.888
--   at:        2022-10-07 15:11:16 PKT
--   site:      Oracle Database 11g
--   type:      Oracle Database 11g




CREATE
  TABLE Customers
  (
    Customer_ID           NUMBER NOT NULL ,
    Name                  VARCHAR2 (25) ,
    Product_Name          VARCHAR2 (25) ,
    Quantity              INTEGER ,
    Address               VARCHAR2 (25) ,
    Employees_Employee_ID NUMBER NOT NULL
  ) ;

CREATE TABLE Customers_JN
 (JN_OPERATION CHAR(3) NOT NULL
 ,JN_ORACLE_USER VARCHAR2(30) NOT NULL
 ,JN_DATETIME DATE NOT NULL
 ,JN_NOTES VARCHAR2(240)
 ,JN_APPLN VARCHAR2(35)
 ,JN_SESSION NUMBER(38)
 ,Customer_ID NUMBER NOT NULL
 ,Name VARCHAR2 (25)
 ,Product_Name VARCHAR2 (25)
 ,Quantity INTEGER
 ,Address VARCHAR2 (25)
 ,Employees_Employee_ID NUMBER NOT NULL
 );

CREATE OR REPLACE TRIGGER Customers_JNtrg
  AFTER 
  INSERT OR 
  UPDATE OR 
  DELETE ON emp2 for each row 
 Declare 
  rec Customers_JN%ROWTYPE; 
  blank Customers_JN%ROWTYPE; 
  BEGIN 
    rec := blank; 
    IF INSERTING OR UPDATING THEN 
      rec.Customer_ID := :NEW.Customer_ID; 
      rec.Name := :NEW.Name; 
      rec.Product_Name := :NEW.Product_Name; 
      rec.Quantity := :NEW.Quantity; 
      rec.Address := :NEW.Address; 
      rec.Employees_Employee_ID := :NEW.Employees_Employee_ID; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      IF INSERTING THEN 
        rec.JN_OPERATION := 'INS'; 
      ELSIF UPDATING THEN 
        rec.JN_OPERATION := 'UPD'; 
      END IF; 
    ELSIF DELETING THEN 
      rec.Customer_ID := :OLD.Customer_ID; 
      rec.Name := :OLD.Name; 
      rec.Product_Name := :OLD.Product_Name; 
      rec.Quantity := :OLD.Quantity; 
      rec.Address := :OLD.Address; 
      rec.Employees_Employee_ID := :OLD.Employees_Employee_ID; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      rec.JN_OPERATION := 'DEL'; 
    END IF; 
    INSERT into Customers_JN VALUES rec; 
  END; 
  /
CREATE
  TABLE Employees
  (
    Employee_ID NUMBER NOT NULL ,
    First_Name  VARCHAR2 (25) ,
    Last_Name   VARCHAR2 (25) ,
    Address     VARCHAR2 (25)
  ) ;

CREATE TABLE Employees_JN
 (JN_OPERATION CHAR(3) NOT NULL
 ,JN_ORACLE_USER VARCHAR2(30) NOT NULL
 ,JN_DATETIME DATE NOT NULL
 ,JN_NOTES VARCHAR2(240)
 ,JN_APPLN VARCHAR2(35)
 ,JN_SESSION NUMBER(38)
 ,Employee_ID NUMBER NOT NULL
 ,First_Name VARCHAR2 (25)
 ,Last_Name VARCHAR2 (25)
 ,Address VARCHAR2 (25)
 );

CREATE OR REPLACE TRIGGER Employees_JNtrg
  AFTER 
  INSERT OR 
  UPDATE OR 
  DELETE ON emp2 for each row 
 Declare 
  rec Employees_JN%ROWTYPE; 
  blank Employees_JN%ROWTYPE; 
  BEGIN 
    rec := blank; 
    IF INSERTING OR UPDATING THEN 
      rec.Employee_ID := :NEW.Employee_ID; 
      rec.First_Name := :NEW.First_Name; 
      rec.Last_Name := :NEW.Last_Name; 
      rec.Address := :NEW.Address; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      IF INSERTING THEN 
        rec.JN_OPERATION := 'INS'; 
      ELSIF UPDATING THEN 
        rec.JN_OPERATION := 'UPD'; 
      END IF; 
    ELSIF DELETING THEN 
      rec.Employee_ID := :OLD.Employee_ID; 
      rec.First_Name := :OLD.First_Name; 
      rec.Last_Name := :OLD.Last_Name; 
      rec.Address := :OLD.Address; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      rec.JN_OPERATION := 'DEL'; 
    END IF; 
    INSERT into Employees_JN VALUES rec; 
  END; 
  /
CREATE
  TABLE Orders
  (
    Order_No              NUMBER NOT NULL ,
    Quantity              INTEGER ,
    Shipped_Date          DATE ,
    Recieved_Date         DATE ,
    Customers_Customer_ID NUMBER NOT NULL
  ) ;

CREATE TABLE Orders_JN
 (JN_OPERATION CHAR(3) NOT NULL
 ,JN_ORACLE_USER VARCHAR2(30) NOT NULL
 ,JN_DATETIME DATE NOT NULL
 ,JN_NOTES VARCHAR2(240)
 ,JN_APPLN VARCHAR2(35)
 ,JN_SESSION NUMBER(38)
 ,Order_No NUMBER NOT NULL
 ,Quantity INTEGER
 ,Shipped_Date DATE
 ,Recieved_Date DATE
 ,Customers_Customer_ID NUMBER NOT NULL
 );

CREATE OR REPLACE TRIGGER Orders_JNtrg
  AFTER 
  INSERT OR 
  UPDATE OR 
  DELETE ON emp2 for each row 
 Declare 
  rec Orders_JN%ROWTYPE; 
  blank Orders_JN%ROWTYPE; 
  BEGIN 
    rec := blank; 
    IF INSERTING OR UPDATING THEN 
      rec.Order_No := :NEW.Order_No; 
      rec.Quantity := :NEW.Quantity; 
      rec.Shipped_Date := :NEW.Shipped_Date; 
      rec.Recieved_Date := :NEW.Recieved_Date; 
      rec.Customers_Customer_ID := :NEW.Customers_Customer_ID; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      IF INSERTING THEN 
        rec.JN_OPERATION := 'INS'; 
      ELSIF UPDATING THEN 
        rec.JN_OPERATION := 'UPD'; 
      END IF; 
    ELSIF DELETING THEN 
      rec.Order_No := :OLD.Order_No; 
      rec.Quantity := :OLD.Quantity; 
      rec.Shipped_Date := :OLD.Shipped_Date; 
      rec.Recieved_Date := :OLD.Recieved_Date; 
      rec.Customers_Customer_ID := :OLD.Customers_Customer_ID; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      rec.JN_OPERATION := 'DEL'; 
    END IF; 
    INSERT into Orders_JN VALUES rec; 
  END; 
  /
CREATE
  TABLE Products
  (
    Product_ID            NUMBER NOT NULL ,
    Name                  VARCHAR2 (25) ,
    Price                 NUMBER ,
    Stock                 INTEGER ,
    Employees_Employee_ID NUMBER NOT NULL
  ) ;

CREATE TABLE Products_JN
 (JN_OPERATION CHAR(3) NOT NULL
 ,JN_ORACLE_USER VARCHAR2(30) NOT NULL
 ,JN_DATETIME DATE NOT NULL
 ,JN_NOTES VARCHAR2(240)
 ,JN_APPLN VARCHAR2(35)
 ,JN_SESSION NUMBER(38)
 ,Product_ID NUMBER NOT NULL
 ,Name VARCHAR2 (25)
 ,Price NUMBER
 ,Stock INTEGER
 ,Employees_Employee_ID NUMBER NOT NULL
 );

CREATE OR REPLACE TRIGGER Products_JNtrg
  AFTER 
  INSERT OR 
  UPDATE OR 
  DELETE ON emp2 for each row 
 Declare 
  rec Products_JN%ROWTYPE; 
  blank Products_JN%ROWTYPE; 
  BEGIN 
    rec := blank; 
    IF INSERTING OR UPDATING THEN 
      rec.Product_ID := :NEW.Product_ID; 
      rec.Name := :NEW.Name; 
      rec.Price := :NEW.Price; 
      rec.Stock := :NEW.Stock; 
      rec.Employees_Employee_ID := :NEW.Employees_Employee_ID; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      IF INSERTING THEN 
        rec.JN_OPERATION := 'INS'; 
      ELSIF UPDATING THEN 
        rec.JN_OPERATION := 'UPD'; 
      END IF; 
    ELSIF DELETING THEN 
      rec.Product_ID := :OLD.Product_ID; 
      rec.Name := :OLD.Name; 
      rec.Price := :OLD.Price; 
      rec.Stock := :OLD.Stock; 
      rec.Employees_Employee_ID := :OLD.Employees_Employee_ID; 
      rec.JN_DATETIME := SYSDATE; 
      rec.JN_ORACLE_USER := SYS_CONTEXT ('USERENV', 'SESSION_USER'); 
      rec.JN_APPLN := SYS_CONTEXT ('USERENV', 'MODULE'); 
      rec.JN_SESSION := SYS_CONTEXT ('USERENV', 'SESSIONID'); 
      rec.JN_OPERATION := 'DEL'; 
    END IF; 
    INSERT into Products_JN VALUES rec; 
  END; 
  /
ALTER TABLE Customers ADD CONSTRAINT Customers_Employees_FK FOREIGN KEY (
Employees_Employee_ID ) REFERENCES Employees ( Employee_ID ) ;

ALTER TABLE Orders ADD CONSTRAINT Orders_Customers_FK FOREIGN KEY (
Customers_Customer_ID ) REFERENCES Customers ( Customer_ID ) ;

ALTER TABLE Products ADD CONSTRAINT Products_Employees_FK FOREIGN KEY (
Employees_Employee_ID ) REFERENCES Employees ( Employee_ID ) ;

insert into Employees values(1,'Mohsin','Mirza','Gulshan');
insert into Employees values(2,'Ahmad','Aleem','Gulshan');
insert into Employee values(3,'Jahanzeb','Asim','Clifton');

insert into Customers values(1,'Minhal','Bag',2,'Defense',1);
insert into Customers values(2,'Wahaj','Pen',2,'Johar',1);
insert into Customers values(3,'Ali','Eraser',2,'Clifton',1);

insert into Orders values(1,20,'3-Oct-2022','5-Oct-2022',1);
insert into Orders values(2,20,'3-Oct-2022','5-Oct-2022',2);
insert into Orders values(3,20,'3-Oct-2022','5-Oct-2022',3);

insert into Products values(4,'Bag',220,3,1);
insert into Products values(5,'Pen',221,3,2);
insert into Products values(6,'Eraser',222,3,3);



-- Oracle SQL Developer Data Modeler Summary Report: 
-- 
-- CREATE TABLE                             4
-- CREATE INDEX                             0
-- ALTER TABLE                              3
-- CREATE VIEW                              0
-- ALTER VIEW                               0
-- CREATE PACKAGE                           0
-- CREATE PACKAGE BODY                      0
-- CREATE PROCEDURE                         0
-- CREATE FUNCTION                          0
-- CREATE TRIGGER                           0
-- ALTER TRIGGER                            0
-- CREATE COLLECTION TYPE                   0
-- CREATE STRUCTURED TYPE                   0
-- CREATE STRUCTURED TYPE BODY              0
-- CREATE CLUSTER                           0
-- CREATE CONTEXT                           0
-- CREATE DATABASE                          0
-- CREATE DIMENSION                         0
-- CREATE DIRECTORY                         0
-- CREATE DISK GROUP                        0
-- CREATE ROLE                              0
-- CREATE ROLLBACK SEGMENT                  0
-- CREATE SEQUENCE                          0
-- CREATE MATERIALIZED VIEW                 0
-- CREATE SYNONYM                           0
-- CREATE TABLESPACE                        0
-- CREATE USER                              0
-- 
-- DROP TABLESPACE                          0
-- DROP DATABASE                            0
-- 
-- REDACTION POLICY                         0
-- 
-- ORDS DROP SCHEMA                         0
-- ORDS ENABLE SCHEMA                       0
-- ORDS ENABLE OBJECT                       0
-- 
-- ERRORS                                   0
-- WARNINGS                                 0
