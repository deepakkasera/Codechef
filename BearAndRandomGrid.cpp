#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testCases,l,n;
	string s;
	cin >> testCases;
	while(testCases--){
		cin >> l >> n;
		cin >> s;
		std::vector<std::vector<char> > v(n,std::vector<char>(n));
		int cntDot=0,cntHash=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> v[i][j];
				if(v[i][j] == '.') cntDot++;
				else cntHash++;
			}
		}
		int ans=0;
		if(cntHash==0){
			int x;
			std::map<int, int> horizontal;
			std::map<int, int> vertical;
			int rightIndex=0,downIndex=0;
			for(int i=0;i<l;i++){
				if(s[i] == 'R'){
					rightIndex++;
					if(!horizontal[rightIndex])
						horizontal[rightIndex]=i+1;
				}
				if(s[i] == 'L'){
					rightIndex--;
					if(!horizontal[rightIndex])
						horizontal[rightIndex]=i+1;
				}
				if(s[i] == 'U'){
					downIndex--;
					if(!vertical[downIndex])
						vertical[downIndex]=i+1;
				}
				if(s[i] == 'D'){		
					downIndex++;
					if(!vertical[downIndex])
						vertical[downIndex]=i+1;
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					int left=-j-1,right=n-j,up=-i-1,down=n-i;
					left = horizontal[left];
					if(!left) left = l+1;
					right = horizontal[right];
					if(!right) right = l+1;
					down = vertical[down];
					if(!down) down = l+1;
					up = vertical[up];
					if(!up) up = l+1;
				    x = min(min(min(left,right),up),down);
				    x-=1;
				    ans^=x;
				}
			}
			cout << ans << endl;			
		}
		else{
			for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int cnt=0; 
				if(v[i][j] == '.'){
					int k=0,x=i,y=j;
					while(k<l && (x<n && x>=0) && (y>=0 && y<n)){
						if(s[k]=='D' && x+1<n && v[x+1][y]=='.') cnt++,x++;
						else if (s[k]=='U' && x-1>=0 && v[x-1][y]=='.') cnt++,x--;
						else if (s[k]=='R' && y+1<n && v[x][y+1]=='.') cnt++,y++;
						else if (s[k]=='L' && y-1>=0 && v[x][y-1]=='.') cnt++,y--;
						else break;
						k++;
					}
				}
				ans^=cnt;
			}
		}
		cout << ans << endl;
	}
}
	return 0;
}