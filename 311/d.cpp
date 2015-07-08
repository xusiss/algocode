    // #includes {{{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
	#include<assert.h>
	#include<stdarg.h>
	#include<time.h>
	#include<limits.h>
	#include<ctype.h>
	#include<string>
	#include<map>
	#include<set>
	#include<queue>
	#include<algorithm>
	#include<vector>
	#include<iostream>
	#include<sstream>
	using namespace std;
	// }}}
	// #defines {{{
	#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
	#define SZ(x) ((int)(x).size())
	#define ALL(x) (x).begin(),(x).end()
	#define REP(i,n) for(int i=0;i<(n);i++)
	#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
	#define PER(i,n) for(int i=(n)-1;i>=0;i--)
	#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
	#define RI(x) scanf("%d",&x)
	#define DRI(x) int x;RI(x)
	#define RII(x,y) scanf("%d%d",&x,&y)
	#define DRII(x,y) int x,y;RII(x,y)
	#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
	#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
	#define RS(x) scanf("%s",x)
	#define PI(x) printf("%d\n",x)
	#define PIS(x) printf("%d ",x)
	#define CASET int ___T,cas=1;scanf("%d",&___T);while(___T--)
	#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
	#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
	#define MP make_pair
	#define PB push_back
	#define MS0(x) memset(x,0,sizeof(x))
	#define MS1(x) memset(x,-1,sizeof(x))

	#define F first
	#define S second
	typedef pair<int,int> PII;
	typedef long long LL;
	typedef unsigned long long ULL;
	// }}}
long long n,m;
vector <int> e[123456];
vector <int> node;
int vist[123456];
bool a=false;
bool b=false;
long long l,r;
void dfs(int p,int k,int c){
	if (vist[p]==-k) {b=true;return;}
	if (vist[p]==k) return;
	vist[p]=k;
	if (k==1) l++; else r++;
	if (c>2) a=true;
	for(int i=0;i<e[p].size();i++){
		dfs(e[p][i],-k,c+1);
	}
}
main(){
	RII(n,m);
	if (m==0) {
		long long ans=n*(n-1)*(n-2)/2/3;
		cout<<3<<" "<<ans<<endl;
		return 0;
	}
	REP(i,m){
		DRII(x,y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	long long cnt=0;
	long long ans=0;
	REP(i,n){
		if (vist[i]==0 && e[i].size()!=0){
			int c=1;
			a=false;
			l=r=0;
			if(e[i].size()>1) a=true;
			dfs(i,1,c);
			if(a==false) cnt++;
			else{
				ans+=l*(l-1)/2;
				ans+=r*(r-1)/2;
			}
		}

	}
	if (b) cout<<0<<" "<<1;else
	if (ans!=0) cout<<1<<" "<<ans;
	else cout<<2<<" "<<cnt*(n-2);
}
