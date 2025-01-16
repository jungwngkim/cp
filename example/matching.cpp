bool dfs(int u)
{
    for(int v : adj[u])
    {
        if(!visited[v] && !mt[v])
        {
            visited[v] = true;
            mt[v] = u;
            return true;
        }
    }

    for(int v : adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            
            if(dfs(mt[v]))
            {
                mt[v] = u;
                return true;
            }
        }
    }

    return false;
}