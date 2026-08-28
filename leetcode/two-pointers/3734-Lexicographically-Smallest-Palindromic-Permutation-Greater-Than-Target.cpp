class Solution {
public:

    string makePalindrome(string half, char middle)
    {
        string res = half;

        if (middle != '\0')
            res += middle;

        for (int i = (int)half.size() - 1; i >= 0; i--)
            res += half[i];

        return res;
    }


    string buildHalf(string targetHalf, map<char, int> halfMap)
    {
        int n = targetHalf.size();

        string res = "";

        int i = 0;

        for (auto it = halfMap.begin(); it != halfMap.end(); )
        {
            if (it->second == 0)
                it = halfMap.erase(it);
            else
                ++it;
        }


        while (i < n)
        {
            char wanted = targetHalf[i];

            auto it = halfMap.find(wanted);

            if (it != halfMap.end())
            {
                res += wanted;

                halfMap[wanted]--;

                if (halfMap[wanted] == 0)
                    halfMap.erase(wanted);

                i++;
            }
            else
            {

                auto bigger = halfMap.upper_bound(wanted);

                if (bigger != halfMap.end())
                {
                    res += bigger->first;

                    halfMap[bigger->first]--;

                    if (halfMap[bigger->first] == 0)
                        halfMap.erase(bigger->first);

                    for (auto p : halfMap)
                        res += string(p.second, p.first);

                    return res;
                }
                break;
            }
        }


        if (i == n)
            return res;

        for (int pos = (int)res.size() - 1; pos >= 0; pos--)
        {
            halfMap[res[pos]]++;

            auto bigger = halfMap.upper_bound(targetHalf[pos]);

            if (bigger != halfMap.end())
            {
                string answer = res.substr(0, pos);

                answer += bigger->first;

                halfMap[bigger->first]--;

                if (halfMap[bigger->first] == 0)
                    halfMap.erase(bigger->first);

                for (auto p : halfMap)
                    answer += string(p.second, p.first);

                return answer;
            }
        }

        return "";
    }


    string createPalind(string ans)
    {
        int n = ans.size();

        map<char, int> freq;

        for (char c : ans)
            freq[c]++;

        int odd = 0;
        char middle = '\0';

        for (auto p : freq)
        {
            if (p.second % 2)
            {
                odd++;
                middle = p.first;
            }
        }

        if (odd > 1)
            return "";

        map<char, int> halfMap;

        for (auto p : freq)
        {
            if (p.second / 2 > 0)
                halfMap[p.first] = p.second / 2;
        }

        string targetHalf = ans.substr(0, n / 2);


        string half = buildHalf(targetHalf, halfMap);
        if (targetHalf.size() > 0 && half == "")
        {
            return "";
        }

        string candidate = makePalindrome(half, middle);

        if (candidate >= ans)
        {
            return candidate;
        }



        if (!next_permutation(half.begin(), half.end()))
        {
            return "";
        }


        candidate = makePalindrome(half, middle);

        if (candidate >= ans)
        {
            return candidate;
        }

        return "";
    }


    string lexPalindromicPermutation(string s, string target)
    {
        map<char, int> m;

        for (char c : s)
        {
            m[c]++;
        }


        string ans = "";

        int n = target.size();
        int i = 0;

        while (i < n)
        {
            auto it = m.find(target[i]);
            if (it != m.end())
            {
                ans += target[i];

                m[target[i]]--;

                if (m[target[i]] == 0)
                {
                    m.erase(target[i]);
                }

                i++;
            }
            else
            {
                break;
            }
        }

        bool found = false;

        if (i<n)
        {
            auto it = m.upper_bound(target[i]);
            if (it != m.end())
            {
                ans += it->first;
                m[it->first]--;
                if (m[it->first] == 0)
                {
                    m.erase(it->first);
                }
                found = true;
            }
        }

        if (!found)
        {
            for (int pos = (int)ans.size()-1;pos >= 0; pos--)
            {
                m[ans[pos]]++;
                auto it = m.upper_bound(ans[pos]);
                if (it!=m.end())
                {
                    ans.resize(pos);
                    ans += it->first;
                    m[it->first]--;
                    if (m[it->first] == 0)
                    {
                        m.erase(it->first);

                    }

                    found = true;
                    break;
                }
            }
        }


        if (!found)
        {
            return "";
        }

        for (auto p : m)
        {
            ans += string(p.second, p.first);
        }


        if (ans <= target)
        {
            return "";
        }


        return createPalind(ans);
    }
};