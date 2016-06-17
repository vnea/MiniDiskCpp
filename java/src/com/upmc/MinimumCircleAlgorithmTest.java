package com.upmc;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

import com.upmc.alogirthms.AlgorithmMinCircle;
import com.upmc.geom.Circle2D;
import com.upmc.geom.Point2D;
import com.upmc.utils.FilePointsLoader;

public class MinimumCircleAlgorithmTest {
	FilePointsLoader FPL = new FilePointsLoader();
	AlgorithmMinCircle AMC = new AlgorithmMinCircle();
	
	private final int NB_FILES = 1664;
	private final String SAMPLES_PATH = "samples";
	private final String PATTERN = "test-";
	private final String EXT = ".points";
	
	private final String RESULTS_PATH = "results";
	
	private final String RESULTS_NAIVE_RADIUS = "res_naive_radius.txt";
	private final String RESULTS_NAIVE_TIME = "res_naive_time.txt";

	private final String RESULTS_WELZL_RADIUS = "res_welzl_radius.txt";
	private final String RESULTS_WELZL_TIME = "res_welzl_time.txt";
	
	private final String RESULTS_NAIVE_VS_WELZL_TIME = "res_naive_vs_welzl_time.txt";
	
	public void testNaiveAlgorithm() throws IOException {
		long totalTimeElapsed = 0;
		StringBuilder sbRadius = new StringBuilder();
		StringBuilder sbTime = new StringBuilder();

		
		for (int i = 1; i <= NB_FILES; ++i) {
			// Load points
			final String CHILD_PATH = PATTERN + Integer.toString(i) + EXT;
			final List<Point2D> POINTS = FPL.loadPoints(SAMPLES_PATH, CHILD_PATH);

			// Measure time in ns
			final long START = System.nanoTime();
				final Circle2D MIN_CIRCLE_NAIVE = AMC.naiveAlgorithm(POINTS);
			final long TIME_ELAPSED = System.nanoTime() - START;
			
			totalTimeElapsed += TIME_ELAPSED;
			//System.out.println(i);
			
			sbRadius.append(Integer.toString(i) + " " + MIN_CIRCLE_NAIVE.radius + "\n");
			sbTime.append(Integer.toString(i) + " " + TIME_ELAPSED + "\n");
		}
		
        File resultFileRadius = new File(RESULTS_PATH, RESULTS_NAIVE_RADIUS);
        BufferedWriter writerRadius = new BufferedWriter(new FileWriter(resultFileRadius));
        writerRadius.write(sbRadius.toString());
        writerRadius.close();
        
        File resultFileTime = new File(RESULTS_PATH, RESULTS_NAIVE_TIME);
        BufferedWriter writerTime = new BufferedWriter(new FileWriter(resultFileTime));
        writerTime.write(sbTime.toString());
        writerTime.close();
		
		
		System.out.println("Total time elapsed Naive : " + totalTimeElapsed + " ns.");
	}
	
	public void testWelzlAlgorithm() throws IOException {
		long totalTimeElapsed = 0;
        StringBuilder sbRadius = new StringBuilder();
        StringBuilder sbTime = new StringBuilder();

        
		for (int i = 1; i <= NB_FILES; ++i) {
			// Load points
			final String CHILD_PATH = PATTERN + Integer.toString(i) + EXT;
			List<Point2D> points = FPL.loadPoints(SAMPLES_PATH, CHILD_PATH);

			// Measure time in ns
			final long START = System.nanoTime();
				final Circle2D MIN_CIRCLE_WELZL = AMC.minidisk(points);
			final long TIME_ELAPSED = System.nanoTime() - START;
			
			totalTimeElapsed += TIME_ELAPSED;
			sbRadius.append(Integer.toString(i) + " " + MIN_CIRCLE_WELZL.radius + "\n");
			sbTime.append(Integer.toString(i) + " " + TIME_ELAPSED + "\n");
		}
		
        File resultFileRadius = new File(RESULTS_PATH, RESULTS_WELZL_RADIUS);
        BufferedWriter writerRadius = new BufferedWriter(new FileWriter(resultFileRadius));
        writerRadius.write(sbRadius.toString());
        writerRadius.close();
        
        File resultFileTime = new File(RESULTS_PATH, RESULTS_WELZL_TIME);
        BufferedWriter writerTime = new BufferedWriter(new FileWriter(resultFileTime));
        writerTime.write(sbTime.toString());
        writerTime.close();
		
		System.out.println("Total time elapsed Welzl : " + totalTimeElapsed + " ns.");
	}
	
	public void testNaiveVsWelzlAlgorithm() throws IOException {
        StringBuilder sb = new StringBuilder();
        
		for (int i = 1; i <= NB_FILES; ++i) {
			// Load points
			final String CHILD_PATH = PATTERN + Integer.toString(i) + EXT;
			List<Point2D> points = FPL.loadPoints(SAMPLES_PATH, CHILD_PATH);

			// Naive
			final long START_NAIVE = System.nanoTime();
				AMC.naiveAlgorithm(points);
			final long TIME_ELAPSED_NAIVE = System.nanoTime() - START_NAIVE;
			
			// Welzl
			final long START_WELZL = System.nanoTime();
				AMC.minidisk(points);
			final long TIME_ELAPSED_WELZL = System.nanoTime() - START_WELZL;
			
			final int GAIN_PERCENTAGE = (int) ((TIME_ELAPSED_NAIVE - TIME_ELAPSED_WELZL) / TIME_ELAPSED_WELZL) * 100;
			
			
			sb.append(Integer.toString(i) + " " + GAIN_PERCENTAGE + "\n");
			System.out.println(i);
		}
		
        File result = new File(RESULTS_PATH, RESULTS_NAIVE_VS_WELZL_TIME);
        BufferedWriter writer = new BufferedWriter(new FileWriter(result));
        writer.write(sb.toString());
        writer.close();
	}
	
	public static void main(String [] args) {
		MinimumCircleAlgorithmTest mat = new MinimumCircleAlgorithmTest();
		try {
			//mat.testWelzlAlgorithm();
			//mat.testNaiveAlgorithm();
			mat.testNaiveVsWelzlAlgorithm();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}
