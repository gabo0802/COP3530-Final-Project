# GitHub Repository for COP3530 Project

Made by Vladmir Alekseev, Gabriel Castejon, and Mason Enojo

Go to replit repository to run the program and see the full code (this does not include the full BRIDGES library): 

[https://replit.com/@gabo0802/COP3530-Project-3]

### Description

Problem: 
■ This program will solve a lack of entertainment ideas when one is bored. It works by allowing users to generate movie recommendations based on genre and critic rating. It shows the highest rated and lowest rated movies through outputting the top and bottom 10, 50, and 100 movies. You can also sort then output all the available movies, genres, and main actors in alphanumeric order and its reverse if desired.

Motivation: 
■ This is a problem because people are always interested in finding something new to watch. People usually want to watch highly rated movies and typically want to avoid watching low rated movies. However, they may also want to watch the worst movie they could think of, and this program takes into account that. The program will create a way to instantly settle on a media to watch, rather than spending hours browsing Netflix.

Features: 
■ Features we have implemented include the data being sorted by movie title, main actor, rating, or genre with the user ability to output the data in ascending or descending order. This is in the formats of top or bottom 10, 50, or 100. They could also choose which type of sorting algorithm to use and the program outputs the amount of time it took to sort the data using that algorithm. These three types are Merge, Quick, and Radix sorts. The original four options output based on the original, real IMDB dataset while option 5 uses extra randomly generated values to test a 100,000 value data set. This large data set is used purely to compare the sorting algorithms on large sets.

Data: 
■ The data used for this project is the IMDB movie dataset, with extra data points being randomly generated as there were only around 500 data points in the set. The rest was randomly generated to create a total of 100,000. In the data, it included an actor, a movie, a rating, and genre(s) in each data point. This was stored in a vector of ActorMovieIMDB objects, where each stored a string actor, string movie, float rating, and vector<string> genres.

Tools:
■ The tools used were the C++ programming language along with the Bridges API. The Bridges API was used purely just to access the IMDB data set in our project. This was implemented in Replit and later uploaded to Github.

Algorithms Implemented:
■ The algorithms used were Radix Sort, Quick Sort, and Merge Sort algorithms to sort the data. Both Quick Sort and Merge Sort are divide and conquer algorithms, where data is broken into sub components and individually sorted then combined to create a final sorted data structure. Radix Sort is a non-comparative sorting algorithm that uses the digits of the largest number to sort all other numbers. Quick and Merge sort could sort both strings and numbers while Radix sort was limited to just numbers in our implementation. As a result we allowed the choice of only quick or merge for title, name, and genre and then an option of quick, merge, or radix for the ratings.

Additional Data Structures/Algorithms used:
■ Additional data structures/algorithms used included vectors to store the ActorMovieIMDB objects and std::reverse to reverse the already sorted data.

Distribution of Work:
■ Vladimir Alekseev: Report, Radix Sort, Merge Sort
■ Gabriel Castejon: Parsing data, Bridges, adjusting the ActorsMovieIMDB.h file to make randomizing and sorting the objects easier
■ Mason Enojo: Quick Sort, Random ActorMovieIMDB generator to create extra data values to reach 100,000 minimum, Report, Video

