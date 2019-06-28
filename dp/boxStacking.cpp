#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main() {
	int t;
	cin>>t;
	while(t--) {
	   int n;
	 cin>>n;

 	  int A[1000],B[1000],C[10001];
	 for(int i=0;i<n;i++)
	 {
		  int a,b,c;
		  cin>>a>>b>>c;
		  A[i]=a;
		  B[i]=b;
		  C[i]=c;
	 }
	 cout<<maxHeight(A,B,C,n)<<endl;
  }
}

class Box {
  public:
  int h, w, l;
};

bool compare(Box b1, Box b2) {
  return(b1.w*b1.l > b2.w*b2.l);
}

int maxHeight(int height[],int width[],int length[],int n)
{
    /* This problem can be reduced to a variation of LIS
    we generate all possible rotations of a box, and store them in an array
    we sort this array on basis of base area in decreasing order since we want base area larger at bottom
    after that we simply apply LIS, for ith box in our stacking order, we can check for all boxes that can be at its bottom
    and take the best option as we do in LIS
    */

    // generate rotations
    Box rotations[3*n];
    int k = 0;
    for(int i = 0; i < n; i++) {
      rotations[k].h = height[i];
      rotations[k].w = min(width[i], length[i]);
      rotations[k].l = max(width[i], length[i]);
      k++;

      rotations[k].h = width[i];
      rotations[k].w = min(height[i], length[i]);
      rotations[k].l = max(height[i], length[i]);
      k++;

      rotations[k].h = length[i];
      rotations[k].w = min(height[i], width[i]);
      rotations[k].l = max(height[i], width[i]);
      k++;
    }

    // sort on decreasing base area
    sort(rotations, rotations + k, compare);

    // for(int i = 0; i < 3*n; i++) {
    //   cout << rotations[i].l << " " << rotations[i].w << " " << rotations[i].h << " " << (rotations[i].l*rotations[i].w) << endl;
    // }

    n = 3*n;

    // use concept of LIS now
    int lis[n];

    // initialization - height of each box can be the first box in stack
    for(int i = 0; i < n; i++) {
      lis[i] = rotations[i].h;
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
        // box base dimensions should be smaller than current box
        if(rotations[i].w < rotations[j].w && rotations[i].l < rotations[j].l) {
          // if placing on top of jth box is better, consider This
          if(lis[j] + rotations[i].h > lis[i]) {
            lis[i] = lis[j] + rotations[i].h;
          }
        }
      }
    }

    int best = -1;
    for(int i = 0; i < n; i++) {
      best = max(best, lis[i]);
    }

    return best;
}
