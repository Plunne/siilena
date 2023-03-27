with Ada.Text_IO;
with Ada.Integer_Text_IO;
with Ada.Strings.Unbounded;


package body libCompany is

	procedure Display_Date (D : Date) is
	begin
        Ada.Text_IO.Put_Line ("Year:" & Natural'Image (D.year));
        Ada.Text_IO.Put_Line ("Month:" & Natural'Image (D.month));
        Ada.Text_IO.Put_Line ("Day:" & Natural'Image (D.day));
    end Display_Date;

    

    procedure PrintEmployee (E : in Employee) is
    begin
        Ada.Text_IO.Put_Line ("Name: " & Ada.Strings.Unbounded.To_String (E.name));
        Ada.Text_IO.Put_Line ("Function: " & EmployeeFunction'Image (E.func));
        Ada.Text_IO.Put_Line ("Salary:" & Float'Image (E.salary));
    end PrintEmployee;

    procedure Set_Salary (E : in out Employee; S : in Float) is
        NEGATIVE_SALARY : exception;
    begin
        if S < Float (0) then
            raise NEGATIVE_SALARY with "Cannot set salary to negative value.";
        else
            E.salary := S;
        end if;
    end Set_Salary;

end libCompany;
