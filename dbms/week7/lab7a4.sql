SET SERVEROUTPUT ON
DECLARE
CURSOR c_emp IS SELECT d.dname,e.empno,e.ename,e.job FROM dept d JOIN emp e ON d.dno=e.deptno 
ORDER BY d.dname,e.empno;
BEGIN
FOR i in c_emp
LOOP
dbms_output.put_line(i.dname||'---->'||i.empno||'   '||i.ename||'  '||i.job);
END LOOP;
END;
/