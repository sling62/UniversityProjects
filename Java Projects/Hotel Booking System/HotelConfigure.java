/**author: Samantha Ling
 * Aim: to get user input on the number of rooms, number of beds in a room and the bed type of each bed
 *      to check/validate the input values using exceptions 
 *      get and set values in other classes similar to hotelTest class
 *      print out these values back to the user
 * Date: 09/12/16
 */
//java InputMismatchException and scanner class imported 
import java.util.InputMismatchException;
import java.util.Scanner;

public class HotelConfigure {

	//constructor for hotel configure
	public HotelConfigure() {

	}

	public static void main(String[] args) 
    {
		//object of hotelConfigure class created in order to execute method called userChoice
		HotelConfigure hotelConfigure = new HotelConfigure();
		hotelConfigure.userChoice();
	}

	//user choice is a simple user interface method created in order to let the user input values when prompted in console
	public void userChoice() 
	{
		//values are initialized as local variables for input
		int roomInput = 0;  //room, bed and bedType input values are initialized to 0
		int bedInput=0;
		int bedTypeInput=0;
		
		int roomInputCheck = 1;   //these variables are used for checking the values entered by the user,variables are initialized to 1
		int bedTypeInputCheck = 1;
		int bedInputCheck = 1;

		//scanner called Read is created in order to read in input values
		Scanner Read = new Scanner(System.in);

		//simple print out statement in order to ask the user to enter a hotel name, this is stored in a local variable called name
		System.out.println("please enter the hotel name:");
		String name = Read.nextLine();

		//new hotel object/hotel is created 
		Hotel hotel = new Hotel();
		//the hotel name is then set by the hotel object
		hotel.setHotelName(name);

		//do while loop, loops round until the user inputs a correct value for the number of rooms
		do
		{
			//try and catch method in order to catch exceptions 
		    try 
			{
		    	//simple print out statement to ask the user for the number of rooms there is in the hotel, this is then stored in roomInput variable
				System.out.println("please enter the number of rooms: ");
				roomInput = Read.nextInt();
				//if statement is used to check input, if a number is entered and greater than 0 then input is correct and it exists out of loop
				if (roomInput > 0) 
				{
					roomInputCheck = 0;
				}
				//however if the input is a number but less than or equal to 0 then input is incorrect and will loop again until correct
				else
				{
					System.out.println("incorrect number of rooms entered");
				}
			}
		    //InputMismatchException checks to see if the user enters a string rather than a number, if they do then it catches the exception and displays error message 
			catch (InputMismatchException ime) 
			{
				System.out.println("incorrect number of rooms entered");
				//this reads in next input value
				Read.next();
			}
		    
		}while(roomInputCheck!=0); //exits out of the loop if roomInputCheck =0 then the input value is correct
		
		//for loop is created in order to loop round each room, the room starts at room 1(k=1) 
		for (int k = 1; k <= roomInput; k++) 
		{
			//a new room object/room is created after each iteration of the for loop
			Room room = new Room();
			//hotel object adds the room to the rooms list in the hotel class
			hotel.addRooms(room);
			//this re-sets the bedInputCheck variable check to 1 each time the for loop iterates
			bedInputCheck = 1;
			
			//the do while loop and the try and catch statements works similarly to the roomsInputCheck above however it is for the bed input
			do
			{
				try
				{
					    
						System.out.println("please enter the number of beds of room " + k + ":");
						bedInput = Read.nextInt();
						
						if(bedInput>0)
						{
							bedInputCheck=0;
						}
						else
						{
							System.out.println("incorrect number of beds entered");
						}
				}
				
				catch (InputMismatchException ime) 
				{
				System.out.println("incorrect number of beds entered");
				Read.next();
				}
				
			}while(bedInputCheck!=0);	
           
            
			//this for loop loops through each bed in a room
			for (int y = 0; y < bedInput; y++) 
			{
				//this re-sets the bedTypeInputCheck variable check to 1 each time the for loop iterates
				bedTypeInputCheck = 1;
				
				//the do while loop and the try and catch statements works similarly to the bedInputCheck above however it is for the bed type input
                do
                {
                	try
                	{ 
                		
                		System.out.println("enter the bed size(1 for single or 2 for bed):");
                		bedTypeInput = Read.nextInt();
                		
                		if(bedTypeInput==1 || bedTypeInput==2)
                		{
                	
                			bedTypeInputCheck=0;
                			room.addBed(new Bed(bedTypeInput));
                		}
                		else
                		{
                			System.out.println("incorrect bed size entered");
                		}
                	}
                	
                	catch (InputMismatchException ime) 
                	{
    				System.out.println("incorrect bed size entered");
    				Read.next();
                	}
				
                }while(bedTypeInputCheck!=0);
                
			 }
			
		  }
			//after loop is finished the hotel object information from the Hotel class is supplied to a method called printReport in the HotelReport class
			System.out.println("\n");
			//a new object of the HotelReport class is created called hotelReport which calls printReport method
		    HotelReport hotelReport = new HotelReport();
			hotelReport.printReport(hotel);

			//hotel calls calcMaximumOccupancy method in the Hotel class and passes the hotel object as a parameter in order to work out the hotels maximum occupancy
			hotel.calcMaximumOccupancy(hotel);
			System.out.println("\n");
			//this value is then retrieved/returned through calling the getMaximumOccupancy method in the Hotel class, this is then printed out 
		    System.out.println("Maximum Occupancy: " + hotel.getMaximumOccupancy());
			
	}
	
	}
	

		



