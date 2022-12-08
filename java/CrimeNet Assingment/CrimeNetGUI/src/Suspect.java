import java.util.ArrayList;

public class Suspect implements Comparable<Suspect>{
	
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
	
	public ArrayList<Suspect> SuggestedSuspects() {
		ArrayList<Suspect> suggested = new ArrayList<>();
		
		for(Suspect this_suspect: this.partners) {
			for(Suspect partnerlist_suspect: this_suspect.partners) {
				if(!this.partners.contains(partnerlist_suspect) && !partnerlist_suspect.equals(this)) {
					suggested.add(partnerlist_suspect);
				}
			}
		}
		
		return suggested;
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
	
	public ArrayList<Suspect> getPartnersList() {
		return this.partners;
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
	
	public String getCity() {
		return this.city;
	}

	@Override
	public int compareTo(Suspect other) {
		return this.name.compareTo(other.name);
	}

}
