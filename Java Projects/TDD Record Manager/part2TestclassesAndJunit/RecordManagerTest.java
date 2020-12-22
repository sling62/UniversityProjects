package part2TestclassesAndJunit;

/**author: Samantha Ling(ID:160720604)
 * Aim: to test the output of the RecordManager class in part 2 of assignment 1 by using the PrintReportClass
 * Date: 26/11/17
 **/

//RecordManager class is imported from package recordManagerClasses
import recordManagerClasses.RecordManager;

public class RecordManagerTest {

	public static void main(String[] args) 
	{
	//a new RecordManagerTest is created called recordManagerTest
	RecordManagerTest recordManagerTest= new RecordManagerTest();
	//a new RecordManager is created
	RecordManager manager = new RecordManager();
	//the recordManagerTest calls the addValues method to set fields for the RecordManager called manager
	recordManagerTest.addValues(manager); 
	}
	
	public void addValues(RecordManager recordManager)
	{
		    //office name is set for the recordManager
            recordManager.setOfficeName("Test Record Manager");
            //a new RecordManagerReport object is created of which calls the print method in RecordManagerReport
            RecordManagerReport recordManagerReport = new RecordManagerReport();
            //the recordManager details are then printed out to console using this method 
			recordManagerReport.printReport(recordManager);	
	}

}