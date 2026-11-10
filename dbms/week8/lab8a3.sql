SET SERVEROUTPUT ON;
DECLARE
 e EMP.EMPNO%TYPE:=&empno; n EMP.ENAME%TYPE; s EMP.SAL%TYPE;
 ex_not_found EXCEPTION; ex_high_salary EXCEPTION;
BEGIN
 BEGIN
  SELECT ENAME,SAL INTO n,s FROM EMP WHERE EMPNO=e;
 EXCEPTION WHEN NO_DATA_FOUND THEN RAISE ex_not_found;
 END;
 DBMS_OUTPUT.PUT_LINE('Empno: '||e||' Name: '||n||' Salary: '||s);
 IF s>25000 THEN
  RAISE ex_high_salary;
 ELSIF s<25000 THEN
  UPDATE EMP SET SAL=25000 WHERE EMPNO=e;
  COMMIT;
  DBMS_OUTPUT.PUT_LINE('Salary updated to 25000/-');
 ELSE
  DBMS_OUTPUT.PUT_LINE('Salary is already 25000/-');
 END IF;
EXCEPTION
 WHEN ex_not_found THEN DBMS_OUTPUT.PUT_LINE('Employee does not exist.');
 WHEN ex_high_salary THEN DBMS_OUTPUT.PUT_LINE('Salary is greater than 25000/-.');
END;
/