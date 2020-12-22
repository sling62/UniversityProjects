/**author: Samantha Ling
 * Aim: to display a Hotel Report showing the hotel name, total number of rooms, each number of beds in a room and the bed type for each bed
 * Date: 06/12/16
 */
public class HotelReport {
	
    //constructor for HotelReport class holds no statements or values
	public HotelReport() 
	{
		
	}
	
    //this method prints the hotel report and takes in a parameter called hotel that is of Hotel type which is a Hotel object that is declared and supplied from Hotel Test and Hotel Configure 
	public void printReport(Hotel hotel)
	{
		//setHotelName is called from the hotel class in the HotelTest and HotelConfigure class in order to set the name of the hotel with a given input
		//getHotelName is called from the Hotel class in order to return the hotel name, this is then formatted using String.format and printed out
		System.out.println(String.format("Hotel Name:%1$s ", hotel.getHotelName()));
		//Similarly goes with getRoomSize which returns the number of rooms
		System.out.println(String.format("Total Number Of Rooms:%1$d", hotel.getRoomsSize()));
		
		//this loop loops until the end of the rooms list
		for(int x=0; x<hotel.getRoomsSize();x++)
		{
			//new line is printed in order to separate blocks of code
			System.out.println("\n");
			//this prints out a room number, loop starts at 0 so i added 1 each time the loop iterates
			System.out.println(String.format("Room:%1$d", (x+1))); 
			//this prints out the number of beds in each room by getting the room at position x and finding out the bed size/total number of beds(hotel.getRooms().get(x).getBedSize())
			System.out.println(String.format("Number of Beds:%1$d",hotel.getRooms().get(x).getBedSize()));
		
		//this loop is nested within another for loop in order to access the number of beds in each room at position x(hotel.getRooms().get(x).getBedSize())
		for(int y=0;y<hotel.getRooms().get(x).getBedSize();y++)
		{
            //this then prints out the bed type of each bed in a room(hotel.getRooms().get(x).getBeds().get(y).getBedSize())
			System.out.println(String.format("Bed type:%1$s", hotel.getRooms().get(x).getBeds().get(y).getBedSize()));
		}

		}
		
	}


}
