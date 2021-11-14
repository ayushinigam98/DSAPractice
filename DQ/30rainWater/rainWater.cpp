#include <iostream>

using namespace std;

int maxWaterStored(int n, int height[])
{
  int maxLeft = height[0];
  int maxRight = height[n-1];
  int left = 1;
  int right = n-2;

  int water = 0;

  while(left <= right)
  {
      if(height[left] > maxLeft)
      {
          maxLeft = height[left];
          left++;
      }
      else if(maxLeft < maxRight)
      {
          water = water + maxLeft - height[left];
          left++;
      }
      else if(height[right] > maxRight)
      {
          maxRight = height[right];
          right--;
      }
      else
      {
          water = water + maxRight - height[right];
          right--;
      }
  }

  return water;
}

int main()
{
    int n;
    cin>>n;
    int height[n];

    for(int i=0; i<n; i++)
    {
        cin>>height[i];
    }

    cout<<maxWaterStored(n, height);
    
    return 0;
}