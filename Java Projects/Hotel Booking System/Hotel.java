/**author: Samantha Ling
 * Aim: to get/set the hotel name, maximum occupancy, room size and create a list of rooms
 * Date: 02/12/16
 */
	

import java.util.ArrayList;
import java.util.List;
public class Hotel {
	
    //global variables declared to use in different methods
	//this stores the hotel name
	private String name;
	//this is a list of all the rooms
	List<Room> rooms;
	//this stores the maximum occupancy of the entire hotel(as an Integer)
	private int maximumOccupancy=0;
	//this stores if the room has a vacancy or not(Use of Boolean to return true or false)
	private Boolean hasVacancies;
	
	public Hotel() 
	{
		//in the hotel constructor i have set the number of rooms to the list of rooms
		this.rooms = new ArrayList<Room>();
	}
	
	public void setHotelName(String name)
	{
		//setting the hotel name
		this.name=name;
	}
	
	public String getHotelName()
	{
		//returning the hotel name
		return name;
	}
	
	public List<Room> getRooms()
	{
		//setting the rooms
		return rooms;
	}
	
	public void addRooms(Room x)
	{
		//adding a room to the room list
		rooms.add(x);

	}
	
	//these following methods are optional 
	
	public int getRoomsSize()
	{
		//getting the room list size 
		return rooms.size();
	}
	
	public void setMaximumOccupancy(int maximumOccupancy)
	{
		//this sets the maximum occupancy
		this.maximumOccupancy=maximumOccupancy;
	}
	
	public int getMaximumOccupancy()
	{
		//this returns the maximum occupancy
		return maximumOccupancy;
	}
	
	//this calculates the maximum occupancy
	public void calcMaximumOccupancy(Hotel hotel)
	{
		// a local variable counter is declared in order to count the total number of occupancy for each bed in each room
        int counter=0;
		
        //first loop loops through each element in the rooms list(stop condition occurs at the end of the list)
	    for(int i=0; i<hotel.getRoomsSize();i++)
	    {
	      //second loop loops through the bed list in rooms class getting the number of beds in each room(stop condition occurs when it has looped through each bed in a room)
		  for(int y=0;y<hotel.getRooms().get(i).getBedSize();y++)
		  {
                //this gets the type of a bed from the rooms class and stores the value in a variable called typeOfBed

			    String typeOfBed = hotel.getRooms().get(i).getBeds().get(y).getBedSize();
			    
                //if statements in order to see which values are added to counter
				if(typeOfBed=="single")
				{
					//if bed type is "single" then one person is allowed to sleep in the bed so counter adds 1
					counter=counter+1;
				}
				else if(typeOfBed=="double")
				{
					//Similarly if bed type is "double" then two people are allowed so the counter adds 2
					counter=counter+2;
				}
				//this loops round each room and each bed in a room to get the total maximum occupancy of the hotel
		   }
		
		   //the value of counter is then set/supplied to method setMaximumOccupancy
		   hotel.setMaximumOccupancy(counter);
	    }
	 
	}
	
	//this sets the value of hasVacancies to true or false whether the room has a vacancy or not
	public void setHasVacancies(Boolean hasVacancies)
	{
		this.hasVacancies=hasVacancies;
	}
	
	//this returns if the room is vacant or not 
	public Boolean getHasVancancies()
	{
		return hasVacancies;
	}
	

}
