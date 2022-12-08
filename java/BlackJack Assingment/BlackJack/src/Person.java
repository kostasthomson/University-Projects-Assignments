import java.util.Random;

public class Person {
	protected Random Generator;
	protected int upper;
	protected int lower;
	protected int card1;
	protected int card2;
	protected int newCard;
	protected int total;
	protected boolean Lost;
	protected boolean Won;
	
	protected Person() {
		this.Generator = new Random();
		this.upper = 11; //upper bound
		this.lower = 2; //lower bound
		this.Lost = false;
		this.Won = false;
	}
		
	private void Winner() {
		this.Won = total == 21;
	}
	
	private void Looser() {
		this.Lost = total > 21;
	}
	
	protected void GetCards() {
		this.card1 = this.GenerateRandomNumber();
		this.card2 = this.GenerateRandomNumber();
		this.updateTotal(this.card1, this.card2);
	}
	
	public void Hit() {
		this.newCard = this.GenerateRandomNumber();
		this.updateTotal(this.newCard);
	}
	
	private int GenerateRandomNumber() {
		return this.Generator.nextInt(upper-1) + lower;
	}
	
	private void updateTotal(int n1) {
		this.total += n1;
		this.Winner();
		this.Looser();
	}
	
	private void updateTotal(int n1, int n2) {
		this.total = n1 + n2;
		this.Winner();
		this.Looser();
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
	
	public boolean hasLost() {
		return Lost;
	}

	public boolean hasWon() {
		return Won;
	}
}
