package com.upmc.alogirthms;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import com.upmc.geom.Circle2D;
import com.upmc.geom.Point2D;

public class AlgorithmMinCircle {
	private Random rand = new Random();
	
    public Circle2D naiveAlgorithm(final List<Point2D> points) {
    	// One point = nul circle
    	if (points.size() == 1) {
    		return new Circle2D(points.get(0).x, points.get(0).y, 0.0);
    	}
    	
    	Circle2D minimumCircle = null;
    	
    	// General case
		for (final Point2D p : points) {
			for (final Point2D q : points) {
				if (p != q) {
					minimumCircle = new Circle2D(p, q);
					if (minimumCircle.containsAllPoints(points)) {
						return minimumCircle;
					}
				}
			}
		}

		// Triangle case
		minimumCircle = new Circle2D(0.0, 0.0, Double.MAX_VALUE);
		for (final Point2D p : points) {
			for (final Point2D q : points) {
				for (final Point2D r : points) {
					if (p != q && q != r && p != r && !Point2D.areColinear(p, q, r)) {
						Circle2D circumscribedCircle = new Circle2D(p, q, r);
						if (circumscribedCircle.radius < minimumCircle.radius && circumscribedCircle.containsAllPoints(points)) {
							minimumCircle = circumscribedCircle;
						}
					}
				}
			}
		}

		return minimumCircle;
    }
    
    public Circle2D minidisk(final List<Point2D> points) {
		return bMinidisk(points, new ArrayList<Point2D>());
    }
	
    private Circle2D bMinidisk(final List<Point2D> points, final List<Point2D> boundary) {
    	Circle2D minimumCircle = null;
		
		if (boundary.size() == 3) {
			minimumCircle = new Circle2D(boundary.get(0), boundary.get(1), boundary.get(2));
		}
		else if (points.isEmpty() && boundary.size() == 2) {
			minimumCircle = new Circle2D(boundary.get(0), boundary.get(1));
		}
		else if (points.size() == 1 && boundary.isEmpty()) {
			minimumCircle = new Circle2D(points.get(0).x, points.get(0).y, 0.0);
		}
		else if (points.size() == 1 && boundary.size() == 1) {
			minimumCircle = new Circle2D(points.get(0), boundary.get(0));
		}
		else {
			Point2D p = points.remove(rand.nextInt(points.size()));
			minimumCircle = bMinidisk(points, boundary);
			
			if (minimumCircle != null && !minimumCircle.containsPoint(p)) {
				boundary.add(p);
				minimumCircle = bMinidisk(points, boundary);
				boundary.remove(p);
				points.add(p);
			}
		}
				
		return minimumCircle;
    }
}
