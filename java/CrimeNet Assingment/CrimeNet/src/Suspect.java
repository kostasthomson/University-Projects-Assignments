import java.util.ArrayList;

public class Suspect {
	
	private String name;
	private String codeName;
	private String city;
	private ArrayList<String> phonelist = new ArrayList<>();
	private ArrayList<Suspect> partners = new ArrayList<>();
	
	public Suspect(String Name, String CodeName, String city) {
		this.name = Name;
		this.codeName = CodeName;
		this.city = city;
	}
	
	public void addNumber(String number) {
		this.phonelist.add(number);
	}
	
	public void ConnectTo(Suspect aSuspect) {
		if(!this.isConnectedTo(aSuspect)) {
			this.partners.add(aSuspect);
		}
	}
	
	public boolean isConnectedTo(Suspect aSuspect) {
		return this.partners.contains(aSuspect);
	}

	public ArrayList<Suspect> getCommonPartners(Suspect aSuspect) {
		ArrayList<Suspect> common = new ArrayList<>();
		for(Suspect thisSus_ListPartner: this.partners) {
			if(aSuspect.partners.contains(thisSus_ListPartner))
				common.add(thisSus_ListPartner);
		}
		return common;
	}
	
	public void printPartners() {
		for(Suspect s: this.partners) {
			System.out.println("Name: " + s.name);
			System.out.println("CodeName: " + s.codeName);
		}
	}
	
	public ArrayList<String> getPhoneList() {
		return this.phonelist;
	}
	
	public int getPartnersListsize() {
		return this.partners.size();
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getCodeName() {
		return this.codeName;
	}
}
