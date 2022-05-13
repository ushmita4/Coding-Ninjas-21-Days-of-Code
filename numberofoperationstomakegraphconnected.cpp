int makeGraphConnected(int n, vector < pair < int, int > > edges, int m) 
{
      if (m < n - 1) 
      {
        return -1;
      }

      vector < int > adj[n + 1];
      for (int i = 0; i < m; i++) {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
      }

      vector < bool > vis(n + 1, false);
      int ctr = 0;

      for (int i = 1; i <= n; i++) 
      {
        if (vis[i] == false) 
        {
          queue < int > q;
          vis[i] = true;
          q.push(i);
          ctr++;

          while (!q.empty()) 
          {
            int u = q.front();
            q.pop();
            for (int v: adj[u]) 
            {
              if (vis[v] == false) 
              {
                vis[v] = true;
                q.push(v);
              }
            }
          }
        }
      }

      int ans = ctr - 1;

      return ans;
}
