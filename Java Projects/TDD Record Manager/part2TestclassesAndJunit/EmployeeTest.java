package part2TestclassesAndJunit;

/**author: Samantha Ling(ID:160720604)
 * Aim: to test the output of the RecordManager and Employee class in part 2 of assignment 1 by using the PrintReportClass
 * Date: 26/11/17
 **/

//Java Date class is imported to create StartDate's for Employees
import java.util.Date;

//RecordManager class and Employee class is imported from package recordManagerClasses
import recordManagerClasses.Employee;
import recordManagerClasses.RecordManager;

public class EmployeeTest {

	public static void main(String[] args) 
	{
		//a new EmployeeTest is created called employeeTest
		EmployeeTest employeeTest= new EmployeeTest();
		//a new RecordManager is created
		RecordManager manager = new RecordManager();
		//the EmployeeTest calls the addValues method to set fields for the RecordManager called manager
		employeeTest.addValues(manager);   
	}
	public void addValues(RecordManager recordManager)
	{
		    //office name is set for the recordManager
            recordManager.setOfficeName("Office 1");
            
            //a new Employee is created called one and the fields of that Employee is set
		    Employee one = new Employee(); 
		    one.setID(5); //this method won't work as set method is declared as final
		    one.setEmployeeName("Polly"); 
		    one.setAddress("61 The Upper Drive"); 
		    one.setDepartment("MANUFACTURING"); 
		    one.setEmployeeName("Ellie");
		    one.setPhoneNo("01273566282"); 
		    one.setStartDate(new Date()); //the start date is set to the current date
	        recordManager.addEmployee(one); // the recordManager adds the Employee one to its list of Employees
		    
	        //the same process above is repeated for a new Employee called two
		    Employee two = new Employee();  
		    two.setEmployeeName("Polly");
		    two.setAddress("61 The Upper Drive");
		    two.setDepartment("sales"); 
		    two.setPhoneNo("01343232312"); 
		    two.setStartDate(new Date());
	        recordManager.addEmployee(two);
	        
	        //a new RecordManagerReport object is created of which calls the print method in RecordManagerReport
			RecordManagerReport recordManagerReport = new RecordManagerReport();
			//the recordManager and Employees details are then printed out to console using this method 
			recordManagerReport.printReport(recordManager);
			
			
	}
}


