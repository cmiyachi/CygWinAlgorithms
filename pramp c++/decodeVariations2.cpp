function decodeVariations(S):
    pre, cur = 27, 0
    first, second = 1, 1

    for i from S.length - 1 to 0:
        d = int(S[i])
        if d == 0:
            cur = 0
        else:
            cur = first
            # pre represents the previously seen number S[i+1]
            # If d*10 + pre < 26 (and d != 0), it is valid to
            # write a letter that uses two digits of encoding length,
            # so we count 'second = dp[i+2]' in our current answer.
            if d * 10 + pre < 27:
                cur += second

        pre = d
        first, second = cur, first

    return cur