import java.util.Scanner;
import java.util.LinkedList;
import java.util.ArrayList;

public class sjtuOJ1566{
	private static class Node{
		public int x, w;
		public Node(int xx, int ww){
			x = xx; w = ww;
		}
	}
	private static class Edge{
		int u, v, w;
		public Edge(int uu, int vv, int ww){
			u = uu; v = vv; w = ww;
		}
	}
	private static ArrayList<LinkedList<Node>> G;
	private static ArrayList<Edge> E;
	private static void init_G(int N, Scanner scan){
		G = new ArrayList<LinkedList<Node>>();
		E = new ArrayList<Edge>();
		for (int i = 0; i < N; i++) G.add(new LinkedList<Node>());
		char[] C; int k, u, v, w;
		for (int i = 0; i < N - 1; i++){
			C = scan.next().toCharArray();
			v = (byte)(C[0]) - (byte)'A';
			k = scan.nextInt();
			for (int j = 0; j < k; j++){
				C = scan.next().toCharArray();
				u = (byte)(C[0]) - (byte)'A';
				w = scan.nextInt();
				G.get(u).add(new Node(v, w));
				G.get(v).add(new Node(u, w));
				E.add(new Edge(v, u, w));
			}
		}
		E.sort((e1, e2) -> Integer.compare(e1.w, e2.w));
	}
	private static int[] root;
	private static void init_root(int N){
		root = new int[N];
		for (int i = 0; i < N; i++) root[i] = i;
	}
	private static int FindRoot(int a){
		if (root[a] == a) return a;
		root[a] = FindRoot(root[a]);
		return (root[a]);
	}
	private static void Unite(int a, int b){
		int ra = FindRoot(a), rb = FindRoot(b);
		root[ra] = rb; return;
	}
	private static boolean isSame(int a, int b){
		int ra = FindRoot(a), rb = FindRoot(b);
		return (ra == rb);
	}
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		init_G(N, scan);
		scan.close();
		init_root(N);
		int Ans = 0;
		for (Edge e:E){
			if (!isSame(e.u, e.v)){
				Ans = Ans + e.w;
				Unite(e.u, e.v);
			}
		}
		System.out.println(Ans);
	}
}