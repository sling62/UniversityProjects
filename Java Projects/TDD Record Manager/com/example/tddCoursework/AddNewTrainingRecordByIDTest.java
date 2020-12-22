package com.example.tddCoursework;

/*
 * JUnit Test class for testing the addNewTrByID method(in RecordManager class) for part 3 of assignment 1 
 * @author Samantha Ling (160720604)
 */

import static org.junit.Assert.*;

import java.util.Date;

import org.junit.Before;
import org.junit.Test;

//RecordManager, Employee, TrainingRecord classes are imported from package recordManagerClasses
import recordManagerClasses.Employee;
import recordManagerClasses.RecordManager;
import recordManagerClasses.TrainingRecord;

public class AddNewTrainingRecordByIDTest {
	
	//A RecordManager called manager and three Employees; one, two and three are declared
	RecordManager manager;
	Employee one;
	Employee two;
	Employee three;

/*the before tag is used to make sure that the following method passes/compiles before any tests are carried out
 * the RecordManager and each Employee is initialised and their fields are set
 * Training Records are created and added to Employees as well
 */
@Before
public void CreateRecordManagerforSearch() {
		
		manager = new RecordManager();
		manager.setOfficeName("Office 2");
		
		one = new Employee();
		one.setEmployeeName("Charlotte");
		one.setAddress("28 Western Road");
		one.setDepartment("sales");
		one.setPhoneNo("01229763929");
		one.setStartDate(new Date());
		manager.addEmployee(one);
		
		TrainingRecord oneTrainingRecord1 = new TrainingRecord();
		oneTrainingRecord1.setRecordName("A level Maths");
		oneTrainingRecord1.setLevelAchieved("A");
		one.addTrainingRecord(oneTrainingRecord1);
		
		TrainingRecord oneTrainingRecord2 = new TrainingRecord();
		oneTrainingRecord2.setRecordName("A level Bussiness");
		oneTrainingRecord2.setLevelAchieved("B");
		one.addTrainingRecord(oneTrainingRecord2);
		
		two = new Employee();
		two.setEmployeeName("Michelle");
		two.setAddress("23 Clifton Terrace");
		two.setDepartment("Manufacturing");
		two.setPhoneNo("01520763897");
		two.setStartDate(new Date());
		manager.addEmployee(two);
		
		TrainingRecord twoTrainingRecord1 = new TrainingRecord();
		twoTrainingRecord1.setRecordName("GCSE Maths");
		twoTrainingRecord1.setLevelAchieved("A");
		two.addTrainingRecord(twoTrainingRecord1);
		
}

//test to see if a new TrainingRecord has been added by getting the number of TrainingRecord's a Employee has
@Test
public void TestGetNumOfTrainingRecords() {
	
	//checking if the number of TrainingRecord's Employee one has is two at first
	assertEquals(2,manager.getEmployees().get(0).getNumOfTrainingRecords());
	//calling the addNewTrByID method in the RecordManager class to add a new TrainingRecord to Employee one
	manager.addNewTrByID(0);
	//checking to see if the number of TrainingRecords Employee one has is now increased by one so now Employee one has 3 TrainingRecords altogether
	assertEquals(3,manager.getEmployees().get(0).getNumOfTrainingRecords());
	
}

//test to see if a new TrainingRecord has been added and if it has, setting and getting the trainingReord details/fields
@Test
public void setandGetDetailsOfNewTrainingRecordByID()
{
	//calling the addNewTrByID method in the RecordManager class to add a new TrainingRecord to Employee two
     manager.addNewTrByID(1);
     //checking to see if the name of the newly added TrainingRecord is NULL
     assertNull(manager.getEmployees().get(1).getTrainingRecords().get(1).getRecordName());
     
     //setting the recordName of the newly added TrainingRecord
     manager.getEmployees().get(1).getTrainingRecords().get(1).setRecordName("A level Geography");
     //checking to see if the recordName field is not NULL for the new TrainingRecord after using the set method
     assertNotNull(manager.getEmployees().get(1).getTrainingRecords().get(1).getRecordName());
     //checking the recordName of the new TrainingRecord
     assertEquals("A level Geography",manager.getEmployees().get(1).getTrainingRecords().get(1).getRecordName());
     
     //same technique as above is carried out however it is now checking the levelAchieved field of the new TrainingRecord
     assertNull(manager.getEmployees().get(1).getTrainingRecords().get(1).getLevelAchieved());
     manager.getEmployees().get(1).getTrainingRecords().get(1).setLevelAchieved("B");
     assertEquals("B",manager.getEmployees().get(1).getTrainingRecords().get(1).getLevelAchieved());
     
     //similar technique as above is carried out however it is now checking the dateAchieved field of the new TrainingRecord
     manager.getEmployees().get(1).getTrainingRecords().get(1).setDateAchieved(10, 06, 1998);
     assertEquals("10/06/1998",manager.getEmployees().get(1).getTrainingRecords().get(1).getDateAchieved());
    
}

}
