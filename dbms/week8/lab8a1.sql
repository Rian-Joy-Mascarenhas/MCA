SET SERVEROUTPUT ON;

DECLARE
    v_empno  emp.empno%TYPE := &empno;
    v_deptno emp.deptno%TYPE := &deptno;
    v_name   emp.ename%TYPE;
    v_num    NUMBER;
BEGIN 
    BEGIN
        SELECT ename INTO v_name FROM emp WHERE empno = v_empno;
        v_num := TO_NUMBER(v_name);
        DBMS_OUTPUT.PUT_LINE('Converted Number: ' || v_num);
    EXCEPTION 
        WHEN INVALID_NUMBER THEN
            DBMS_OUTPUT.PUT_LINE('INVALID_NUMBER: Employee name cannot be converted to a number.');
        WHEN NO_DATA_FOUND THEN
            NULL; 
    END;

    BEGIN
        SELECT ename INTO v_name FROM emp WHERE empno = v_empno;
        DBMS_OUTPUT.PUT_LINE('Employee (by empno): ' || v_name);
    EXCEPTION 
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.PUT_LINE('NO_DATA_FOUND: Employee does not exist.');
    END;

    BEGIN
        SELECT ename INTO v_name FROM emp WHERE deptno = v_deptno;
        DBMS_OUTPUT.PUT_LINE('Employee (by deptno): ' || v_name);
    EXCEPTION
        WHEN TOO_MANY_ROWS THEN 
            DBMS_OUTPUT.PUT_LINE('TOO_MANY_ROWS: Multiple employees found in this department.');
        WHEN NO_DATA_FOUND THEN 
            DBMS_OUTPUT.PUT_LINE('NO_DATA_FOUND: No employee found in this department.');
    END;
END;
/