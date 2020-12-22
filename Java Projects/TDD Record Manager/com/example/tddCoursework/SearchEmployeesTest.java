package com.example.tddCoursework;

/*
 * JUnit Test class for testing the searchEmployees method(in the RecordManager) for part 3 of assignment 1 
 * @author Samantha Ling (160720604)
 * IMPORTANT NOTE!: this class was previously named ExampleLoggingTest and so may appear on log at the beginning
 * as this however the name has now been changed to SearchEmployeesTest/TestNumOfEmployeesFoundInSearch, 
 * in addition to this another method name previously called TestGetSearchList is now TestNumOfEmployeesFoundInSearch
 */
import static org.junit.Assert.*;

import java.util.Date;

import org.junit.Before;
import org.junit.Test;

//RecordManager, Employee, TrainingRecord classes are imported from package recordManagerClasses
import recordManagerClasses.Employee;
import recordManagerClasses.RecordManager;
import recordManagerClasses.TrainingRecord;

public class SearchEmployeesTest extends AbstractLoggingJUnitTest {

	//A RecordManager called manager and three Employees; one, two and three are declared
	RecordManager manager;
	Employee one;
	Employee two;
	Employee three;
	
	/*the before tag is used to make sure that the following method passes/compiles before any tests are carried out
	 * the RecordManager and each Employee is initialised and their fields are set
	 * Training Record is created and is added to an Employee as well
	 */
	@Before
	public void CreateRecordManagerforSearch() {
		
		manager = new RecordManager();
		//office name of RecordManager is set
		manager.setOfficeName("Office 1");
		
		//a new Employee is created called one and the fields of that Employee is set
		one = new Employee();
		one.setID(5); //setting the employee ID to 5 shouldn't work as set method is declared as final
		one.setEmployeeName("Sally");
		one.setAddress("3 barns road");
		one.setDepartment("sales");
		one.setPhoneNo("01289763829");
		one.setStartDate(new Date()); //the start date is set to the current date
		manager.addEmployee(one); // the recordManager should add the Employee one to its list of Employees(as seen from part 2 test classes)
		
		//a new TrainingRecord is created called oneTrainingRecord and some the fields of that TrainingRecord are set
		TrainingRecord oneTrainingRecord = new TrainingRecord();
		oneTrainingRecord.setRecordName("A level Maths");
		one.addTrainingRecord(oneTrainingRecord); // the Employee one should add the trainingRecord oneTrainingRecord to its list of TrainingRecords(as seen from part 2 test classes)
		
		//a new Employee is created called two and some of the fields of that Employee are set
		two = new Employee();
		two.setEmployeeName("Sally");
		two.setDepartment("manufacturing");
		two.setPhoneNo("01520763897");
		manager.addEmployee(two);
		
		//a new Employee is created called three and some of the fields of that Employee are set
		three = new Employee();
		three.setEmployeeName("Susan");
		three.setAddress("5 barns road");
		three.setDepartment("manufacturing");
		three.setStartDate(new Date());
		manager.addEmployee(three);
		
	}
	
	//The first test searches the employees for a supplied name and returns the number of found employees which have that name 
	@Test
	public void TestNumOfEmployeesFoundInSearch() {
		
		//testing exact name string matches of employees 
		/*manager.searchEmployees("Sally");
		assertEquals(2,manager.getNumOfFoundEmployees());*/
		
		//manager calls the searchEmployees method in the RecordManager class to search for 'susan'
		manager.searchEmployees("susan");
		//expecting the number of found employees returned to be 0 as the searchEmployees method is case sensitive 
		assertEquals(0,manager.getNumOfFoundEmployees());
		
	}
	
	/*the second test again searches the employees for a supplied name, however now this test is checking to see when an employee does match the supplied name
	 * if they have been added to the foundEmployees list in RecordManager and gets the name of that employee to see if it is an exact match 
	 */
	@Test
	public void TestGetSearchListNames()
	{
		manager.searchEmployees("Susan");
		//checking Employee name at index 0 in getFoundEmployees list to see if it matches the exact name searched for
		assertEquals("Susan",manager.getFoundEmployees().get(0).getName());
		assertNotEquals("susan",manager.getFoundEmployees().get(0).getName());
	}
	
	/*the third test is similar to the second test however is now checking the ID of an Employee found in the employeesFound List after the search is carried out, 
	 * to see if it matches as expected
	 */
	@Test
	public void TestGetSearchListIDs()
	{
		manager.searchEmployees("Sally");
		assertEquals(1, manager.getFoundEmployees().get(1).getEmployeeID());
	}
	
	/*the fourth test is similar to the third test however is now checking the address of an Employee found in the employeesFound List after the search is carried out, 
	 * to see if it matches as expected
	 */
	@Test
	public void TestGetSearchListAddresses()
	{
		manager.searchEmployees("Sally");
		//checking for NULL and non-NULL assigned values of different found employee addresses
		assertNotNull(manager.getFoundEmployees().get(0).getAddress());
		assertNull(manager.getFoundEmployees().get(1).getAddress());
		//checking for exact String matches for addresses
		assertNotEquals("4 barns road",manager.getFoundEmployees().get(0).getAddress());
		assertEquals("3 barns road",manager.getFoundEmployees().get(0).getAddress());
	}
	
	/*the fifth test is similar to the fourth test however is now checking the department of an Employee found in the employeesFound List after the search is carried out, 
	 * to see if it matches as expected
	 */
	@Test
	public void TestGetSearchListDepartments()
	{
		manager.searchEmployees("Susan");
		//checking for non-NULL assigned value of the first employee found 
		assertNotNull(manager.getFoundEmployees().get(0).getDepartment());
		//for exact String matches for departments
		assertEquals("manufacturing",manager.getFoundEmployees().get(0).getDepartment());
	}
	
	/*the sixth test is similar to the fifth test however is now checking the phone number of an Employee found in the employeesFound List after the search is carried out, 
	 * to see if it matches as expected
	 */
	@Test
	public void TestGetSearchListPhoneNums()
	{
		manager.searchEmployees("Sally");
		//checking for exact String matches for phone numbers
		assertNotEquals("129763829", manager.getFoundEmployees().get(0).getPhoneNo());
		assertEquals("01520763897", manager.getFoundEmployees().get(1).getPhoneNo());
	}
	
	/*the seventh test is similar to the sixth test however is now checking the start date of an Employee found in the employeesFound List after the search is carried out, 
	 * to see if it matches as expected
	 */
	@Test
	public void TestGetSearchListGetStartDate()
	{
		manager.searchEmployees("Sally");
		//checking for exact String matches for start dates as the dates(of type Calendar) should formatted
		
		//assertEquals("01/12/2017", manager.getFoundEmployees().get(0).getStartDate()); - expected date needs to be the current date in the format dd/mm/yyyy
		assertNotEquals(new Date(),manager.getFoundEmployees().get(0).getStartDate());
		//checking for NULL assigned value of the start date of the second employee found as it hasn't been set yet
		assertNull(manager.getFoundEmployees().get(1).getStartDate());
	}
	
	//the eighth test tries to get the training record for an employee which had been searched for and found 
	public void TestGetSearchListGetTrainingRecord()
	{
		manager.searchEmployees("Sally");
		//getting the name of the first training record found for the first employee found to see if it is as expected
		assertEquals("A level Maths",manager.getFoundEmployees().get(0).getTrainingRecords().get(0).getRecordName());
	}
	

}
