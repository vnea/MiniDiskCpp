package com.upmc.utils;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import com.upmc.geom.Point2D;

public class FilePointsLoader {
	final private static int NB_POINTS = 256;
	
	public List<Point2D> loadPoints(final String parentPath, final String childPath) {
		List<Point2D> list = null;
		Scanner scanner = null;
		
		try {
			scanner = new Scanner(new File(parentPath, childPath));
			list = new ArrayList<Point2D>(NB_POINTS);
			
			while (scanner.hasNextInt()) {        
		        list.add(new Point2D(scanner.nextInt(), scanner.nextInt()));
			    
			}
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		finally {
			scanner.close();
		}

		
		return list;
	}

}
