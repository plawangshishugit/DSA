class Solution {
public:
    const int MAX = 1e5 + 1;

    // Sieve of Eratosthenes
    vector<bool> sieve(int maxVal) {
        vector<bool> is_prime(maxVal + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= maxVal; j += i)
                    is_prime[j] = false;
            }
        }
        return is_prime;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 1: Precompute all primes
        vector<bool> is_prime = sieve(maxVal);

        // Step 2: Build map: prime → indices i such that nums[i] % prime == 0
        unordered_map<int, vector<int>> prime_to_indices;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int d = 1; d * d <= x; ++d) {
                if (x % d == 0) {
                    if (is_prime[d]) prime_to_indices[d].push_back(i);
                    int q = x / d;
                    if (q != d && is_prime[q]) prime_to_indices[q].push_back(i);
                }
            }
        }

        // Step 3: BFS
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);

        unordered_set<int> used_primes;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front(); q.pop();

                if (i == n - 1) return steps;

                // Adjacent steps
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // Prime teleport
                int val = nums[i];
                if (is_prime[val] && used_primes.find(val) == used_primes.end()) {
                    for (int j : prime_to_indices[val]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                    used_primes.insert(val);
                }
            }
            steps++;
        }

        return -1;
    }
};