SET SERVEROUTPUT ON;
DECLARE
 p NUMBER:=&principal; r NUMBER:=&interest_rate; y NUMBER:=&years;
 interest_amt NUMBER;
BEGIN
 IF p<=1000 THEN
  DBMS_OUTPUT.PUT_LINE('Error: Principal must be greater than 1000.');
 ELSIF r<5 THEN
  DBMS_OUTPUT.PUT_LINE('Error: Interest rate must be at least 5%.');
 ELSIF y<1 THEN
  DBMS_OUTPUT.PUT_LINE('Error: Duration must be at least 1 year.');
 ELSE
  interest_amt:=p*r*y/100;
  DBMS_OUTPUT.PUT_LINE('Interest to be paid: '||interest_amt);
 END IF;
END;
/