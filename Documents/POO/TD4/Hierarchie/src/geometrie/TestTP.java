package geometrie;

public class TestTP {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Point p1 = new Point(5.1, 2.0, "A");
		Point p2 = new Point(6.1, 2.0, "B");
		Point p3 = new Point (1.1,6.0, "B");
		Point p4 = new Point (3.8,7.5, "C");

		Quadrilatere quad=new Quadrilatere(p1,p2,p3,p4);
		
		Rectangle rect=new Rectangle();
		
		System.out.println("Périmetre du quadrilatère = " + quad.getPerimetre());
		System.out.println("Périmetre du rect = " + rect.getPerimetre());
		
		
		//System.out.println(p1 + "  " + p2 );
		//System.out.println("Distance " + p1.distance(p2) );
		
		
		//Quadrilatere quad=new Quadrilatere();
		//System.out.println(quad);
		
		//System.out.println(quad2);
	}

}
