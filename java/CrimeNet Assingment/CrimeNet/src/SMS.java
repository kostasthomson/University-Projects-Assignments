
public class SMS extends Communication{
	
	private String messagecontent;
	
	public SMS(String phone1, String phone2, int day, int month, int year, String message) {
		super(phone1, phone2, day, month, year);
		this.messagecontent = message;
	}
	
	public void printInfo() {
		System.out.println("This SMS has the following info");
		super.printInfo();
		System.out.println("Text: " + this.messagecontent);
	}
	
	public String getMessageContent() {
		return this.messagecontent;
	}
	
	public boolean isContentMatched(String text) {
		return this.messagecontent.contains(text);
	}
	
}
