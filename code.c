long unsigned factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int convert(char * str) {
    int value = 0;
    for (int i=0; str[i] != '\0'; i++) {
        value = value * 10 + (str[i] - '0');
    }
    return value;
}
