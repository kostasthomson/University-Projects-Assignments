import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.ArrayList;
import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JTextField;

import edu.uci.ics.jung.algorithms.layout.CircleLayout;
import edu.uci.ics.jung.algorithms.shortestpath.DistanceStatistics;
import edu.uci.ics.jung.graph.UndirectedGraph;
import edu.uci.ics.jung.graph.UndirectedSparseGraph;
import edu.uci.ics.jung.visualization.VisualizationViewer;
import edu.uci.ics.jung.visualization.decorators.ToStringLabeller;

public class SuspectsNetworkFrame extends JFrame{
	private JTextField diameterField = new JTextField();
	
	
	public SuspectsNetworkFrame(Registry registry) {	
		ArrayList<Suspect> allSuspects = registry.getSuspectList();
		
	//creating undirected graph
		UndirectedGraph<String, String> graph = new UndirectedSparseGraph<>();
	//set graph's vertices by suspect's code name
		for(Suspect suspect: allSuspects) {
			graph.addVertex(suspect.getCodeName());
		}
	//set graph's edges by the relation of possible partners
		int i = 1;
		for(Suspect suspect: allSuspects) {
			ArrayList<Suspect> curr_suspectpartners = suspect.getPartnersList();
			for(Suspect partner: curr_suspectpartners) {
				graph.addEdge("Edge"+i, suspect.getCodeName(), partner.getCodeName());
				i++;
			}
		}
		
	//creating image of the graph
		CircleLayout<String, String> layout = new CircleLayout<>(graph);
		Dimension dimension = new Dimension(300, 300);
		VisualizationViewer<String, String> graphImage = new VisualizationViewer<>(layout, dimension);
		graphImage.getRenderContext().setVertexLabelTransformer(new ToStringLabeller<String>());
		
		Double diameter = DistanceStatistics.diameter(graph);
		String diameterText = diameter.toString();
		diameterField.setText("Diameter = " + diameterText);
		diameterField.setBackground(Color.WHITE);
		diameterField.setEditable(false);
		
		this.setLayout(new BorderLayout());
		this.getContentPane().add(graphImage);
		this.getContentPane().add(diameterField, BorderLayout.SOUTH);
		this.setTitle("Suspects Network");
		this.setSize(400, 400);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
	
}
