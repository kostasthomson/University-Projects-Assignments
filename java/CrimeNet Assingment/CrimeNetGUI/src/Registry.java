import java.util.ArrayList;

public class Registry {
	ArrayList<Suspect> suspects = new ArrayList<>();
	ArrayList<Communication> communications = new ArrayList<>();
	
	public void addSuspect(Suspect aSuspect) {
		this.suspects.add(aSuspect);
	}
	
	public void addCommunication(Communication aCommunication) {
		this.communications.add(aCommunication);
		this.updateSuspectsByPhones(aCommunication.getPhone1(), aCommunication.getPhone2());
	}
	
	private void updateSuspectsByPhones(String Num1, String Num2) {
		
		Suspect s1 = this.findSuspectFromNumber(Num1);
		Suspect s2 = this.findSuspectFromNumber(Num2);
		
		if(s1 != null && s2 != null) {
			s1.ConnectTo(s2);
			s2.ConnectTo(s1);
		}else {
			System.out.println("These numbers does not match with any suspect...");
		}
	}
	
	private Suspect findSuspectFromNumber(String Num) {
		
		for(Suspect s: this.suspects) {
			for(String phone: s.getPhoneList()) {
				if(phone.equals(Num))
					return s;
			}
		}
		return null;
	}
	
	public Suspect getSuspectWithMostPartners() {
		
		Suspect maxPartnersSuspect = null;
		int maxPartners = -1;
		
		for(Suspect s: this.suspects) {
			if(s.getPartnersListsize() >= maxPartners) {
				maxPartnersSuspect = s;
				maxPartners = s.getPartnersListsize();
			}
		}
		return maxPartnersSuspect;
	}
	
	public PhoneCall getLongestPhoneCallBetween(String number1, String number2) {
		
		PhoneCall maxPhoneCallBetween = null;
		int maxDuration = -1;
		
		for(Communication comm: this.communications) {
			if(comm instanceof PhoneCall) {
				PhoneCall currCall = (PhoneCall) comm;
				boolean number1_statement = this.CompareNumbertoPhones(number1, currCall.getPhone1(), currCall.getPhone2());
				boolean number2_statement = this.CompareNumbertoPhones(number2, currCall.getPhone1(), currCall.getPhone2());
				
				if(number1_statement && number2_statement) {
					if(currCall.getDuration() > maxDuration) {
						maxDuration = currCall.getDuration();
						maxPhoneCallBetween = currCall;
					}
				}
			}
		}
		return maxPhoneCallBetween;
	}
	
	public ArrayList<SMS> getMessagesBetween(String number1, String number2){
		
		ArrayList<SMS> messages = new ArrayList<>();
		
		for(Communication comm: this.communications) {
			if(comm instanceof SMS) {
				SMS currSMS = (SMS) comm;
				boolean number1_statement = this.CompareNumbertoPhones(number1, currSMS.getPhone1(), currSMS.getPhone2());
				boolean number2_statement = this.CompareNumbertoPhones(number2, currSMS.getPhone1(), currSMS.getPhone2());
			
				if((number1_statement && number2_statement) && !number1.equals(number2)) {
					boolean containsBomb = currSMS.isContentMatched("Bomb");
					boolean containsAttack = currSMS.isContentMatched("Attack");
					boolean containsExplosives = currSMS.isContentMatched("Explosives");
					boolean containsGun = currSMS.isContentMatched("Gun");
					
					if(containsBomb || containsAttack || containsExplosives || containsGun) {
						messages.add(currSMS);
					}
				}
			}
		}
		return messages;
	}
	
	private boolean CompareNumbertoPhones(String num, String phone1, String phone2) {
		return num.equals(phone1) || num.equals(phone2);
	}
	
	public ArrayList<Suspect> getSuspectList() {
		return this.suspects;
	}
	
}
