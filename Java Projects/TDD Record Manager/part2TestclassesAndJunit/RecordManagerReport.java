package part2TestclassesAndJunit;
/**author: Samantha Ling(ID:160720604)
 * Aim: to print the output and return values of the RecordManager, Employee and TrainingRecord Classes
 * Date: 26/11/17
 **/
import recordManagerClasses.RecordManager;

public class RecordManagerReport {

	//method to print and return the Record Manager details and All Employees and their details as well as their Training Record details
	public void printReport(RecordManager recordManager)
	{
		//prints record manager name(office)
		System.out.println(String.format("Record Manager Office:%s ", recordManager.getOfficeName()));
		//prints the total number of employees in the record manager
		System.out.println(String.format("Total Number Of Employees:%s", recordManager.getNumOfEmployees()));
		
		//for loop iterates through the employees list getting their details and printing them out
		for(int x=0; x<recordManager.getNumOfEmployees();x++)
		{
			System.out.println("\n");
			System.out.println(String.format("Employee ID:%d",recordManager.getEmployees().get(x).getEmployeeID()));
			System.out.println(String.format("Name:%s",recordManager.getEmployees().get(x).getName())); 
			System.out.println(String.format("Address:%s",recordManager.getEmployees().get(x).getAddress()));
			System.out.println(String.format("Phone Number:%s",recordManager.getEmployees().get(x).getPhoneNo()));
			System.out.println(String.format("Department:%s",recordManager.getEmployees().get(x).getDepartment()));
			System.out.println("Start Date:" + recordManager.getEmployees().get(x).getStartDate());
			System.out.println("Number of qualifications: "+recordManager.getEmployees().get(x).getNumOfTrainingRecords());
	    
			System.out.println("");
			
		//for loop iterates through the Training record list for each employee, getting the details of each training record and printing them out
		for(int y=0;y<recordManager.getEmployees().get(x).getNumOfTrainingRecords();y++)
		{
			System.out.println(String.format("Name of Qualification:%s", recordManager.getEmployees().get(x).getTrainingRecords().get(y).getRecordName()));
			System.out.println(String.format("Level Achieved:%s", recordManager.getEmployees().get(x).getTrainingRecords().get(y).getLevelAchieved()));
			System.out.println("Date Achieved:"+ recordManager.getEmployees().get(x).getTrainingRecords().get(y).getDateAchieved());
		}

		}
	}
	
	//similar to printReport method above, printSearchReport prints and returns the details of all the Employees found from the searchEmployees method(in RecordManager) as well as their Training Record details
	public void printSearchReport(RecordManager recordManager)
	{
		    //prints the total number of employees found in the record manager from a given name
			System.out.println(String.format("Total Number of Employees Found:%s", recordManager.getNumOfFoundEmployees()));
			
			for(int x=0; x<recordManager.getNumOfFoundEmployees();x++)
			{
				System.out.println("\n");
				System.out.println(String.format("Employee ID:%d",recordManager.getFoundEmployees().get(x).getEmployeeID()));
				System.out.println(String.format("Name:%s",recordManager.getFoundEmployees().get(x).getName())); 
				System.out.println(String.format("Address:%s",recordManager.getFoundEmployees().get(x).getAddress()));
				System.out.println(String.format("Phone Number:%s",recordManager.getFoundEmployees().get(x).getPhoneNo()));
				System.out.println(String.format("Department:%s",recordManager.getFoundEmployees().get(x).getDepartment()));
				System.out.println("Start Date:" + recordManager.getFoundEmployees().get(x).getStartDate());
				System.out.println("Number of qualifications: "+recordManager.getFoundEmployees().get(x).getNumOfTrainingRecords());
		    
				System.out.println("");
			for(int y=0;y<recordManager.getFoundEmployees().get(x).getNumOfTrainingRecords();y++)
			{
				System.out.println(String.format("Name of Qualification:%s", recordManager.getFoundEmployees().get(x).getTrainingRecords().get(y).getRecordName()));
				System.out.println(String.format("Level Achieved:%s", recordManager.getFoundEmployees().get(x).getTrainingRecords().get(y).getLevelAchieved()));
				System.out.println("Date Achieved:" + recordManager.getFoundEmployees().get(x).getTrainingRecords().get(y).getDateAchieved());
			}

			}
    }
}
