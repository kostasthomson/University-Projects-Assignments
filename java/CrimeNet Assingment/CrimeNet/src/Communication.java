
public class Communication {

	private String phone1;
	private String phone2;
	private int year;
	private int month;
	private int day;
	
	public Communication(String phone1, String phone2, int day, int month, int year) {
		this.phone1 = phone1;
		this.phone2 = phone2;
		this.day = day;
		this.month = month;
		this.year = year;
	}
	
	public void printInfo() {
		System.out.println("Between " + this.phone1 + " --- " + this.phone2);
		System.out.println("on " + this.year + "/" + this.month + "/" + this.day);
	}
	
	public String getPhone1() {
		return this.phone1;
	}
	
	public String getPhone2() {
		return this.phone2;
	}
}
