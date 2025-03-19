int main() { 
    // Ordenação em tempo linear
    // Complexidade de tempo: O(n + k), n é o tamanho do vetor e k o range dos elementos (r-l+1)
    // Complexidade de espaco: O(2*n), pois precisa de um vetor auxiliar
    
    int n, l = INF, r = -INF; cin >> n;
    vector<int> v(n);

    REP(i, 0, n) {
        cin >> v[i];
        l = min(v[i], l);
        r = max(v[i], r);
    }

    // contando as frequências
    int k = r-l+1;
    vector<int> freq(k);
    for (auto& x: v) freq[x-l]++;

    // fazendo a soma de prefixo para saber a posição
    REP(i, 1, k) freq[i] += freq[i-1];

    // colocar os valores na posição correta no vetor auxiliar
    vector<int> aSorted(n);
    for (int i = n-1; i >= 0; i--) {
        aSorted[--freq[v[i]-l]] = v[i];
    }
    
    for (auto x: aSorted) cout << x << " ";

    return 0;
}