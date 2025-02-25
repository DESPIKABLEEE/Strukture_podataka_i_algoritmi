


int f(int *niz, int n) {
  int i = n, sum = 0;
  while(i > 0) {
   int j = 1;
   while(j < n) {
    sum += niz[j];
    j = j*2;
   }
   i--;
  }
  return sum;
}

// T(n) = c1 + n * (c2 + log(n)) = n * log(N)
// O(n) = n * log(N)


int f(int *niz, int n) {
    int i = n, sum = 0;
    while(i > 0) {
      int j = 0;
      while(j < i) {
          sum += niz[j];
          j++;
      }
      while(j < n) {
          sum += niz[j];
          j++;
      }
      i--;
    }
    return sum;
}

// T(n) = c1 + n * (c2 + n/2 + n) = n * (n + n) = n^2 + n^2
// O(n) = n^2


int f(int *niz, int n) {
    int i = n, sum = 0;
    while(i > 0) {
        int j = 0;
        while(j+i < n) {
            sum += niz[j+i];
            j++;
        }
        i--;
    }
    return sum;
}

// T(n) = c1 + n * (c2 + n) = n * n
// O(n) = n^2



int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n) {
        sum += niz[i];
        i+=2;
    }
    int j = 1;
    while (j < 2 * n) {
        sum += niz[j];
        j= j+j;
    }
    return sum;
}

// T(n) = c1 + n/2 + c2 + log(2n) = n + log(n) = n
// O(n) = n


int f(int *niz, int n) {
    int i = n, sum = 0;
    while(i > 0) {
        sum += niz[i/2];
        i--;
    }
    while(i < n) {
        sum += niz[i/2];
        i++;
    }
    return sum;
}

// T(n) = c1 + n + n = n + n
// O(n) = n


int f(int *niz, int n) {
    int i = n, sum = 0;
    while(i > 0) {
        sum += niz[i/2];
        i--;
    }
    while(i < n) {
        sum += niz[i/2];
        i*=2;
    }
    return sum;
}

// T(n) = c1 + n + n/2 = n + n
// O(n) = n


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n) {
        int j = 1;
        while (j < n) {
            sum += niz[j];
            j = 3*j;
        }
        i++;
    }
    return sum;
}

// T(n) = c1 + n * (c2 + n/3) = n * n
// O(n) = n^2 - 


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n) {
        sum += niz[i];
        n--;
    }
    return sum;
}

// T(n) = c1 + n/2 = n
// O(n) = n


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < 2 * n) {
        int j = 0;
        while (j < n / 2) {
         sum += niz[j];
         j++;
        }
        i++;
    }
    return sum;
}

// T(n) = c1 + 2n * (c2 + n/2) = n * n
// O(n) = n^2


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i <= n) {
        int j = 0;
        while (j < i) {
            sum += niz[j];
            j++;
        }
        i++;
    }
    return sum;
}

// T(n) = c1 + n * (c2 + n) = n * n
// O(n) = n^2


int f(int *niz, int n) {
    int j = 1;
    int i = 0, sum = 0;
    while (j < 2 * n) {
        sum += niz[j];
        j++;
    }
    while(i < n * n) {
        sum += niz[j];
        i++;
    }
    return sum;
}

// T(n) = c1 + c2 + 2n + n^2 = n + n^2
// O(n) = n^2


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < 2 * n) {
        sum += niz[i];
        i++;
    }
    int j = 0;
    while (j < n * n) {
        sum += niz[j];
        j++;
    }
    return sum;
}

// T(n) = c1 + 2n + c2 + n^2 = n + n^2
// O(n) = n^2



int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i <= n) {
        int j = 1;
        while (j < 2*n) {
            sum += niz[j];
            j = j + j;
        }
        i++;
    }
    return sum;
}

// T(n) = c1 + n * (c2 + log(2n)) = n * log(n)
// O(n) = n * log(n)


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n * n) {
        sum += niz[j];
        i++;
    }
    int j = 1;
    while (j < 2 * n) {
        sum += niz[j];
        j++;
    }
    return sum;
}

// T(n) = c1 + n^2 + c2 + 2n = n^2 + n
// O(n) = n^2


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n * n) {
        int j = 0;
        while (j < 2 * n) {
            sum += niz[j];
            j++;
        }
        i++;
    }
    return sum;
}

// T(n) = c1 + n^2 * (c2 + 2n) = n^2 * n
// O(n) = n^3


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i <= n / 2) {
        sum += niz[j];
        int j = 0;
        while (j < n / 2) {
            sum += niz[j];
            j += 2;
        }
        i++;
    }
    return sum;
}

// T(n) = c1 + n/2 * (c2 + n/4) = n * n
// O(n) = n^2


int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i <= n / 2) {
        sum += niz[j];
        int j = 0;
        while (j < i) {
            sum += niz[j];
            j++;
        }
        i++;
    }
    return sum;
}

// T(n) = c1 + n/2 * (c2 + n/2) = n * n
// O(n) = n^2
