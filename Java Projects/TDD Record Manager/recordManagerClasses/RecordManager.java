package recordManagerClasses;
/**author: Samantha Ling(ID:160720604)
 * Aim: to create a Record Manager for an office and create a list of employees as well as implement search methods
 * Date: 26/11/17
 * IMPORTANT NOTE: For adding a new Employee, their ID is automatically created in this class then passed as a parameter 
 * to a set method in Employee which is final and therefore cannot be altered.
 */
import java.util.ArrayList;
import java.util.List;

public class RecordManager {

	//a (office) name is asssigned to each Record Manager to identify it, if multiple Record Managers are created
	private String officeName;
	//a list of employees created from the Employee class is stored 
	List<Employee> employees;
	//a list of employees found from the name search is stored 
	List<Employee> foundEmployees = new ArrayList<Employee>();
	
	public RecordManager() 
	{
	    //sets employees list to a new arrayList when a new RecordManager is created
		this.employees = new ArrayList<Employee>();
		
	}
	//sets office name for each Record Manager
	public void setOfficeName(String name)
	{
		this.officeName=name;
	}
	
	//gets office name for each Record Manager
	public String getOfficeName()
	{
		return officeName;
	}
	
	//returns a list of employees 
	public List<Employee> getEmployees()
	{
		return employees;
	}
	
	/*when a new Employee is created from the employee class the employee can then be added to the list of employees
	 * using this method, for which the unique employee ID is assigned to the index position of the Employee in the list
	 */
	public void addEmployee(Employee employee)
	{
		employees.add(employee);
		int i = employees.size();
		employees.get(i-1).setID(i-1);

	}
	
	//gets the number of Employees in the list employees
	public int getNumOfEmployees()
	{
		return employees.size();
	}
	
	/*search method implemented to search the list of employees and add the employee to the list of found employees
	 * if the name of the employee contains the name of the String provided when the method is called
	 */
	public void searchEmployees(String name)
	{
		//Boolean is created which is set to true if an employee name is matched to the searched name
		Boolean found;
		
		//for loop loops through the list of employees
		for(int i =0; i<getNumOfEmployees(); i++)
		{
			//name is retrieved from each employee
			String text = employees.get(i).getName();
			//the name is then checked to see if it contains the String that is being searched for
			found = text.contains(name);
			//for which if it does then the employee is added to the list of foundEmployees, if not then the next employee is checked
			if(found == true)
			{
				foundEmployees.add(employees.get(i));
			}
		}
	
	}
	
	//returns a list of employees found from the search method; searchEmployees
	public List<Employee> getFoundEmployees()
	{
		return foundEmployees;
	}
	
	//gets the number of found employees from the search 
	public int getNumOfFoundEmployees()
	{
		return foundEmployees.size();
	}
	
	//searching method implemented that adds a new training Record to the employee of which the supplied ID matches
	public void addNewTrByID(int ID)
	{
		//for loop that loops through the employee list getting the employee ID for each employee
		for(int i =0; i<getNumOfEmployees(); i++)
		{
			int text = employees.get(i).getEmployeeID();
			//if the employee ID matches exactly to the ID that was supplied a new Training Record is added to that Employee
			if(text == ID)
			{
				TrainingRecord recordByID = new TrainingRecord();
	            employees.get(i).addTrainingRecord(recordByID);
			}
		}
	}
	
}
