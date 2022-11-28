#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
每个字母只可能作为一个单词的首字母来贡献答案
lastIndex[i]表示以s[i]为首字母如果存在单词的情况下，单词最后一个字母的下标的最小值
f[i][j]表示前i个字符分成j组的最优解
f[i][j]=max{f[k-1][j-1]+w|j<=k<=i}  k逆序枚举， w表示最后一段，即第j段中单词个数
*/
const int N=205, M=45;
char s[N],word[7][N],len[7];
int p,k,n,num;
int lastIndex[N],f[N][M];

void dp() {
    n = strlen(s + 1);
    memset(lastIndex, 0x7f, sizeof(lastIndex));
    for(int i=1;i<=n;i++){ //枚举一整串中的每个位置
        for(int j=1;j<=num;j++){ //枚举每个单词
            //1、剩余的字符个数比这个单词的长度还短
            //2、现有的lastIndex[i]值比即将讨论的lastIndex[i]值更优
            // 这两种情况出现一种可以直接忽略这个单词
            if (i + len[j] > n || i + len[i] - 1 >= lastIndex[i])
                continue;
            
            bool flag = false;

            for (int k = 0; k < len[j]; k++)
            {
                if (s[i + k] != word[j][k + 1])
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
                continue;
            
            lastIndex[i] = i + len[j] - 1;
        }
    }

    // DP过程
    for(int i=1;i<=n;i++){ //长度为i的串
        for(int j=1;j<=k;j++){ //分成j部分
            int w = 0; // 最后一段中单词个数
            for(int k=i;k>=j;k--){ // 最后一段的起止位置为[k,i]
                if(lastIndex[k]<=i)
                    w++;
                f[i][j]=max(f[i][j], f[k-1][j-1]+w);
            }
        }
    }
}

int main()
{
    // 字串的行数 分为k个部分
    scanf("%d%d",&p,&k);
    for(int i=1;i<=p;i++)
        scanf("%s",s+1+20*(i-1));  // 拼成一长串
    scanf("%d", &num);  // 字典中单词个数
    for(int i=1;i<=num;i++) {
        scanf("%s", word[i]+1);
        len[i]=strlen(word[i]+1);
    }
    dp();
    printf("%d\n",f[n][k]);
    return 0;
}
