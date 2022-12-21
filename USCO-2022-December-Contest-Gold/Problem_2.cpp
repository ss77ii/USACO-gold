#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2000;

int N;
int h[MAX_N + 1];

// Array to store the number of visible mountains for each mountain i
int visible[MAX_N + 1];

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> h[i];
  }

  // Initialize the visible array
  for (int i = 1; i <= N; i++) {
    visible[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (h[j] > h[i]) {
        visible[i]++;
      } else {
        break;
      }
    }
    for (int j = i + 1; j <= N; j++) {
      if (h[j] > h[i]) {
        visible[i]++;
      } else {
        break;
      }
    }
  }

  int Q;
  cin >> Q;

  long long total_pairs = 0;
  for (int i = 1; i <= Q; i++) {
    int x, y;
    cin >> x >> y;

    // Update the height of mountain x
    h[x] += y;

    // Update the visible array for mountain x
    for (int j = x - 1; j >= 1; j--) {
      if (h[j] > h[x]) {
        visible[x]++;
      } else {
        break;
      }
    }
    for (int j = x + 1; j <= N; j++) {
      if (h[j] > h[x]) {
        visible[x]++;
      } else {
        break;
      }
    }

    // Update the visible array for the affected mountains
    for (int j = x - 1; j >= 1; j--) {
      if (h[j] <= h[x]) {
        visible[j]--;
      } else {
        break;
      }
    }
    for (int j = x + 1; j <= N; j++) {
      if (h[j] <= h[x]) {
        visible[j]--;
      } else {
        break;
      }
    }

    // Calculate the total number of visible pairs
    for (int j = 1; j <= N; j++) {
      total_pairs += visible[j];
    }
    cout << total_pairs << endl;
  }

  return 0;
}
