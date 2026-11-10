CREATE OR REPLACE TRIGGER TRG_PRJ_FUND_ELIGIBILITY
AFTER UPDATE OF PRJ_FUND ON PROJ
FOR EACH ROW
DECLARE
 duration_days NUMBER; elapsed_days NUMBER;
 additional_fund NUMBER; eligible NUMBER;
BEGIN
 duration_days:=:OLD.END_DATE-:OLD.STRT_DATE;
 elapsed_days:=SYSDATE-:OLD.STRT_DATE;
 additional_fund:=NVL(:NEW.PRJ_FUND,0)-NVL(:OLD.PRJ_FUND,0);
 IF duration_days<=0 THEN
  DBMS_OUTPUT.PUT_LINE('Invalid project duration.');
 ELSIF additional_fund>0 THEN
  IF elapsed_days/duration_days<0.5 THEN
   eligible:=additional_fund*0.70;
  ELSE
   eligible:=additional_fund*0.40;
  END IF;
  DBMS_OUTPUT.PUT_LINE('You are eligible for Rs. '||
                       TO_CHAR(eligible,'9999990.00'));
 END IF;
END;
/