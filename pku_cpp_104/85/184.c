
int main()
{
    int i, j, n;
    char s[32];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        for (j = 0; s[j]!='\0'; j++) {
            if (!((s[j] == '_') ||
                  (s[j] >= 'A' && s[j] <= 'Z') ||
                  (s[j] >= 'a' && s[j] <= 'z') ||
                  (s[j] >= '0' && s[j] <= '9' && j > 0)))
                break;
        }
        if (s[j]!='\0')
            printf("no\n");
        else
            printf("yes\n");
    }
    
    return 0;
}
