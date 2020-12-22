package part2TestclassesAndJunit;

/**author: Samantha Ling(ID:160720604)
 * Aim: to test the output of the RecordManager, Employee and TrainingRecord class in part 2 of assignment 1 by using the PrintReportClass
 * Date: 26/11/17
 **/

//RecordManager, Employee, TrainingRecord classes are imported from package recordManagerClasses
import recordManagerClasses.Employee;
import recordManagerClasses.RecordManager;
import recordManagerClasses.TrainingRecord;

//Java Date class is imported to create StartDate's for Employees
import java.util.Date;

public class TrainingRecordTest {

    public static void main(String[] args) 
	{
    	//a new TrainingRecordTest is created called trainingRecordTest
		TrainingRecordTest trainingRecordTest= new TrainingRecordTest();
		//a new RecordManager is created
		RecordManager manager = new RecordManager();
		//the trainingRecordTest calls the addValues method to set fields for the RecordManager called manager
		trainingRecordTest.addValues(manager);   
	}
	public void addValues(RecordManager recordManager)
	{
		    //office name is set for the recordManager
            recordManager.setOfficeName("Test Record Manager");
            
            //a new Employee is created called one and the fields of that Employee is set
		    Employee one = new Employee(); 
		    one.setEmployeeName("Polly"); 
		    one.setAddress("61 The Upper Drive"); 
		    one.setDepartment("MANUFACTURING"); 
		    one.setEmployeeName("Ellie");
		    one.setPhoneNo("01273566282"); 
		    one.setStartDate(new Date()); //the start date is set to the current date
	        recordManager.addEmployee(one); // the recordManager adds the Employee one to its list of Employees
	        
	        //a new TrainingRecord is created called first and the fields of that TrainingRecord is set
	        TrainingRecord first = new TrainingRecord();
	        first.setRecordName("a level");
	        first.setLevelAchieved("PASS"); 
	        first.setDateAchieved(4,06,1998);//the date achieved is set using day,month,year
		    one.addTrainingRecord(first); // the Employee one adds the TrainingRecord first to its list of training records
		    
		    //the same process above is repeated for a new TrainingRecord called second
		    TrainingRecord second = new TrainingRecord();
	        second.setRecordName("GCSE");
	        second.setLevelAchieved("PASS"); 
	        second.setDateAchieved(20,10,2008); 
		    one.addTrainingRecord(second); // the Employee one adds another TrainingRecord called second to its list of training records
		    
		    //the same process above is repeated for a new Employee called two
		    Employee two = new Employee();  
		    two.setEmployeeName("Polly");
		    two.setAddress("61 The Upper Drive");
		    two.setDepartment("sales"); 
		    two.setPhoneNo("0134727828"); 
		    two.setStartDate(new Date());
	        recordManager.addEmployee(two);
	        
	        
	        //a new RecordManagerReport object is created of which calls the print method in RecordManagerReport
			RecordManagerReport recordManagerReport = new RecordManagerReport();
			//the recordManager, Employees and their TrainingRecords details are then printed out to console using this method
			recordManagerReport.printReport(recordManager);
	
	}
}
