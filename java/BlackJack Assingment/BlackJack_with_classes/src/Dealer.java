import java.util.Random;

public class Dealer {
	private Random Generator;
	private int upper;
	private int lower;
	private int bound = 19; //dealer bound to draw
	private int cardShown;
	private int cardHidden;
	private int newCard;
	private int total;
	private boolean hasLost = false;
	private boolean hasWon = false;
	
	public Dealer(Random generator, int upper_bound, int lower_bound) {
		Generator = generator;
		upper = upper_bound;
		lower = lower_bound;
	}
	
	public boolean inBound() {
		return total < bound;
	}
	
	public boolean Winner() {
		hasWon = total == 21;
		return hasWon;
	}
	
	public boolean Looser() {
		hasLost = total > 21;
		return hasLost;
	}
	
	public void printWinnerMessage() {
		System.out.println("\nDEALER WINS!");
	}
	
	public void printShownMessage() {
		System.out.println("The dealer has a " + cardShown + " showing, and a hidden card.");
	}
	
	public void printHiddenMessage() {
		System.out.println("His hidden card was " + cardHidden + ".");
	}
	
	public void printCard() {
		System.out.println("He drew a " + newCard);
	}
	
	public void printTotal() {
		System.out.println("His total is " + total);
	}
	
	public void Hit() {
		newCard = GenerateRandomNumber();
		total += newCard;
	}
	
	public void GetCards() {
		cardShown = GenerateRandomNumber();
		cardHidden = GenerateRandomNumber();
		updateTotal(cardShown, cardHidden);
	}
	
	private int GenerateRandomNumber() {
		return Generator.nextInt(upper-1) + lower;
	}
	
	
//getters / setters	
	private void updateTotal(int n1, int n2) {
		total = n1 + n2;
	}
	public int getCard1() {
		return cardShown;
	}

	public int getCard2() {
		return cardHidden;
	}
	
	public int getNewCard() {
		return newCard;
	}

	public int getTotal() {
		return total;
	}
	
	public boolean HasLost() {
		return hasLost;
	}

	public boolean HasWon() {
		return hasWon;
	}

}
