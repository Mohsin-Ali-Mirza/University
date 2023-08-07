SET SERVEROUTPUT ON
--Q1
DECLARE 
    NUM INTEGER;
    SAL INTEGER;
BEGIN
    NUM:=&NUM;
    SELECT SALARY INTO SAL FROM EMPLOYEES WHERE EMPLOYEE_ID = NUM;
    IF(SAL<1000) THEN
        SAL := SAL+(SAL*0.1);
    ELSIF(SAL>= 1000 AND SAL<=1500) THEN
        SAL := SAL+(SAL*0.15);
    ELSIF(SAL> 1500) THEN
        SAL := SAL+(SAL*0.20);
    ELSE
        SAL := 0;
    END IF;    
    DBMS_OUTPUT.PUT_LINE('INCREMENTED SALARY IS: '||SAL);    
END;

--Q2
DECLARE
    EMPID INTEGER;
    COMM EMPLOYEES.COMMISSION_PCT%TYPE;
    SAL EMPLOYEES.SALARY%TYPE;
    SAL1 EMPLOYEES.SALARY%TYPE;
BEGIN
    EMPID:='&EMPID';
    SELECT SALARY,COMMISSION_PCT INTO SAL,COMM FROM EMPLOYEES WHERE EMPLOYEE_ID=EMPID AND COMMISSION_PCT IS NULL;
    COMM:=0.2;
    SAL1:=SAL+(SAL*COMM);
    UPDATE EMPLOYEES SET EMPLOYEES.SALARY = SAL1 WHERE EMPLOYEE_ID=EMPID; 
    
END;    

--Q3
DECLARE
    BEGIN
    FOR CO IN (SELECT E.EMPLOYEE_ID,D.DEPARTMENT_NAME FROM EMPLOYEES E, DEPARTMENTS D WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID AND D.DEPARTMENT_ID=30)
    LOOP
    DBMS_OUTPUT.PUT_LINE ('DEPARTMENT NAME ' || CO.DEPARTMENT_NAME || ' FOR THE EMPLOYEE ID: ' || CO.EMPLOYEE_ID);
    END LOOP;    
END;

--Q4
DECLARE
EMPID INTEGER;
BONUS INTEGER;
SAL EMPLOYEES.SALARY%TYPE;

    BEGIN
    SELECT SALARY INTO SAL FROM EMPLOYEES WHERE EMPLOYEE_ID=&EMPID;
    IF(SAL < 1000) THEN
    BONUS:=SAL*0.1;
    ELSIF (SAL > 1000 AND SAL <=1500) THEN
    BONUS:=SAL*0.15;
    ELSIF (SAL > 1500) THEN
    BONUS:=SAL*0.20;
    END IF;
    DBMS_OUTPUT.PUT_LINE ('BONUS: ' || BONUS);
    END;
    
--Q5
CREATE OR REPLACE PROCEDURE GETSALARY (NUM IN INTEGER) AS

BEGIN

    SELECT SALARY FROM EMPLOYEES WHERE EMPLOYEE_ID = EID)
      
END;
    SELECT GETSALARY(20) FROM EMPLOYEES;
    
--Q6
SET SERVEROUTPUT ON
CREATE OR REPLACE PROCEDURE INCSAL (EID IN INTEGER)
AS
    
BEGIN
    UPDATE EMPLOYEES SET SALARY = SALARY+(SALARY*10) WHERE EMPLOYEE_ID=EID;  
END;
    EXEC INCSAL(110);

--Q7
SET SERVEROUTPUT ON
CREATE OR REPLACE PROCEDURE ADDSAL (DNUM IN INTEGER)
AS
    
BEGIN
    UPDATE EMPLOYEES SET SALARY = SALARY+1000 WHERE SALARY>5000 AND DEPARTMENT_ID=DNUM;    
END;
EXEC ADDSAL(20);


--Q9
DECLARE 
    N1 INTEGER;
    N2 INTEGER;
    TSUM INTEGER;
BEGIN
    N1 := &N1;
    N2 := &N2;
    TSUM := N1+N2;
    DBMS_OUTPUT.PUT_LINE('THE SUM IS: '|| TSUM);
END;

--Q10
DECLARE 
    N1 INTEGER;
    N2 INTEGER;
    TSUM INTEGER;
BEGIN
    TSUM := 0;
    N1 := &N1;
    N2 := &N2;
    FOR A IN N1..N2 LOOP
    TSUM := TSUM+A;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('THE SUM IS: '|| TSUM);
END;

--Q11
DECLARE 
    EID INTEGER;
    FNAME VARCHAR(30);
    DNAME VARCHAR(30);
    HDATE DATE;
BEGIN
    EID := &EID;
    SELECT FIRST_NAME INTO FNAME FROM EMPLOYEES 
    WHERE EMPLOYEE_ID = EID;
    SELECT DEPARTMENT_NAME INTO DNAME FROM DEPARTMENTS 
    WHERE DEPARTMENT_ID = (SELECT DEPARTMENT_ID FROM EMPLOYEES 
    WHERE EMPLOYEE_ID = EID); 
    SELECT HIRE_DATE INTO HDATE FROM EMPLOYEES WHERE EMPLOYEE_ID = EID;
    DBMS_OUTPUT.PUT_LINE('THE EMPLOYEE NAME IS '|| FNAME);
    DBMS_OUTPUT.PUT_LINE('THE EMPLOYEE DEPARTMENT NAME IS '|| FNAME);
    DBMS_OUTPUT.PUT_LINE('THE EMPLOYEE HIRE DATE IS '|| HDATE);
END;

--Q12
DECLARE 
TEMP INTEGER;
NUMB INTEGER;
REV INTEGER;
BEGIN 
    REV := 0;
    NUMB := &NUMB;
    TEMP := NUMB;
    WHILE TEMP>0 
    LOOP
        REV := REV*10;
        REV := REV + MOD(TEMP,10);
        TEMP := TEMP/10;
        
    END LOOP;
    IF(REV = NUMB) THEN
        DBMS_OUTPUT.PUT_LINE('NUMBER IS PALDINDROME');
    ELSE
        DBMS_OUTPUT.PUT_LINE('NUMBER IS NOT PALDINDROME');
    END IF;    
END;

--Q13
DECLARE 
EMPLOYEE_ID INTEGER;
FIRST_NAME VARCHAR(20);
LAST_NAME   VARCHAR(20);
EMAIL   VARCHAR(20);
PHONE_NUMBER    VARCHAR(20);
HIRE_DATE   DATE;
JOB_ID  VARCHAR(20);
SALARY  INTEGER;
COMMISSION_PCT FLOAT;
MANAGER_ID  INTEGER;
DEPARTMENT_ID   INTEGER;
BEGIN 
    EMPLOYEE_ID := &EMPLOYEE_ID;
    FIRST_NAME := &FIRST_NAME;
    LAST_NAME := &LAST_NAME;
    EMAIL := &EMAIL;
    PHONE_NUMBER := &PHONE_NUMBER;
    HIRE_DATE := &HIRE_DATE;
    JOB_ID := &JOB_ID;
    SALARY := &SALARY;
    COMMISSION_PCT := &COMMISSION_PCT;
    MANAGER_ID := &MANAGER_ID;
    DEPARTMENT_ID := &DEPARTMENT_ID;
END;

--Q15
DECLARE 
    TSUM INTEGER;
BEGIN
    TSUM := 0;
    FOR A IN 1..100 LOOP
    TSUM := TSUM+A;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('THE SUM IS: '|| TSUM);
END;