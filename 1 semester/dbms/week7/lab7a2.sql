SET SERVEROUTPUT ON;
DECLARE
    v_empno EMP.EMPNO%TYPE := &v_empno;
    CURSOR c_emp IS  SELECT e.ename, d.dname, e.sal 
    FROM emp e JOIN dept d ON e.deptno = d.dno 
    WHERE e.empno = v_empno;       
BEGIN
    FOR i IN c_emp LOOP
        DBMS_OUTPUT.PUT_LINE(i.ename || ' works in ' || i.dname || ' department and draws ' || i.sal || ' as salary');
    END LOOP;
END;
/