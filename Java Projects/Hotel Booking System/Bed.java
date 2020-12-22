/**author: Samantha Ling
 * Aim: to get/set the bedType of each bed in a room 
 * Date: 05/12/16
 */

public class Bed {
    
	//private global variable called bedType is declared which stores the Type of the bed as a string
	private String bedType;
	
	//this method gets the bed Type 
	public String getBedSize() 
	{
		return bedType;
	}

    //this method sets the bed size by supplying the bedType variable as a parameter
	public void setBedSize(int bedType) 
	{
		//these if statements decide which bed Type is set depending on which bed size is entered, 1 or 2(single or double)
		if(bedType==1)
	    {
			this.bedType = "single";
	    }
		else if(bedType==2)
		{
		    this.bedType ="double";
		}
	}
		
    //the constructor takes the bed size value input(1 or 2) which is then stored in bedTypeChoice and supplies it to the setBedSize method as a parameter
	public Bed(int bedTypeChoice) 
	{
		this.setBedSize(bedTypeChoice);
	}

	//this prints the value of the bed Type as a string and returns it when the getBedSize method is called
	public String toString()
	{
		return bedType;
	}
	
		

}
