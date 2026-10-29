class Solution
{
    int n, LOG, timer;
    vector<vector<int>> g, up;
    vector<int> depth, tin, tout, label, seg, lazy;

    void dfs(int root)
    {
        vector<array<int,3>> st{{root, root, 0}};
        while (!st.empty())
        {
            auto [u,p,state] = st.back(); st.pop_back();
            if (state == 0)
            {
                tin[u] = timer++;
                up[0][u] = p;
                for (int j=1;j<LOG;j++) up[j][u] = up[j-1][up[j-1][u]];
                st.push_back({u,p,1});
                for (int i=(int)g[u].size()-1;i>=0;i--)
                {
                    int v=g[u][i]; if (v==p) continue;
                    depth[v]=depth[u]+1; st.push_back({v,u,0});
                }
            }
            else tout[u]=timer-1;
        }
    }

    int lca(int a,int b)
    {
        if (depth[a] < depth[b]) swap(a,b);
        int diff=depth[a]-depth[b];
        for (int j=0;j<LOG;j++) if (diff&(1<<j)) a=up[j][a];
        if (a==b) return a;
        for (int j=LOG-1;j>=0;j--) if (up[j][a]!=up[j][b]) { a=up[j][a]; b=up[j][b]; }
        return up[0][a];
    }

    void build(int node,int l,int r,const vector<int>& base)
    {
        if (l==r) { seg[node]=base[l]; return; }
        int mid=(l+r)/2; build(node*2,l,mid,base); build(node*2+1,mid+1,r,base);
    }
    void apply(int node,int val){ seg[node]^=val; lazy[node]^=val; }
    void push(int node){ if(lazy[node]){ apply(node*2,lazy[node]); apply(node*2+1,lazy[node]); lazy[node]=0; } }
    void update(int node,int l,int r,int ql,int qr,int val)
    {
        if(qr<l||r<ql) return;
        if(ql<=l&&r<=qr){ apply(node,val); return; }
        push(node); int mid=(l+r)/2;
        update(node*2,l,mid,ql,qr,val); update(node*2+1,mid+1,r,ql,qr,val);
    }
    int point(int node,int l,int r,int idx)
    {
        if(l==r) return seg[node];
        push(node); int mid=(l+r)/2;
        return idx<=mid ? point(node*2,l,mid,idx) : point(node*2+1,mid+1,r,idx);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries)
    {
        this->n=n; LOG=1; while((1<<LOG)<=n) LOG++;
        g.assign(n,{}); for(auto&e:edges){g[e[0]].push_back(e[1]);g[e[1]].push_back(e[0]);}
        up.assign(LOG,vector<int>(n)); depth.assign(n,0); tin.resize(n); tout.resize(n); timer=0; dfs(0);
        label.resize(n); for(int i=0;i<n;i++) label[i]=1<<(s[i]-'a');
        vector<int> order(n),rootXor(n),base(n);
        for(int i=0;i<n;i++) order[tin[i]]=i;
        for(int pos=0;pos<n;pos++){ int u=order[pos]; rootXor[u]=(u==0?label[u]:rootXor[up[0][u]]^label[u]); }
        for(int i=0;i<n;i++) base[tin[i]]=rootXor[i];
        seg.assign(4*n+5,0); lazy.assign(4*n+5,0); build(1,0,n-1,base);
        vector<bool> ans;
        for(const string&q:queries)
        {
            stringstream ss(q); string type; int u; ss>>type>>u;
            if(type=="update")
            {
                char c; ss>>c; int nm=1<<(c-'a'); int delta=label[u]^nm;
                if(delta){ update(1,0,n-1,tin[u],tout[u],delta); label[u]=nm; }
            }
            else
            {
                int v; ss>>v; int w=lca(u,v);
                int mask=point(1,0,n-1,tin[u])^point(1,0,n-1,tin[v])^label[w];
                ans.push_back(mask==0 || (mask&(mask-1))==0);
            }
        }
        return ans;
    }
};
