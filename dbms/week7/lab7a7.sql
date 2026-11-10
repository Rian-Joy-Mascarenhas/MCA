SET SERVEROUTPUT ON
DECLARE
v_job emp.job%type:='&v_job';
v_deptno emp.deptno%type:='&v_deptno';
CURSOR c_emp(p_job emp.job%type, p_deptno emp.deptno%type)IS
SELECT empno,ename,job,sal FROM emp
WHERE job=p_job and  deptno=p_deptno;
BEGIN
for i in c_emp(v_job,v_deptno)
LOOP
dbms_output.put_line(i.empno||' '||i.ename||' '||i.job||' '||'Salary:'||i.sal);
END LOOP;
END;
/