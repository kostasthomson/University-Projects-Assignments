import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class FindSuspectFrame extends JFrame{
	
	private JFrame thisFrame = this;
	private JPanel panel = new JPanel();
	private JTextField searchField = new JTextField("Please enter suspect's name");
	private JButton findButton = new JButton("Find");
	private JButton visualizeButton = new JButton("Visualize Network");
	private Registry registry;
	private ArrayList<Suspect> allSuspects = new ArrayList<>();
	
	
	public FindSuspectFrame(Registry reg) {
		
		registry = reg;
		allSuspects = reg.getSuspectList();

		FindButtonListener findListener = new FindButtonListener();
		findButton.addActionListener(findListener);
		
		VisualizeButtonListener visualizeListener = new VisualizeButtonListener();
		visualizeButton.addActionListener(visualizeListener);
		
		panel.add(searchField);
		panel.add(findButton);
		panel.add(visualizeButton);
		
		this.setContentPane(panel);
		this.setSize(300, 150);
		this.setTitle("Find Suspect");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class FindButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			Suspect SearchedSuspect = null;
			boolean found = false;
			String suspectFieldText = searchField.getText();
			
			for(Suspect suspect: allSuspects) {
				String suspectName = suspect.getName();
				if(suspectName.equals(suspectFieldText)) {
					SearchedSuspect = suspect;
					found = true;
					break;
				}
			}
			
			if(!found) {
				//Message
				JOptionPane.showMessageDialog(panel, "Suspect " + suspectFieldText + " Not Found");
			}else {
				//Must close this window
				//Suspect Page
				thisFrame.dispose();
				new SuspectPageFrame(registry, SearchedSuspect);
			}
			
		}
		
	}
	
	class VisualizeButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			new SuspectsNetworkFrame(registry);
		}
		
	}
	
}
