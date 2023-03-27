with Ada.Text_IO;
with Ada.Integer_Text_IO;
with Ada.Strings.Unbounded;


package libCompany is

	SMIC : constant := 1_709.28;
	
    type Date is record
        year  : Natural range 1_900 .. 2_100;
        month : Natural range 1 .. 12;
        day   : Natural range 1 .. 31;
    end record;
	
    type EmployeeFunction is (BOSS, SALES, HR, SALARIED);
    type Vehicle is (CAR, BIKE, SCOOTER, BICYCLE, PUBLIC_TRANSPORT);
	
    type Employee (func : EmployeeFunction) is record
	
        name             : Ada.Strings.Unbounded.Unbounded_String;
        birthdate        : Date;
        salary           : Float := SMIC;
        personal_vehicle : Vehicle;
		
        case func is
		
            when BOSS | SALES =>
                pro_vehicle      : Vehicle;
                business_expense : Float;
                cell_plan        : Boolean;
				
            when HR | SALARIED =>
                food_voucher : Natural;
        end case;
		
    end record;
   
   procedure Display_Date (D : Date);
   procedure PrintEmployee (E : in Employee);
   procedure Set_Salary (E : in out Employee; S : in Float);

end libCompany;
