import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.awt.Color;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class SuspectPageFrame extends JFrame{
	
//window contents
	private JFrame thisFrame = this;
	private JPanel parent_Panel = new JPanel();
	private JPanel panel1 = new JPanel();
	private JPanel panel2 = new JPanel();
	private JPanel panel3 = new JPanel();
	private JPanel panel4 = new JPanel();
//panel1
	private JTextField SuspectNameField = new JTextField(10);
	private JTextField SuspectCodeNameField = new JTextField(10);
	private JTextArea SuspectPhoneListArea = new JTextArea(4, 5);
//panel2
	private JTextField CommunicationNumberField = new JTextField(12);
	private JTextArea MessagesFieldArea = new JTextArea(10, 24);
	private JButton FindSMSButton = new JButton("Find SMS");
//panel3
	private JLabel PartnersLabel = new JLabel("Partners");
	private JTextArea SuspectPartnersListArea = new JTextArea(10, 20);
//panel4
	private JLabel SuggestedPartnersLabel = new JLabel("Suggested Partners ----->");
	private JTextArea SuggestedPartnersArea = new JTextArea(10, 20);
//parent panel
	private JButton BackButton = new JButton("Back to Search Screen");
	
	
	private Registry registry;
	private ArrayList<String> suspectphonelist;
	private ArrayList<Suspect> suspectpartnerlist;
	private ArrayList<Suspect> suspectsuggestedpartnerslist;
	
	public SuspectPageFrame(Registry reg, Suspect suspect) {
		//class attributes initialization
		registry = reg;
		suspectphonelist = suspect.getPhoneList();
		suspectpartnerlist = suspect.getPartnersList();		
		suspectsuggestedpartnerslist = suspect.SuggestedSuspects();
		//sorting with build-in method
		Collections.sort(suspectpartnerlist);
		Collections.sort(suspectsuggestedpartnerslist);
		
	//creating button listeners
		//SMS
		ButtonListener_SMS SMS_listener = new ButtonListener_SMS();
		FindSMSButton.addActionListener(SMS_listener);
		//Back
		ButtonListener_Back back_listener = new ButtonListener_Back();
		BackButton.addActionListener(back_listener);
		
		//field values initialization		
		SuspectNameField.setText(suspect.getName());
		SuspectNameField.setEditable(false);
		SuspectCodeNameField.setText(suspect.getCodeName());
		SuspectCodeNameField.setEditable(false);
		for(String phone: this.suspectphonelist)
			SuspectPhoneListArea.append(phone + "\n");
		SuspectPhoneListArea.setEditable(false);
		this.fillAreaField(suspectpartnerlist, SuspectPartnersListArea);
		this.fillAreaField(suspectsuggestedpartnerslist, SuggestedPartnersArea);
		
		panel1.add(SuspectNameField);
		panel1.add(SuspectCodeNameField);
		panel1.add(SuspectPhoneListArea);
		
		panel2.add(CommunicationNumberField);
		panel2.add(MessagesFieldArea);
		panel2.add(FindSMSButton);
		
		panel3.add(PartnersLabel);
		panel3.add(SuspectPartnersListArea);
		
		panel4.add(SuggestedPartnersLabel);
		panel4.add(SuggestedPartnersArea);
		
		parent_Panel.add(panel1);
		parent_Panel.add(panel2);
		parent_Panel.add(panel3);
		parent_Panel.add(panel4);
		parent_Panel.add(BackButton);
		
		
		//default window operations
		this.setContentPane(parent_Panel);
		this.setSize(490, 700);
		this.setTitle("Suspect Page");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	
	//method for filling area field given a list of suspects
	private void fillAreaField(ArrayList<Suspect> list, JTextArea area) {
		for(Suspect curr_suspect: list) {
			String curr_suspect_name = curr_suspect.getName();
			String curr_suspect_codename = curr_suspect.getCodeName();
			area.append(curr_suspect_name + ", " + curr_suspect_codename + "\n");
		}
		area.setEditable(false);
	}
	
	
//ActionListener classes
	class ButtonListener_SMS implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			MessagesFieldArea.setText("");
			
			String CommunicationNumberText = CommunicationNumberField.getText();
			
			for(String phone: suspectphonelist) {
				ArrayList<SMS> messagesBetween = registry.getMessagesBetween(phone, CommunicationNumberText);
				for(SMS sms: messagesBetween) {
					MessagesFieldArea.append(sms.getMessageContent() + "\n");
				}
			}
		}
		
	}
	
	class ButtonListener_Back implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			thisFrame.dispose();
			new FindSuspectFrame(registry);
		}
		
	}
	
}
