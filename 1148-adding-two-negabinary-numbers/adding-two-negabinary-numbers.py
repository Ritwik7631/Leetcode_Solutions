class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        
        # helper function convert negabinary to int

        def to_integer(arr):
            result = 0
            base = -2
            for bit in arr:
                result = result * base + bit
            return result

        # helper function to convert int to negabinary

        def to_negabinary(num):
            if num == 0:
                return [0]
            result = []

            while num != 0:
                remainder = num % -2
                num //= -2

                if remainder < 0:
                    remainder += 2
                    num += 1
                result.append(remainder)
            return result[::-1]

        num1 = to_integer(arr1)
        num2 = to_integer(arr2)

        sum_num = num1 + num2

        result = to_negabinary(sum_num)
    
        return result