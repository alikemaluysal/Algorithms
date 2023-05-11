public class Solution {
    public int LengthOfLongestSubstring(string s)
    {
            int n = s.Length;
            if (n < 2)
                return n;
            int maxLenght = 1;
            var map = new Dictionary<char, int>();
            map[s[0]] = 0;
            int start = 0;
            int end = 1;
            while (end < n)
            {
                if (map.ContainsKey(s[end]))
                    start = Math.Max(start, map[s[end]] + 1);
                map[s[end]] = end;
                maxLenght = Math.Max(maxLenght, end - start + 1);
                end++;
            }
            return maxLenght;
    }
}