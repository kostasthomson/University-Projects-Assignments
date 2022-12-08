import java.util.Random;
import java.util.Scanner;

public class Main {

	static Random Generator = new Random();
	static int lower_bound = 2;
	static int upper_bound = 11;
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		String answer;
//initializing objects
		Player P = new Player(Generator, upper_bound, lower_bound);
		Dealer D = new Dealer(Generator, upper_bound, lower_bound);
		
//starting message
		System.out.println("Welcome to the simplified blackjack game!");
//player drawing cards
		P.GetCards();
		P.printCards(2);
		P.printTotal();
//checking if player is winner or looser by drawing first 2 cards
		if(!P.Winner() && !P.Looser()) {
//dealer drawing cards
			D.GetCards();
//printing message
			D.printShownMessage();
			while(true) {
//getting answer
				while(true) {
					System.out.println("\nWould you like to \"hit\" or \"stay\"? ");
					answer = in.nextLine();
					if(answer.equals("hit") || answer.equals("stay")) {
						break;
					}
					System.out.println("Input a valid answer");
				}
//checking answer
				if(answer.equals("hit")) {
//player hits
					P.Hit();
				}else {
//player stays
					break;
				}
//printing messages
				P.printCards(1);
				P.printTotal();
//checking if player lost
				if(P.Looser()) {
					System.out.println("You have lost.");
					break;
				}
//checking if player won
				if(P.Winner()) {
					break;
				}
			}
//checking if player lost-won before dealer starts play
			if (!P.HasLost() && !P.HasWon()) {
//printing messages
				System.out.println("\nOK, dealer is playing.");
				D.printHiddenMessage();
				D.printTotal();
				while(true) {
//checking if dealers total is in bound
					if(D.inBound()) {
//dealer hits
						System.out.println("\nDealer chooses to hit.");
						D.Hit();
					}else {
//dealer stays
						System.out.println("\nDealer stays.\n");
						break;
					}
//printing messages
					D.printCard();
					D.printTotal();
//checking if dealer lost
					if(D.Looser()) {
						System.out.println("\nDealer has lost.");
						break;
					}
//checking if dealer won
					if(D.Winner()) {
						break;
					}
				}
			}
		}
//printing messages
		if((!P.HasLost() && !D.HasLost()) && (!P.HasWon() && !D.HasWon())) {
			//messages if the game is normally completed
			D.printTotal();
			P.printTotal();
		}
		if(P.HasLost() || (D.HasWon() && !D.HasLost()) && (D.getTotal() >= P.getTotal())) {
			//message if dealer wins before game is normally complete
			D.printWinnerMessage();
		}else if(D.HasLost() || (P.HasWon() && !P.HasLost()) && (P.getTotal() > D.getTotal())) {
			//message if player wins before game is normally completed
			P.printWinnerMessage();
		}
		in.close();
	}
}
