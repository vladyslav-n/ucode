int mx_sqrt(int x) {
    if (x < 0)
        return 0;
    if (x == 0 || x == 1)
        return x;
    int half = x / 2;
    for (int i = 2; i <= half && i < 46341; i++)
    {
        if (i * i == x)
        {
            return i;
        }
    }
    return 0;
}

