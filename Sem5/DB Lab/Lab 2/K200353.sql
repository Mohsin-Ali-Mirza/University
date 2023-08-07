--Set 1
--Task 1
SELECT SALARY AS "ANNUAL_SALARY" FROM EMPLOYEES WHERE SALARY > 20000 AND SALARY < 30000;
--Task 2
SELECT EMPLOYEE_ID,FIRST_NAME FROM EMPLOYEES WHERE DEPARTMENT_ID BETWEEN 60 AND 100;
--Task 3
SELECT * FROM EMPLOYEES WHERE FIRST_NAME LIKE '%ll%';
--Task 4
SELECT * FROM EMPLOYEES,LOCATIONS WHERE CITY = 'Toronto' OR CITY = 'Hiroshima' OR CITY = 'Sydney' ;
--Task 5
SELECT * FROM EMPLOYEES WHERE COMMISSION_PCT IS null;

--Set 2
--Task 1
SELECT INITCAP(FIRST_NAME),LOWER(JOB_TITLE) FROM EMPLOYEES,JOBS;
--Task 2
SELECT FIRST_NAME || JOB_TITLE AS "Name + Title", LENGTH(FIRST_NAME), INSTR(FIRST_NAME,'A') FROM EMPLOYEES,JOBS WHERE JOB_TITLE LIKE '%Sales%';
--Task 3
SELECT EMPLOYEE_ID,TO_DATE(HIRE_DATE),EXTRACT(MONTH FROM HIRE_DATE) AS "HIRE MONTH" FROM EMPLOYEES WHERE EXTRACT(YEAR FROM HIRE_DATE) = 2003;
--Task 4
SELECT EMPLOYEE_ID,EXTRACT(MONTH FROM HIRE_DATE) AS "HIRE MONTH" , EXTRACT(YEAR FROM HIRE_DATE) AS "HIRE YEAR" FROM EMPLOYEES;
--Task 5
SELECT FIRST_NAME, TO_CHAR(HIRE_DATE, 'DD MONTH,YYYY') FROM EMPLOYEES;
--Task 6
SELECT TO_CHAR(SALARY,'$99999') FROM EMPLOYEES WHERE FIRST_NAME = 'Neena';
--Task 7
SELECT NEXT_DAY(SYSDATE,'MONDAY') FROM DUAL;
--Task 8
SELECT * FROM EMPLOYEES WHERE LAST_NAME LIKE '%A%';
--Task 9
SELECT FIRST_NAME,SUBSTR(FIRST_NAME,LENGTH(FIRST_NAME)-2,3) FROM EMPLOYEES;
--Task 10
SELECT EMPLOYEE_ID,HIRE_DATE, FLOOR(MONTHS_BETWEEN(SYSDATE,HIRE_DATE)) AS "MONTHS EMPLOYEED", NEXT_DAY(HIRE_DATE,'Friday'), TO_CHAR(LAST_DAY(HIRE_DATE),'Day') FROM EMPLOYEES, DUAL WHERE FLOOR(MONTHS_BETWEEN(SYSDATE,HIRE_DATE)) > 100;

--Set 3
--Task 1
SELECT EMPLOYEE_ID, FIRST_NAME, SALARY AS BEFORE_INCREMENT, SALARY*1.15 AS AFTER_INCREMENT, SALARY*0.15 AS INCREMENTED_AMOUNT FROM EMPLOYEES;
--Task 2
SELECT FIRST_NAME, HIRE_DATE, TO_CHAR(HIRE_DATE,'DAY') AS DAY_STARTED FROM EMPLOYEES ORDER BY (NEXT_DAY(HIRE_DATE, 'MONDAY') - HIRE_DATE) desc;
--Task 3
SELECT DEPARTMENT_ID, EMPLOYEE_ID, ROUND(COMMISSION_PCT,1) FROM EMPLOYEES;
--Task 4
SELECT * FROM EMPLOYEES WHERE COMMISSION_PCT > 0 AND NOT(DEPARTMENT_ID=90 OR DEPARTMENT_ID=100);
--Task 5
SELECT * FROM EMPLOYEES WHERE EXTRACT(YEAR FROM HIRE_DATE)=2010;
--Task 6
SELECT * FROM JOBS,EMPLOYEES WHERE MIN_SALARY > 8000 AND MIN_SALARY<15000 AND COMMISSION_PCT=0;
--Task 7
SELECT FIRST_NAME,LAST_NAME,JOB_ID FROM EMPLOYEES WHERE EMPLOYEE_ID > 100 AND EMPLOYEE_ID < 150 AND DEPARTMENT_ID > 90 AND DEPARTMENT_ID < 100;
--Task 8
SELECT SALARY+COMMISSION_PCT*SALARY AS TOTAL_SALARY,COMMISSION_PCT FROM EMPLOYEES WHERE COMMISSION_PCT IS NOT NULL;