#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 200005
#define MOD 1000000007

long long int dp[MAX], ans;
long long int sum[MAX], square_sum[MAX];
int siz[MAX];

struct Node {
    int val;
    struct Node *next;
}*adj[MAX];

void dfs(int u, int p)
{
    siz[u] = 1;
    struct Node *temp = adj[u];
    while (temp != NULL)
    {
        if (temp->val == p)
        {
            temp = temp->next;
            continue;

        }
//Temp starts here
//Here the logic
        dfs(temp->val, u);
        dp[u] = (dp[u] + (sum[u] * (square_sum[temp->val] + 2 * sum[temp->val] + siz[temp->val])) + (sum[temp->val] + siz[temp->val]) * (square_sum[u])) % MOD;

        sum[u] = (sum[u] + sum[temp->val] + siz[temp->val]) % MOD;
        siz[u] += siz[temp->val];

        square_sum[u] += square_sum[temp->val] + 2 * sum[temp->val] + siz[temp->val];
        square_sum[u] %= MOD;
        temp = temp->next;
    }
    ans += dp[u];
    if (ans >= MOD)
        ans -= MOD;
}

int main(int argc, const char *argv[])
{
    int z;
    scanf("%d", &z);
    while (z--)
    {
        int n;
        scanf("%d", &n);
        ans = 0;

        //elements reset for new test case
        for (int i = 0; i < n; i++)
        {
            siz[i] = sum[i] = dp[i] = square_sum[i] = 0;
            adj[i] = NULL;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            u--;
            v--;
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->val = v;
            newNode->next = adj[u];
            adj[u] = newNode;

            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->val = u;
            newNode->next = adj[v];
            adj[v] = newNode;
        }

        dfs(0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
