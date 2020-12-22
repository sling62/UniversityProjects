package recordManagerClasses;
/**author: Samantha Ling(ID:160720604)
 * Aim: to create a TrainingRecord to assign to an Employee's trainingRecords list  
 * Date: 26/11/17
 * Important changes to UML:Instead of creating a date achieved field of type Date, I changed it to of type
 * Calender as then it is easier for the user to enter the dateAchieved.
 * In addition to this I have also changed the return type of getDateAchieved so that it returns a String instead of a Date 
 * and the reason for this is because then the date can be formatted correctly. 
 */
	
import java.text.SimpleDateFormat;
//import Calendar Class
import java.util.Calendar;

public class TrainingRecord {

	    //stores the TrainingRecord name
		private String recordName;
		//stores the level achieved for a TrainingRecord
		private String levelAchieved;
		//stores the date of which the TrainingRecord was achieved, this is of type calendar and is assigned to a calendar instance
	    Calendar dateAchieved =  Calendar.getInstance();
		
		public TrainingRecord(){
			
		}
		//method to set the TrainingRecord name 
		public void setRecordName(String name){
			this.recordName = name;
		}
		//method to set the Level achieved for a TrainingRecord
	    public void setLevelAchieved(String level){
	   
			this.levelAchieved=level;
		}
	    //method to get the TrainingRecord name
		public String getRecordName()
		{
			return recordName;
		}
		//method to get the level achieved for the TrainingRecord 
		public String getLevelAchieved()
		{
			return levelAchieved;
		}
		//method to set the date that the TrainingRecord was achieved, the user can set the day, month and year of that date
		public void setDateAchieved(int day, int month, int year)
		{
			dateAchieved.set(year, month -1, day);
		}
		//method to get the date the TrainingRecord was achieved
		public String getDateAchieved()
		{
			//the supplied calendar date is formatted as a String using SimpleDateFormat 
			SimpleDateFormat format1 = new SimpleDateFormat("dd/MM/yyyy");
			//the day, month and year of which the user has set is for the TrainingRecord is retrieved using getTime()
		    String formatted = format1.format(dateAchieved.getTime());
		    //this then returns the formatted calendar date
			return formatted;
		}
		
		
}


