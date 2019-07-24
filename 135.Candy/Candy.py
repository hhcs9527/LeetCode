class Solution:
    def candy(self, ratings: List[int]) -> int:
        min_pos = ratings.index(min(ratings))
        num_candy = [1] * len(ratings)
        # Check
        i = 0
        while(i < len(ratings)):
            # current比右邊的大
            if (i + 1  < len(ratings) and ratings[i] > ratings[i+1] and num_candy[i] <= num_candy[i+1]):
                num_candy[i] = num_candy[i+1] + 1
            # current比右邊的小
            if (i + 1  < len(ratings) and ratings[i] < ratings[i+1] and num_candy[i] >= num_candy[i+1]):
                num_candy[i+1] = num_candy[i] + 1
            i += 1
        i = len(ratings) - 1
        while(i >= 0):
            # current比左邊的大
            if (i - 1  >= 0 and ratings[i-1] < ratings[i] and num_candy[i] <= num_candy[i-1]):
                num_candy[i] = num_candy[i-1] + 1
            # current比左邊的小
            if (i - 1  >= 0 and ratings[i-1] > ratings[i] and num_candy[i] >= num_candy[i-1]):
                num_candy[i-1] = num_candy[i] + 1
            i-= 1
        return sum(num_candy)