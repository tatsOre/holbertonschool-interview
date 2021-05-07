#!/usr/bin/python3
"""
Recursive function that queries the Reddit API and prints the count
of the frequency of specific words in the titles of all hot articles
for a given subreddit
"""


import requests


def count_words(subreddit, word_list, allposts={}, after=""):
    """
    Prints a sorted count of given keywords
    (<word_list>: case-insensitive, delimited by spaces)
    """
    base_url = 'https://api.reddit.com/r/'
    endpoint = f'{base_url}{subreddit}/hot?after={after}'
    headers = {'user-agent': 'holbie1626_t100_2021'}
    word_list = set([word.lower() for word in word_list])

    response = requests.get(endpoint, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return None

    data = response.json()
    after = data.get('data').get('after')
    posts = data.get('data').get('children')

    if posts:
        for post in posts:
            title = post.get('data').get('title').lower().split()
            for word in title:
                if word in word_list:
                    allposts[word] = allposts.get(word, 0) + 1
    if after:
        return count_words(subreddit, word_list, allposts, after)
    else:
        sorted_dict = dict(sorted(allposts.items()))
        for key, value in sorted_dict.items():
            print(f"{key}: {value}")
        return sorted_dict
