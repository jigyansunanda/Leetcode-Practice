var halvesAreAlike = function (s) {
    let n = s.length;
    let vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"];
    let st = new Set(vowels);
    let x = 0;
    for (let i = 0; i < n; ++i) {
        if (st.has(s[i])) {
            x += i >= n / 2 ? 1 : -1;
        }
    }
    return x === 0;
};