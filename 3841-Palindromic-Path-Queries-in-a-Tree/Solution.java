class Solution
{
    private int n, LOG, timer;
    private java.util.List<Integer>[] graph;
    private int[][] up;
    private int[] depth,tin,tout,label,seg,lazy;

    private void dfs(int root)
    {
        java.util.ArrayDeque<int[]> st=new java.util.ArrayDeque<>();
        st.push(new int[]{root,root,0});
        while(!st.isEmpty())
        {
            int[] f=st.pop(); int u=f[0],p=f[1],state=f[2];
            if(state==0)
            {
                tin[u]=timer++; up[0][u]=p;
                for(int j=1;j<LOG;j++) up[j][u]=up[j-1][up[j-1][u]];
                st.push(new int[]{u,p,1});
                java.util.List<Integer> list=graph[u];
                for(int i=list.size()-1;i>=0;i--){ int v=list.get(i); if(v==p) continue; depth[v]=depth[u]+1; st.push(new int[]{v,u,0}); }
            }
            else tout[u]=timer-1;
        }
    }
    private int lca(int a,int b)
    {
        if(depth[a]<depth[b]){int t=a;a=b;b=t;}
        int diff=depth[a]-depth[b];
        for(int j=0;j<LOG;j++) if((diff&(1<<j))!=0) a=up[j][a];
        if(a==b) return a;
        for(int j=LOG-1;j>=0;j--) if(up[j][a]!=up[j][b]){a=up[j][a];b=up[j][b];}
        return up[0][a];
    }
    private void build(int node,int l,int r,int[] base){ if(l==r){seg[node]=base[l];return;} int mid=(l+r)>>>1; build(node<<1,l,mid,base); build(node<<1|1,mid+1,r,base); }
    private void apply(int node,int val){seg[node]^=val;lazy[node]^=val;}
    private void push(int node){if(lazy[node]!=0){apply(node<<1,lazy[node]);apply(node<<1|1,lazy[node]);lazy[node]=0;}}
    private void update(int node,int l,int r,int ql,int qr,int val){if(qr<l||r<ql)return;if(ql<=l&&r<=qr){apply(node,val);return;}push(node);int mid=(l+r)>>>1;update(node<<1,l,mid,ql,qr,val);update(node<<1|1,mid+1,r,ql,qr,val);}
    private int point(int node,int l,int r,int idx){if(l==r)return seg[node];push(node);int mid=(l+r)>>>1;return idx<=mid?point(node<<1,l,mid,idx):point(node<<1|1,mid+1,r,idx);}

    public boolean[] palindromePath(int n,int[][] edges,String s,String[] queries)
    {
        this.n=n;LOG=1;while((1<<LOG)<=n)LOG++;
        graph=new java.util.ArrayList[n];for(int i=0;i<n;i++)graph[i]=new java.util.ArrayList<>();
        for(int[]e:edges){graph[e[0]].add(e[1]);graph[e[1]].add(e[0]);}
        up=new int[LOG][n];depth=new int[n];tin=new int[n];tout=new int[n];timer=0;dfs(0);
        label=new int[n];for(int i=0;i<n;i++)label[i]=1<<(s.charAt(i)-'a');
        int[] order=new int[n],rootXor=new int[n],base=new int[n];
        for(int i=0;i<n;i++)order[tin[i]]=i;
        for(int pos=0;pos<n;pos++){int u=order[pos];rootXor[u]=(u==0?label[u]:rootXor[up[0][u]]^label[u]);}
        for(int i=0;i<n;i++)base[tin[i]]=rootXor[i];
        seg=new int[4*n+5];lazy=new int[4*n+5];build(1,0,n-1,base);
        java.util.ArrayList<Boolean> out=new java.util.ArrayList<>();
        for(String q:queries)
        {
            String[] p=q.split(" ");int u=Integer.parseInt(p[1]);
            if(p[0].equals("update")){int nm=1<<(p[2].charAt(0)-'a');int d=label[u]^nm;if(d!=0){update(1,0,n-1,tin[u],tout[u],d);label[u]=nm;}}
            else{int v=Integer.parseInt(p[2]);int w=lca(u,v);int mask=point(1,0,n-1,tin[u])^point(1,0,n-1,tin[v])^label[w];out.add(mask==0||(mask&(mask-1))==0);}
        }
        boolean[] ans=new boolean[out.size()];for(int i=0;i<out.size();i++)ans[i]=out.get(i);return ans;
    }
}
