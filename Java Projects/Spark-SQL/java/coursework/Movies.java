package coursework;

/*CSC2024 Coursework 2 SPARK DataFrames and SQL
 * Student ID: 160720604
 * Date: 03/05/18
 */

import static org.apache.spark.sql.functions.col;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

import org.apache.log4j.Level;
import org.apache.log4j.LogManager;
import org.apache.spark.SparkConf;
import org.apache.spark.api.java.JavaSparkContext;
import org.apache.spark.sql.Dataset;
import org.apache.spark.sql.Row;
import org.apache.spark.sql.SparkSession;


public class Movies {
	
	//PATH is defined here of which is the path to the resources ml-latest folder in my workspace 
	private static String PATH = Messages.getString("CourseworkTwoSparkSQL"); 
	
	//these are the names of the csv files in the ml-latest folder, these file names are appended onto the PATH to be used in this program    
	private static String MOVIES = "movies.csv";
	private static String RATINGS  = "ratings.csv";
	private static String MOVIE_GENRES  = "movieGenres.csv";
	
	static SparkConf conf = new SparkConf().setMaster("local").setAppName("My Coursework");
	static JavaSparkContext sc = new JavaSparkContext(conf);
	static SparkSession spark = SparkSession.builder().appName("CSC2024 Coursework Two Spark SQL")
			.config("spark.some.config.option", "some-value").getOrCreate();
	
	public static void main(String[] args) {
		
		LogManager.getLogger("org").setLevel(Level.ERROR);
		
		//step methods 
		stepOne();
		stepTwo();
		stepThree();
		stepFour();
		stepFive();
		stepSix();
		stepSeven();
		
		spark.stop();
		
	}
	
	public static void stepOne()
	{
		System.out.println("Step 1: ");
		System.out.println("");
		
		System.out.println("ratings: ");
		//loading the ratings data from the ratings.csv file into the DataFrame ratings
		Dataset<Row> ratings = LoadRatingsData();
		//printing the schema of ratings
		ratings.printSchema(); 
		
		System.out.println("movies: ");
		//loading the movies data from the movies.csv file into the DataFrame movies
		Dataset<Row> movies = LoadMoviesData();
		//printing the schema of movies
		movies.printSchema();
	}
	
	public static void stepTwo()
	{
		System.out.println("Step 2: See movieGenres.csv file in resources ml-latest folder");
		System.out.println("");
		
		//loading the movies data from the movies.csv file into the DataFrame movies
		Dataset<Row> movies = LoadMoviesData();
		
		try {
			
			 //creating a new filewriter called FW which writes to a new csv file called movieGenres in the resources ml-latest folder in my workspace
			 FileWriter FW = new FileWriter(new File(PATH + MOVIE_GENRES));
		     
			 //created a new list called moviesList 
		     List<Row> moviesList = new ArrayList<Row>();
				
		     //this then takes the movies DataFrame coloumns movieId and genres and converts it to a list using collectAsList()
			 moviesList = movies.select("movieId","genres").collectAsList();
				
			//appending the column titles to the movieGenres file
			FW.append("movieId,genre\n");
				
			    //for loop to loop around the moviesList getting each row 
				for(Row moviesRow : moviesList) {
					
					//get the genres on the current row in moviesList and converting to a string to be assigned to string genres
					String genres = moviesRow.getAs("genres").toString();
					//splitting the string genres into the seperate genres and storing each genre in the string array genresSplit  
					String[] genresSplit = genres.split(Pattern.quote("|"));
					
					//get the id on the current row in moviesList and converting to a string to be assigned to string id
					String id = moviesRow.getAs("movieId").toString();
					
					//looping through genresSplit array and appending to the movieGenres file the genres and movieIds for each movie
					for(String genre : genresSplit) {
						FW.append(id);
						FW.append(',');
						FW.append(genre);
						FW.append('\n');
					}
					
				
					}
				FW.flush();
				//close movieGenres file
			    FW.close();
		     
		     
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void stepThree()
	{
		System.out.println("Step 3: ");
		System.out.println("");
		
		//loading the movies data from the movieGenres.csv file created in step 2 into the DataFrame movieGenres
		Dataset<Row> movieGenres = LoadMovieGenresData();
		
		System.out.println("movieGenres: ");
		//printing the schema of movieGenres
		movieGenres.printSchema();
		
		//ordering the movieGenres DataFrame by the movieId value in descending order and printing off the first 50 rows 
		movieGenres.orderBy(col("movieId").desc()).show(50);
	
	}
	
	public static void stepFour()
	{
		System.out.println("Step 4: ");
		System.out.println("");
		
		//loading the movies data from the movieGenres.csv file created in step 2 into the DataFrame movieGenres
		 Dataset<Row> movieGenres = LoadMovieGenresData();
		 
		 //creating a new dataFrame called genrePopularity
		 Dataset<Row> genrePopularity;
		 //grouping the genres in movieGenres dataFrame and counting the number of each genre this is then assigned to genrePopularity
		 genrePopularity = movieGenres.groupBy(movieGenres.col("genre")).count().withColumnRenamed("count", "moviesCount");
		 
		 //ordering genrePopularity by the moviesCount of each genre in descending order
		 genrePopularity = genrePopularity.orderBy(genrePopularity.col("moviesCount").desc());
		 System.out.println("genrePopularity: ");
		//printing the schema of genrePopularity 
		 genrePopularity.printSchema();
		 //printing off the first 10 rows in genrePopularity 
		 genrePopularity.show(10);
		 
	}
	
	public static void stepFive()
	{
		
		 //data from step 4 
		 Dataset<Row> ratings = LoadRatingsData();
		 Dataset<Row> movieGenres = LoadMovieGenresData();
		 Dataset<Row> genrePopularity = movieGenres.groupBy(movieGenres.col("genre")).count().withColumnRenamed("count", "moviesCount");
		 genrePopularity = genrePopularity.orderBy(genrePopularity.col("moviesCount").desc());
		 
		 System.out.println("Step 5: ");
		 System.out.println("");
		 
		 //getting the first 10 rows in genre column(ie. top 10 genres) from the genrePopularity dataFrame and converting it to a list which is then assigned to genrePopularityList 
		 List<Row> genrePopularityList = new ArrayList<Row>();
		 genrePopularityList = genrePopularity.select("genre").limit(10).collectAsList();
		
		 //filtering through the genrePopularityList and getting each row(ie Genre)
		 for(Row Genre: genrePopularityList)
		 {
			 //getting the movieIds from movieGenres for the matching top 10 genres in genrePopularity and assigning this to genrePopularityMovieIds
			 Dataset<Row> genrePopularityMovieIds = movieGenres.filter(genrePopularity.col("genre").equalTo(Genre.getAs("genre"))).select("movieId");
			 //joining the records from the ratings table of which the movieIds in ratings matches those in genrePopularityMovieIds and assigning this to ratingsMatchingMovieIds
			 Dataset<Row> ratingsMatchingMovieIds= genrePopularityMovieIds.join(ratings,ratings.col("movieId").equalTo(genrePopularityMovieIds.col("movieId")));
			 //ratingsMatchingMovieIds is then grouped by userId and assigned to ratingsSortedByUserIds
			 Dataset<Row> ratingsSortedByUserIds = ratingsMatchingMovieIds.groupBy(ratingsMatchingMovieIds.col("userId")).count();
			 //ratingsSortedByUserIds is then ordered by the count of the number of user ratings made by a user in a genre, the highest number(ie. first row) of ratings in a genre is then assigned to Row HighestGenreRatingsCount 
			 Row HighestGenreRatingsCount = ratingsSortedByUserIds.orderBy(col("count").desc()).first();
			 
			 //the current genre is stored in string genre
			 String genre = Genre.getAs("genre").toString();
			 
			 //this is then printed out alongside the userId of the user who rated the highest number of movies in that genre
			 System.out.println("<" + genre + ", " + HighestGenreRatingsCount.getAs("userId").toString() + ">");
		 }
	}
	
	private static void stepSix() {
		
		System.out.println("");
		System.out.println("Step 6: ");
		System.out.println("");
		
		Dataset<Row> ratings = LoadRatingsData();
		Dataset<Row> movieGenres = LoadMovieGenresData();
		
		//joining the movieGenres dataFrame with the ratings dataFrame, joining the records from ratings of which the movieId matches those in movieGenres
		Dataset<Row> movieGenresMatchingRatingsMovieIds = movieGenres.join(ratings, ratings.col("movieId").equalTo(movieGenres.col("movieId")));

		//counting the number of movies rated by all users, ordered in descending order to get the top ten users who have rated the most movies then replacing the column name count with ratingsCount
		Dataset<Row> topTenUsers = ratings.groupBy(col("userId")).count().orderBy(col("count").desc()).withColumnRenamed("count", "ratingsCount");

		//converting topTenUsers to a list
		List<Row> topTenUsersList = topTenUsers.takeAsList(10);

		for (int i = 0; i < topTenUsersList.size(); i++) {

			//getting the user Id of the user at the current index in the topTenUsersList
			String userId = topTenUsersList.get(i).get(0).toString();
			//getting the ratingsCount of the user at the current index in the topTenUsersList
			String ratingsCount = topTenUsersList.get(i).get(1).toString();
			//getting the movie genres of the user at the current index in the topTenUsersList
			Dataset<Row> userMovieGenres = movieGenresMatchingRatingsMovieIds.filter(col("userId").equalTo(userId));
			//grouping the movie genres of the user by the count of number of movies rated in a genre in descending order 
			Dataset<Row> userMostRatedGenres = userMovieGenres.groupBy(col("genre")).count().orderBy(col("count").desc());
			//getting the first record in userMostRatedGenres(so the most common genre) and converting it to string
			String mostCommonGenre = userMostRatedGenres.first().getAs("genre").toString();
			
			//printing out result of the user Id, ratingsCount and mostCommonGenre 
			String result = "<" + userId + ", " + ratingsCount + ", " + mostCommonGenre + ">" ;
			System.out.println(result);
			
		}

	}

	
	public static void stepSeven()
	{
		System.out.println("");
		System.out.println("Step 7: ");
		
		Dataset<Row> Ratings = LoadRatingsData();
		//ratings DataFrame is then copied to avgRatingsAndVariance DataFrame
		Dataset <Row> avgRatingsAndVariance = Ratings;
		//replacing the avgRatingsAndVariance dataFrame by "ratingsData" to be used in spark.sql function 
		avgRatingsAndVariance.createOrReplaceTempView("ratingData");
		//selecting the movieId, highest average rating and variance(var_samp) of each rating from ratingData
		avgRatingsAndVariance = spark.sql("SELECT movieId,AVG(rating),var_samp(rating) FROM ratingData GROUP BY movieId ORDER BY avg(rating) DESC");
		//this is then printed 
		avgRatingsAndVariance.show(10);
	}
	
	//loading the movies.csv file from resources ml_latest folder in workspace and returning it as a DataFrame 
	private static Dataset<Row> LoadMoviesData() {
		return spark.read().option("inferSchema", true).option("header", true).option("multLine", true)
				.option("mode", "DROPMALFORMED").csv(PATH + MOVIES);
	}

	//loading the ratings.csv file from resources ml_latest folder in workspace and returning it as a DataFrame 
	private static Dataset<Row> LoadRatingsData() {
		return spark.read().option("inferSchema", true).option("header", true).option("multLine", true)
				.option("mode", "DROPMALFORMED").csv(PATH + RATINGS);
	}
	
	//loading the movieGenres.csv file from resources ml_latest folder in workspace and returning it as a DataFrame 
	private static Dataset<Row> LoadMovieGenresData() {
		return spark.read().option("inferSchema", true).option("header", true).option("multLine", true)
				.option("mode", "DROPMALFORMED").csv(PATH + MOVIE_GENRES);
	}
	
}
	