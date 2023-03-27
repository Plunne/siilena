with Ada.Text_IO;
with Ada.Integer_Text_IO;
with Ada.Strings.Unbounded;
with libCompany; use libCompany;


procedure Main is

date_1     : Date := (year => 1_986, month => 5, day => 9);
employee_1 : Employee (HR);

begin
    employee_1.name := Ada.Strings.Unbounded.To_Unbounded_String ("John");
    PrintEmployee (employee_1);
    Set_Salary (employee_1, 2_458.9);
    PrintEmployee (employee_1);
    Set_Salary (employee_1, -2_458.9);
end Main;
