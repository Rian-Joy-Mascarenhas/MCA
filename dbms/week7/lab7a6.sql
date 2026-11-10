SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_emp IS 
        SELECT p.prj_no, p.dno, p.prj_name, t.task_id, t.task_name, t.status
        FROM proj p 
        LEFT JOIN task t ON p.prj_no = t.prj_id AND p.dno = t.dno
        ORDER BY p.dno, p.prj_no, t.task_id;
BEGIN
    FOR i IN c_emp LOOP
        DBMS_OUTPUT.PUT_LINE('Project: ' || i.prj_name || ' | Task ID: ' || NVL(TO_CHAR(i.task_id), 'No Task')
 || ' | Task: ' || NVL(i.task_name, 'No Task') || ' | Status: ' || NVL(i.status, 'N/A'));
    END LOOP;
END;
/