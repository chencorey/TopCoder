// https://community.topcoder.com/stat?c=problem_statement&pm=14099
// This problem was used for: 
// Single Round Match 677 Round 1 - Division II, Level Two
// Note: this code was generated

public class FourStrings {
	public static int shortestLength(String a, String b, String c, String d){
		int min = f(f(f(a, b), c), d).length();
		min = Math.min(min, f(f(f(a, b), d), c).length());
		min = Math.min(min, f(f(f(a, c), b), d).length());
		min = Math.min(min, f(f(f(a, c), d), b).length());
		min = Math.min(min, f(f(f(a, d), b), c).length());
		min = Math.min(min, f(f(f(a, d), c), b).length());
		min = Math.min(min, f(f(f(b, a), c), d).length());
		min = Math.min(min, f(f(f(b, a), d), c).length());
		min = Math.min(min, f(f(f(b, c), a), d).length());
		min = Math.min(min, f(f(f(b, c), d), a).length());
		min = Math.min(min, f(f(f(b, d), a), c).length());
		min = Math.min(min, f(f(f(b, d), c), a).length());
		min = Math.min(min, f(f(f(c, a), b), d).length());
		min = Math.min(min, f(f(f(c, a), d), b).length());
		min = Math.min(min, f(f(f(c, b), a), d).length());
		min = Math.min(min, f(f(f(c, b), d), a).length());
		min = Math.min(min, f(f(f(c, d), a), b).length());
		min = Math.min(min, f(f(f(c, d), b), a).length());
		min = Math.min(min, f(f(f(d, a), b), c).length());
		min = Math.min(min, f(f(f(d, a), c), b).length());
		min = Math.min(min, f(f(f(d, b), a), c).length());
		min = Math.min(min, f(f(f(d, b), c), a).length());
		min = Math.min(min, f(f(f(d, c), a), b).length());
		min = Math.min(min, f(f(f(d, c), b), a).length());
		return min;
	}
	public static String f(String a, String b){		
		for(int i=b.length(); i>0; i--){
			if(a.endsWith(b.substring(0, i))){
				return a+b.substring(i);
			}
		}
		if(a.indexOf(b)!=-1){
			return a;
		}
		return a+b;
	}/*
	public static void main(String[] args){
		System.out.println(shortestLength("thereare", "arelots", "lotsof", "ofcases"));
	}*/
}
