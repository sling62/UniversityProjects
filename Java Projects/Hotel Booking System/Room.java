/**author: Samantha Ling
 * Aim: to create a list of beds, get/set a list of beds and the amount of beds/beds size 
 * Date: 04/12/16
 */

import java.util.ArrayList;
import java.util.List;

public class Room {
	
	//list of Bed's called beds is declared as a global variable to use in different methods
    private List<Bed> beds;
    
 
	//this method gets the bed list
	public List<Bed> getBeds()
	{
		return beds;
	}
	
	//this method gets the bed list size(number of beds)
	public int getBedSize()
	{
		return beds.size();
	}
	
	//this constructor sets the bed list
	public Room() 
	{
		this.beds= new ArrayList<Bed>();
	}
	
	//this method adds a bed to the bed list
	public void addBed(Bed y)
	{
		beds.add(y);
	}
	
    

	

}

