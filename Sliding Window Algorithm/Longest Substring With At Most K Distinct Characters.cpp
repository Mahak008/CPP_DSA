int longestKSubstr(string s, int k) {
  int l = 0, r = 0, maxLen = -1;
  map <char, int> mp;
  if (k > s.length()) {
    return -1;
  }
        
  while(r < s.length()) {
    ++mp[s[r]];
    if(mp.size() > k) {
      --mp[s[l]];
      
      if(mp[s[l]] == 0) {
        mp.erase(s[l]);
      }
      ++l;
    }
    
    maxLen = max(maxLen, (r-l+1));
    ++r;
  }
  return maxLen;
}
