-- create table empsal(
-- empno number(10),
-- empname varchar2(20),
-- sal number(10,2),
-- hra number(10,2),
-- da number(10,2),
-- gross number(10,2),
-- pf number(10,2),
-- netsal number(10,2));

set serveroutput on
DECLARE
    v_empno EMP.EMPNO%TYPE := &v_empno;
    v_hra EMPSAL.HRA%TYPE;
    v_da EMPSAL.DA%TYPE;
    v_pf EMPSAL.PF%TYPE;
    v_gross EMPSAL.GROSS%TYPE;
    v_netsal EMPSAL.NETSAL%TYPE;
    CURSOR c_emp IS SELECT empno, ename, sal FROM emp WHERE empno = v_empno;
BEGIN
    FOR i IN c_emp LOOP
        v_hra := i.sal * 0.50;
        v_da := i.sal * 0.20;
        v_pf := i.sal * 0.12;
        v_gross := i.sal + v_hra + v_da;
        v_netsal := v_gross - v_pf;
        INSERT INTO empsal (empno, empname, sal, hra, da, gross, pf, netsal) 
        VALUES (i.empno, i.ename, i.sal, v_hra, v_da, v_gross, v_pf, v_netsal);
        DBMS_OUTPUT.PUT_LINE('Salary details inserted for ' || i.ename);
    END LOOP;
END;
/