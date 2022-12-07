#ifndef IMDB_H

#define IMDB_H

#include <string>
//Modified from the original
#include <cstdlib>
#include <time.h> 

using namespace std;

namespace bridges {
	namespace dataset {
		/**
		 *	@brief A class to hold actor movie data -- using IMDB dataset
		 *
		 *  This dataset has a set of actor-movie pairs with movie rating and
		 *   genres, possibly. There are two datasets, the first has 1813 actor
		 *   movie pairs and no other attribute data. The second also has
		 *	 movie ratings and genres.
		 *
		 *  A user typically does not create an ActorMovieIMDB object. 
		 *	They are usually returned by 
		 *  bridges::DataSource::getActorMovieIMDBData() and 
		 *	bridges::DataSource::getActorMovieIMDBData2()
		 *
		 * 	@sa Check out the tutorial on the IMDB dataset at 
		 *	https://bridgesuncc.github.io/tutorials/Data_IMDB.html
		 *
		 *	@author Kalpathi Subramanian
		 *	@date 2/18/18, 12/28/20
		 *
		 */
		class ActorMovieIMDB {  
			private:
				string actor, movie;
				double rating;
				vector<string> genres;
        int sorter = 2; // 0 = Actor, 1 = Movie, 2 = Rating, 3 = Genre
			public:
				ActorMovieIMDB () {
					actor = "Jared Leto";
          movie = "Saturday Night Live";
          //Random Number Generator taken from https://cplusplus.com/reference/cstdlib/rand/ 
          srand (time(NULL));
          int rat = rand() % 100;
					rating = rat / 10.0;
          switch(rat % 10) {
            case 1:
              genres.push_back("Drama");
              break;
            case 2:
              genres.push_back("Sci-Fi");
              break;
            case 3:
              genres.push_back("Action");
              break;
            case 4:
              genres.push_back("Comedy");
              break;
            case 5:
              genres.push_back("Horror");
              break;
            case 6:
              genres.push_back("Western");
              break;
            case 7:
              genres.push_back("Romance"); 
              break;
            case 8:
              genres.push_back("Documentary");
              break;
            case 9:
              genres.push_back("Musical");
              break;
            default:
              genres.push_back("Theatre");
              break;
          }
				}

				/**
				 * This method initializes an actor movie object with an actor/movie pair.
				 *
				 *	@param[in] a actor
				 *	@param[in] m movie
				 */
				ActorMovieIMDB(const string& a, const string& m) {
					actor = a;
					movie = m;
					//Random Number Generator taken from https://cplusplus.com/reference/cstdlib/rand/ 
          srand (time(NULL));
          int rat = rand() % 100;
					rating = rat / 10.0;
          switch(rat % 10) {
            case 1:
              genres.push_back("Drama");
              break;
            case 2:
              genres.push_back("Sci-Fi");
              break;
            case 3:
              genres.push_back("Action");
              break;
            case 4:
              genres.push_back("Comedy");
              break;
            case 5:
              genres.push_back("Horror");
              break;
            case 6:
              genres.push_back("Western");
              break;
            case 7:
              genres.push_back("Romance"); 
              break;
            case 8:
              genres.push_back("Documentary");
              break;
            case 9:
              genres.push_back("Musical");
              break;
            default:
              genres.push_back("Theatre");
              break;
          }
				}


				/**
				 * This method initializes an actor movie object with an actor/movie pair.
				 *
				 *	@param[in] a actor
				 *	@param[in] m movie
				 *	@param[in] r rating
				 *	@param[in] genr genres
				 */
				ActorMovieIMDB(const string& a, const string& m, float r, const vector<string>& genr) {
					actor = a;
					movie = m;
					rating = r;
					genres = genr;
				}

				/**
				 * @brief Get actor name
				 *
				 * @return actor name
				 */
				string getActor() const {
					return actor;
				}
				/**
				 * @brief Set actor name
				 *
				 * @param a actor name
				 *
				 */
				void setActor (const string& a) {
					actor = a;
				}

				/**
				 * @brief Get movie name
				 *
				 * @return movie name
				 */
				string getMovie() const {
					return movie;
				}

				/**
				 * @brief xSet movie name
				 *
				 * @param[in] m movie name
				 */
				void setMovie (const string& m) {
					movie = m;
				}

				/**
				 * @brief Get movie rating
				 *
				 * @return movie rating
				 */
				double getMovieRating() const {
					return rating;
				}

				/**
				 * @brief Set movie rating
				 *
				 * @param[in] r movie rating
				 */
				void setMovieRating(double r) {
					rating = r;
				}

				/**
				 * @brief Get movie genres
				 *
				 * @return movie genres [vector of strings]
				 */
				vector<string> getGenres() const {
					return genres;
				}
        //returns the first element of the genres vector
        string getMainGenre() const {
          return genres[0];
        }
        void setGenres(const vector<string>& g) {
					genres = g;
				}

        void setSortState(int n) {
          switch(n) {
            case 0:
              sorter = 0; //Actor
              break;
            case 1:
              sorter = 1; //Movie
              break;
            case 3:
              sorter = 3; //Genre
              break;
            default:
              sorter = 2; //Rating
              break;
          }
        }
				/**
				 * @brief Set movie genres
				 *
				 * @param[in] g vector of movie genres
				 */
				//Operator Overloading implementation for sorting
        friend bool operator==(const ActorMovieIMDB& a, const ActorMovieIMDB& b) {
          switch(a.sorter) {
            case 1:
              return a.getMovie() == b.getMovie();
            case 0:
              return a.getActor() == b.getActor();
            case 3:
              return a.genres[0] == b.genres[0];
            default:
              return a.getMovieRating() == b.getMovieRating();
          }
        }
        friend bool operator!=(const ActorMovieIMDB& a, const ActorMovieIMDB& b) {
          switch(a.sorter) {
            case 1:
              return a.getMovie() != b.getMovie();
            case 0:
              return a.getActor() != b.getActor();
            case 3:
              return a.genres[0] != b.genres[0];
            default:
              return a.getMovieRating() != b.getMovieRating();
          }
        }
        friend bool operator>(const ActorMovieIMDB& a, const ActorMovieIMDB& b) {
          switch(a.sorter) {
            case 1:
              return a.getMovie() > b.getMovie();
            case 0:
              return a.getActor() > b.getActor();
            case 3:
              return a.genres[0] > b.genres[0];
            default:
              return a.getMovieRating() > b.getMovieRating();
          }
        }
        friend bool operator<(const ActorMovieIMDB& a, const ActorMovieIMDB& b) {
          switch(a.sorter) {
            case 1:
              return a.getMovie() < b.getMovie();
            case 0:
              return a.getActor() < b.getActor();
            case 3:
              return a.genres[0] < b.genres[0];
            default:
              return a.getMovieRating() < b.getMovieRating();
          }
        }
		};
	}
} // namespace bridges

#endif
