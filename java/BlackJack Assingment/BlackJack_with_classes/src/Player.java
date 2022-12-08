import java.util.Random;

public class Player {
	private Random Generator;
	private int upper;
	private int lower;
	private int card1;
	private int card2;
	private int newCard;
	private int total;
	private boolean hasLost = false;
	private boolean hasWon = false;
	
	public Player(Random generator, int upper_bound, int lower_bound) {
		Generator = generator;
		upper = upper_bound;
		lower = lower_bound;
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
		System.out.println("\nYOU WIN!");
	}
	
	public void printCards(int n) {
		if(n == 1) {
			System.out.println("You drew a " + newCard);
		}else {
			System.out.println("You get a " + card1 + " and a " + card2 + ".");
		}
		
	}
	
	public void printTotal() {
		System.out.println("Your total is " + total + "\n");
	}
	
	public void Hit() {
		newCard = GenerateRandomNumber();
		total += newCard;
	}
	
	public void GetCards() {
		card1 = GenerateRandomNumber();
		card2 = GenerateRandomNumber();
		updateTotal(card1, card2);
	}
	
	private int GenerateRandomNumber() {
		return Generator.nextInt(upper-1) + lower;
	}
	
	
//getters / setters	
	private void updateTotal(int n1, int n2) {
		total = n1 + n2;
	}
	public int getCard1() {
		return card1;
	}

	public int getCard2() {
		return card2;
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
