package part3Testclass;
/**author: Samantha Ling(ID:160720604)
 * Aim: to test the output of the RecordManager, Employee and TrainingRecord classes(by using the PrintReportClass) after using TDD in JUnit in part 3 of assignment 1 
 * Date: 26/11/17
 **/
//Java Date class is imported to create StartDate's for Employees
import java.util.Date;
//RecordManagerReport class is imported from package part2TestclassesandJunit
import part2TestclassesAndJunit.RecordManagerReport;
//RecordManager, Employee, TrainingRecord classes are imported from package recordManagerClasses
import recordManagerClasses.Employee;
import recordManagerClasses.RecordManager;
import recordManagerClasses.TrainingRecord;


public class RecordManagerPart3Tests {

	public static void main(String[] args) 
	{
		//a new RecordManagerPart3Tests object is created called recordManagerTest
		RecordManagerPart3Tests recordManagerTest= new RecordManagerPart3Tests();
		//a new RecordManager is created
		RecordManager manager = new RecordManager();
		//the recordManagerTest calls the addValues method to set fields for the RecordManager classes(RecordManager,Employee and TrainingRecord) called manager
		recordManagerTest.addValues(manager);   
	}
	public void addValues(RecordManager recordManager)
	{
		    //office name is set for the recordManager
            recordManager.setOfficeName("Test Record Manager");
            
            //a new Employee is created called one and the fields of that Employee is set
		    Employee one = new Employee(); 
		    one.setID(5); //doesn't work as method is declared as final
		    one.setEmployeeName("Polly"); 
		    one.setAddress("61 The Upper Drive"); 
		    one.setDepartment("MANUFACTURING"); 
		    one.setEmployeeName("Ellie"); // setting the employeeName to see if it changes the name of the employee from Polly to Ellie
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
		    one.addTrainingRecord(second);  // the Employee one adds another TrainingRecord called second to its list of training records
		    
		    //the same process above is repeated for a new Employee called two
		    Employee two = new Employee();  
		    two.setEmployeeName("Polly");
		    two.setAddress("61 The Upper Drive");
		    two.setDepartment("sales"); 
		    two.setPhoneNo("01347261819"); 
		    two.setAddress("65 The Upper Drive"); // setting the employee Address to see if it changes the address of the employee from 61 to 65 The Upper Drive
		    two.setStartDate(new Date());
	        recordManager.addEmployee(two);
	        
	        //a search is carried out to see if any of the employees names in the Employees list contains 'Polly'
	        recordManager.searchEmployees("Polly");
	      
	        
	        //a new RecordManagerReport object is created of which calls the print method in RecordManagerReport
			RecordManagerReport recordManagerReport = new RecordManagerReport();
			//the recordManager, Employees and their TrainingRecords details are then printed out to console using this method
			recordManagerReport.printReport(recordManager);
			//the employees found from the search and their TrainingRecords details are printed out to console using this method
			recordManagerReport.printSearchReport(recordManager);
			
			//gets the number of training records Employee two has
	        System.out.println("Number of training records:" + recordManager.getEmployees().get(1).getNumOfTrainingRecords());
	        //a new trainingRecord is then added to Employee two 
	        recordManager.addNewTrByID(1);
	        //checking to see if the new Training Record has been added to Employee two by getting the number of training records Employee two has again
	        System.out.println("Number of training records:" + recordManager.getEmployees().get(1).getNumOfTrainingRecords());
		
	}
}
