SET SERVEROUTPUT ON;
DECLARE
    v_prjid proj.prj_no%TYPE := '&prj_id';
    CURSOR c_emp(p_prjid proj.prj_no%TYPE) IS 
        SELECT e.ename, e.sal, d.dname 
        FROM emp e 
        JOIN dept d ON e.deptno = d.dno 
        JOIN proj p ON d.dno = p.dno
        WHERE p.prj_no = p_prjid
        ORDER BY e.sal DESC
        FETCH FIRST 2 ROWS ONLY;  
BEGIN
    DBMS_OUTPUT.PUT_LINE('--- Top 2 Highest-Paid Employees for Project: ' || v_prjid || ' ---');
    FOR i IN c_emp(v_prjid) LOOP
        dbms_output.put_line(i.ename || ' | Salary: ' || i.sal || ' | Department: ' || i.dname);
    END LOOP;
END;
/