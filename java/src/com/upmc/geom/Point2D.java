package com.upmc.geom;

public class Point2D {
	public double x;
	public double y;
	
	public Point2D(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double distanceSquaredTo(final Point2D p) {
		final double DX = x - p.x;
		final double DY = y - p.y;
		
		return DX * DX + DY * DY;
	}
	
	public double distanceTo(final Point2D p) {
		return Math.sqrt(distanceSquaredTo(p));
	}
	
	public static boolean areColinear(final Point2D p1, final Point2D p2, final Point2D p3) {
		return Math.abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) == 0.0;
	}
	
	@Override
	public String toString() {
		return "X: " + x + ", Y: " + y; 
	}
}
