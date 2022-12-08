import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		String answer;
		
		Player P = new Player();
		Dealer D = new Dealer();
		
		System.out.println("Welcome to the simplified blackjack game!");
		
		//player's info messages
		System.out.println("You get a " + P.getCard1() + " and " + P.getCard2() + ".");
		System.out.println("Your total is " + P.getTotal() + ".\n");
		
		//dealer's info message
		System.out.println("The dealer has a " + D.getShowingCard() + " showing, and a hidden card.");

		//game starts
		if(!P.hasWon() || !P.hasLost()) {
			//player's turn
			while(!P.hasLost() && !P.hasWon()) {
				while(true) {
					System.out.print("\nWould you like to \"hit\" or \"stay\"? ");
					answer = input.nextLine();
					if(answer.equals("hit") || answer.equals("stay"))
						break;
					System.out.println("Give valid answer (\"hit\" \\ \"stay\")\n");
				}
				
				if(answer.equals("hit")) {
					P.Hit(); //player gets a new card
					System.out.println("You drew a " + P.getNewCard() + ".");
					System.out.println("Your total is " + P.getTotal() + ".");
				}else
					break; //player passes
			}
			
			if(!P.hasLost() && !P.hasWon()) {			
				//dealer's turn
				System.out.println("\nOK, dealer is playing.");
				System.out.println("His hidden card was " + D.getHiddenCard() + ".");
				System.out.println("His total is " + D.getTotal() + ".\n");
				if(!D.hasWon() || !D.hasLost()) {
					while(D.inBound() && D.getTotal() < P.getTotal()) {
						System.out.println("Dealer chooses to hit.");
						D.Hit(); //dealer gets a new card
						System.out.println("He draws a " + D.getNewCard() + ".");
						System.out.println("His total is " + D.getTotal() + ".\n");
					}
					//dealer passes
					if(!D.hasLost() && !D.hasWon()) {
						System.out.println("Dealer stays.\n");
						System.out.println("Dealer total is " + D.getTotal() + ".");
						System.out.println("Your total is " + P.getTotal() + ".");
					}
				}
			}
		}
		
		if((P.hasLost() || D.hasWon() || (D.getTotal() >= P.getTotal())) && !D.hasLost()) {
			System.out.println("\nDEALER WINS!");
		}else if((D.hasLost() || P.hasWon() || (P.getTotal() > D.getTotal())) && !P.hasLost()) {
			System.out.println("\nYOU WIN!");
		}
		
		input.close();
	}
}