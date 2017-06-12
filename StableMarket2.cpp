#include <bits/stdc++.h>
using namespace std;

struct node
{
	int left,right,index,k;
};

bool comp(node A,node B){
	if(A.left/BLOCK_SIZE != B.left/BLOCK_SIZE){
		return A.left/BLOCK_SIZE < B.left/BLOCK_SIZE
	}
	return A.right < B.right;
}

int N,Q,L,R,K;
int BLOCK_SIZE;
int answers[1000100], above[1000010], iden[1000010], cnt[1000010];
int arr[100010];
node queries[100010];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cin >> N >> Q;
		BLOCK_SIZE = static_cast<int>(sqrt(N));
		int j=0;
		cin >> arr[1];
		for(int i=2;i<=N;i++)
		{
			cin >> arr[i];
			if(arr[i] == arr[j-1])
				iden[i] = j;
			else{
				j++;
				iden[i] = j;
			}
		}	
		for(int i=0;i<Q;i++)
		{
			cin >> L >> R >> K;
			queries[i].left = L;
			queries[i].right = R;
			queries[i].index = i;
			queries[i].k = K;
		}

		sort(queries,queries+n,comp);

		int m_left = queries[0].left;
		int m_right = m_left-1;

		for(int i=0;i<Q;i++){
			int leftIndex = queries[i].left;
			int rightIndex = queries[i].right;
			while(m_right < rightIndex){
				m_right++;
				above[]
			}
			while(m_right > rightIndex){

			}
			while(m_left < leftIndex){

			}
			while(m_left > leftIndex){

			}
		}
	}
	return 0;
}