SET SERVEROUTPUT ON;

DECLARE
    CURSOR c_proj IS
        SELECT dno, prj_no, prj_credit, prj_fund FROM proj;
        
    v_fund        NUMBER(12,2);
    v_emp_share   NUMBER(12,2);
    v_dept_share  NUMBER(12,2);
    v_count       NUMBER;
BEGIN
    FOR p IN c_proj LOOP
        v_fund := p.prj_fund * (p.prj_credit * 0.10);

        SELECT COUNT(*) INTO v_count
        FROM emp
        WHERE deptno = p.dno;

        v_emp_share := v_fund * 0.70;
        IF v_count > 0 THEN
            v_emp_share := v_emp_share / v_count;
            
            UPDATE emp
            SET comm = NVL(comm, 0) + v_emp_share
            WHERE deptno = p.dno;
        END IF;
      
        v_dept_share := v_fund * 0.30;
        
        UPDATE dept
        SET dept_budget = NVL(dept_budget, 0) + v_dept_share
        WHERE dno = p.dno;
        
    END LOOP;
    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Incentives and department budgets successfully allocated!');
END;
/