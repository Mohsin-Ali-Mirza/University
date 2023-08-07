--Task 1
SELECT FIRST_NAME,DEPARTMENT_NAME,SALARY,JOB_TITLE
FROM EMPLOYEES E, DEPARTMENTS D, JOBS J 
WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID AND E.JOB_ID=J.JOB_ID 
ORDER BY DEPARTMENT_NAME ASC;

--Task 2
SELECT COUNT(*),DEPARTMENT_NAME 
FROM EMPLOYEES E JOIN DEPARTMENTS D
ON E.DEPARTMENT_ID=D.DEPARTMENT_ID
GROUP BY DEPARTMENT_NAME
HAVING COUNT(*)>=2;

--Task 3
SELECT * 
FROM EMPLOYEES E JOIN JOBS J 
ON E.JOB_ID=J.JOB_ID
WHERE SALARY<MIN_SALARY;

--Task 4
SELECT E.FIRST_NAME,J.JOB_TITLE,E.SALARY,D.DEPARTMENT_ID,D.DEPARTMENT_NAME,L.CITY 
FROM EMPLOYEES E,JOBS J,DEPARTMENTS D,LOCATIONS L
WHERE E.JOB_ID=J.JOB_ID AND E.DEPARTMENT_ID=D.DEPARTMENT_ID AND D.LOCATION_ID=L.LOCATION_ID AND E.SALARY*12=60000 OR J.JOB_TITLE <> 'ANALYST';

--Task 5
SELECT * 
FROM EMPLOYEES A JOIN EMPLOYEES B
ON A.MANAGER_ID=B.EMPLOYEE_ID;

--Task 6 
SELECT D.DEPARTMENT_ID, D.DEPARTMENT_NAME,E.FIRST_NAME
FROM EMPLOYEES E FULL OUTER JOIN DEPARTMENTS D
ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
WHERE E.DEPARTMENT_ID IS NULL;


--Task 7
SELECT E.FIRST_NAME, E.SALARY,D.DEPARTMENT_NAME, D.DEPARTMENT_ID
FROM EMPLOYEES E LEFT JOIN DEPARTMENTS D
ON E.DEPARTMENT_ID = D.DEPARTMENT_ID;

--Task 9
SELECT E.FIRST_NAME
FROM EMPLOYEES E LEFT JOIN DEPARTMENTS D
ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
WHERE D.DEPARTMENT_ID IS NULL;

--TASK 8
SELECT E.FIRST_NAME, D.DEPARTMENT_NAME, L.STREET_ADDRESS, L.CITY
FROM  EMPLOYEES E, DEPARTMENTS D, LOCATIONS L
WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID AND D.LOCATION_ID = L.LOCATION_ID AND L.STATE_PROVINCE IS NULL;

--TASK 10
SELECT E.FIRST_NAME, L.COUNTRY_ID, L.STATE_PROVINCE
FROM EMPLOYEES E, DEPARTMENTS D, LOCATIONS L
WHERE D.LOCATION_ID = L.LOCATION_ID AND E.DEPARTMENT_ID = D.DEPARTMENT_ID
AND L.COUNTRY_ID = 'US' AND L.STATE_PROVINCE <> 'Washington';



