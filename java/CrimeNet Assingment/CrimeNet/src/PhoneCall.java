
public class PhoneCall extends Communication {

	private int duration;
	
	public PhoneCall(String phone1, String phone2, int day, int month, int year, int duration) {
		super(phone1, phone2, day, month, year);
		this.duration = duration;
	}
	
	public void printInfo() {
		System.out.println("This phone call has the following info");
		super.printInfo();
		System.out.println("Duration: " + this.duration);
	}
	
	public int getDuration() {
		return this.duration;
	}
	
}
