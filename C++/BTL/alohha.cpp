#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    getline(cin,word);

    //ky tu hop le
    for (size_t i=0;i<word.length();i++)
    {
        char c = tolower(word[i]);
        if (!(c == ' ' || c == '\'' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'p' || c == 'k' || c == 'h' || c == 'l' || c == 'm' ||
            c == 'n' || c == 'w'))
        {
            cout << word << " contains invalid characters.";
            return 0;
        }
    }

    //phat am
    string result = "";
    int i = 0;
    while (i < word.length())
    {
        char c = tolower(word[i]);

        if (c == ' ')
        {
            result += " ";
            i++;
            continue;
        }
        if (c == '\'')
        {
            result += '\'';
            i++;
            continue;
        }

        // nguyen am
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            // nhom nguyen am
            bool flag = false;
            if (i + 1 < word.length())
            {
                char c2 = tolower(word[i + 1]);
                if (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u')
                {
                    string pair = "";
                    pair += c;
                    pair += c2;

                    if (pair == "ai" || pair == "ae")
                    {
                        result += "eye";
                        i += 2;
                        flag = true;
                    }
                    else if (pair == "ao" || pair == "au")
                    {
                        result += "ow";
                        i += 2;
                        flag = true;
                    }
                    else if (pair == "ei")
                    {
                        result += "ay";
                        i += 2;
                        flag = true;
                    }
                    else if (pair == "eu")
                    {
                        result += "eh-oo";
                        i += 2;
                        flag = true;
                    }
                    else if (pair == "iu")
                    {
                        result += "ew";
                        i += 2;
                        flag = true;
                    }
                    else if (pair == "oi")
                    {
                        result += "oy";
                        i += 2;
                        flag = true;
                    }
                    else if (pair == "ou")
                    {
                        result += "ow";
                        i += 2;
                        flag = true;
                    }
                    else if (pair == "ui")
                    {
                        result += "ooey";
                        i += 2;
                        flag = true;
                    }
                }
            }
            if (!flag)
            {
                if (c == 'a') result += "ah";
                else if (c == 'e') result += "eh";
                else if (c == 'i') result += "ee";
                else if (c == 'o') result += "oh";
                else if (c == 'u') result += "oo";
                i++;
            }

            if (i < word.length() && tolower(word[i]) != ' ' && tolower(word[i]) != '\'')
            {
                result += '-';
            }
        }
        else
        {
            if (c == 'p' || c == 'k' || c == 'h' ||
                c == 'l' || c == 'm' || c == 'n')
            {
                result += c;
            }
            else if (c == 'w')
            {
                // kiem tra ky tu truoc w
                if (i > 0)
                {
                    char prev = tolower(word[i-1]);
                    // w sau i hoac e: doc thanh v
                    if (prev == 'i' || prev == 'e')
                    {
                        result += 'v';
                    }
                    else
                    {
                        // cac truong hop khac: doc thanh w
                        result += 'w';
                    }
                }
                else
                {
                    // w o dau tu: doc thanh w
                    result += 'w';
                }
            }
            i++;
        }
    }

    // loai bo dau gach noi cuoi cung neu co
    if (!result.empty() && result.back() == '-')
    {
        result.pop_back();
    }

    cout << result << endl;

    return 0;
}