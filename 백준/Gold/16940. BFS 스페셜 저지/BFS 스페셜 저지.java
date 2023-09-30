import java.io.*;
import java.util.*;

public class Main{
    static int n;
    static ArrayList<Integer>[] graph;
    static int[] order;   // 주어진 순서 값을 저장하는 배열
    static int[] parent;  // 각 정점의 이전에 방문되는 부모 정정 저장 배열
    static boolean[] visited; // 각 정점의 방문 완료 여부 저장 배열
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        
        // ************** 그래프 초기화 ******************
        graph = new ArrayList[n+1];
        for(int i=1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        
        StringTokenizer st = null;
        for(int i=1; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            
            graph[u].add(v);
            graph[v].add(u);
        }
        // ************* 여기까지 그래프 생성 완료 ****************
        
        
        
        // ************* 주어진 탐색 순서를 저장 *********************
        order = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1; i <= n; i++){
            order[i] = Integer.parseInt(st.nextToken());
        }
        // ************* 주어진 탐색 순서 저장 완료 ******************
        
        
        
        // ************* BFS 탐색 시 사용할 큐 생성, 부모 정점 저장 및 방문 여부 저장 배열 생성 ****
        Queue<Integer> q = new LinkedList<>();
        parent = new int[n+1];
        visited = new boolean[n+1];
        
        q.offer(1);
        visited[1] = true;  // 1번 정점에서 시작하여 방문 완료 처리
        // ************* 큐, 배열 생성 완료 *********************
        
        
        
        // ************* BFS 탐색 시작하여 순서 알맞은지 보는 코드 *****************
        int idx = 2;
        
        // order의 1부터 n까지 모두 살펴야 한다.
        for(int i=1; i <= n; i++){
            // 다 살펴보지 않았는데 큐가 비었다면 불가능한 방법이다.
            if(q.isEmpty()){
                System.out.println(0);
                System.exit(0);
            }
            
            // 큐에서 뽑은 값이 현재 order에 맞지 않으면 불가한 방법이다.
            int c = q.poll();
            if(c != order[i]) {
                System.out.println(0);
                System.exit(0);
            }
            
            // 현재 정점과 인접한 정점을 Child라고 하고 그 수를 센 다음, 부모 정점으로 저장
            int cnt = 0;  // child의 개수를 저장하는 변수
            for(int child : graph[c]){
                if(!visited[child]){
                    parent[child] = c;
                    cnt++;
                }
            }
            
            // 현재 index부터 자식의 개수만큼 index를 검사하여 다음 탐색할 정점을 찾는다.
            for(int j=0; j < cnt; j++){
            
                // n을 넘어가거나 부모가 현재 정점이 아닌데 다음 순서에 있다면 불가한 경우
                if(j+idx > n || parent[order[j+idx]] != c){
                    System.out.println(0);
                    System.exit(0);
                }
                // 큐에 추가하고 방문 완료 처리한다.
                q.offer(order[j+idx]);
                visited[order[j+idx]] = true;
            }
            
            // 자식들 추가된 수만큼 더해 준다.
            idx += cnt;
        }
        
        System.out.println(1);
        br.close();
    }
}