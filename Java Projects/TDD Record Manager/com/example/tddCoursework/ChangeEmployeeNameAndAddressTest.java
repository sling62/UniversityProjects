package com.example.tddCoursework;
/*
 * JUnit Test class for testing the setEmployeeName and setAddress method(in Employee class) for part 3 of assignment 1 
 * @author Samantha Ling (160720604)
 */
import static org.junit.Assert.*;

import java.util.Date;

import org.junit.Before;
import org.junit.Test;

//RecordManager and Employee classes are imported from package recordManagerClasses
import recordManagerClasses.Employee;
import recordManagerClasses.RecordManager;

public class ChangeEmployeeNameAndAddressTest {
    
	//A RecordManager called manager and three Employees; one, two and three are declared
	RecordManager manager;
	Employee one;
	Employee two;
	Employee three;
	
	/*the before tag is used to make sure that the following method passes/compiles before any tests are carried out
	 * the RecordManager and each Employee is initialised and their fields are set
	 */
	@Before
	public void CreateRecordManagerforSearch() {
		
		manager = new RecordManager();
		manager.setOfficeName("Office 1");
		
		one = new Employee();
		one.setEmployeeName("Ellie");
		one.setAddress("21 Montreplier Road");
		one.setDepartment("sales");
		one.setPhoneNo("01289763829");
		one.setStartDate(new Date());
		manager.addEmployee(one);
		
		two = new Employee();
		two.setEmployeeName("Polly");
		two.setAddress("56 Station Road");
		two.setDepartment("Sales");
		two.setPhoneNo("01520763897");
		two.setStartDate(new Date());
		manager.addEmployee(two);
		
		three = new Employee();
		three.setEmployeeName("polly");
		three.setAddress("8 Church Road");
		three.setDepartment("sales");
		three.setPhoneNo("0818739323");
		three.setStartDate(new Date());
		manager.addEmployee(three);
		
	}
	
	//Test to check if changing the name of an employee would the expected returned value or not 
	@Test
	public void TestChangeNameOfEmployee() {
		
		one.setEmployeeName("Elle");
		assertEquals("Elle", manager.getEmployees().get(0).getName());
		//changing the name of Employee one
		one.setEmployeeName("Molly");
		//checking to see Employee one no longer has its previous name 
		assertNotEquals("Elle", manager.getEmployees().get(0).getName());
		//checking to see if Employee one now has the changed name
		assertEquals("Molly", manager.getEmployees().get(0).getName());
		
		//at first Employee three name had not been set
	    three.setEmployeeName("Melissa");
	    //checking to see if Employee three name is not NULL now
	    assertNotNull(manager.getEmployees().get(2).getName());
	    //checking the name of Employee three 
	    assertEquals("Melissa",manager.getEmployees().get(2).getName());
	}
	
	//this test branches off TestChangeNameOfEmployee but instead of just changing some of the names in the employees list(in RecordManager class), it changes the name of an Employee of which was searched for(using searchEmployees method) and was found
	@Test
	public void TestChangeNameOfEmployeeBeforeAndAfterSearch()
	{
	   /*manager.searchEmployees("polly");
	   assertEquals(1, manager.getNumOfFoundEmployees());*/
	
	   //Employee three name is set to Polly
	   three.setEmployeeName("Polly");
	   //searchEmployees method is invoked on the name Polly
	   manager.searchEmployees("Polly");
	   
	   //checks for expected number of returned employees from search
	   assertEquals(2, manager.getNumOfFoundEmployees());
	   
	   assertNotEquals("polly",three.getName());
	   assertEquals("Polly",three.getName());
	   
	   assertEquals("Polly",manager.getFoundEmployees().get(1).getName());
	   
	}
	
	//Similar to TestChangeNameOfEmployee, this Test checks to see if changing the address of an employee would have the expected returned value or not 
	@Test
	public void TestChangeAddressOfEmployee()
	{
		assertNotNull( manager.getEmployees().get(1).getAddress());
		assertNotEquals("48 Station Road", manager.getEmployees().get(1).getAddress());
		two.setAddress("48 Station Road");
		assertNotEquals("56 Station Road", manager.getEmployees().get(1).getAddress());
		assertEquals("48 Station Road", manager.getEmployees().get(1).getAddress());
		
	}

}
