/**author: Samantha Ling
 * Aim: To test if my program works correctly/as expected by creating a Hotel object and using hard coded values and the HotelReport class to print the output values to console.
 *      To add and test maximum occupancy methods in the Hotel class
 * Date: 07/12/16
 */

public class HotelTest {
	
    //HotelTest constructor contains no statements/holds no values
	public HotelTest() {

	}
	

	public static void main(String[] args) 
	{
		//new object of HotelTest class is declared called hotelTest
		HotelTest hotelTest= new HotelTest();
		//a new Hotel object/a new hotel is created and is called hotel 
		Hotel hotel = new Hotel();
		
		//the hotel object is passed as a parameter to a method called addvalues which adds the values/properties of the hotel 
		hotelTest.addValues(hotel);   
	}
	
	//this method tests the different classes methods with different hard coded values to see if they work correctly
	public void addValues(Hotel hotel)
	{
            //hotel object calls the setHotelName method in Hotel class in order to set the name, in this case its called "Test Hotel"
            hotel.setHotelName("Test Hotel");
            
		    Room one = new Room();  //a new Room object/a new Room is created called one 
	        one.addBed(new Bed(1)); //this Room object then calls the method addBed in order to add a new bed object/a new bed which is the bed type of a single(as implied by the number 1)
			hotel.addRooms(one); //this room is then added to the rooms list in the Hotel class
			
			//so when the printReport method is called from the HotelReport it should print out the following for the above room:
			//Room: 1
			//Number of beds: 1
			//Bed type: single
			
			Room two = new Room();  
			two.addBed(new Bed(1));
			two.addBed(new Bed(2)); 
			hotel.addRooms(two);
			
			//Similarly for the second room when the printReport method is called it should print out:
			//Room: 2
			//Number of beds: 2
			//Bed type: single     
			//Bed type: double
	
			Room three = new Room();
			three.addBed(new Bed(2));
			hotel.addRooms(three);
			
			//Similarly for the third room when the printReport method is called it should print out:
			//Room: 3
			//Number of beds: 1   
			//Bed type: double
			
			//a new HotelReport object called hotelReport is created in order to call the printReport method, it has a parameter with the Hotel object in order to supply values
			HotelReport hotelReport = new HotelReport();
			hotelReport.printReport(hotel);
			
			//the calcMaximumOccupancy method is called from the hotel class(with a parameter of the hotel object) of which works out the max occupancy of the hotel and sets the property maximumOccupancy
			hotel.calcMaximumOccupancy(hotel);
			System.out.println("\n");
			//the maximum occupancy is then taken from the Hotel class and displayed
			System.out.println("Maximum Occupancy: " +hotel.getMaximumOccupancy());
			
	}

}
