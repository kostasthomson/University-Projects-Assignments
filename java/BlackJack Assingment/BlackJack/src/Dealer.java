
public class Dealer extends Person {
	private int showingcard;
	private int hiddencard;
	private int draw_bound = 16;
	
	public Dealer() {
		super();
		super.GetCards();
		this.showingcard = super.card1;
		this.hiddencard = super.card2;
	}
	
	public boolean inBound() {
		return super.total < draw_bound;
	}
	
	public int getShowingCard() {
		return showingcard;
	}
	
	public int getHiddenCard() {
		return hiddencard;
	}
}
