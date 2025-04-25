from collections import defaultdict
from itertools import combinations

class Solution(object):
    def mostVisitedPattern(self, username, timestamp, website):
        """
        :type username: List[str]
        :type timestamp: List[int]
        :type website: List[str]
        :rtype: List[str]
        """

        # Step 1: First I’ll zip all three arrays into one list of (timestamp, user, site)
        # and sort by timestamp so that the order of visits is preserved
        logs = sorted(zip(timestamp, username, website))

        # Step 2: Next, I’ll build a dictionary to store, for each user,
        # the ordered list of websites they visited
        user_visits = defaultdict(list)
        for time, user, site in logs:
            user_visits[user].append(site)

        # Step 3: I’ll use another dictionary to map each 3-sequence pattern
        # to a set of users who followed that pattern
        pattern_users = defaultdict(set)

        for user, sites in user_visits.items():
            # For each user, I generate all unique combinations of 3 websites
            # in the order they were visited
            patterns = set(combinations(sites, 3))  # set avoids duplicate patterns per user
            for pattern in patterns:
                pattern_users[pattern].add(user)

        # Step 4: Now I scan all patterns to find the one with the highest score
        # If there’s a tie, I pick the lexicographically smallest one
        max_count = 0
        result_pattern = tuple()

        for pattern, users in pattern_users.items():
            count = len(users)
            if count > max_count or (count == max_count and pattern < result_pattern):
                max_count = count
                result_pattern = pattern

        # Finally I return the winning pattern as a list of strings
        return list(result_pattern)
