#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 5
#define MAX_SEATS 10

// Movie structure
struct Movie {
    int id;
    char title[50];
    char genre[20];
    char showtime[10];
    int seats[MAX_SEATS]; // 0 = available, 1 = booked
};

// Initialize movies
void initializeMovies(struct Movie movies[]) {
    movies[0].id = 1; strcpy(movies[0].title, "Avengers"); strcpy(movies[0].genre, "Action"); strcpy(movies[0].showtime, "10:00AM");
    movies[1].id = 2; strcpy(movies[1].title, "Frozen"); strcpy(movies[1].genre, "Animation"); strcpy(movies[1].showtime, "11:30AM");
    movies[2].id = 3; strcpy(movies[2].title, "Inception"); strcpy(movies[2].genre, "Sci-Fi"); strcpy(movies[2].showtime, "02:00PM");
    movies[3].id = 4; strcpy(movies[3].title, "Titanic"); strcpy(movies[3].genre, "Romance"); strcpy(movies[3].showtime, "05:00PM");
    movies[4].id = 5; strcpy(movies[4].title, "Joker"); strcpy(movies[4].genre, "Drama"); strcpy(movies[4].showtime, "08:00PM");
    
    // Initialize seats as available
    for(int i=0;i<MAX_MOVIES;i++){
        for(int j=0;j<MAX_SEATS;j++){
            movies[i].seats[j] = 0;
        }
    }
}

// Display all movies
void displayMovies(struct Movie movies[]) {
    printf("\nAvailable Movies:\n");
    printf("ID\tTitle\t\tGenre\t\tShowtime\n");
    for(int i=0;i<MAX_MOVIES;i++){
        printf("%d\t%s\t%s\t%s\n", movies[i].id, movies[i].title, movies[i].genre, movies[i].showtime);
    }
}

// Search movie by title
void searchMovie(struct Movie movies[]) {
    char keyword[50];
    printf("\nEnter movie title to search: ");
    scanf(" %[^\n]", keyword);

    int found = 0;
    for(int i=0;i<MAX_MOVIES;i++){
        if(strstr(movies[i].title, keyword) != NULL){
            printf("Found: ID: %d | Title: %s | Genre: %s | Showtime: %s\n", 
                    movies[i].id, movies[i].title, movies[i].genre, movies[i].showtime);
            found = 1;
        }
    }
    if(!found) printf("No movie found with that title.\n");
}

// Book a seat
void bookSeat(struct Movie movies[]) {
    int movieID, seat;
    printf("\nEnter Movie ID to book: ");
    scanf("%d", &movieID);

    int found = 0;
    for(int i=0;i<MAX_MOVIES;i++){
        if(movies[i].id == movieID){
            found = 1;
            printf("Seats (0=available, 1=booked): ");
            for(int j=0;j<MAX_SEATS;j++){
                printf("%d ", movies[i].seats[j]);
            }
            printf("\nEnter seat number (0-%d): ", MAX_SEATS-1);
            scanf("%d", &seat);

            if(seat>=0 && seat<MAX_SEATS){
                if(movies[i].seats[seat]==0){
                    movies[i].seats[seat]=1;
                    printf("Seat %d booked successfully!\n", seat);
                } else {
                    printf("Seat already booked!\n");
                }
            } else {
                printf("Invalid seat number!\n");
            }
            break;
        }
    }
    if(!found) printf("Movie ID not found!\n");
}

// Main menu
int main() {
    struct Movie movies[MAX_MOVIES];
    initializeMovies(movies);

    int choice;
    while(1){
        printf("\n--- Movie Ticket Booking ---\n");
        printf("1. Display Movies\n");
        printf("2. Search Movie\n");
        printf("3. Book Seat\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: displayMovies(movies); break;
            case 2: searchMovie(movies); break;
            case 3: bookSeat(movies); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
