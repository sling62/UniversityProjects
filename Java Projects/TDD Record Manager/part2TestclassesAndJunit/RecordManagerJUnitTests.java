package part2TestclassesAndJunit;

/*
 * JUnit Test class for RecordManager,Employee and TrainingRecord classes for part 2 of assignment 1 
 * NOTE:This Junit does not follow TDD
 * @author Samantha Ling (160720604)
 * 
 */

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

//RecordManager, Employee, TrainingRecord classes are imported from package recordManagerClasses
import recordManagerClasses.RecordManager;
import recordManagerClasses.Employee;
import recordManagerClasses.TrainingRecord;

import org.junit.Assert;
import org.junit.Before;

public class RecordManagerJUnitTests {
		
	    //Record manager is created 
		RecordManager manager;
		
		//the before tag is used to make sure that the following method passes/compiles before any tests are carried out
		@Before
		public void testCreateRecordManager()
		{
			//manager is assigned to a new RecordManager
			manager = new RecordManager();
		}
		
		//test method for testing the RecordManager and its methods and return values
		@Test
		public void testGetRecordManager()
		{
			//creating a new employee called a
			Employee a = new Employee();
			//then setting the name
			a.setEmployeeName("Elle");
			//testing the addEmployee method in RecordManager to see if it adds Employee a
			manager.addEmployee(a);
			
			//created a new List of employees of type employee 
			List<Employee> b = new ArrayList<Employee>();
			//then adding a to this list as well
			b.add(a);
			
			//testing if creating the same list as the employees list and adding the same employee, the employee at index 0 will be the same or not
			Assert.assertEquals(manager.getEmployees().get(0),b.get(0));
			
		}

		//test method for testing the Record Manager and Employee classes and its methods and return values
		@Test
		public void testGetEmployee() {

			//creating a new employee called one
			Employee one = new Employee();
			//then setting the name
			one.setEmployeeName("Jessica");
			//testing the return name value of Employee one
			assertEquals("Jessica",one.getName());
			
			//adding Employee one to the List of Employees in the RecordManger manager
			manager.addEmployee(one);
			//checking to see if there is now a employee added to the List of Employees in the RecordManger manager
			assertNotEquals(0,manager.getNumOfEmployees());
			
		}
		
		//test method for testing the Employee and TrainingRecord classes and its methods and return values
		@Test
		public void testGetTrainingRecord()
		{
			
			Employee one = new Employee();
			one.setEmployeeName("Jessica");

			manager.addEmployee(one);
			
			// a new TrainingRecord is created called a and some of the fields in TrainingRecord are set
			TrainingRecord a = new TrainingRecord();
			a.setRecordName("A levels");
			a.setLevelAchieved("Pass");
			
			// a new TrainingRecord is created called b and some of the fields in TrainingRecord are set
			TrainingRecord b = new TrainingRecord();
			b.setLevelAchieved("First");
			b.setDateAchieved(20, 06, 1998);
			
			//checking for a non-Null field for getting the date achieved for TrainingRecord b
			assertNotNull(b.getDateAchieved());
			
			//assigning the TrainingRecords a and b to Employee one
			one.addTrainingRecord(a);
			one.addTrainingRecord(b);
			
			//checking to see if both a and b TrainingRecords had been added, by checking the level achieved for the second training record of Employee one
			assertNotEquals("Pass",one.getTrainingRecords().get(1).getLevelAchieved());
			
			
		}
		
		

}



