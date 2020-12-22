package recordManagerClasses;
/**author: Samantha Ling(ID:160720604)
 * Aim: to create a Employee to assign to the Record Manager employees list and create a list of their training Records as well 
 * Date: 26/11/17
 * Important changes to UML: instead of the ID being set in the constructor as planned, a setID method has been created 
 *  that is final and the id is passed as a parameter from RecordManager(See record manager header comments)
 *  Also changed the return type of getStartDate so that it returns a String instead of a date 
 *  and the reason for this is because then the date can be formatted correctly. 
 */

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;


public class Employee {
	
	//a list of trainingRecords created from the TrainingRecord class is stored
	private List<TrainingRecord> trainingRecords;
	//stores the assigned Employee ID
	private int uniqueID;
	//stores the Employee name
	private String employeeName;
	//stores the Employee address
	private String address;
	//stores the Employee phone number
	private String phoneNo;
	//stores the Employee department they work in
	private String department;
	//stores the Date the Employee starts 
	private String startDate;

	public Employee() 
	{
		//sets trainingRecords list to a new arrayList when a new Employee is created so that they can have multiple records
		this.trainingRecords= new ArrayList<TrainingRecord>();
	}
	
	//method that sets the Employee ID(is set to final so that once set cannot be changed during runtime)
	public final void setID(int id){
		this.uniqueID = id;
	}
	
	//gets the list of training Records the Employee has
	public List<TrainingRecord> getTrainingRecords()
	{
		return trainingRecords;
	}
	//method to add a new TrainingRecord to the list of trainingRecords a Employee has
	public void addTrainingRecord(TrainingRecord trainingRecord)
	{
		trainingRecords.add(trainingRecord);
	}
	
	//method to set the Employee name
	public void setEmployeeName(String name)
	{
		this.employeeName=name;
	}
	//method to set the Employee address
	public void setAddress(String employeeAddress)
	{
		this.address=employeeAddress;
	}
	//method to set the Employee phoneNo
	public void setPhoneNo(String phoneNum)
	{
			this.phoneNo= phoneNum;
	}
	//method to set the Employee department they work in
	public void setDepartment(String employeeDepartment)
	{
		this.department=employeeDepartment;
	    
	}
	//method to set the Employee start Date(usually the current date is set to the Employee start date as it is usually when the employee is added into the system)
	public void setStartDate(Date employeeStartDate)
	{
		//the supplied date is then formatted as a String using SimpleDateFormat 
		SimpleDateFormat dateFormatter = new SimpleDateFormat("dd/MM/yyyy");
		//the start date is then set to the formatted version of the date supplied
		this.startDate=dateFormatter.format(employeeStartDate);
	}
	//method to get the Employee Name
	public String getName()
	{
	   return employeeName;
	}
	//method to get the Employee Address
	public String getAddress()
	{
	   return address;
	}
	//method to get the Employee department they work in
	public String getDepartment()
	{
	   return department;
	}
	//method to get the Employee start date
	public String getStartDate()
	{
		return	startDate;
	}
	//method to get the Employee PhoneNo
	public String getPhoneNo()
	{
		return phoneNo;
	}
	//method to get the Employee ID
	public int getEmployeeID()
	{
		return uniqueID;
	}
	//method to get the number of TrainingRecords the Employee has
	public int getNumOfTrainingRecords()
	{
		return trainingRecords.size();
	}
	

}
